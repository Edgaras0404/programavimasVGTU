#include <iostream>
#include <string>

int main()
{
    setlocale( LC_ALL, "Lithuanian" );
    std::string input, output;
    getline ( std::cin, input );

    for ( char x : input )
    {
        output.push_back( x );
        output.push_back( x );
    }
    
    std::cout << output << std::endl;

    return 0;
}