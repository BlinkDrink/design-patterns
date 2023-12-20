#pragma once
#include <string>
#include <memory>

using std::string;

namespace Problem2
{
	namespace TextTransformations
	{
		using std::unique_ptr;
		using std::shared_ptr;

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
	}
}
