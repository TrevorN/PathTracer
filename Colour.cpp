#include "Colour.hpp"

Colour::Colour()
{

	this->r = -1;
	this->g = -1;
	this->b = -1;

}

Colour::Colour(int r, int g, int b)
{

	this->r = r;
	this->g = g;
	this->b = b;

}

Colour::Colour(int rgb)
{

	r = rgb>>16&0xFF;
	g = rgb>>8&0xFF;
	b = rgb&0xFF;

}

Colour Colour::operator+(Colour other)
{

	r=r+other.getRed();
	g=g+other.getGreen();
	b=b+other.getBlue();

}

Colour Colour::operator-(Colour other)
{

	r=r-other.getRed();
	g=g-other.getGreen();
	b=b-other.getBlue();

}

Colour& Colour::operator+=(Colour other)
{

	this->r+=other.getRed();
	this->g+=other.getGreen();
	this->b+=other.getBlue();
	return *this;

}

Colour& Colour::operator-=(Colour other)
{

	this->r-=other.getRed();
	this->g-=other.getGreen();
	this->b-=other.getBlue();
	return *this;

}

int Colour::getRed(){

	return r;

}

int Colour::getGreen(){

	return g;

}

int Colour::getBlue(){

	return b;

}

int Colour::getRGB(){

	return ((r&0xFF)<<16)+((g&0xFF)<<8)+(b&0xFF);

}

void Colour::normalize(){

	r = r>255?255:r<0?0:r;
	g = g>255?255:g<0?0:g;
	b = b>255?255:b<0?0:b;

}
