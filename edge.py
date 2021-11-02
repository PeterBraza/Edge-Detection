import PIL
from PIL import Image, ImageOps
import numpy as np
from numpy import asarray
tfile = open("edge.txt", "r")
rip = tfile.read()
tlist = rip.split(" ")
#print(tlist)
print(len(tlist))
del tlist[len(tlist)-1]
#dimensions would go here
img = PIL.Image.new("L", (254, 254))
nimg = PIL.Image.new("L", (254, 254))
for i in range((len(tlist)-1), 0, -1):
    tlist[i] = int(tlist[i])

nimg.save('edgy.png')
nimg.putdata(tlist)
#tlist.reverse()
img.putdata(tlist)
img.show()
nimg.save
