#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
const int NMax = 15;

struct patiekalas 
{
	string name = "";
	unsigned long kiekis[12] = { 0 };
	unsigned long kaina = 0;
};

int prices[10] = { 0 };

void getInput(patiekalas A[], int& n, int& p) 
{
	ifstream fd(inputF);

	if (!fd.is_open())
	{
		cout << "Error opening the input file " << inputF << endl;
	}

	fd >> n >> p;
	for (int i = 0; i < n; i++)
	{
		int temp;
		fd >> temp;
		prices[i] = temp;
	}

	for (int i = 0; i < p; i++)
	{
		fd.ignore(100, '\n');
		char b[NMax + 1] = "";
		fd.read(b, NMax);
		A[i].name = b;

		for (int z = 0; z < n; z++)
		{
			fd >> A[i].kiekis[z];
		}
	}

	fd.close();

}

void setOutput(patiekalas A[], int p, long totalPrice)
{
	ofstream fr(outputF);
	if (!fr.is_open())
	{
		cout << "Error opening the input file " << outputF <<endl;
	}
	

	for (int i = 0; i < p; i++)
	{
		fr << setw(NMax) << left << A[i].name << " " << A[i].kaina << endl;
	}
	
	fr << totalPrice / 100 << " " << totalPrice % 100 << endl;

	fr.close();
	
}

void calcPrices(patiekalas A[], int n, int p) 
{
	for (int i = 0; i < p; i++)
	{
		for (int z = 0; z < n; z++)
		{
			
			A[i].kaina += (A[i].kiekis[z] * prices[z]);
			cout << A[i].kaina << endl;
		}
	}

}

unsigned long orderPrice(patiekalas A[], int p)
{
	int price = 0;
	for (int i = 0; i < p; i++)
	{
		price += A[i].kaina;
	}
	return price;
}

int main() 
{
	patiekalas A[10];
	int n, p;
	getInput(A, n, p);
	calcPrices(A, n, p);
	long totalPrice = orderPrice(A, p);
	setOutput(A, p, totalPrice);

	return 0;
}