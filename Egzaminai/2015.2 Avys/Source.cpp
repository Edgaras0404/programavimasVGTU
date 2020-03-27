#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";


struct Avis
{
    string name = "";
    char DNA[20] = "";
    int coef = 0;
};

void readData(Avis A[], int& N, int& M, string& exSheep);

void writeData(Avis A[], int N, int M, string exSheep);

bool sortByCoef(Avis a, Avis b);

void calcCoef(Avis A[], int N, int M, string exSheep);


int main()
{
    int n, m;
    string exSheep;
    Avis A[1000];

    readData(A, n, m, exSheep); //read data from the file

    calcCoef(A, n, m, exSheep);


    sort(A, A + n, sortByCoef);

    writeData(A, n, m, exSheep); // write data into the file

    return 0;
}


//The function that calculates the coeficient
void calcCoef(Avis A[], int N, int M, string exSheep)
{
    char exDNA[20] = "";

    for (int i = 0; i < N; i++)
    {
        if (A[i].name == exSheep)
        {
            for (int z = 0; z < M; z++)
            {
                exDNA[z] = A[i].DNA[z];

            }
            
        }
        
    }
    
    
    for (int i = 0; i < N; i++)
    {

        
        if (A[i].name != exSheep)
        {
            for (int z = 0; z < M; z++)
            {
                
                if (exDNA[z] == A[i].DNA[z])
                {
                    //cout << exDNA[z] << A[i].DNA[z] << endl;
                    A[i].coef++;

                }
                
            }
        }
        
    }
    
}


//sorting function, returning if the former value is larger than the latter
bool sortByCoef(Avis a, Avis b)
{
    if (a.coef != b.coef)
    {
        return a.coef > b.coef;
    }
    
    return a.name < b.name;

}


//The function that reads data from the input file
void readData(Avis A[], int& N, int& M, string& exSheep)
{
    ifstream fd(inputF); 
    if (fd.is_open())
    {
        int sheep;
        fd >> N >> M >> sheep;
        
        for (int i = 0; i < N; i++)
        {
            fd.ignore(80, '\n'); //ignoring '\n' 

            char b[11] = ""; //reading the name of the sheep
            fd.read(b, 10);
            A[i].name = b;

            if (sheep == i + 1)
            {
                exSheep = b;
            }
            
            fd.ignore(1);
            fd.read(A[i].DNA, M); //reading the DNA data
        } 


    }
    else
    {
        cerr << "Failed to open file: " << inputF << endl;
    }
    
}


//The function that writes data into the output file
void writeData(Avis A[], int N, int M, string exSheep)
{
    ofstream fr(outputF);
    if (fr.is_open())
    {
        fr << exSheep << endl;

        for (int i = 0; i < N; i++)
        {
            if (exSheep !=  A[i].name)
            {
                fr << setw(10) << A[i].name << " " << A[i].coef << endl;
            }
            
        }

    }
    else
    {
        cerr << "Failed to open file: " << outputF << endl;
    }
    
}