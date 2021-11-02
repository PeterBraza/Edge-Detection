import PIL
from PIL import Image, ImageOps
import numpy as np
from numpy import asarray
png = Image.open('256woman.jpeg')
print(png.size)
#declare string dims that is png.size
dims = str(png.size)
#rmc stands for removed characters, and the replace will essentially remove those characters
#png.size is a tuple that looks like (x, y)
#x and y are numbers
rmc = "(),"
for char in rmc:
    dims = dims.replace(char, "")
#dim for dimensions text file
dim = open ("dimensions.txt", "w")
dim.write(dims)
#converts image to grayscale
new_img = ImageOps.grayscale(png)
new_img.save('grayscale.png')
#reads pixels from the grayscale image
img = Image.open('grayscale.png', 'r')
pixel = list(img.getdata())
print(len(pixel))
txt = open ("matrix.txt", "w")
for number in pixel:
    txt.write(str(number) + " ")
txt.close
