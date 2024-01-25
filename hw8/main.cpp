// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.12.11
// Purpose: complement Huffman algorithm to compress and decompress file 
// compiler standard: g++11
#include "libs/huffmanlib.cpp"
int main(int argc, char *argv[]){
    if (argc == 5 && string(argv[1]) == "-c")
        compress(string(argv[2]), string(argv[4]));
    else if (argc == 5 && string(argv[1]) == "-u")
        decompress(string(argv[2]), string(argv[4]));
    else {
        std::cout << "error argument! " << std::endl
                  << "Usage:./main.elf $(option) $(inputfile) -o $(outputfile)\n"
                  << "\noption:\n"
                  << "\"-c\" compress file\n"
                  << "\"-u\" decompress file\n\n"
                  << "e.g.\n"
                  << "compress - e.g. ./main.elf -c src/test.txt -o output/encoded_output.compress\n"
                  << "decompress - e.g. ./main.elf -u output/encoded_output.compress -o output/decoded_output.txt\n";
    }
    return 0;
}