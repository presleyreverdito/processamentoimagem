###############################################
#Algoritmo que plota o hitograma de uma imagem
#
#
#
#Criado em :dezembro 2017
###############################################

import cv2
import numpy as np
from matplotlib import pyplot as plt
img = cv2.imread('imagem.jpeg',0)
plt.hist(img.ravel(),256,[0,256]); plt.show()
