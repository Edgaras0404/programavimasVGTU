#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void splitStr( std::vector<std::string>& words, std::string line)
{
    std::string str;
    char tests[] = { ' ', ',', '.', ';', '!', '?' };
    
    bool eow = false;
    for ( char x : line )
    {
        for ( char test : tests )
        {
            if ( x == test )
            {
                if ( str.size() )
                {
                    words.push_back( str );
                }
                
                str = "";
                eow = true;
            }
   
        }
        if ( !eow )
        {
            str.push_back( x );
        }
        else
        {   
            eow = false;   
        }
        
    }
}

bool srtStr ( std::string& a, std::string& b )
{
    if ( a.size() != b.size() )
    {
        return a.size() > b.size();
    }
    return true;
}

int main()
{
    setlocale( LC_ALL, "Lithuanian" );
    std::string line;
    getline( std::cin, line );    

    std::vector<std::string> words;
    
    splitStr( words, line );
    
    std::sort( words.begin(), words.end(), srtStr );

    std::cout << words.at( 0 ) << std::endl;

    return 0;
}
