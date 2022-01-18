#include <iostream>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;
//removes all spaces from a string
string spaceremove(string str){
    string nstr;
    for(int i = 0; i < str.length(); i++){
        int count = 0;
        if(str[i] != ' '){
            nstr = nstr + str[i];
            count++;
        }
        else{
            count--;
        }
    }
    return nstr;
}
//converts a string, like "8" to an int type, 8
//finished
int convert(string str){
    stringstream num(str);
    int nt = 0;
    num >> nt;
    return nt;
}
string scon(int a){
    stringstream str(a);
    string s;
    str >> s;
    return s;
}
//takes arguments string, indice 1 and indice 2 and then returns a new string that is between the indices
//finished?
string index(string total, int indone, int indtwo){
    //new string that will be returned, will equal the string between the indices of the main string
    //I can't call it new since that relates to memory in c++
    string newb;
    for(int i = indtwo-1; i >= indone; i--){
        newb = total[i]+newb;
    }
    return newb;
}
//relu, as opposed to sigmoid
//finished
int relu(int a){
    if(a<0){
        return 0;
    }
    else{
        return a;
    }
}
//the derivative of the relu function
//finished
double reludv(double dv){
    if(dv<0){
        return 0;
    }
    else{
        return 1;
    }
}
//layers of neurons
/*struct neuron{
    int signature;//denotes which neuron it is in the layer
    double activation; //the activation, between 0 and 1
    int layernum;
};*/
//connections between neurons
//probably not going to need this
/*struct connection{
    double ingoingneuron;
    double outgoingneuron;
    double weight;
    double bias;
};*/
//space function
//finished
//really just a shorthand for putting spaces between outputs for debugging, it is shorter than repeatedly putting  "cout << "\n\n";"
void s(){
    cout << "\n\n";
}
const double e = 2.718281828;
//logistic function
//finished
double sigmoid(double x){
    double wow = pow(e, -x);
    double bottom = 1 + wow;
    return (1/bottom);
}
//derivative of logistic function at a point
//finished
double sigdx(double x){
    double top = pow(e, -x);
    double bottom = (1 + pow(e, -x));
    double botsqr = bottom * bottom;
    return top/botsqr;
}
//flnum = firstlayernum
//theoretically done, but will have to add more for weights and biases
double* firstlayerneuron(double a, int flnum, double arr[999]){
    double val = sigmoid(a);
    arr[flnum] = val;
    return arr;
}
//under construction
double* secondlayerneuron(){
    return 0;
}
//does scalar multiplication on an array/vector, as in a number multiplied by each number in the array
//finished
double * scalar(int width, int height, double arr[(width*height)], double product){
    static double *yarr = arr;
    for(int i = 0; i < (width*height); i++){
        yarr[i]*=product;
    }
    return yarr;
}
//finished! Crown jewel, most difficult function to make here
int * matrixmultiply(int wone, int hone, int arrone[(hone*wone)], int wtwo, int htwo, int arrtwo[(htwo*wtwo)]){
    //obviously if the height of the first matrix != the width of the second, then the matrix cannot be multiplied (hence, what this if statement is for)
    if(wone != htwo){
        cerr << "Error: invalid multiplication" << "\n";
        return 0;
    }
    //declares an array equal to the size of the array that mutliplying the two matrices will equal
    //pointer "k" will be the array that will be returned
    static int *k;
    //I have to allocate memory for k, but if I don't put "(int*)" it will be void, which will throw an error
    k = (int*)malloc((hone*wtwo)*sizeof(int));
    //calculates dot product for each and every iteration
    int initsum = 0;
    //initialize count to keep track of which indice the array "k" is at
    int count = 0;
    for(int i = 0; i < hone; i++){
        for(int j = 0; j < wtwo; j++){
            //resets dot product value to 0 after each calcuation/iteration
            for(int c = 0; c < htwo; c++){
                initsum += (arrone[(wone*i) + c]*arrtwo[j + (c*wtwo)]);
                //cout << (arrone[(wone*i) + c]) << " " << arrtwo[j + (c*wtwo)] << "\n";
            }
            //cout << count << "\n";
            k[count] = initsum;
            count++;
            initsum=0;
        }
    }
    return k;
    
}
//dotproduct function, can be used to pass a kernel over an image
//the length of each array or vector has to be the same
//finished
int dotproduct(int mag, int arr[mag], int arrtwo[mag]){
    int dot = 0;
    for(int i = 0; i < mag; i++){
        dot+=(arr[i]*arrtwo[i]);
    }
    return dot;
}
//crossproduct function for 3-D vectors
//finished
double* crossproduct(double arr[3], double arrtwo[3]){
    static double *a;
    a = (double*)malloc(3 * (sizeof(double)));
    a[0] = ((arr[1]*arrtwo[2]) - (arr[2]*arrtwo[1]));
    a[1] = ((arr[2]*arrtwo[0])-(arr[0]*arrtwo[2]));
    a[2] = ((arr[0])*arrtwo[1] - (arr[1]*arrtwo[0]));
    return a;
    free(a);
}
//this functioncreates an array of indices of where all the spaces are in the txt file so that another function can know which string is a number that should be added to an array
//finished
int* txtread(){
    ifstream matrix("matrix.txt");
    //read txt file into list
    string list;
    getline(matrix, list, (char) matrix.eof());
    //cout << list.size() << "\n";
    //number of spaces in the txt document
    int spacect, counter = 0;
    for(int i = 0; i < list.size(); i++){
        if(list[i] == ' '){
            spacect++;
        }
       //spacect establishes how large to make the array
    }
    //cout << spacect << "\n";
    //declares "last array" (larr) and then allocates the memory
    static int *larr;
    larr = (int*)malloc(spacect*(sizeof(int)));
    for(int i = 0; i < list.size(); i++){
        if(list[i] == ' '){
            larr[counter] = i;
            counter++;
        }
    }
    return larr;
    free(larr);
    
}
//read/parse the dimensions of the image from the text file and returns it in an int array
int* dimread(){
    ifstream d("dimensions.txt");
    string dimensions;
    getline(d, dimensions, (char) d.eof());
    //gets the value of the indice in which there is a space
    int space;
    for(int c = 0; c < dimensions.size(); c++){
        if(dimensions[c] == ' '){
            //assigns variable space to the indice i
            space = c;
        }
    }
    string x = index(dimensions, 0, space);
    string y = index(dimensions, space, dimensions.size());
    //converts dimension array that holds the dimensions of the png/image
    //cout << x << "\n";
    //cout << y << "\n";
    int darr[2] = {convert(x), convert(y)};
    int *arr= darr;
    return arr;
    
}
class neuralnetwork{
public:
    //first layer number (of neurons)
    int flnum;
    double *flact;
    //first layer activation, array with the number of neurons
    //each layer activation
    double (*connect)[];
    double relu(double a){
        if(a<0){
            return 0;
        }
        else{
            return a;
        }
    }
    double reludv(double dv){
        if(dv<0){
            return 0;
        }
        else{
            return 1;
        }
    }
};
class firstlayerneuron: public neuralnetwork{
public:
    double activation;
    int connectionum;
};
class connection: public neuralnetwork{
public:
    double weight;
    double bias;
    int initlayer;
    int receivinglayer;
    int neuro;
};
class neuron: public connection{
public:
    double activation;
};
