#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
const int stopL = 20;

struct busStop {
	string name = "";
	vector<int> stops;
};

void getInput(int& n, busStop A[]) {
	ifstream fd(inputF);
	if (!fd.is_open()) {
		cout << "error";
	}

	fd >> n;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++) {
		char b[stopL + 1] = "";
		fd.read(b, stopL);
		A[i].name = b;
		int temp;
		fd >> temp;
		for (int n = 0; n < temp; n++) {
			int temp2;
			fd >> temp2;
			A[i].stops.push_back(temp2);
		}
		fd.ignore(80, '\n');
		sort(A[i].stops.begin(), A[i].stops.end());
	}

	fd.close();
}

int longestRoute(busStop A[], int n) {

	int bus[1001];
	int mostStops = 0;
	for (int i = 0; i <= 1000; i++) 
	{
		bus[i] = 0;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int z = 0; z < A[i].stops.size(); z++)
		{
			int currCheck = A[i].stops.at(z);
			bus[currCheck] += 1;
		}
	}

	for (int i = 0; i <= 1000; i++)
	{
		if (bus[i] > mostStops) {
			mostStops = bus[i];
		}
	}
	for (int i = 1; i <= 1000; i++)
	{
		if (bus[i] == mostStops) {
			return i;
		}
	}

}

void getOutput(busStop A[], int longestR, int n) {
	
	ofstream fr(outputF);
	if (!fr.is_open()) {
		cout << "error";
	}

	fr << longestR;
	for (int i = 0; i < n; i++)
	{
		for (int z = 0; z < A[i].stops.size(); z++)
		{
			if (A[i].stops.at(z) == longestR)
			{
				fr << endl;
				fr << A[i].name;
			}
		}
	}
	fr.close();
}

int main() {
	int n = 0;
	busStop A[101];
	getInput(n, A);
	getOutput(A, longestRoute(A, n), n);

	return 0;
}