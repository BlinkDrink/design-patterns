# Label Decorators and Transformations - Problem 2

### Design patterns used:

- Bridge
- Composite
- Decorator
- Dependency injection
- Proxy
- Strategy
- Template Method
- Factory

This project currently supports four label types `SimpleLabel`, `RichLabel`, `ProxyLabel`, `HelpLabel` all implementing the given interface `Label`:

```C++
class Label
{
public:
	virtual string getText() const = 0;
	virtual bool operator==(const Label& other) const = 0;
	virtual ~Label() = default;
};
```

Currently supported Decorators are `TextTransformationDecorator`, `RandomTransformationDecorator` and `RotatingTransformationDecorator` all implementing the base class `LabelDecoratorBase`:

```C++
/**
    * \brief Abstract class for all Decorator objects. It is also a Label to allow for Decorator functionality
    */
class LabelDecoratorBase : public Label
{
protected:
    unique_ptr<Label> m_label;
public:
    LabelDecoratorBase(unique_ptr<Label> next);

    /**
        * \brief Starts the process of decorator removal from a given decorator
        * This is the algorithm on which Template Method Design Pattern is applied
        * by overriding specific part of it in the derived classes
        * \param from - starting point(label) from which decorator will be found and removed
        * \param toRemove - the target decorator that will be removed
        * \return - the chain of decorators starting with from, excluding toRemove (if it was found)
        */
    static unique_ptr<Label> removeDecoratorFrom(unique_ptr<Label> from, const LabelDecoratorBase& toRemove);

    /**
        * \brief Called inside of removeDecoratorFrom and overriden in deriving classes of LabelDecoratorBase
        * Implements different logic for the different decorators
        * \param toRemove - the target decorator that will be removed
        * \return - the chain of decorators, excluding toRemove (if it was found)
        */
    virtual unique_ptr<Label> removeDecorator(const LabelDecoratorBase& toRemove) = 0;

    virtual string getText() const override = 0;
    virtual bool operator==(const Label& other) const override = 0;

};
```

## Decorator and Strategy

The Strategy itself is the class TextTransformation. It has method transform(string text) which is overriden in all of the derived classes of TextTransformation:

```C++
/**
 * \brief Base class for the different algorithms we can apply to a Label
 */
class TextTransformation
{
public:
	/**
	 * \brief Used for adding children to the CompositeTransformation. For every other
	 * transformation it does nothing. Chosen transparency over safety
	 * \param transformation - the transformation that will be added to the composite
	 */
	virtual void add(shared_ptr<TextTransformation> transformation) = 0;

	virtual string transform(string text) const = 0;
	virtual ~TextTransformation() = default;
	virtual bool operator==(const TextTransformation& other) const = 0;
};
```

With this implementation we can use the Strategy design pattern and Decorator design pattern to chain multiple decorators together and give them specific algorithms that transform the underlying text of a label. Dependency injection is used to inject the specific Strategy we want to apply on the labels:

```C++
unique_ptr<Label> label = make_unique<SimpleLabel>("some text");
label = make_unique<TextTransformationDecorator>(std::move(label), make_shared<ReplaceTransformation>("so","aweso"));
label = make_unique<TextTransformationDecorator>(std::move(label), make_shared<DecorateTransformation>());
cout << label->getText();
// prints -={ awesome text }=-
```

## Template method

Template method is applied in the LabelDecoratorBase class. The algorithm that we apply template method to is removeDecoratorFrom and the specific parts that we modify are removeDecorator() method that every child of LabelDecoratorBase should implement:

```C++
unique_ptr<Label> LabelDecoratorBase::removeDecoratorFrom(unique_ptr<Label> from, const LabelDecoratorBase& toRemove)
{
	LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(from.get());
	if (decorator)
		return decorator->removeDecorator(toRemove); // this is the part of the algorithm we want to vary depending on the decorator it is called from

	return std::move(from);
}
```

Here we allow for removal of Decorators through the static method in LabelDecoratorBase like so:

```C++
const TextTransformationDecorator toRemove(make_unique<SimpleLabel>(text), make_shared<CapitalizeTransformation>);
unique_ptr<Label> decorator1 = make_unique<RandomTransformationDecorator>(make_unique<ProxyLabel>(timeout), transformations, seed);
decorator1 = make_unique<TextTransformationDecorator>(std::move(decorator1), make_shared<CapitalizeTransformation>());
decorator1 = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(decorator1), toRemove);
```

## Composite

We want to achieve the same functionality as decorators but using text transformations only. This is achieved by using Composite design pattern with TextTransformations:

```C++
/**
 * \brief Class representing the composition of text transformations over a string
 */
class CompositeTransformation : public TextTransformation
{
private:
	vector<shared_ptr<TextTransformation>> m_transformations;
public:

	/**
	 * \brief Transforms a given string by applying text transformations on it, calls transform on every child TextTransformation
	 * \param text - the text that text transformations will be done upon
	 * \return - newly transformed string
	 */
	string transform(string text) const override;

	/**
	 * \brief Equality operator
	 * \param other - the object the comparison is done against
	 * \return - true if elements of m_transformations match (deep comparison), false otherwise
	 */
	bool operator==(const TextTransformation& other) const override;

	/**
	 * \brief Adds a new transformation to the vector m_transformations
	 * \param transformation - the transformation that will be added
	 */
	void add(shared_ptr<TextTransformation> transformation) override;
};
```

