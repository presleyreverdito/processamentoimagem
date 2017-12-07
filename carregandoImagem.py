###############################################
#Algoritmo que simplesmente dedtecta bordas
#
#
#
#Criado em : dezembro/2017
###############################################
from PIL import Image #Importar a biblioteca
import ImageFilter

im = Image.open("/home/presley/Dropbox/ECA/Processamento de Imagens/Processing_w_Python/imagem.jpeg") #Abrir a imagem

im2 = im.filter(ImageFilter.FIND_EDGES) # Aplicando filtro de detecção de borda

im2.save("/home/presley/Dropbox/ECA/Processamento de Imagens/Processing_w_Python/imagemfiltrada.jpeg") #Salvar imagem
