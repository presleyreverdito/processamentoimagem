#include "imgproc.h"

#include <math.h>


int main(int argc, char * argv[])
{
	// initialise the library
	init_imgproc();


	// open the webcam, with a capture resolution of width 320 and height 240
	Camera * cam = camOpen(320, 240);

	// create a new viewer of the same resolution with a caption
	Viewer * view = viewOpen(320, 240, "Colour Key");


	while(1){
		// constant variables used in the algorithm
		unsigned int ref_red = 255;
		unsigned int ref_green = 80;
		unsigned int ref_blue = 80;
		unsigned int threshold = 96;

		// calculate the squared threshold to simplify calculations
		unsigned int threshold_sq = threshold * threshold;

		// capture an image from the webcam	
		Image * img = camGrabImage(cam);


		// iterators
		unsigned int x, y;
		for(x = 0; x < img->width; x++){
			for(y = 0; y < img->height; y++){
				char * pixel = imgGetPixel(img, x, y);
				unsigned int red = pixel[2];
				unsigned int green = pixel[1];
				unsigned int blue = pixel[0];

				// subtract the pixel colour from the reference
				unsigned int d_red = ref_red - red;
				unsigned int d_green = ref_green - green;
				unsigned int d_blue = ref_blue - blue;

				// calculate the squared length of the difference vector
				unsigned int length_sq = d_red * d_red +
										 d_green * d_green + 
										 d_blue * d_blue;

				if(length_sq > threshold_sq){
					imgSetPixel(img, x, y, 0, 0, 0);
				} else {
					imgSetPixel(img, x, y, 255, 255, 255);
				}
			}
		}

		// display the image
		viewDisplayImage(view, img);

		// destroy the image
		imgDestroy(img);
	}

	// finally quit
	viewClose(view);
	camClose(cam);

	// finally we uninitialise the library
	quit_imgproc();
	return 0;
}
