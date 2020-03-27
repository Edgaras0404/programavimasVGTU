#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;


int main(){

    ifstream fd;
    fd.open("Duom1.txt");
    double x;
    fd >> x;
    double y;
    double r = 0;
    for (int i=x; i>0; i--){
        fd >> y;
        double temp = 0;
        for (int n=y; n>0; n--){
            double z;
            fd >> z;
            temp = temp + 1/z;
        }
        r = r + 1/temp;
    }
    fd.close();
    ofstream fr;
    fr.open("Rez1.txt");
    fr << fixed << setprecision(2) << r ;
    fr.close();


    return 0;
}