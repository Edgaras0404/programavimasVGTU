#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";

void input(int routes[], int leftBus[], bool bus[], int n) {
	ifstream fd(inputF);
	if (!fd.is_open()) {
		cout << "Input file could not be accessed" << endl;
	}
	fd >> n;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		int temp2 = 0;
		fd >> temp >> temp2;
		if (temp2 > 0) {
			routes[temp - 1] += temp2;
		}
		else {
			leftBus[temp - 1] += temp2;
		}
		bus[temp - 1] = 1;
	}

	fd.close();

}
void maxPassengers(ofstream& fr, int routes[]) {
	int maxVal = 0;
	for (int i = 0; i < 100; i++) {
		if (routes[i] > maxVal) { maxVal = routes[i]; }
	}
	for (int i = 0; i < 100; i++) {
		if (maxVal == routes[i]) {
			fr << setw(6) << right << i + 1 << endl;
			break;
		}
	}

}

void busOrder(bool bus[], ofstream& fr) {
	for (int i = 0; i < 100; i++) {
		if (bus[i] != 0) {
			fr << setw(6) << right << i + 1;
		}
	}
	fr << endl;
}

int main() {
	int routes[100];
	int leftBus[100];
	bool bus[100];
	for (int i = 0; i < 100; i++) {
		routes[i] = 0;
		leftBus[i] = 0;
		bus[i] = 0;
	}
	int n = 0;

	input(routes, leftBus, bus, n);
	ofstream fr(outputF);
	if (!fr.is_open()) {
		cout << "Output file could not be accessed" << endl;
	}
	busOrder(bus, fr);
	for (int i = 0; i < 100; i++) {
		if (routes[i]) {
			fr << setw(6) << right << routes[i];
		}
	} 
	fr << endl;
	for (int i = 0; i < 100; i++) {
		if (leftBus[i] < 1 && bus[i]) {
			fr << setw(6) << right << leftBus[i];
		}
	} fr << endl;
	maxPassengers(fr, routes);
	fr.close();

	return 0;
}