#pragma once
#include <memory>
#include <vector>

#include "Label.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace Composites
	{
		using std::vector;
		using Labels::Label;
		using std::unique_ptr;
		using TextTransformations::TextTransformation;

		/**
		 * \brief Class representing the composition of text transformations over a string
		 */
		class CompositeTransformation : public TextTransformation
		{
		private:
			vector<unique_ptr<TextTransformation>> m_transformations;
		public:
			string transform(string text) const override;
			bool operator==(const TextTransformation& other) const override;
			void add(unique_ptr<TextTransformation>& transformation) override;
		};
	}
}
