#include "CensorTransformationFactory.h"

namespace Problem2
{
	namespace Factories
	{
		shared_ptr<CensorTransformation> CensorTransformationFactory::
			createCensorTransformation(const string& to_censor)
		{
			if (to_censor.length() <= 4)
			{
				if (m_censor_flyweights.find(to_censor) != m_censor_flyweights.end())
				{
					return m_censor_flyweights[to_censor];
				}

				shared_ptr<CensorTransformation> censorTransformation = make_shared<CensorTransformation>(to_censor);
				m_censor_flyweights[to_censor] = censorTransformation;
				return censorTransformation;
			}

			return make_shared<CensorTransformation>(to_censor);
		}
	}
}

