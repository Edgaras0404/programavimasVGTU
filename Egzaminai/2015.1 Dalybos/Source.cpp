#include <iostream>
#include <fstream>

using namespace std;


void calculate(int mokiniai[], int dubeneliai[])
{
	for (int i = 0; i < 10; i++)
	{
		int z = i + 1;
		while (dubeneliai[i] > 0)
		{
			mokiniai[z]++;
			dubeneliai[i]--;
			z++;
		}
	}

}

int main()
{
	int mokiniai[20] = { 0 };
	int dubeneliai[10] = { 10 };

	for (int i = 0; i < 10; i++)
	{
		dubeneliai[i] = 10;
	}

	ifstream fd("U1.txt");
	for (int i = 0; i < 10; i++)
	{
		int temp;
		fd >> temp;
		dubeneliai[i] -= temp;
		mokiniai[i] += temp;
	}

	fd.close();

	calculate(mokiniai, dubeneliai);

	ofstream fr("U1rez.txt");

	for (int i = 0; i < 19; i++)
	{
		fr << mokiniai[i] << " ";
	}
	fr << mokiniai[19];

	fr.close();

	return 0;
}