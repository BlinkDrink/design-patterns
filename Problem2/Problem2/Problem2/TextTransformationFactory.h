#pragma once
#include <unordered_map>

#include "CensorTransformationFactory.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace Factories
	{
		using std::unordered_map;
		using std::vector;
		using TextTransformations::TextTransformation;

		class TextTransformationFactory
		{
		private:
			unordered_map<string, shared_ptr<TextTransformation>> m_basic_transformations;
			CensorTransformationFactory m_censor_transformation_factory;
			vector<string> m_available_types = { "capitalize", "normalize_spaces", "censor", "decorate", "left_trim", "right_trim", "replace" };
		public:
			/**
			 * \brief Sets the inner unordered_map to contain the basic transformations that don't initialize any data members through their constructors (e.g. capitalize, normalize_spaces, decorate, left_trim, right_trim)
			 */
			TextTransformationFactory();

			/**
			 * \brief Creates a TextTransformation based on some text input
			 * \param input - the type of TextTransformation that will be created (e.g. replace abc def, censor o, decorate etc.)
			 * \return A shared instance of the text transformation that is required
			 */
			shared_ptr<TextTransformation> create_transformation(const string& input);
		};
	}
}

