#include <iostream> // DECLARING THE NEEDED ( ? ) LIBRARIES
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std; // USING THE STANDART NAMESPACE

int main(){
    ifstream fd; // INPUT FILE STREAM OBJECT NAMED fd
    fd.open("Duom2.txt"); // INPUT FILE NAME
    int n, v, h, m; // DECLARING n, SPEED, HOURS, MINUTES

    fd >> n >> v >> h >> m; // READING EVERYTHING FROM FILE OBJECT (fd)
    vector<double> s; // CREATING A DOUBLE VECTOR TO STORE ALL DISTANCE DATA
    vector<string> miestas; // CREATING A STRING VECTOR TO STORE CITY NAMES
    for ( int i = 0; i < n; i++ ) { // LOOP TO READ ALL THE DATA, LOOPS FOR TIMES n
        string tempS; // TEMPORARY STRING
        double tempN; // TEMPORARY DOUBLE
        fd >> tempS; // READING A STRING INTO THE TEMPORARY STRING VARIABLE
        fd >> tempN; // READING A DOUBLE INTO THE TEMPORARY DOUBLE VARIABLE
        miestas.push_back(tempS); // PUSHING THE TEMPORARY STRING INTO THE STRING VECTOR CONTAINING CITY NAMES
        s.push_back(tempN); // PUSHING THE TEMPORARY DOUBLE INTO THE STRING VECTOR CONTAINING DISTANCES BETWEEN CITIES
    }
    fd.close(); // CLOSING THE FILE YOU READ FROM TO PREVENT CRASHES ( ? USELESS ERRORPROOFING, SHOULD BE IMPLEMENTED WITH MORE ERRORPROOFING )

    int laikas = h * 60 + m; // COUNTING THE TIME IN MINUTES
    ofstream fr; // OUTPUT FILE STREAM OBJECT NAMED fr
    fr.open("Rez2.txt"); // OUTPUT FILE NAME
    for ( int i = 0; i < n; i++ ) { // LOOPING FOR n TIMES TO CALCULATE DISTANCES BETWEEN CITIES AND PRINT THEM 

        double temp = s.at(i) / v; // CALCULATING TIME TO STOP
        laikas = laikas + temp; // CALCULATING TIME ON STOP
        int valandos = laikas / 60; // CALCULATING HOURS FROM MINUTES
        int minutes = laikas % 60; // LEAVING THE REMAINDER INTO MINUTES
        cout << miestas.at(i) << "  " << valandos << " val." << minutes << " min." << endl;
        fr << miestas.at(i) << "  " << valandos << " val." << minutes << " min." << endl; // PRINTING THE CITY NAME, HOURS AND MINUTES
    }
    fr.close(); // CLOSING THE FILE YOU WRITE TO TO PREVENT ERRORS ( ? USELESS ERRORPROOFING, SHOULD BE IMPLEMENTED WITH MORE ERRORPROOFING )

    return 0; // END OF FILE BITCHES
}