#include <iostream>
#include <fstream>

using namespace std;

const char inputF[] = "U2.txt";
const char outputF[] = "U2rez.txt";

struct Data
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    int r = 255;
    int g = 255;
    int b = 255;
};   

void readData(Data data[], int& n)
{
    ifstream fd(inputF);
    if (fd.is_open())
    {
        fd >> n;

        for (int i = 0; i < n; i++)
        {
            fd >> data[i].x >> data[i].y >> data[i].dx >> data[i].dy >> data[i].r >> data[i].g >> data[i].b;
        }

        fd.close();
    }
    else
    {
        cerr << "Error opening file: " << inputF << endl;
    }
}

void addBlock(Data data, int screen[100][100][3])
{
    for (int i = 0; i < data.dy; i++)
    {
        for (int z = 0; z < data.dx; z++)
        {
            screen[data.x+z][data.y+i][0] = data.r;
            screen[data.x+z][data.y+i][1] = data.g;
            screen[data.x+z][data.y+i][2] = data.b;
        }   
    }
}

void writeData(int screen[100][100][3], int a, int b, int x, int y)
{   
    ofstream fr(outputF);
    if (fr.is_open())
    {    
        fr << a << " " << b << endl;
        for (int i = 0; i < a; i++)
        {
           for (int z = 0; z < b; z++)
           {
               fr << screen[z][i][0] <<  " " << screen[z][i][1] << " " << screen[z][i][2] << endl;
           }
           
        }
        
        fr.close();
    }
    else
    {
        cerr << "File could not be created/opened: " << outputF << endl;
    }
}

void trimSize(int screen[100][100][3], int& a, int& b, int& topX, int& topY)
{
    
    bool xFound = false;
    bool yFound = false;
    int largestA = 0;
    int largestB = 0;
    for (int i = 0; i < 100; i++)
    {
       for (int z = 0; z < 100; z++)
       {
           if (screen[i][z][0] < 255 || screen[i][z][1] < 255 || screen[i][z][2] < 255 )
           {

               largestA = z;
               if (!xFound)
               {
                   topX = z;
                   xFound = true;
               }
               
           }
           
       }
       
        if (largestA > a)
        {
            a = largestA;
        }
               
    }
    
    for (int i = 0; i < 100; i++)
    {
       for (int z = 0; z < 100; z++)
       {
           if (screen[z][i][0] < 255 || screen[z][i][1] < 255 || screen[z][i][2] < 255 )
           {
                
                largestB = z;
                if (!yFound)
                {
                    topY = z;
                    yFound = true;
                }
           }
           
       }
       

        if (largestB > b)
        {
            b = largestB;
        }
       
    }

    a++;
    b++;

}

int main()
{   
    int n = 0;
    Data data[100];
    int screen[100][100][3] = { 0 };

    for (int i = 0; i < 100; i++)
    {
        for (int z = 0; z < 100; z++)
        {
            screen[i][z][0] = 255;
            screen[i][z][1] = 255;
            screen[i][z][2] = 255;
        }
        
    }
    
    
    readData(data, n);

    for (int i = 0; i < n; i++)
    {
        addBlock(data[i], screen);
    }
    

    int a = 0;
    int b = 0;
    int topX = 0;
    int topY = 0;

    
    trimSize(screen, a, b, topX, topY);
    writeData(screen, a, b, topX, topY);

    return 0;
}

