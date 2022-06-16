// remove whats not neccesary

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

//using namespace std;


void reversal(std::string &str) {
    int strLen = str.length() - 1;
    for (int i = 0; i <= strLen; i++) {
        std::swap(str[i], str[strLen]);
        strLen--;
    }
    return;
}


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
    std::string::size_type end;

    while (std::getline(in, line)) {
        hexString = line.substr(5, 10);  // Substrings into string consisting of nibbles 3-10
        dec = std::stol(hexString, &end, 16);
        bin = decToBinary(dec);
        out << bin << std::endl;
        std::string finalBits = bin.substr(9, 28);
        out << "DB: " << finalBits << std::endl;
        //bin.erase(30, 2);
        //bin.erase(0, 2);
        out << line << " | " <<  "0x" << hexString << " | " << "0b" << finalBits << std::endl;
    }


    in.close();
    out.close();
    return EXIT_SUCCESS;
    }
