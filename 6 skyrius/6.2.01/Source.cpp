#include<iostream>
#include<string>

bool contains( std::string input, std::string sequence )
{
    if ( input.find( sequence ) != std::string::npos )
    {
        return true;
    }
    

    return false;
}

int main()
{
    std::string input;
    std::string sequence;

    getline( std::cin, input );
    getline( std::cin, sequence );
    
    std::string s = " " + input + " ";
    std::string t = " " + sequence + " ";

    if ( contains( s, t ) )
    {
        std::cout << "TAIP" << std::endl;
    }
    else
    {
        std::cout << "NE" << std::endl;
    }
    
    return 0;
}
