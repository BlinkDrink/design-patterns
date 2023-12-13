#pragma once
#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class CensorTransformation : public TextTransformation
		{
		private:
			string to_censor;
		public:
			/**
			 * \brief Censors a specific string by replacing all of its occurrences in the label with asterisks
			 * \param text - string whose characters will be censored
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;

			CensorTransformation(string to_censor);

			/**
			 * \brief Comparator - uses dynamic_cast
			 * \param other - the object the comparison is done against
			 * \return - true if object types and data member to_censor match
			 */
			bool operator==(const TextTransformation& other) override;
			void add(std::unique_ptr<TextTransformation>& transformation) override;
		};
	}
}
