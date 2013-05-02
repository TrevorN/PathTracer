#include "PngFactory.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

PngFactory::PngFactory()
{

}

int PngFactory::makePng(Colour* image, int resX, int resY, std::string filename)
{

	FILE* rendering;
	int bytes_per_pixel = 4;
	int compositionSize = resX*resY;
	png_byte *colors = (png_byte*) malloc(bytes_per_pixel*compositionSize*sizeof(*colors));
	png_byte rgbDepth = 8;

	for(int i = 0; i < compositionSize; i++){

		int hue = image[i].getRGB();
		int offset = i*bytes_per_pixel;
		colors[offset] = (hue>>16)&0xFF;
		colors[offset+1] = (hue>>8)&0xFF;
		colors[offset+2] = (hue)&0xFF;
		colors[offset+3] = 255;

	}

	png_byte **row_pointers = (png_byte**) malloc(resY*sizeof(*row_pointers));

	for(int i = 0; i < resY; i++){

		row_pointers[i] = colors+i*resX*bytes_per_pixel;

	}

	rendering = fopen(filename.c_str(), "wb");

	if(!rendering){

		return(-1);

	}

	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if(!png_ptr){
		
		return(-1);

	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	
	if(!info_ptr){

		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		return(-1);

	}

	if(setjmp(png_jmpbuf(png_ptr))){
		png_destroy_write_struct(&png_ptr, &info_ptr);
		fclose(rendering);
		return(-1);
	}

	png_init_io(png_ptr, rendering);
	png_set_write_status_fn(png_ptr, write_row_callback);
	png_set_compression_level(png_ptr, Z_DEFAULT_COMPRESSION);
	png_set_IHDR(png_ptr, info_ptr, resX, resY, rgbDepth, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	png_text text_ptr[3];
	text_ptr[0].key = (char*) "Title";
	text_ptr[0].text = (char*) "$WAG";
	text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
	text_ptr[1].key = (char*) "Author";
	text_ptr[1].text = (char*) "Adam Schmidt & Trevor Nielsen";
	text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
	text_ptr[2].key = (char*) "Description";
	text_ptr[2].text = (char*) "this";
	text_ptr[2].compression = PNG_TEXT_COMPRESSION_zTXt;
	png_set_text(png_ptr, info_ptr, text_ptr, 3);

	png_write_info(png_ptr, info_ptr);

	
	png_color_8p sig_bit = (png_color_8p) malloc(sizeof(png_color_8));
	sig_bit->red = rgbDepth;
	sig_bit->green = rgbDepth;
	sig_bit->blue = rgbDepth;
	sig_bit->alpha = rgbDepth;
	
	png_set_sBIT(png_ptr, info_ptr, sig_bit);
	png_set_shift(png_ptr, sig_bit);

	
	if(resY > PNG_UINT_32_MAX/png_sizeof(png_bytep)){

		png_error(png_ptr, "too big image");

	}

	png_write_image(png_ptr, row_pointers);

	png_write_end(png_ptr, NULL);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	free(colors);
	free(row_pointers);



	fclose(rendering);
	return 0;
	
}

void PngFactory::write_row_callback(png_structp png_ptr, png_uint_32 row, int pass)
{


}
