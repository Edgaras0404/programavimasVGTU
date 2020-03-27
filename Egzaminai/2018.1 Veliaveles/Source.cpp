#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int flagCnt(int g, int z, int r)
{
    int flags = 0;

    if (g <= z && g <= r)
    {
        flags = trunc(g/2);
    }
    else if (z <= g && z <= r)
    {
        flags = trunc(z/2);
    }
    else if (r <= g && r <= z)
    {
        flags = trunc(r/2);
    }
       
    
    return flags;
}

int main()
{
    ifstream fd ("U1.txt");

    int n;
    fd >> n;
    int g = 0;
    int z = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        char s = ' ';
        fd >> s >> temp;
        if (s == 'G')
        {
            g += temp;
        }
        else if (s == 'Z')
        {
            z += temp;
        }
        else if (s == 'R')
        {
            r += temp;
        }        
        
    }
    
    fd.close();

    int flags = flagCnt(g, z, r);
    g = g - (flags * 2);
    z = z - (flags * 2);
    r = r - (flags * 2);

    ofstream fr("U1rez.txt");

    fr << flags << endl;
    fr << "G = " << g << endl;
    fr << "Z = " << z << endl;
    fr << "R = " << r << endl;

    fr.close();
    return 0;
}