Here is an example usage:

```C++
vector<shared_ptr<TextTransformation>> transformations1;
transformations1.push_back(make_shared<CapitalizeTransformation>());
transformations1.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
transformations1.push_back(make_shared<DecorateTransformation>());
transformations1.push_back(make_shared<ReplaceTransformation>("e", "o"));
transformations1.push_back(make_shared<CensorTransformation>("so"));

CompositeTransformation s;
s.add(transformations1[0]);
tt->add(transformations1[1]);
tt->add(transformations1[3]);
s.add(tt);
s.add(transformations1[2]);

s.transform("some text"); // outputs "-={ Somo toxt }=-"
```

## Bridge

The Bridge design pattern is used in the implementation of HelpLabel by decoupling the abstraction (HelpLabel) and implementation (Label):

```C++
class HelpLabel : public Label
{
private:
	unique_ptr<Label> m_imp;
	string m_help_text;
public:

	/**
	 * \brief HelpLabel constructor. Uses dependency injection for m_imp
	 * \param implementation - the specific label implementation that will receive help text
	 * \param help_text - the help message that the HelpLabel will give
	 */
	HelpLabel(unique_ptr<Label> implementation, string help_text);

	/**
	 * \brief Calls getText() of the underlying label (m_imp)
	 */
	string getText() const override;

	/**
	 * \return - the private data member m_help_text
	 */
	string getHelpText() const;

	/**
	 * \brief Equality operator - uses dynamic cast
	 * \param other - the object the comparison is done against
	 * \return true if the other object is of type HelpLabel and their m_imp and m_help_text match
	 * the current m_imp and m_help_text
	 */
	bool operator==(const Label& other) const override;

    /**
    * \brief Setter
    * \param help_text - the new value for the m_help_text field
    */
    void setHelpText(string help_text);
};
```

## Proxy

The Proxy design pattern is used in our fourth type of label - `ProxyLabel`. The label itself serves as a proxy for a label that will be created when the user requires its text for the first time:

```C++
class ProxyLabel : public Label
{
private:
	mutable unique_ptr<Label> m_real_label;
	mutable int m_timeout_threshold;
	mutable int m_request_count;
	mutable bool m_prompt_user;

public:
	ProxyLabel(int timeout = 5);

	/**
	 * \brief Gets the text of the underlying label. m_real_label gets created when getText gets called for the first time
	 * After getText gets called timeout number of times a console input will be required in order to reset the text of the
	 * underlying label or keep it the same.
	 * \return - m_real_label's getText()
	 */
	string getText() const override;

	/**
	 * \brief Equality operator - uses dynamic_cast
	 * \param other - the object the comparison is done against
	 * \return - true if other is of type ProxyLabel and their m_real_label, m_timeout_threshold, m_request_count and m_prompt_user
	 * match the current ones
	 */
	bool operator==(const Label& other) const override;
};
```

Here is usage example of ProxyLabel:

```C++
const ProxyLabel proxyLabel(5); // proxy label has not set its inner label at this point.
const istringstream input_stream("some text");
cin.rdbuf(input_stream.rdbuf());
proxyLabel.getText(); // After prompting the user for the text of the label, it sets the inner label to a SimpleLabel with the given text
```

## Factory

Factory design pattern is used in TextTransformationFactory like so:

```C++
class TextTransformationFactory
{
private:
	unordered_map<string, shared_ptr<TextTransformation>> m_basic_transformations;
	CensorTransformationFactory m_censor_transformation_factory;
	vector<string> m_available_types = { "capitalize", "normalize_spaces", "censor", "decorate", "left_trim", "right_trim", "replace" };
public:
	TextTransformationFactory();

	shared_ptr<TextTransformation> create_transformation(const string& input_type);
};
```

The basic text transformations that don't have any data fields and complex constructor logic are set in the TextTransformationFactory's constructor:

```C++
TextTransformationFactory::TextTransformationFactory()
{
	m_basic_transformations["capitalize"] = make_shared<CapitalizeTransformation>();
	m_basic_transformations["decorate"] = make_shared<DecorateTransformation>();
	m_basic_transformations["normalize_spaces"] = make_shared<NormalizeSpaceTransformation>();
	m_basic_transformations["left_trim"] = make_shared<LeftTrimTransformation>();
	m_basic_transformations["right_trim"] = make_shared<RightTrimTransformation>();
}

shared_ptr<TextTransformation> TextTransformationFactory::create_transformation(const string& input_type)
{
	istringstream iss(input_type);
	string type;
	iss >> type;

	bool is_contained = false;
	for (size_t i = 0; i < m_available_types.size(); ++i)
	{
		if (type == m_available_types[i])
		{
			is_contained = true;
			break;
		}
	}

	if (!is_contained)
		throw invalid_argument("Invalid transformation type");

	if (type == "replace")
	{
		string from, to;
		if (!(iss >> from >> to))
			throw invalid_argument("Arguments for replace transformation were insufficient or invalid type");

		return make_shared<ReplaceTransformation>(from, to);
	}

	if (type == "censor")
	{
		string to_censor;
		if (!(iss >> to_censor))
			throw invalid_argument("Arguments for censor transformation were insufficient or invalid type");

		return m_censor_transformation_factory.createCensorTransformation(to_censor);
	}

	return m_basic_transformations[type];
}
```
