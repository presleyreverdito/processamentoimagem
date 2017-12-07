#####################################################
#Algoritmo capaz de rotacionar uma imagem em 45º
#
#Criado em: dezembro/2017
#####################################################
from PIL import Image #Importar a biblioteca
im = Image.open("/home/presley/Dropbox/ECA/Processamento de Imagens/Processing_w_Python/imagem.jpeg") #Abrir a imagem
im2 = im.rotate(180) #Rotacionar a imagem em 45 graus
im2.save("/home/presley/Dropbox/ECA/Processamento de Imagens/Processing_w_Python/imagemrodada.jpeg") #Salvar imagem rotacionada
im2.show()
