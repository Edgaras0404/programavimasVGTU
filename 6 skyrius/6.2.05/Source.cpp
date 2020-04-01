#include <iostream>
#include <string>
#include <vector>


std::string reformatStr( std::string line )
{
    std::string str;
    bool inBrackets = false;
    for ( char x : line )
    {
        if ( x == '<' )
        {
            inBrackets = true;
        }
        if ( !inBrackets )
        {
            str.push_back( x );
        }
        if ( x == '>' )
        {
            inBrackets = false;
        }

    }
    
    return str;
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    std::string line;
    getline( std::cin, line );    

    std::cout << reformatStr( line ) << std::endl;

    return 0;
}
