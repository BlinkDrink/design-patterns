#include "TextTransformationFactory.h"
#include <sstream>

#include "CapitalizeTransformation.h"
#include "DecorateTransformation.h"
#include "LeftTrimTransformation.h"
#include "NormalizeSpaceTransformation.h"
#include "ReplaceTransformation.h"
#include "RightTrimTransformation.h"

namespace Problem2
{
	namespace Factories
	{
		using std::istringstream;
		using std::invalid_argument;
		using TextTransformations::CapitalizeTransformation;
		using TextTransformations::LeftTrimTransformation;
		using TextTransformations::RightTrimTransformation;
		using TextTransformations::DecorateTransformation;
		using TextTransformations::NormalizeSpaceTransformation;
		using TextTransformations::ReplaceTransformation;
		using TextTransformations::CensorTransformation;

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
	}
}
