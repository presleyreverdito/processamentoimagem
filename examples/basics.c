#include "imgproc.h"


int main(int argc, char * argv[])
{
	// initialise the library
	init_imgproc();


	// open the webcam, with a capture resolution of width 320 and height 240
	Camera * cam = camOpen(160, 120);

	// create a new viewer of the same resolution with a caption
	Viewer * view = viewOpen(160, 120, "First");

	// capture an image from the webcam	
	Image * img = camGrabImage(cam);

	// display the image in the viewer
	viewDisplayImage(view, img);


	// iterators
	unsigned int x, y;
	for(x = 0; x < img->width; x++){
		for(y = 0; y < img->height; y++){
			// Get a pointer to the current pixel
			char * pixel = imgGetPixel(img, x, y);

			// extract the red, green and blue intensities
			// index 0 is blue and 2 is red
			char red = pixel[2];
			char green = pixel[1];
			char blue = pixel[0];

			// test for predominantly red
			if(red > green && red > blue){
				// set the pixel to the colour 255, 0, 0 (completely red)
				imgSetPixel(img, x, y, 255, 0, 0);
			}
			// green
			else if(green > red && green > blue){
				imgSetPixel(img, x, y, 0, 255, 0);
			}
			// assume blue otherwise
			else {
				imgSetPixel(img, x, y, 0, 0, 255);
			}
		}
	}

	// display the image to view the changes
	viewDisplayImage(view, img);

	// wait for 5 seconds to give us a chance to see the changes
	waitTime(5000);

	// now we will free the memory for the various objects
	imgDestroy(img);
	viewClose(view);
	camClose(cam);

	// finally we unintialise the library
	quit_imgproc();
	return 0;
}
