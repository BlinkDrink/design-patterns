#pragma once
#include "FigureFactory.h"
using std::istream;

/**
 * \brief Factory used to create Figure objects from streams (i.e. STDIN, File Streams and so on)
 */
class StreamFigureFactory : public FigureFactory
{
private:
	istream& stream_;
public:
	/**
	 * \brief Initializing constructor used to set the stream from which the figures will be read 
	 * \param s - the stream from which the figures will be read
	 */
	StreamFigureFactory(istream& s);

	/**
	 * \brief By given arguments for a figure (i.e. "circle 2.5") return a figure satisfying the given type
	 * \param args - string representation of a figure
	 * \return - dynamically allocated figure satisfying the given arguments
	 */
	unique_ptr<Figure> create_figure() const override;
};