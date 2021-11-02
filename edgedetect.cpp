#include "functions.h"
/*the libraries in functions.h are:
#include <iostream>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <sstream>*/
int main(){
    int matread;
    fstream outxt ("edge.txt", ios_base::out);
    fstream outdim ("dim2.txt", ios_base::out);
    ifstream mat ("matrix.txt", ios_base::in);
    int number;
    ifstream dim ("dimensions.txt", ios_base::in);
    string dimread;
    //getline(dim, dimread, (char) dim.eof());
    int dimarr[2];
    string read;
    int z = 0;
    while(dim >> number){
        dimarr[z] = number;
        z++;
    }
    //variable that will be read from the matrix txt file and then be put into array
    cout << dimarr[0] << " " << dimarr[1] << "\n";
    int x = dimarr[0];
    int y = dimarr[1];
    int matrarr[x*y];
    int ct = 0;
    while(mat >> matread){
        matrarr[ct] = matread;
        ct++;
    }
    int twodarr[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            twodarr[i][j] = matrarr[(i+1)*(j+1)-1];
        }
    }
    //the edge detection matrix
    int kernel[] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
    //int *outarr;
    int outarr[((x-2)*(y-2))];
    //declares the sum for the dot product of each vector
    int sum = 0;
    int size = sizeof(outarr)/4;
    cout << size << "\n";
    //declaring new 3x3 matrix that the kernel will be multiplied with, and find a dot product
    int kernalarr[9];
    int c = 0;
    int i = 0;
    //tells the loop where to stop the convolution
    int minus = size - (3*x);
    int fminus = 25 - 15;
    while(c < size){
        if((((i+2)%x) == 0)){
            //cout << i << " ";
            i+=2;
        }
        
        //sets all the kernalarr values.
     kernalarr[0] = matrarr[i];
        kernalarr[1] = matrarr[i+1];
        kernalarr[2] = matrarr[i+2];
        kernalarr[3] = matrarr[i + x];
        kernalarr[4] = matrarr[i + x + 1];
        kernalarr[5] = matrarr[i + x + 2];
        kernalarr[6] = matrarr[i + (2 * x)];
        kernalarr[7] = matrarr[i + (2 * x) + 1];
        kernalarr[8] = matrarr[i + (2 * x) + 2];
        sum = dotproduct(9, kernalarr, kernel);
        outarr[c] = sum;
        i++;
        c++;
        
    }
    for(int i = 0; i < 9; i++){
        outarr[i] = (relu(outarr[i]));
        //cout << outarr[i] << " ";
    }
    for(int i = 0; i < size; i++){
       outxt << outarr[i] << " ";
    }
  //  cout << x-2 << " " << y-2 << "\n";
    cout << "\n";
    system("open 256woman.jpeg");
    cout << dotproduct(9, kernel, kernel) << "\n";
}
