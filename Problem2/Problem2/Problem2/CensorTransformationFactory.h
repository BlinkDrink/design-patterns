#pragma once
#include <memory>
#include <unordered_map>

#include "CensorTransformation.h"

namespace Problem2
{
	namespace Factories
	{
		using std::shared_ptr;
		using std::make_shared;
		using std::unordered_map;
		using TextTransformations::CensorTransformation;

		class CensorTransformationFactory
		{
		private:
			unordered_map<string, shared_ptr<CensorTransformation>> m_censor_flyweights;

		public:
			shared_ptr<CensorTransformation> createCensorTransformation(const std::string& word)
			{
				if (word.length() <= 4)
				{
					if (m_censor_flyweights.find(word) != m_censor_flyweights.end())
					{
						return m_censor_flyweights[word];
					}

					shared_ptr<CensorTransformation> censorTransformation = make_shared<CensorTransformation>(word);
					m_censor_flyweights[word] = censorTransformation;
					return censorTransformation;
				}

				return make_shared<CensorTransformation>(word);
			}
		};
	}
}

