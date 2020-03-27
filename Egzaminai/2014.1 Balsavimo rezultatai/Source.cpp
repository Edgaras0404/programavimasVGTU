#include <iostream>
#include <fstream>

using namespace std;

struct logotipai
{
	int balsai = 0;
	int taskai = 0;
	int direktoriausTaskai = 0;
};


void readData(logotipai A[]) 
{
	ifstream fd("U1.txt");
	int n;
	fd >> n;
	for (int i = 0; i < n; i++)
	{
		int temp[3];
		fd >> temp[0] >> temp[1] >> temp[2];
		A[0].balsai += temp[0];
		A[1].balsai += temp[1];
		A[2].balsai += temp[2];

		if (temp[0] != temp[1] || temp[1] != temp[2] || temp[2] != temp[0])
		{
			if (temp[0] == temp[1] && temp[0] > temp[2])
			{
				A[0].taskai += 2;
				A[1].taskai += 2;
			}
			else if (temp[0] == temp[2] && temp[0] > temp[1])
			{
				A[0].taskai += 2;
				A[2].taskai += 2;
			}
			else if (temp[1] == temp[2] && temp[1] > temp[0])
			{
				A[1].taskai += 2;
				A[2].taskai += 2;
			}
			else
			{
				if (temp[0] > temp[1] && temp[0] > temp[2])
				{
					A[0].taskai += 4;
				}
				else if (temp[1] > temp[0] && temp[1] > temp[2])
				{
					A[1].taskai += 4;
				}
				else if (temp[2] > temp[0] && temp[2] > temp[1])
				{
					A[2].taskai += 4;
				}
			}
		}
	}

	fd >> A[0].direktoriausTaskai >> A[1].direktoriausTaskai >> A[2].direktoriausTaskai;
}

void writeData(logotipai A[], int winner)
{
	ofstream fr("U1rez.txt");
	fr << A[0].balsai << " " << A[1].balsai << " " << A[2].balsai << endl;
	fr << A[0].taskai << " " << A[1].taskai << " " << A[2].taskai << endl;
	fr << winner;
}

void directorsPoints(logotipai A[])
{
	if (A[1].taskai == A[2].taskai && A[1].taskai == A[0].taskai)
	{
		for (int i = 0; i < 3; i++)
		{
			A[i].taskai += A[i].direktoriausTaskai;
		}
	}

	if ((A[0].taskai == A[1].taskai && A[0].taskai > A[2].taskai) || (A[0].taskai == A[2].taskai && A[0].taskai > A[1].taskai) || (A[1].taskai == A[2].taskai && A[1].taskai > A[0].taskai))
	{
		if (A[0].taskai == A[1].taskai && A[0].taskai > A[2].taskai)
		{
			A[0].taskai += A[0].direktoriausTaskai;
			A[1].taskai += A[1].direktoriausTaskai;
		} 
		else if (A[0].taskai == A[2].taskai && A[0].taskai > A[1].taskai)
		{
			A[0].taskai += A[0].direktoriausTaskai;
			A[2].taskai += A[2].direktoriausTaskai;
		}
		else if (A[1].taskai == A[2].taskai && A[1].taskai > A[0].taskai)
		{
			A[1].taskai += A[1].direktoriausTaskai;
			A[1].taskai += A[2].direktoriausTaskai;
		}

	}
}

int findBestLogo(logotipai A[])
{
	if (A[0].taskai > A[1].taskai && A[0].taskai > A[2].taskai)
	{
		return 1;
	}
	else if (A[1].taskai > A[0].taskai && A[1].taskai > A[2].taskai)
	{
		return 2;
	}
	else if (A[2].taskai > A[0].taskai&& A[2].taskai > A[1].taskai)
	{
		return 3;
	}
}

int main()
{
	logotipai A[3];
	readData(A);
	directorsPoints(A);
	writeData(A, findBestLogo(A));

	return 0;
}