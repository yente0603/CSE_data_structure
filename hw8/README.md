Option:  
-c compress file  
-u decompress file  


Usage:  
create ELF file
```
make
```
compress
```cpp
./main.elf -c src/test.txt -o output/encoded_output.compress
```  
decompress
```cpp
./main.elf -u output/encoded_output.compress -o output/decoded_output.txt
```
clean
```
make clean
```

*note: you should change the context of \'clean\' in Makefile according to the file you compress.