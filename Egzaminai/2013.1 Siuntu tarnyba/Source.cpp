#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";
const int NMax = 10;

struct imones
{
	string name = "";
	int x = 0;
	int y = 0;
	int distanceTo = 0;
};

void readInput(imones A[], int& n, int& m)
{
	ifstream fd(inputF);
	fd >> n >> m;

	for (int i = 0; i < n; i++)
	{
		fd.ignore(100, '\n');

		char b[NMax + 1] = "";
		fd.read(b, NMax);
		A[i].name = b;

		fd >> A[i].x >> A[i].y;
	}

	fd.close();
}

void writeOutput(imones A[], int packagesDelivered, int distanceDriven)
{
	ofstream fr(outputF);
	fr << packagesDelivered << " " << distanceDriven << " " << A[packagesDelivered - 1].name;
}

int distanceCalc(int x, int y)
{
	return abs(x) + abs(y);
}

int main()
{
	imones A[100];
	int n, m;
	int packagesDelivered = 0;
	int distanceDriven = 0;

	readInput(A, n, m);

	for (int i = 0; i < n; i++)
	{
		int temp = distanceCalc(A[i].x, A[i].y) * 2;
		if (distanceDriven + temp <= m)
		{
			distanceDriven += temp;
			packagesDelivered++;
		}
		else
		{
			break;
		}
	}

	writeOutput(A, packagesDelivered, distanceDriven);

	return 0;
}