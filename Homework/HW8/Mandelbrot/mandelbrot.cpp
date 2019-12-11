// Luke Underwood
// 12/8/19
// mandelbrot.cpp
// Mandelbrot project
// CS201

#include<string>
#include"Color3.hpp"
#include"Image3.hpp"

int main(int argc, char** argv)
{
	int w = 0;
	int h = 0;
	if (argc == 3)
	{
		w = std::stoi(argv[1]);
		h = std::stoi(argv[2]);

		if (w <= 0)
		{
			std::cout << "Bad width argument. Using default\n";
			w = 175;
		}

		if (h <= 0)
		{
			std::cout << "Bad rows argument. Using default\n";
			h = 100;
		}

	}
	else
	{
		std::cout << "Bad arguments. Use <width>, <height>\n"
			<< "Using defaults\n";
		w = 175;
		h = 100;
	}

	Image3 image(w, h);
	double xscaled = 0;
	double yscaled = 0;
	double xcurrent = 0;
	double ycurrent = 0;
	double rsquare = 0;
	double isquare = 0;
	double zsquare = 0;
	int count = 0;

	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			xscaled = x * 3.5 / w - 2.5;
			yscaled = y * 2.0 / h - 1.0;
			xcurrent = 0;
			ycurrent = 0;
			rsquare = 0;
			isquare = 0;
			zsquare = 0;
			count = 0;
			while (rsquare + isquare <= 4 && count < 512)
			{
				xcurrent = rsquare - isquare + xscaled;
				ycurrent = zsquare - rsquare - isquare + yscaled;
				rsquare = pow(xcurrent, 2);
				isquare = pow(ycurrent, 2);
				zsquare = pow(xcurrent + ycurrent, 2);
				count++;
			}

			if (count < 256)
			{
				Color3 color(255 - count, 255 - count, 255);
				image.setPixel(x, y, color);
			}
			else
			{
				count -= 255;
				Color3 color(0, 0, 255 - count);
				image.setPixel(x, y, color);
			}
		}
	}

	image.savePPM("mandelbrot.PPM");
}