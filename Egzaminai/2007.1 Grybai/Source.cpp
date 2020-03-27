#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";

struct diena {
	int baravyk = 0;
	int raudonik = 0;
	int leps = 0;
	int total = 0;
	bool grybauta = false;
};


int main() {
	ifstream fd(inputF);
	int n;
	fd >> n;
	diena A[32];
	for (int i = 0; i < n; i++) {
		int temp, a, b, c;
		fd >> temp >> a >> b >> c;
		A[temp].grybauta = true;
		A[temp].baravyk += a;
		A[temp].raudonik += b;
		A[temp].leps += c;
	}
	fd.close();

	ofstream fr(outputF);
	for (int i = 0; i <= 31; i++) {
		A[i].total = A[i].baravyk + A[i].raudonik + A[i].leps;
		if (A[i].grybauta && A[i].total != 0) {
			fr << i << " " << A[i].baravyk << " " << A[i].raudonik << " " << A[i].leps << endl;
		}
	}
	
	int largest = 0;
	for (int i = 0; i <= 31; i++)
	{
		if (A[i].total > largest)
		{
			largest = A[i].total;
		}
	}

	for (int i = 0; i <= 31; i++)
	{
		if (largest == A[i].total)
		{
			fr << i << " " << largest << endl;
			i = 32;
		}
	}
	

	return 0;
}

