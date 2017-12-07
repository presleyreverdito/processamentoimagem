#include "imgproc.h"

#include <math.h>


int main(int argc, char * argv[])
{
	// initialise the library
	init_imgproc();


	// open the webcam, with a capture resolution of width 320 and height 240
	Camera * cam = camOpen(320, 240);

	// create a new viewer of the same resolution with a caption
	Viewer * view = viewOpen(320, 240, "First");


	while(1){

		// capture an image from the webcam	
		Image * img = camGrabImage(cam);

		// Create an empty image
		Image * img_edge = imgNew(320, 240);


		// iterators
		unsigned int x, y;
		for(x = 1; x < img->width - 1; x++){
			for(y = 1; y < img->height - 1; y++){
				// initialise Gx and Gy to 0
				int Gx = 0;
				int Gy = 0;
				unsigned int intensity = 0;
				char * pixel;

				// Left column
				pixel = imgGetPixel(img, x - 1, y - 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += -intensity;
				Gy += -intensity;

				pixel = imgGetPixel(img, x - 1, y);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += -2 * intensity;

				pixel = imgGetPixel(img, x - 1, y + 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += -intensity;
				Gy += +intensity;

				// middle column
				pixel = imgGetPixel(img, x, y - 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gy += -2 * intensity;
			
				pixel = imgGetPixel(img, x, y + 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gy += +2 * intensity;

				// right column
				pixel = imgGetPixel(img, x + 1, y - 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += +intensity;
				Gy += -intensity;

				pixel = imgGetPixel(img, x + 1, y);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += +2 * intensity;
			
				pixel = imgGetPixel(img, x + 1, y + 1);
				intensity = pixel[0] + pixel[1] + pixel[2];
				Gx += +intensity;
				Gy += +intensity;

				// calculate the gradient length
				unsigned int length = (unsigned int)sqrt( (float)(Gx * Gx) + (float)(Gy * Gy) );

				// normalise the length to 0 to 255
				length = length / 17;

				// draw the pixel on the edge image
				imgSetPixel(img_edge, x, y, length, length, length);
			}
		}

		// display the edge image
		viewDisplayImage(view, img_edge);

		// now we will free the memory for the various objects
		imgDestroy(img_edge);
		imgDestroy(img);
	}

	// finally quit
	viewClose(view);
	camClose(cam);

	// finally we uninitialise the library
	quit_imgproc();
	return 0;
}
