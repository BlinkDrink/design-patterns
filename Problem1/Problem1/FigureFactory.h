#pragma once
#include <memory>
#include "Figure.h"
using std::unique_ptr;

/**
 * \brief Abstract Factory for creating different types of figures depending on their input
 */
class FigureFactory {
public:
    
    virtual unique_ptr<Figure> create_figure(const string& params) const = 0;
    virtual ~FigureFactory() = default;
};