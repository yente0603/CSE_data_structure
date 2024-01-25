## Option

-c compress file  
-u decompress file  

## Usage of original Makefile

create an executable(.elf) file on linux based system

```zsh
make
```

compress & decompress

```c++
./main.elf -c src/test.txt -o output/encoded_output.compress
./main.elf -u output/encoded_output.compress -o output/decoded_output.txt
```  

## Usage of Cmake

```zsh
mkdir build && cd build
cmake .. #since CmakeLists.txt is in the upper folder 
make
```

compress & decompress

```c++
./main.elf -c ../src/test.txt -o ../output/encoded_output.compress
./main.elf -u ../output/encoded_output.compress -o ../output/decoded_output.txt
```  

note: If you want to use Cmake, you have to change all the directory in the huffmanlib.cpp.  
> huffmanlib.cpp:152: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:163: "output/encoded_output.compress" > "../output/encoded_output.compress"  
> huffmanlib.cpp:192: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:203: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:245: "output/frequency_table.txt" > "../output/frequency_table.txt"  
> huffmanlib.cpp:246: "output/ratio.txt" > "../output/ratio.txt"  
