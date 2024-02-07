#pragma once
#include "FigureType.h"
#include <string>

using std::string;
using std::unique_ptr;

namespace Problem1
{
	using Figures::FigureType;

	namespace Figures
	{
		class Figure
		{
		protected:
			string m_string_format;
			double m_perimeter = 0;
		public:
			virtual double perimeter() const = 0;
			virtual string toString() const = 0;
			virtual unique_ptr<Figure> clone() const = 0;
			virtual bool operator==(const Figure& other) const = 0;
			virtual FigureType figureType() const = 0;
			virtual ~Figure() = default;
		};
	}
}
