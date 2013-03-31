#ifndef C_COLOUR
#define C_COLOUR

class Colour{

		int r;
		int g;
		int b;
		
	public:
		Colour();
		Colour(int, int, int);
		Colour(int);
		Colour& operator+=(Colour);
		Colour& operator-=(Colour);
		Colour operator+(Colour);
		Colour operator-(Colour);
		int getRed();
		int getGreen();
		int getBlue();
		int getRGB();
		void normalize();
};

#endif
