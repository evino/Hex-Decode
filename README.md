# hexDecoder
Takes in hex values from an input file via comman line arguments, and
prints bits 14-41 from the hex addresses to an outfile.

## Usage
Clone repo and compile using steps below.

Compilation:
Has been tested using clang++.
```
clang++ hexDecode.cpp -o decoder
```

Running:
1. Enter `make` to generate hexDecoder executable.
2. ./hexDecoder <inFile> <outFile>
  
  
Cleaning workspace:

  Enter `make clean` to remove object file and executable.
