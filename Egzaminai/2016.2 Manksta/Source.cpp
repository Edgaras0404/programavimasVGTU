#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct pratimai {
	string name = "";
	int amount = 0;
};

const int NMax = 20;

bool rikiuoti(pratimai a, pratimai b) {
	return a.amount > b.amount;
}

int main() {
	ifstream fd("U2.txt");
	if (!fd.is_open()) 
	{
		cout << "error opening input file" << endl;
	}
	int n;
	pratimai A[100];
	fd >> n;
	int pratimuKiekis = -1;
	for (int i = 0; i < n; i++)
	{
		fd.ignore(100, '\n');
		char b[NMax + 1] = "";
		fd.read(b, NMax);
		int temp;
		fd >> temp;
		bool exists = false;
		int pratimas = 0;
		for (int z = 0; z < 100; z++)
		{
			if (b == A[z].name) 
			{
				exists = true;
				pratimas = z;
				break;
			}
			
		}
		if (exists) 
		{
			A[pratimas].amount += temp;

		}
		else 
		{
			pratimuKiekis++;
			A[pratimuKiekis].name = b;
			A[pratimuKiekis].amount += temp;
			
		}
		
	}
	fd.close();
	pratimuKiekis++;

	sort(A, A + pratimuKiekis, rikiuoti);

	ofstream fr("U2rez.txt");
	if (!fr.is_open())
	{
		cout << "error opening output file" << endl;
	}
	for (int i = 0; i < pratimuKiekis; i++)
	{
		fr << A[i].name << " " << A[i].amount << endl;
	}

	return 0;
}