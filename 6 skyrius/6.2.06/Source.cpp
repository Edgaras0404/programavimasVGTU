#include <iostream>
#include <string>
#include <vector>

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

void editVc( std::vector<std::string>& words )
{
    std::vector<std::string> vec;  
    for ( int i = 0; i < words.size(); ++i )
    {   
        if ( words.at( i ).at( 0 ) == 'm' )
        {
            vec.push_back( words.at( i ) );
        }   
    }
    words = vec;
}


int main()
{
    setlocale(LC_ALL, "Lithuanian");
    std::string line;
    getline( std::cin, line );    

    std::vector<std::string> words;
    
    splitStr( words, line );
    editVc( words );

    if ( words.size() )
    {
        std::cout << words.size() << std::endl;
        for (int i = 0; i < words.size() - 1; i++)
        {
            std::cout << words.at( i ) << " ";
        }
        std::cout << words.at( words.size() - 1 ) << std::endl;
    }
    else
    {
        std::cout << "NĖRA" << std::endl;
    }
    
    
    return 0;
}
