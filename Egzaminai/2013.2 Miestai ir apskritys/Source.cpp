#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>


using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";
int apskriciuSk = 0;


struct Miestas
{
	string miestas = "";
	string apskritis = "";
	int populiacija = 0;

};

struct Apskritis
{
	string name = "";
	int smallestPopulation = 0;
	int totalPopulation = 0;
};

void readData(Miestas miestai[], int & n)
{
	ifstream fd(inputF);
	fd >> n;
	for (int i = 0; i < n; i++)
	{
		fd.ignore(100, '\n');
		char b[21] = "";
		fd.read(b, 20);
		miestai[i].miestas = b;
		char c[14] = "";
		fd.read(c, 13);
		miestai[i].apskritis = c;
		fd >> miestai[i].populiacija;
	}
	fd.close();
}

void writeData(Apskritis apskritys[], int n)
{
	ofstream fr(outputF);
	fr << n << endl;
	for (int i = 0; i < n; i++)
	{
		fr << setw(13) << apskritys[i].name << apskritys[i].smallestPopulation << " " << apskritys[i].totalPopulation << endl;
	}
}

void calculate(Apskritis apskritys[], Miestas miestai[], int miestuSk)
{
	for (int i = 0; i < miestuSk; i++)
	{
		bool apskritisEgzistuoja = false;
		for (int z = 0; z < apskriciuSk; z++)
		{
			if (miestai[i].apskritis == apskritys[z].name)
			{
				apskritys[z].totalPopulation += miestai[i].populiacija;
				apskritys[z].smallestPopulation = miestai[i].populiacija;
				apskritisEgzistuoja = true;
			}
			
		}
		if (!apskritisEgzistuoja)
		{
			apskritys[apskriciuSk].name = miestai[i].apskritis;
			apskritys[apskriciuSk].totalPopulation += miestai[i].populiacija;
			apskritys[apskriciuSk].smallestPopulation = miestai[i].populiacija;
			apskriciuSk++;
		}

	}
}

bool sortByPopulation(Miestas a, Miestas b)
{
	return a.populiacija > b.populiacija;
}

bool sortByAlphabet(Apskritis a, Apskritis b)
{
	if (a.smallestPopulation != b.smallestPopulation)
	{
		return a.smallestPopulation < b.smallestPopulation;
	}
	return a.name < b.name;
}


int main()
{
	Apskritis apskritys[10];
	Miestas miestai[103];
	int miestuSk = 0;
	readData(miestai, miestuSk);
	sort(miestai, miestai + miestuSk, sortByPopulation);
	calculate(apskritys, miestai, miestuSk);
	
	sort(apskritys, apskritys + apskriciuSk, sortByAlphabet);

	writeData(apskritys, apskriciuSk);

	return 0;
}