#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
const int NMax = 20;

struct runner {
	string name = "";
	int time = 0;
};

void printOutput(runner A[], int size) {
	ofstream fr(outputF);

	for (int i = 0; i < size; i++)
	{
		fr << setw(NMax) << left << A[i].name << A[i].time / 60 << " " << A[i].time % 60 << endl;
	}

	fr.close();
}

bool isSlower(runner a, runner b) {
	return a.time < b.time;
}

int test(int a) {
	return a;
}
int main() {
	ifstream fd(inputF);
	int n = 0;
	fd >> n;
	runner A[5000];
	int groupSizes[2500] = { 0 };
	int amount = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		fd >> temp;
		groupSizes[i] = temp;
		for (int z = 0; z < temp; z++)
		{
			int minutes = 0;
			int seconds = 0;
			fd.ignore(1, '\n');
			char b[NMax + 1] = "";
			fd.read(b, NMax);
			A[amount].name = b;
			fd >> minutes >> seconds;
			A[amount].time = minutes * 60 + seconds;
			amount++;
			
		}
	}
	fd.close();

	int temp = 0;
	int temp2 = 0;
	runner leaderboard[2500];


	for (int i = 0; i < 2500; i++)
	{
		sort(A + temp, A + temp + groupSizes[i], isSlower);
		for (int z = temp; z < trunc(temp + trunc(groupSizes[i] / 2)); z++) {
			leaderboard[temp2].name = A[z].name;
			leaderboard[temp2].time = A[z].time;
			temp2++;
		}
		temp += groupSizes[i];
	}

	sort(leaderboard, leaderboard + temp2, isSlower);

	for (int i = 0; i < temp2; i++)
	{
		cout << setw(NMax) << left << leaderboard[i].name << leaderboard[i].time / 60 << " " << leaderboard[i].time % 60 << endl;
	}

	printOutput(leaderboard, temp2);
	return 0;
}