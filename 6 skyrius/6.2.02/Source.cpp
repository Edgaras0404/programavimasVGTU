#include <iostream>
#include <string>
#include <vector>

void stringCheck ( std::string input );
int errCheck ( std::string text, std::string sub );
int eopCheck ( std::string text );


int main()
{
    setlocale(LC_ALL, "Lithuanian");
    std::string input, line;
    while ( getline( std::cin, line) )
    {
        input += " " + line;
    }

    stringCheck( input );
    
    return 0;
}

void stringCheck( std::string input )
{
    int mistakes = 0;

    mistakes += errCheck( input, "." );
    mistakes += errCheck( input, "," );
    mistakes += errCheck( input, ";" );
    mistakes += errCheck( input, "!" );
    mistakes += errCheck( input, "?" );
    mistakes += eopCheck ( input );

    if ( mistakes )
    {
        std::cout << "Rastų skyrybos klaidų skaičius: " << mistakes << std::endl;
    }
    else
    {
        std::cout << "Skyrybos ženklai sudėti pagal taisykles" << std::endl;
    }
    
}


int errCheck ( std::string text, std::string sub )
{
    int x = 0;

    std::vector<unsigned int> positions;

    unsigned int pos = text.find ( sub );
    while ( pos != std::string::npos )
    {
        positions.push_back( pos );
        pos = text.find( sub, pos + 1);
    }
       

    for (int i = 0; i < positions.size(); i++)
    {   
        if ( positions.at( i ) + 1 >= text.size() )
        {
            if ( text.at( positions.at( i ) - 1 ) == ' ' )
            {
                ++x;
            }
        }
        else
        {
            if ( text.at( positions.at( i ) - 1 ) == ' ' || !( text.at( positions.at( i ) + 1 ) == ' ' || text.at( positions.at( i ) + 1 ) == '\n' ) )
            {
                ++x;
            }
        }
        
        
    }
    
    return x;
}

int eopCheck ( std::string text )
{
    int x = 0;

    unsigned int pos = text.find ('\n');
    while ( pos != std::string::npos )
    {
        if ( !( text.find( '.', pos - 2 ) || text.find( ',', pos - 2 ) || text.find( ';', pos - 2 ) || text.find( '!', pos - 2 ) || text.find( '!', pos - 2 ) ) )
        {
            ++x;
            pos = text.find( '\n', ++pos );
        }
    }    

    return x;
}