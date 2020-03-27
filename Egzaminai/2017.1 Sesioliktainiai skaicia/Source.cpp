#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;


string decToHex(int data0)
{
    char str[3] = "";
    
    int temp = data0 / 16;
    for (int i = 0; i < 2; i++)
    {
        switch (temp)
        {
            case 0:
                str[i] = '0';
                break;

            case 1:
                str[i] = '1';
                break;

            case 2:
                str[i] = '2';
                break;

            case 3:
                str[i] = '3';
                break;

            case 4:
                str[i] = '4';
                break;

            case 5:
                str[i] = '5';
                break;

            case 6:
                str[i] = '6';
                break;

            case 7:
                str[i] = '7';
                break;

            case 8:
                str[i] = '8';
                break;

            case 9:
                str[i] = '9';
                break;

            case 10:
                str[i] = 'A';
                break;
                
            case 11:
                str[i] = 'B';
                break;
                
            case 12:
                str[i] = 'C';
                break;
                
            case 13:
                str[i] = 'D';
                break;

            case 14:
                str[i] = 'E';
                break;
                
            case 15:
                str[i] = 'F';
                break;

            default:
                break;
        }

    
        temp = data0 % 16;
    }
    
    return str;
}

void readData(vector<int>& data, int& a, int& b)
{

    ifstream fd("U1.txt");

    fd >> a >> b;
    fd.ignore(1);

    for (int i = 0; i < a * b; i++)
    {
        for (int z = 0; z < 3; z++)
        {

            int temp;
            fd >> temp;
            data.push_back(temp);

        }
    }

    fd.close();
}

int main()
{
    
    int a, b;
    
    vector<int> data;   
    
    readData(data, a, b);

    
    

    ofstream fr("U1rez.txt");
    
   

    int count = 0;
  
    
    
    
    for (int i = 0; i < a; i++)
    {
        for (int z = 1; z < b; z++)
        {
            fr <<  decToHex(data.at(count)) <<  decToHex(data.at(count+1)) <<   decToHex(data.at(count+2)) << ";";
            count += 3;
        }
        fr << decToHex(data.at(count)) <<  decToHex(data.at(count+1)) <<   decToHex(data.at(count+2)) << endl;
        count += 3;
    }
    
    
    fr.close();
    
}