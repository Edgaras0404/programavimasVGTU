#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    int n, sum = 0;

    in >> n;

    in.close();

    for ( int i = 1; i <= n; i++ )
    {
        if ( i % 2 == 0 )
        {
            sum += i;
        }
        
    }
    
    out << sum / n << endl;

    out.close();

    return 0;
}
