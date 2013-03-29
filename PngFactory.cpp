#include "PngFactory.hpp"
#include <stdio.h>
using namespace std;
PngFactory::PngFactory(){

}

int PngFactory::makePng(Colour* image, int resX, int resY){

	FILE* rendering;
	rendering = fopen("test.png", "wb");

	if(rendering < 0){

		return(-1);

	}

	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, (png_voidp) 0, 0, 0);

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
		return(-1);
	}

	png_init_io(png_ptr, rendering);

	png_set_write_status_fn(png_ptr, write_row_callback);

	png_set_compression_level(png_ptr, Z_DEFAULT_COMPRESSION);

	png_set_IDHR(png_ptr, info_ptr, resX, resY, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	palette = (png_colorp) png_malloc(png_ptr, PNG_MAX_PALETTE_LENGTH* png_sizeof(png_color));
	png_set_PLTE(png_ptr, info_ptr, palette, PNG_MAX_PALETTE_LENGTH);


	text_ptr[0].key = "Title";
	text_ptr[0].text = "$WAG";
	text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
	text_ptr[1].key = "Author";
	text_ptr[1].text = "Adam Schmidt & Trevor Nielsen";
	text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
	text_ptr[2].key = "Description";
	text_ptr[2].text = "this";
	text_ptr[2].compression = PNG_TEXT_COMPRESSION_zTXt;
	png_set_text(png_ptr, info_ptr, text_ptr, 3);

	png_write_info(png_ptr, info_ptr);

	png_color_8p sig_bit;
	png_get_sBIT(png_ptr, info_ptr, &sig_bit);
	png_set_shift(png_ptr, sig_bit);
	sig_bit.red = 8;
	sig_bit.green = 8;
	sig_bit.blue = 8;
	png_set_sBIT(png_ptr, info_ptr, sig_bit);
	png_set_shift(png_ptr, sig_bit);
	png_set_packing(png_ptr);
	png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);
	png_set_bgr(png_ptr);

	png_set_swap(png_ptr);

	png_set_packswap(png_ptr);

	png_set_shift(png_ptr, &sig_bit);

	int bytes_per_pixel = 4;
	png_uint_32 k, height, width;
	height = resY;
	width = resX;
	png_byte image[height][width*bytes_per_pixel];
	png_bytep row_pointers[height];
	
	if(height > PNG_UINT_32_MAX/png_sizeof(png_bytep))
		png_error(png_ptr, "too big image"):

	for(k = 0; k < height; k++)
		row_pointers[k] = image + k*width*bytes_per_pixel;

	png_write_image(png_ptr, row_pointers);

	png_free(png_ptr, palette);
	palette=NULL;




	fclose(rendering);
	return 0;
	
}

void PngFactory::write_row_callback(png_structp png_ptr, png_uint_32 row, int pass)
{

	std::cout << "swag"

}
