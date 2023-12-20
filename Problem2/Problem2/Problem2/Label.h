#pragma once
#include <string>

using std::string;

namespace Problem2
{
	namespace Labels
	{

		/**
		 * \brief Base class for all Label objects
		 */
		class Label
		{
		public:
			virtual string getText() const = 0;
			virtual bool operator==(const Label& other) const = 0;
			virtual ~Label() = default;
		};
	}
}
