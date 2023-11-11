#include "StreamFigureFactory.h"
#include <stdexcept>
#include<sstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::invalid_argument;
using std::stringstream;
using std::make_unique;

StreamFigureFactory::StreamFigureFactory(istream& s) : stream_(s)
{
}

unique_ptr<Figure> StreamFigureFactory::create_figure() const
{
    string type;
    stream_ >> type;

    // TODO: Reading input from stream_ may throw (i.e. "rectangle 3.5" this expects another value)
    if (type == "triangle") {
        double a, b, c;
        stream_ >> a >> b >> c;
        return make_unique<Triangle>(a, b, c);
    }
    else if(type == "rectangle")
    {
        double a,b;
        stream_ >> a >> b;
        return make_unique<Rectangle>(a,b);
    }
    else if(type == "circle")
    {
        double radius;
        stream_ >> radius;
        return make_unique<Circle>(radius);
    }

    throw invalid_argument("Invalid figure type");
}
