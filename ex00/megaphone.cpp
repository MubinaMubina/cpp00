
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
            
            
            char upper_c = static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
            result += upper_c;
            j++;
        }
        i++;
    }

    std::cout << result;
    std::cout << "\n";
    return 0;
}
