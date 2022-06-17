// Takes in input file via command line, containing hex values and outputs
// bits 14-41 of the value into an output file.

// Incase you're wondering why I have such a random program,
// it was for a very specific debug :)

#include <iostream>
#include <fstream>

// Reverses binary string
void reversal(std::string &str) {
    int strLen = str.length() - 1;
    for (int i = 0; i <= strLen; i++) {
        std::swap(str[i], str[strLen]);
        strLen--;
    }
    return;
}

// Converts long integer in base 1o to binary
std::string decToBinary(long dec) {
    std::string bits;
    while (dec) {
        if (dec & 1) {
            bits += "1";  // 1
        } else {
             bits += "0";  // 0
        }
        dec >>= 1;  // right shift by 1
    }
    reversal(bits);
    return bits;
}


int main(int argc, char **argv) {
    std::ifstream in;
    std::ofstream out;
    std::string line;

    // check command line for correct number of arguments
    if( argc != 3 ){
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>" << std::endl;
        return(EXIT_FAILURE);
    }

    // open file for reading
    in.open(argv[1]);
    if( !in.is_open() ){
        std::cerr << "Unable to open file " << argv[1] << " for reading" << std::endl;
        return(EXIT_FAILURE);
    }

    // open file for writing
    out.open(argv[2]);
    if( !out.is_open() ){
        std::cerr << "Unable to open file " << argv[2] << " for writing" << std::endl;
        return(EXIT_FAILURE);
    }


    // splits hex string into two hex-strings each consisting of 16 nibbles (64 bits)
    std::string hexString; // Nibbles 0-15
    std::string bin;
    long dec;
    //char *end;
    //std::string end = ",\t\n ";

    out << "      original hex val                      bits 14-41" << std::endl;
    
    while (std::getline(in, line)) {
        hexString = line.substr(5, 10);  // Substrings into string consisting of nibbles 5-15 from original hex string
        dec = std::stol(hexString, NULL, 16);
        bin = decToBinary(dec);
        std::string finalBits = bin.substr(9, 28);  // breaks down binary string into substring that only contains
                                                    // bits 14-41.

        out << line << " | " << "0b" << finalBits << std::endl;
    }


    in.close();
    out.close();
    return EXIT_SUCCESS;
}
