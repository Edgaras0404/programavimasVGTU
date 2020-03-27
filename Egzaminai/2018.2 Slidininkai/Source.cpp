#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Rezultatai
{
    string name = "";
    int startingTime = 0;
    int finishingTime = 0;
    bool finished = false;
    int time = 0;
};



void readData(Rezultatai A[], int& n, int& m)
{
    ifstream fd("U2.txt");

    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd.ignore(80, '\n');
        char b[20 + 1] = "";
        fd.read(b, 20);
        A[i].name = b;
        int h, m, s;
        fd >> h >> m >> s;
        A[i].startingTime = h * 3600 + m * 60 + s;
    }
    fd >> m;

    for (int i = 0; i < m; i++)
    {

        fd.ignore(80, '\n');
        char b[20 + 1] = "";
        fd.read(b, 20);

        for (int z = 0; z < n; z++)
        {


            if ( b == A[z].name )
            {


                int h, m, s;
                fd >> h >> m >> s;
                cout << h << " " << m << " " << s << endl;
                A[z].finishingTime = (h * 3600) + (m * 60) + s;

                cout << A[z].finishingTime << " " << A[z].startingTime << endl;
                A[z].time = A[z].finishingTime - A[z].startingTime;
                //cout << A[z].time << endl;
                if (A[z].time <= 3600)
                {

                    A[z].finished = true;
                }
            }


        }

    }

}

bool sortByTime(Rezultatai a, Rezultatai b)
{
    if  (a.time != b.time)
    {
        return a.time < b.time;
    }
    return a.name < b.name;
}


void writeData(Rezultatai A[], int n)
{
    ofstream fr("U2rez.txt");
    for (int i = 0; i < n; i++)
    {
        if (A[i].finished)
        {
            fr << setw(20) << A[i].name << " " << A[i].time / 60 << " " << A[i].time % 60 << endl;
        }

    }

}

int main()
{
    int N = 0;
    int M = 0;
    Rezultatai A[30];
    readData(A, N, M);

    sort(A, A + N, sortByTime);

    writeData(A, N);





    return 0;
}