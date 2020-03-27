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

using namespace std;

const int CPav = 15; 
const int CMax = 100;
const char CDfv[] = "Duom2.txt";
const char CDfr[] = "Rez2.txt";

struct Miestas {
	string pav = "";
	double distanceTo = 0;
	int val = 0;
	int minut = 0;
};

void Skaityti(Miestas A[], int & n, int & v, int & h, int & m) {
	ifstream fd(CDfv);
	if (!fd.is_open()) {
		cout << "error";
	}

	fd >> n >> v >> h >> m;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++)	{
		char b[CPav + 1] = "";
		fd.read(b, CPav);
		A[i].pav = b;
		string temp;
		getline(fd,temp);
		stringstream ss(temp);
		ss >> A[i].distanceTo;
	}
	fd.close();
}

void Spausdinti(Miestas A[], int n) {
	ofstream fr(CDfr);
	if (!fr.is_open()) {
		cout << "error";
	}

	for (int i = 0; i < n; i++) {
		fr  << setw(CPav) << left << A[i].pav << right << A[i].val << " val. " << A[i].minut << " min." << endl;
	}
	fr.close();
}

void Skaiciuoti(Miestas A[], int n, int v, int h, int m) {

	double s;
	double t = h * 60 + m;;
	s = A[0].distanceTo;	
	t += s / v * 60;
	A[0].val = t / 60;
	int minutes = trunc(t);
	A[0].minut = minutes % 60;
	cout << "t0" <<"= " << t << endl;
	for (int i = 1; i < n; i++) {
		s = A[i].distanceTo;
		t += s / v * 60;
		A[i].val = t / 60;
		minutes = trunc(t);
		A[i].minut = minutes % 60;
		cout << "t" << i << "= " << t << endl;
	}
	
}

int main() {
	
	int n, v, h, m;
	Miestas A[CMax];
	Skaityti(A, n, v, h, m);
	Skaiciuoti(A, n, v, h, m);
	Spausdinti(A, n);

	return 0;
}