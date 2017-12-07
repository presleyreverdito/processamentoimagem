typedef struct {
	unsigned int image_width;
	unsigned int image_height;
} Camera;


typedef struct {
} Image;	



Camera * camOpen(unsigned int width, unsigned int height);
Image * camGrabImage(Camera * cam);
void camClose(Camera * cam);


Image * imgNew();
Image * imgFromFile(char * filename);
Image * imgCopy(Image * img);

void imgDrawLine(Image * img, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);
void imgSetPixel(Image * img, char r, char g, char b);
char * imgGetPixel(Image * img, unsigned int x, unsigned int y);

void imgDestroy(Image * img);


Viewer * viewOpen(char * title, unsigned int width, unsigned int height);
void viewDisplayImage(Viewer * view, Image * img);
void viewClose(Viewer * view);

void waitTime(size_t milliseconds);
