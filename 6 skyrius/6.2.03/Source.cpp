#include <iostream>
#include <string>
#include <cctype>

void checkIfStarts( std::string str, unsigned int& count )
{
    unsigned const int testLetters = 3;

    if ( str.length() > 1 )
    {
        std::string sub[testLetters] = { " v", " t", " k" };

        for (int i = 0; i < testLetters; i++)
        {
            std::string::size_type pos = str.find ( sub[i] );
            while ( pos != std::string::npos )
            {
                ++count;
                pos = str.find( sub[i], pos + 1);
            }

            if ( str.at( 0 )  == sub[i].at( 1 ) )
            {
                ++count;
            }
            
        }
        
    }

}


int main()
{
    unsigned int count = 0;
    std::string line;
    while ( getline( std::cin, line ) )
    {
        checkIfStarts( line, count );
    }

    std::cout << count << std::endl;

    return 0;
}