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
			TextTransformationFactory();


			/**
			 * \brief
			 * \param input_type
			 * \return
			 */
			shared_ptr<TextTransformation> create_transformation(const string& input_type);
		};
	}
}

