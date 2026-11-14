#include <cctype>
#include <iostream>
#include <string>
#include <vector>



int main(int argc, char* argv[])
{
    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // loop over each character from user input
    while (std::cin >> inputChar) {
        // Uppercase alphabetic characters
        if (std::isalpha(inputChar)) {
            inputText += std::toupper(inputChar);
            continue;
        }

        // Transliterate digits to English words
        switch (inputChar) {
            case '0':
                inputText += "ZERO";
                break;
            case '1':
                inputText += "ONE";
                break;
            case '2':
                inputText += "TWO";
                break;
            case '3':
                inputText += "THREE";
                break;
            case '4':
                inputText += "FOUR";
                break;
            case '5':
                inputText += "FIVE";
                break;
            case '6':
                inputText += "SIX";
                break;
            case '7':
                inputText += "SEVEN";
                break;
            case '8':
                inputText += "EIGHT";
                break;
            case '9':
                inputText += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions

    //Ex 4.1: reading arguments with cpp 
    const std::vector<std::string> cmdLineArgs {argv, argv + argc};
    
    for(auto it = cmdLineArgs.begin(); it != cmdLineArgs.end(); ++it){
        std::cout << *it << std::endl;
    }

    //Ex 4.2: printing a help message
    
    for(auto it = cmdLineArgs.begin(); it != cmdLineArgs.end(); ++it){
        if(*it == "--help" || *it == "-h"){
            std::cout << "Usage: ./mpags-cipher [options]" << "\n" << "Options: " << "\n"; 
            std::cout << "-h, --help " << "\t\t" << "Display this help message." << std::endl;
        }
    }


    //Ex 4.3: handle all the flags and options

    std::string input_file { };
    std::string output_file { };

    for(auto it = cmdLineArgs.begin(); it != cmdLineArgs.end(); ++it){
        if(*it == "--help" || *it == "-h"){
            std::cout << "Usage: ./mpags-cipher [options]" << "\n" << "Options: " << "\n"; 
            std::cout << "-h, --help " << "\t\t" << "Display this help message." << std::endl;
            std::cout << "-i, -o " << "\t\t" << "input and output files" << std::endl;
            std::cout << "-v, --version " << "\t\t" << "Display current version" << std::endl;
            break;
        } else if(*it == "--version" || *it == "-v"){
            std::cout << "mpags-cipher version 1.0" << std::endl;

        } else if(*it == "-i"){
            if(it + 1 != cmdLineArgs.end()){
                input_file = *(it + 1);
                ++it;
            } else {
                std::cout << "Missing input file:" << std::endl;
                return 1;
            }
        } else if(*it == "-o"){
            if(it + 1 != cmdLineArgs.end()){
                output_file = *(it + 1);
                ++it;
            } else {
                std::cout << "Missing output file:" << std::endl;
                return 1;
            }
        } 
    }

    return 0;
}
