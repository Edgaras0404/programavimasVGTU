#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

const char inputF[] = "U1.txt";
const char outputF[] = "U1rez.txt";
const int maxPlayers = 12;
const int maxPlayerNumber = 99;
const int maxTime = 40;
int n = 0;

struct player
{
	int number = 0;
	int playTime = 0;
	int breakTime = 0;
	bool isStarting = false;
};



void getInput(player A[])
{
	ifstream fd(inputF);
	if (!fd.is_open())
	{
		cout << "Error whilst opening file: " << inputF << endl;
	}
	else
	{
		fd >> n;
		for (int i = 0; i < n; i++)
		{
			fd >> A[i].number;
			int t;
			fd >> t;
			for (int z = 0; z < t; z++)
			{
				int temp = 0;
				fd >> temp;
				if (temp > 0 && z == 0)
				{
					A[i].isStarting = true;
				}
				if (temp > 0)
				{
					A[i].playTime += temp;
				}
				if (temp < 0)
				{
					A[i].breakTime += temp;
				}

			}
		}
		fd.close();
	}

}

bool sortPlayTime(player A, player B)
{
	return A.playTime > B.playTime;
}

bool sortBreakTime(player A, player B)
{
	return A.breakTime < B.breakTime;
}

void setOutput(player A[])
{
	ofstream fr(outputF);
	if (!fr.is_open())
	{
		cout << "Error whilst opening file: " << outputF << endl;
	}
	else
	{
		int numbers[5];
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i].isStarting)
			{
				numbers[temp] = A[i].number;
				temp++;
			}
		}
		sort(numbers, numbers + 5);
		fr << numbers[0] << " " << numbers[1] << " " << numbers[2] << " " << numbers[3] << " " << numbers[4] << endl;
		fr << A[0].number << " " << A[0].playTime << endl;
		sort(A, A + n, sortBreakTime);
		fr << A[0].number << " " << 0  - A[0].breakTime << endl;
	}

}

int main()
{
	player A[maxPlayers];
	
	getInput(A);
	sort(A, A + n, sortPlayTime);
	setOutput(A);

	return 0;
}