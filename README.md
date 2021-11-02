# Edge-Detection
    This project will output an image that will highlight the edges of a certain inputted image. 
    First, the image is converted to grayscale in python, employing the PIL library in Image.py. The dimensions of the image are parsed and outputted to a txt file named dimensions.txt.
The pixel values are put into a list, which are then also put into a text file called matrix.txt. The C++ file then reads and parses the dimensions from the txt file and those are set as
the dimensions for the new array, matrarr. The entirety of matrix.txt is put into matrarr. I made the somewhat arbitrary choice of using the edge detection kernel {-1, -1, -1, -1, 8, -1, -1, -1, -1}.
This is convoluted/passed over the image, and the outputs are saved in another array. The entirety of this array is put into edge.txt. Finally, edge.py reads the pixel values from edge.txt and 
outputs those to the final image, which displays the final image with all edges made obvious.
