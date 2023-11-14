#pragma once
#include "FigureFactory.h"
#include <fstream>

using std::istream;
using std::ifstream;

/**
 * \brief Factory used to create Figure objects from streams (i.e. STDIN, File Streams and so on)
 */
class StreamFigureFactory : public FigureFactory
{
private:
	ifstream m_file;
	istream& m_stream;
public:
	/**
	 * \brief Initializing constructor used to set the stream from which the figures will be read
	 * \param s - the stream from which the figures will be read
	 */
	StreamFigureFactory(istream& s);

	/**
	 * \brief Constructor with rvalue refference used to move an already created instance of a file into the data member
	 * m_file. m_stream is directed to m_file.
	 * \param s
	 */
	StreamFigureFactory(ifstream&& s);

	/**
	 * \brief By given arguments for a figure (i.e. "circle 2.5") return a figure satisfying the given type
	 * \param args - string representation of a figure
	 * \return - dynamically allocated figure satisfying the given arguments
	 */
	unique_ptr<Figure> create_figure() const override;
};