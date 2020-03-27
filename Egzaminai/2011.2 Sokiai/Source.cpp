#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
const int teisejuMax = 10;
const int sokejuMax = 100;
const char NMax = 20;

struct sokejai
{
	string name = "";
	int r1[teisejuMax] = { 0 };
	int r2[teisejuMax] = { 0 };
	int total1 = 0;
	int total2 = 0;
	int total = 0;
};

void getInput(sokejai A[], int & n, int & k)
{
	ifstream fd(inputF);
	if (!fd.is_open())
	{
		cout << "Error opening file: " << inputF << endl;
	}
	else
	{
		fd >> n >> k;
		for (int i = 0; i < n; i++)
		{
			fd.ignore(100, '\n');
			char b[NMax + 1] = "";
			fd.read(b, NMax);
			A[i].name = b;

			for (int z = 0; z < k; z++)
			{
				fd >> A[i].r1[z];
			}

			for (int z = 0; z < k; z++)
			{
				fd >> A[i].r2[z];
			}
		}
	}
}

int calcTotal(int rating[], int k)
{
	int value = 0;
	sort(rating, rating + k);
	for (int i = 1; i < k - 1; i++)
	{
		value += rating[i];
	}
	return value;
}

bool scoreSort(sokejai A, sokejai B)
{
	return A.total > B.total;
}

void setOutput(sokejai A[], int n)
{
	ofstream fr(outputF);
	if (!fr.is_open())
	{
		cout << "Error opening file: " << outputF << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fr << setw(NMax) << left << A[i].name << " " << A[i].total << endl;
		}
		fr.close();
	}
}

int main()
{
	sokejai A[sokejuMax];
	int n, k;
	getInput(A, n, k);
	for (int i = 0; i < n; i++)
	{
		A[i].total1 = calcTotal(A[i].r1, k);
		A[i].total2 = calcTotal(A[i].r2, k);
		A[i].total = A[i].total1 + A[i].total2;
	}
	sort(A, A + n, scoreSort);
	setOutput(A, n);
	return 0;
}