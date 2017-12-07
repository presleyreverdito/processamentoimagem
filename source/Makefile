all: camera.o image.o viewer.o util.o
	gcc -shared -Wall -g -ggdb -O2 -Wl,-soname,libimgproc.so,-z,defs -o libimgproc.so camera.o image.o viewer.o util.o -lpython2.7 -lSDLmain -lSDL
	chmod 755 imgproc.py
	cp imgproc.py /usr/local/lib/python2.7/dist-packages
	cp libimgproc.so /usr/lib/
	cp imgproc.h /usr/include/

%.o: %.c imgproc.h
	gcc -std=c99 -Wall -fPIC -g -ggdb -O2 -c -o $@ $< -I/usr/include/python2.7/
