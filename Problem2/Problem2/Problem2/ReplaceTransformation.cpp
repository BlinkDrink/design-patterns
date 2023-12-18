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

		bool ReplaceTransformation::operator==(const TextTransformation& other) const
		{
			const ReplaceTransformation* cast = dynamic_cast<const ReplaceTransformation*>(&other);
			if (!cast)
				return false;

			return from == cast->from && to == cast->to;
		}

		void ReplaceTransformation::add(std::unique_ptr<TextTransformation>& transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}
