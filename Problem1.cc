#include <iostream>
#include <iomanip>
#include <cmath>
int main() {

	std::cout << std::fixed << std::setprecision(2);
	float x1,y1,x2,y2;
	std::cout << ("enter two points x1,y1 and x2,y2 in 2D space\n");
	std::cin >> x1 >> y1 >> x2 >> y2;


	float Y = y2 - y1;
	float X = x2 - x1;


	if (std::abs(X) < 0.0000001 && std::abs(Y) < 0.0000001) {

		std::cout << "the slope is 0/0 and is undefined" << std::endl;
	}
	else if (std::abs(X) < 0.0000001)

		std::cout << "slope is vertical at x = " << x1 << std::endl;

	else if (std::abs(Y) < 0.0000001)
		std::cout << "slope is horizontal at y = " << y1 << std::endl;

	else {

		float slope = Y/X;

		// y = mx + b // b = y - mx //
		
		float b = y1 - (slope * x1);

		float invSlope = -1./slope;
		float invb = y1 - (invSlope * x1);

		char sign = '+';
		char invSign = '+';
		if (b < 0) {sign = '-'; b = std::abs(b);}
		if (invb < 0) {invSign = '-'; invb = std::abs(invb);}

		std::cout << "The equation for your line is y = " << slope << "x " << sign << " " << b << std::endl;

		std::cout << "The equation for the perpendicular line is y = " << invSlope << "x " << invSign << " " << invb << std::endl;



	}

	return 0;



}
