#include <iostream>
#include <fstream>

using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";

int motPoros = 0;
int vyrPoros = 0;
int motAtl = 0;
int vyrAtl = 0;

void getInput(int pirstines[2][2][100])
{
	ifstream fd(inputF);
	if (!fd.is_open())
	{
		cout << "Error whilst opening the file: " << inputF << endl;
	}
	else
	{
		int n;
		fd >> n;

		for (int i = 0; i < n; i++)
		{
			int type, side, size;
			fd >> type >> side >> size;
			if (type == 3) //vyriskos
			{
				if (side == 1) //kaires rankos
				{
					pirstines[0][0][size]++;
				}
				else if (side == 2) //desines rankos
				{
					pirstines[0][1][size]++;
				}
			}
			else if (type == 4) //moteriskos
			{
				if (side == 1) //kaires rankos
				{
					pirstines[1][0][size]++;
				}
				else if (side == 2) //desines rankos
				{
					pirstines[1][1][size]++;
				}
			}
		}

		fd.close();
	}
}

void calcPairs(int pirstines[2][2][100])
{
	for (int i = 0; i < 100; i++)
	{

		//vyriskos
		
		if (pirstines[0][0][i] > 0 || pirstines[0][1][i] > 0)
		{
			if (pirstines[0][0][i] == pirstines[0][1][i])
			{
				vyrPoros += pirstines[0][0][i]; //jei vienodas kiekis abeju vyrisku pirstiniu pridedame prie vyrPoros ju kieki
			}
			else if (pirstines[0][0][i] > pirstines[0][1][i])
			{
				vyrPoros += pirstines[0][1][i]; //jei vienos puses pirstiniu daugiau, pridedame kitos puses pirstiniu kieki i vyrPoros
				vyrAtl += pirstines[0][0][i] - pirstines[0][1][i]; //atliekamos pirstines yra daugiau esancios puses pirstiniu kiekis - maziau esancios puses pirstiniu kiekis
			}
			else
			{
				vyrPoros += pirstines[0][0][i]; //jei kitos puses pirstiniu daugiau, pridedame kitos puses pirstiniu kieki i vyrPos
				vyrAtl += pirstines[0][1][i] - pirstines[0][0][i]; 
			}
		}

		//moteriskos
		
		if (pirstines[1][0][i] > 0 || pirstines[1][1][i] > 0)
		{
			if (pirstines[1][0][i] == pirstines[1][1][i])
			{
				motPoros += pirstines[1][0][i];
			}
			else if (pirstines[1][0][i] > pirstines[1][1][i])
			{
				motPoros += pirstines[1][1][i];
				motAtl += pirstines[1][0][i] - pirstines[1][1][i];
			}
			else
			{
				motPoros += pirstines[1][0][i];
				motAtl +=pirstines[1][1][i] - pirstines[1][0][i];
			}
		}
	}
}

void setOutput() 
{
	ofstream fr(outputF);
	if (!fr.is_open())
	{
		cout << "Error whilst opening the file: " << outputF << endl;
	} 
	else
	{
		fr << motPoros << endl;
		fr << vyrPoros << endl;
		fr << motAtl << endl;
		fr << vyrAtl << endl;

		fr.close();
	}
}

int main()
{
	int pirstines[2][2][100] = { 0 };
	getInput(pirstines);
	calcPairs(pirstines);
	setOutput();

	return 0;
}