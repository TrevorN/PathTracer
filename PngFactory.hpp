#ifndef C_PNGFACTORY
#define C_PNGFACTORY

#include "Colour.hpp"
#include <png.h>
#include <zlib.h>

class PngFactory
{

		void write_row_callback(png_structp, png_uint_32, int);
	public:
		PngFactory();
		int makePng(Colour*, int, int);
};
#endif
