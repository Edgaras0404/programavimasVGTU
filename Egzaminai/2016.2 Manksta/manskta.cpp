#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ifstream fd;
	fd.open("U2.txt");
	int n;
	fd >> n;
	vector<int> domenis;
	vector<string> duomenys;
	auto ak47 = make_pair(duomenys, domenis);
	int dataPl = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		fd >> temp;
		vector<int>::iterator it;
		it = find(ak47.first.begin(), ak47.first.end(), temp);
		if (it != ak47.first.end()) {
			int brr;
			fd >> brr;
			ak47.second.at(i) = ak47.second.at(i) + brr;
		}
		else {
			ak47.first.push_back(temp);
			int brr;
			fd >> brr;
			ak47.second.push_back(brr);
		}

	}
	for (int i = 0; i < ak47.first.size(); i++) {
		cout << ak47.first.at(i) << "   " << ak47.second.at(i) << endl;
	}

	return 0;
}