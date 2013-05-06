#ifndef C_COLOUR
#define C_COLOUR

class Colour{

		int comps[3];
		
	public:
		Colour();
		Colour(int, int, int);
		Colour(int);
		Colour& operator+=(Colour);
		Colour& operator-=(Colour);
		Colour& operator/=(int);
		Colour& operator*=(int);
		Colour operator+(Colour);
		Colour operator-(Colour);
		Colour operator/(int);
		Colour operator*(int);
		int getRed();
		int getGreen();
		int getBlue();
		int getRGB();
		void normalize();
};

#endif
