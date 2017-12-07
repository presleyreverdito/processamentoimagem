#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "image.h"

#include <linux/videodev2.h>
#include <Python.h>


// declaration of buffer structure
struct Buffer;


// device container
struct Device {
	// public
	unsigned int img_width;
	unsigned int img_height;
	// private
	char *name;
	int handle;
	struct Buffer * buffers;
	unsigned int n_buffers;
};


// Open the camera capture device
struct Device * devOpen(char * dev_name);
// Set the capture device's format
void devSetFormat(struct Device *dev, unsigned int width, unsigned int height);

// Get the width and height of the capture
unsigned int devGetCaptureWidth(struct Device *dev);
unsigned int devGetCaptureHeight(struct Device *dev);

// Dequeue and enqueue a buffer
unsigned int devDequeueBuffer(struct Device *dev);
void devEnqueueBuffer(struct Device *dev, unsigned int buffer);

// Create an image from a dequeued buffer
struct Image * devImageFromBuffer(struct Device *dev, unsigned int buffer_id);


void devClose(struct Device *dev);


#endif // _CAMERA_H_

