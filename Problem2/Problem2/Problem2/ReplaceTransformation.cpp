#include "ReplaceTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string ReplaceTransformation::transform(string text) const
		{
			size_t pos = text.find(from);
			while (pos != std::string::npos)
			{
				text.replace(pos, from.size(), to);
				pos = text.find(from, pos + to.size());
			}
			return text;
		}

		ReplaceTransformation::ReplaceTransformation(string from, string to) : from(std::move(from)), to(std::move(to))
		{
		}
	}
}
