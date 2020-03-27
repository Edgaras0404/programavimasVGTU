#include <iostream> // DECLARING THE NEEDED ( ? ) LIBRARIES
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <string>

const char CDfv[] = "U2.txt";
const char CDfr[] = "U2rez.txt";
const int CPav = 15;

using namespace std;

struct Grybautojas {
    string vardas;
    int baravyk = 0;
    int raudonik = 0;
    int leps = 0;
    int total = 0;
};

int main() {

    Grybautojas A[101];
    int n;

    ifstream fd(CDfv);
	if (!fd.is_open()) {
		cout << "error";
	}
	fd >> n;

	for (int i = 1; i < n+1; i++)	{
		char b[CPav + 1] = "";
		fd.ignore(80, '\n');
		fd.read(b, CPav);

		A[i].vardas = b;
		int d, baravyk, raudonik, leps;

        fd >> d;
        for (int z = 0; z < d; z++) {
            fd >> baravyk >> raudonik >> leps;
            A[i].baravyk += baravyk;
            A[i].raudonik += raudonik;
            A[i].leps += leps;
        }
        A[i].total += A[i].baravyk + A[i].raudonik + A[i].leps;
        cout << A[i].total << endl;
	}
	fd.close();
    ofstream fr(CDfr);
	if (!fr.is_open()) {
		cout << "error";
	}

	for (int i = 1; i < n+1; i++) {
		fr  << setw(CPav) << left << A[i].vardas << setw(5) << right << A[i].baravyk << setw(5) << A[i].raudonik << setw(5) << A[i].leps << endl;
	}
    int largest = 0;
	for (int i = 1; i < 101; i++)
	{
		if (A[i].total > largest)
		{
			largest = A[i].total;
		}
	}
    cout << largest;
	for (int i = 1; i < 101; i++)
	{
		if (largest == A[i].total)
		{
			fr << setw(CPav) << A[i].vardas << A[i].total << endl;
			i = 102;
		}
	}





	fr.close();


    return 0;
}