
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    int j;

    if(argc >= 2)
    {
        std::string result;
        while(argv[i][j])
        {   
            j = 0;
            if(argv[i][j] == ' ')
                j++;
            result[] = argv[i][j];
            j++;
        }
        std::cout << " ";
        i++;

    }
    else
    {
        
    }
    std::cout << "\n";
    return 0;
}


#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    std::string result;

    while (i < argc)
    {
        int j = 0;
        while (argv[i][j])
        {
            static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
            result += argv[i][j];
            j++; 
        }
        i++;
    }

    std::cout << result;
    std::cout << "\n";
    return 0;
}
