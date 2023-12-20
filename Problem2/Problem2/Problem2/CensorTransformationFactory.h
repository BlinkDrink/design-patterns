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
			/**
			 * \brief Creates a CensorTransformation object with the given word to censor.
			 * If the word's length is <= 4 then a flyweight object is stored inside m_censor_flyweights and reused each time
			 * it is requested again
			 * \param to_censor - the word that will be censored
			 * \return - shared_ptr to the CensorTransformation object that will be shared
			 */
			shared_ptr<CensorTransformation> createCensorTransformation(const string& to_censor);
		};
	}
}

