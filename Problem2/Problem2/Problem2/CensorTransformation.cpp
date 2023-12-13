#include "CensorTransformation.h"

#include <memory>

namespace Problem2
{
	namespace TextTransformations
	{
		string CensorTransformation::transform(string text) const
		{
			size_t pos = text.find(to_censor);
			while (pos != std::string::npos)
			{
				text.replace(pos, to_censor.size(), to_censor.size(), '*');
				pos = text.find(to_censor, pos + to_censor.size());
			}
			return text;
		}

		CensorTransformation::CensorTransformation(string to_censor) : to_censor(std::move(to_censor))
		{
		}

		bool CensorTransformation::operator==(const TextTransformation& other)
		{
			const CensorTransformation* cast = dynamic_cast<const CensorTransformation*>(&other);
			if (!cast)
				return false;

			return to_censor == cast->to_censor;
		}

		void CensorTransformation::add(std::unique_ptr<TextTransformation>& transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}
