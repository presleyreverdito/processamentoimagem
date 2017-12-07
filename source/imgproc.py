from ctypes import *
import atexit


# load the image processing shared object
lib = cdll.LoadLibrary("libimgproc.so")


# assign function result types
lib.imgPixel.restype = py_object


# initialise the library
lib.init_imgproc()

# register the library quit function
atexit.register(lib.quit_imgproc)



def timeWait(msec):
	lib.timeWait(msec)


class Camera:
	def __init__(self, width=160, height=120):
		self.c_ptr = lib.camOpen(width, height)

		self.width = lib.camGetWidth(self.c_ptr)
		self.height = lib.camGetHeight(self.c_ptr)

	def grabImage(self):
		ptr = lib.camGrabImage(self.c_ptr)
		return Image(0, 0, ptr)

	def __del__(self):
		lib.camClose(self.c_ptr)


class Viewer:
	def __init__(self, width=160, height=120, title="Image Processing"):
		self.c_ptr = lib.viewOpen(width, height, title)
		
		self.width = width
		self.height = height

	def displayImage(self, img):
		lib.viewDisplayImage(self.c_ptr, img.c_ptr)

	def __del__(self):
		lib.viewClose(self.c_ptr)


class Image:
	def __init__(self, width=160, height=120, c_ptr=0):
		if c_ptr == 0:
			if isinstance(width, int):
				self.c_ptr = lib.imgNew(width, height)
				self.width = width
				self.height = height
			else:
				self.c_ptr = lib.imgFromBitmap(width)
				self.width = lib.imgGetWidth(self.c_ptr)
				self.height = lib.imgGetHeight(self.c_ptr)
		else:
			self.c_ptr = c_ptr
			self.width = lib.imgGetWidth(self.c_ptr)
			self.height = lib.imgGetHeight(self.c_ptr)

	def copy(self):
		newimg = lib.imgCopy(self.c_ptr)
		return Image(0, 0, newimg.c_ptr)

	def __getitem__(self, key):
		x, y = key
		return lib.imgPixel(self.c_ptr, x, y)

	def __setitem__(self, key, value):
		x, y = key
		r, g, b = value
		lib.imgSetPixel(self.c_ptr, x, y, r, g, b)

	def __del__(self):
		lib.imgDestroy(self.c_ptr)


	
