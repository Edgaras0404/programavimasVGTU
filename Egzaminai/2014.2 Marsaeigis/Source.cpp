#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char inputF[] = "U2.txt";		//ivesties ir isvesties failu pav.
const char outputF[] = "U2rez.txt";


int x = 0; //x koordinate
int y = 0; //y koordinate
int goalX = 0; //tikslo X koordinate
int goalY = 0; //tikslo Y koordinate
int N = 0;


struct Seka //marsaeigio struktura su duomenimis
{
	int seka[30] = { 0 };
	bool pasiektasTikslas = 0;
	int ikiTikslo = 0;
	int elementuN = 0;
};


void readData(Seka A[])
{
	ifstream fd(inputF);
	if (!fd.is_open())
	{
		cout << "Error whilst opening file: " << inputF << endl; //spausdiname error jeigu neatidaromas failas
	}
	else // jei faila pavyko atidaryti
	{
		fd >> x >> y >> goalX >> goalY; //gaunam pradines ir tikslo koordinates.
		fd >> N;

		for (int i = 0; i < N; i++)
		{
			int temp;
			fd >> temp;

			for (int z = 0; z < temp; z++)
			{
				fd >> A[i].seka[z];
				A[i].elementuN++;
			}
		}

		fd.close();
	}
}

void writeData(Seka A[])
{
	
	ofstream fr(outputF);
	if (!fr.is_open())
	{
		cout << "Error whilst opening file: " << outputF << endl; //spausdiname error jeigu neatidaromas failas
	}
	else // jei faila pavyko atidaryti
	{
		for (int i = 0; i < N; i++)
		{
			cout << A[i].pasiektasTikslas << endl;
			if (A[i].pasiektasTikslas)
			{
				fr << setw(20) << left << "pasiektas tikslas";
				for (int z = 0; z < A[i].ikiTikslo; z++)
				{
					fr << A[i].seka[z] << " ";
				}
				fr << A[i].ikiTikslo << endl;
			}
			else
			{
				fr << setw(20) << left << "sekos pabaiga";
				for (int z = 0; z < A[i].elementuN; z++)
				{
					fr << A[i].seka[z] << " ";
				}
				fr << A[i].elementuN << endl;
			}
		}


		fr.close();
	}
}

void calculate(Seka A[])
{
	for (int loop = 0; loop < N; loop++)
	{
		int calcX = x;
		int calcY = y;
		for (int i = 0; i <= A[loop].elementuN; i++)
		{
			if (!A[loop].pasiektasTikslas)
			{
				if (calcX == goalX && calcY == goalY)
				{

					A[loop].pasiektasTikslas = 1;
					A[loop].ikiTikslo = i;
				}
				else
				{
					switch (A[loop].seka[i])
					{
					case 1: calcY++;
						break;
					case 2: calcX++;
						break;
					case 3: calcY--;
						break;
					case 4: calcX--;
						break;
					}
				}
			}
		}
	}
}

int main()
{
	Seka A[10];
	readData(A);	
	calculate(A);
	writeData(A);

	return 0;
}

//EZ