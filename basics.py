##################################################################
#Algoritmo capaz de converter as cores de uma imagem monocromática
#depois binarizando-a a partir de um limiar e por fim detectando
#suas bordas.
#Esse é um exemplo básico para o processamento de imagem.
#
#Criado em : dezembro/2017
########################## basics ############################

import cv2
from PIL import Image,ImageFilter,ImageEnhance
import numpy as np
from matplotlib import pyplot as plt


#scriptDir = HYP_Utils.GetDemoDir()

#PIL_Version = Image.VERSION


im = Image.open("imagem3.jpeg")

mono = im.convert('L')
threshold = 50
binary = mono.point(lambda p: p > threshold and 255)
#bw = im.convert('1', dither=Image.NONE)
Edge = binary.filter(ImageFilter.FIND_EDGES)
Edge.show()
