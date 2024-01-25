# Implementation of a compression software with Huffman algorithm

## Use the original Makefile written by author

```zsh
mkdir obj output
make
```

compress & decompress

```zsh
Usage:./main.elf $(option) $(inputfile) -o $(outputfile)

option:
"-c" compress file
"-u" decompress file

e.g.
compress - e.g. ./main.elf -c src/test.txt -o output/encoded_output.compress
decompress - e.g. ./main.elf -u output/encoded_output.compress -o output/decoded_output.txt
```  

## Use the Cmake for cross-platform

```zsh
cmake --version # checking if you have installed cmake
mkdir obj output build && cd build
cmake .. #since CmakeLists.txt is in the upper folder 
make
```

compress & decompress

```cpp
./main.elf -c ../src/test.txt -o ../output/encoded_output.compress
./main.elf -u ../output/encoded_output.compress -o ../output/decoded_output.txt
```  

note: If you want to use the Cmake, you have to change all the directory in the huffmanlib.cpp.  
> huffmanlib.cpp:152: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:163: "output/encoded_output.compress" > "../output/encoded_output.compress"  
> huffmanlib.cpp:192: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:203: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:245: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:246: "output/ratio.txt" > "../output/ratio.txt"  
