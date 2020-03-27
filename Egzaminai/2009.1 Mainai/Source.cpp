#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";

struct country {
	int n = 0;
	vector<int> nom;
	vector<int> coins;
	int totalMoney = 0;
};

void getInput(country A[]) {
	ifstream fd(inputF);
	int n;
	int temp = 0;

	//Gilija
	fd >> n;

	A[0].n = n;
	for (int i = 0; i < n; i++)
	{	
		int value;
		fd >> value;
		A[0].nom.push_back(value);
	}
	for (int i = 0; i < n; i++)
	{
		int value;
		fd >> value;
		A[0].coins.push_back(value);
		temp += A[0].coins.at(i) * A[0].nom.at(i);
	}
	//if (temp <= 3000) {
	A[0].totalMoney = temp;
	//}
	//else
	//{
	//	A[0].totalMoney = 3000;
	//}
	sort(A[0].nom.begin(), A[0].nom.end());

	//Eglija
	fd >> n;
	A[1].n = n;
	temp = 0;
	for (int i = 0; i < n; i++)
	{
		int value;
		fd >> value;
		A[1].nom.push_back(value);
	}
	for (int i = 0; i < n; i++)
	{
		int value;
		fd >> value;
		A[1].coins.push_back(value);
		
		temp += A[1].coins.at(i) * A[1].nom.at(i);
	}
	//if (temp <= 3000) {
		A[1].totalMoney = temp;
	//}
	//else 
	//{ 
	//	A[1].totalMoney = 3000; 
	//}

	sort(A[1].nom.begin(), A[1].nom.end());
}


int main() {

	country A[2];
	getInput(A);
	double temp0 = A[1].totalMoney;
	double temp1 = A[0].totalMoney;
	ofstream fr(outputF);

	int coins1 = 0;
	for (int i = A[1].n - 1; i >= 0 ; i--)
	{

		fr << A[1].nom.at(i) << " ";
		if (A[1].nom.at(i) != 0) {
			fr << trunc(temp1 / A[1].nom.at(i)) << endl;
			coins1 += trunc(temp1 / A[1].nom.at(i));
			temp1 = temp1 - ( trunc(temp1 / A[1].nom.at(i)) * A[1].nom.at(i) );
		}
	}
	fr << coins1 << endl;

	coins1 = 0;
	for (int i = A[0].n - 1; i >= 0; i--)
	{

		fr << A[0].nom.at(i) << " ";
		if (A[0].nom.at(i) != 0) {
			fr << trunc(temp0 / A[0].nom.at(i)) << endl;
			coins1 += trunc(temp0 / A[0].nom.at(i));
			cout << temp0 << " " << A[0].nom.at(i) << endl;
			temp0 = temp0 - (trunc(temp0 / A[0].nom.at(i)) * A[0].nom.at(i));
		}
	}
	fr << coins1 << endl;

	return 0;
}