#include <iostream>
#include <fstream>

using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";

int readData() {
	ifstream fd(inputF);
	int n;
	int max = 0;
	fd >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		fd >> temp;
		if (temp > max) {
			max = temp;
		}
	}
	fd.close();
	return max;
}

int other(int maxval) {

	int cnt = 0;

	ifstream fd(inputF);
	int n;
	fd >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		fd >> temp;
		if (temp * 2 <= maxval)
		{
			cnt++;
		}
	}


	return cnt;
}

int main() {

	int maxWeight = readData();
	ofstream fr(outputF);
	fr << maxWeight << " " << other(maxWeight);




	return 0;
}