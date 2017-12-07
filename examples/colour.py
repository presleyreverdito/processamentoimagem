import imgproc
from imgproc import *

# import maths module for the square root function
import math


# open a webcam to take pictures
camera = Camera(160, 120)

# Open a viewer window to display images
viewer = Viewer(160, 120, "Colour Key")

# take a picture from the camera
img = camera.grabImage()

# display the image in the viewer
viewer.displayImage(img)


# constant variables used in the algorithm
ref_red = 255
ref_green = 0
ref_blue = 0
threshold = 64


# take a picture from the camera
img = camera.grabImage()

# iterate over each pixel in the image
for x in range(0, img.width):
	for y in range(0, img.height):
		red, green, blue = img[x, y]

		# subtract the pixel colour from the reference
		d_red = ref_red - red
		d_green = ref_green - green
		d_blue = ref_blue - blue

		# length of the difference vector
		length = math.sqrt( (d_red * d_red) + (d_green * d_green) + (d_blue * d_blue) )

		if length > threshold:
			img[x, y] = 0, 0, 0
		else:
			img[x, y] = 255, 255, 255


# display the image again
viewer.displayImage(img)

# delay for 5000 milliseconds to give us time to see the changes, then exit
waitTime(5000)


# end of the script
