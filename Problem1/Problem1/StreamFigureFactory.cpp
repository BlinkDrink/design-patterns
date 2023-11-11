#include "StreamFigureFactory.h"
#include <stdexcept>
#include<sstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::invalid_argument;
using std::stringstream;
using std::make_unique;

StreamFigureFactory::StreamFigureFactory(istream& s) : stream(s)
{
}

unique_ptr<Figure> StreamFigureFactory::create_figure(const string& args) const
{
	stringstream iss(args);
    string type;
    iss >> type;

    // TODO: Reading input from stream may throw (i.e. "rectangle 3.5" this expects another value)
    if (type == "triangle") {
        double a, b, c;
        iss >> a >> b >> c;
        return make_unique<Triangle>(a, b, c);
    }
    else if(type == "circle")
    {
        double radius;
        iss >> radius;
        return make_unique<Circle>(radius);
    }
    else if(type == "rectangle")
    {
        double a,b;
        iss >> a >> b;
        return make_unique<Rectangle>(a,b);
    }

    throw invalid_argument("Invalid figure type");
}
