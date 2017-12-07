import imgproc
from imgproc import *


# open a webcam to take pictures
camera = Camera(320, 240)

# Open a viewer window to display images
viewer = Viewer(320, 240, "The first step")

# take a picture from the camera
img = camera.grabImage()

# display the image in the viewer
viewer.displayImage(img)


# iterate over each pixel in the image
for x in range(0, img.width):
	for y in range(0, img.height):
		# Get the value at the xth column and yth row, place the intensities into variables
		red, green, blue = img[x, y]

		# test to find which colour is dominant
		if red > green and red > blue:
			# Red is dominant, so set the pixel to completely red
			img[x, y] = 255, 0, 0
		elif green > red and green > blue:
			img[x, y] = 0, 255, 0
		else:
			# if red or green isn't dominant, blue must be
			img[x, y] = 0, 0, 255


# display the image again
viewer.displayImage(img)

# delay for 5000 milliseconds to give us time to see the changes, then exit
waitTime(5000)


# end of the script
