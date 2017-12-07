###########################################
#Algoritmo capaz de tirar uma foto da webcam 
#e salva-la em um diretório
#
#Criado em dezembro/2017
###########################################
import pygame, sys
import pygame.camera
import time
import cv2
from PIL import Image,ImageFilter,ImageEnhance

WEBCAM_DIR = "/home/presley/Dropbox/ECA/Processamento de Imagens/Processing_w_Python"

pygame.init()
pygame.camera.init()
cam = pygame.camera.Camera("/dev/video0", (640,480))

cam.start()
image = cam.get_image()
cam.stop

timestamp = time.strftime("%d-%m-%Y_%H-%M-%S", time.localtime())
filename = "%s/%s.jpg" % (WEBCAM_DIR, timestamp)

# salvando a imagem
pygame.image.save(image, filename)

print "Salvo"
