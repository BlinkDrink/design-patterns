# Figure Factory - Problem 1

## Design patterns used:

- Prototype
- Abstract Factory
- Factory
- Singleton

This project currently supports three figure types `Circle`, `Rectangle`, `Triangle`, all implementing the given interface `Figure`:

```C++
class Figure
{
protected:
	string m_string_format;
	double m_perimeter;
public:
	virtual double perimeter() const = 0;
	virtual string toString() const = 0;
	virtual unique_ptr<Figure> clone() const = 0;
	virtual bool operator==(const Figure& other) const = 0;
	virtual FigureType figureType() const = 0;
	virtual ~Figure() = default;
};
```

- `toString` operation stringifies figures in format: `"figureName propertyA propertyB..."`

Currently supported factories are `StreamFigureFactory` and `RandomFigureFactory` both implementing the interface `FigureFactory`:

```C++
class FigureFactory {
public:
	virtual unique_ptr<Figure> create_figure() = 0;
	virtual ~FigureFactory() = default;
};
```

Adding new figures to the program is easy as all we have to do is create the class for the new figure and inherit from `Figure`. Figure Factories can be extended easily to cover logic for the newly added figure:

```C++
unique_ptr<Figure> StreamFigureFactory::create_figure()
{
	string type;
	if (!(m_stream >> type))
		throw invalid_argument("Invalid figure name in file");

	if (type == "triangle") {
		double a, b, c;
		if (!(m_stream >> a >> b >> c))
			throw invalid_argument("Invalid triangle format in file");

		return make_unique<Triangle>(a, b, c);
	}
	else if (type == "rectangle")
	{
		double a, b;
		if (!(m_stream >> a >> b))
			throw invalid_argument("Invalid rectangle format in file");

		return make_unique<Rectangle>(a, b);
	}
	else if (type == "circle")
	{
		double radius;
		if (!(m_stream >> radius))
			throw invalid_argument("Invalid circle format in file");

		return make_unique<Circle>(radius);
	}
        else if (type == "elipse")
        {
                // some logic..
        }

	throw invalid_argument("Invalid figure type");
}
```

Lastly the project has `UserInputFactory` that follows the Singleton design pattern to raise the abstraction level over the factories and create them based on the input type (Random/STDIN/File).

```C++
class UserInputFactory
{
private:
	UserInputFactory() = default;
public:
	unique_ptr<FigureFactory> create_figure_factory(const string& input_type) const;

	static UserInputFactory& getInstance();

	UserInputFactory(const UserInputFactory& other) = delete;
	UserInputFactory& operator=(const UserInputFactory& other) = delete;
	UserInputFactory(UserInputFactory&& other) = delete;
	UserInputFactory& operator=(UserInputFactory&& other) = delete;
};
```

If we later decide that we need another factory, lets say `ServerAPIFigureFactory` all we need to do is create the class and inherit from `FigureFactory`. Then we can extend the `UserInputFactory` like this:

```C++
unique_ptr<FigureFactory> UserInputFactory::create_figure_factory(const string& input_type) const // File/STDIN/Random
{
	if (input_type == "Random")
	{
		double lower, upper;
		cout << "Enter lower bound:";
		cin >> lower;
		cout << "Enter upper bound:";
		cin >> upper;

		return make_unique<RandomFigureFactory>(lower, upper, time(nullptr));
	}
	else if (input_type == "STDIN")
	{
		return make_unique<StreamFigureFactory>(cin);
	}
	else if (input_type == "File") {
		string filename;
		cout << "Enter file name: ";
		cin >> filename;

		ifstream file(filename);
		if (!file.is_open())
			throw invalid_argument("File couldn't be opened for reading");

		return make_unique<StreamFigureFactory>(std::move(file));
	}
        else if (input_type == "ServerAPI")
        {
            // some logic for getting the data from the server
        }

	throw invalid_argument("Invalid input type");
}
```

### Further extension

If at some point we decide that our application will not only support figures but `Curves` as well we can then achieve that by creating new Abstract Product (just like Figure) and call it `Curve`. Then we have to create an appropriate `CurveFactory` base class to give the interface for curve creation based on some context. Lastly in the `UserInputFactory` we can create new method

```C++
unique_ptr<CurveFactory> create_curve_factory(const string& input_type) const;
```

which will handle the factory creation.
