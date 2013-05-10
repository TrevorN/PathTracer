#include "Colour.hpp"
#include <cmath>

Colour::Colour()
{
	comps[0] = 0;
	comps[1] = 0;
	comps[2] = 0;
}

Colour::Colour(int red, int green, int blue)
{
	comps[0] = red;
	comps[1] = green;
	comps[2] = blue;
}

Colour::Colour(int rgb)
{
	comps[0] = rgb>>16&0xFF;
	comps[1] = rgb>>8&0xFF;
	comps[2] = rgb&0xFF;
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

Colour Colour::operator*(int other)
{
	Colour result = *this;
	result *= other;
	return result;
}

Colour& Colour::operator+=(Colour other)
{

	comps[0] += other.getRed();
	comps[1] += other.getGreen();
	comps[2] += other.getBlue();
	return *this;

}

Colour& Colour::operator-=(Colour other)
{

	comps[0] -= other.getRed();
	comps[1] -= other.getGreen();
	comps[2] -= other.getBlue();
	return *this;

}

Colour& Colour::operator/=(int other)
{

	comps[0] /= other;
	comps[1] /= other;
	comps[2] /= other;
	return *this;

}

Colour& Colour::operator*=(int other)
{
	comps[0] *= other;
	comps[1] *= other;
	comps[2] *= other;
	return *this;
}

int Colour::getRed(){

	return comps[0];

}

int Colour::getGreen(){

	return comps[1];

}

int Colour::getBlue(){

	return comps[2];

}

int Colour::getRGB()
{
	int red = getRed();
	int green = getGreen();
	int blue = getBlue();
	return ((red&0xFF)<<16)+((green&0xFF)<<8)+(blue&0xFF);
}

void Colour::normalize()
{
	int r = getRed();
	int g = getGreen();
	int b = getBlue();
	comps[0] = r>255?255:r<0?0:r;
	comps[1] = g>255?255:g<0?0:g;
	comps[2] = b>255?255:b<0?0:b;
}
