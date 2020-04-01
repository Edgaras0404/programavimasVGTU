#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int inARow( std::string& line, unsigned int at )
{
    unsigned int x = 1;

    ++at;

    while ( line.at( at ) == ' ' )
    {
        line.erase( at, 1 );
        ++x;
    }
    
    return x;
}

void output( const unsigned int count, std::string line )
{
    if ( count > 1 )
    {
        std::cout << "TAIP" << std::endl;
    }
    else
    {
        std::cout << "NE" << std::endl;
    }

    std::cout << line << std::endl;
    std::cout << "Daugiausiai tarpų: " << count << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    std::string line;
    getline( std::cin, line );

    std::vector<unsigned int> spaces;

    for ( unsigned int i = 0; i < line.length(); i++ )
    {
        if ( line.at( i ) == ' ' )
        {
            spaces.push_back( inARow( line, i ) );
        }   
    }

    if ( spaces.size() )
    {
        output( *std::max_element( spaces.begin(), spaces.end() ), line );
    }
    else
    {
        output( 0, line );
    }
    
    return 0;
}