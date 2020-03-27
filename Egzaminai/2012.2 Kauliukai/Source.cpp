#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
const int NMax = 10;


struct Data
{
	string name = "";
	int score = 0;
	int times = 0;
	int index = 0;

};

void readInput(Data A[], int& n)
{
	ifstream fd(inputF);
	int k;
	fd >> n >> k;

	for (int i = 0; i < n; i++)
	{
		fd.ignore(100, '\n');
		char b[NMax + 1] = "";
		fd.read(b, NMax);
		A[i].name = b;
		A[i].index = i;
		for (int z = 0; z < k; z++)
		{
			int temp;
			fd >> temp;
			
			if (temp % 2 == 0)
			{
				A[i].score += temp;
				A[i].times++;
			}
			else
			{
				A[i].score -= temp;
			}
		}
	}
	
	fd.close();
}

void writeOutput(Data A[])
{
	ofstream fr(outputF);
	fr << setw(10) << left << A[0].name << " " << A[0].score;
}

bool compareData(Data a, Data b)
{
	if (a.score != b.score)
	{
		return a.score > b.score;
	}

	if (a.times != b.times)
	{
		return a.times > b.times;
	}

	return a.index < b.index;
}

int main()
{
	Data A[50];
	int n;
	readInput(A, n);
	sort(A, A + n, compareData);
	writeOutput(A);
	return 0;
}