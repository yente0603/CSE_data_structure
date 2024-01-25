# Implementation of a compression software with Huffman algorithm

## Use the Makefile written by author

```bash
mkdir obj output
make
make clean
```

compress & decompress

```bash
Usage:./main.elf $(option) $(inputfile) -o $(outputfile)

option:
"-c" compress file
"-u" decompress file

e.g.
compress - e.g. ./main.elf -c src/test.txt -o output/encoded_output.compress
decompress - e.g. ./main.elf -u output/encoded_output.compress -o output/decoded_output.txt
```  

## Use the Cmake for cross-platform

```bash
cmake --version
mkdir obj output build && cd build
cmake ..
make
./main.elf -c ../src/test.txt -o ../output/encoded_output.compress
./main.elf -u ../output/encoded_output.compress -o ../output/decoded_output.txt
make clean-custom
```

> Checking if you have installed cmake.
> Since CmakeLists.txt is in the upper folder, we use `make ..` to initilize cmake.
> To enable using the `make clean-custom` command to clean up custom files such as .elf or .compress.
