#pragma once
#include <memory>
#include <vector>

#include "Label.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		using std::vector;
		using Labels::Label;
		using std::unique_ptr;
		using std::shared_ptr;
		using TextTransformations::TextTransformation;

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
	}
}
