#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main(){
    string filename;
    cout << "Enter the file you would like to open: ";
    getline(cin, filename);
    //cout << filename << "\n";
    ifstream fill (filename);
    ofstream name ("name.txt");
    if(!fill){
        cerr << "Error: file does not exist\n";
        return 0;
    }
    else{
        name << filename;
    }
    //sleep(1);
    system("python3 image.py");
    //sleep(1);
    system("g++ -o edge edgedetect.cpp");
    //sleep(1);
    system("./edge");
    //sleep(1);
    system("python3 edge.py");
}
