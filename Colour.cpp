#include "Colour.hpp"

Colour::Colour()
{

	this->r = 0;
	this->g = 0;
	this->b = 0;

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

	Colour result = *this;
	result += other;
	return result;

}

Colour Colour::operator-(Colour other)
{

	Colour result = *this;
	result -= other;
	return result;

}

Colour Colour::operator/(int other)
{

	Colour result = *this;
	result /= other;
	return result;

}

Colour& Colour::operator+=(Colour other)
{

	this->r += other.getRed();
	this->g += other.getGreen();
	this->b += other.getBlue();
	return *this;

}

Colour& Colour::operator-=(Colour other)
{

	this->r -= other.getRed();
	this->g -= other.getGreen();
	this->b -= other.getBlue();
	return *this;

}

Colour& Colour::operator/=(int other)
{

	this->r /= other;
	this->g /= other;
	this->b /= other;
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
