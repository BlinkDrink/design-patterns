#pragma once
#include "FigureFactory.h"

class RandomFigureFactory : public FigureFactory
{
public:
	unique_ptr<Figure> create_figure(const string& args) const override;
};