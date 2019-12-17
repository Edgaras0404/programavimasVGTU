#include <iostream> // DECLARING THE NEEDED ( ? ) LIBRARIES
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std; // USING THE STANDART NAMESPACE

int main(){
    ifstream fd; 
    fd.open("Duom2.txt"); 
    int n, v, h, m; 

    fd >> n >> v >> h >> m; 
    vector<double> s; 
    vector<string> miestas; 
    for ( int i = 0; i < n; i++ ) { 
        string tempS; 
        double tempN; 
        fd >> tempS; 
        fd >> tempN; 
        miestas.push_back(tempS); 
        s.push_back(tempN); 
    }
    fd.close(); 

    int laikas = h * 60 + m; 
    ofstream fr; 
    fr.open("Rez2.txt"); 
    for ( int i = 0; i < n; i++ ) { 

        int temp = trunc( s.at(i) / v * 60 ); 
        laikas = laikas + temp; 
        int valandos = laikas / 60; 
        int minutes = laikas % 60; 
        fr << miestas.at(i) << "\t\t" << valandos << "val. " << minutes << " min." << endl; 
    }
    fr.close(); 

    return 0; 
}