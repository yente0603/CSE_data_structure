Usage: ./main.elf \$(option) \$(inputfile) -o \$(outputfile)


option:  
-c compress file  
-u decompress file  


e.g.  
compress
```cpp
./main.elf -c src/test2.jpg -o output/encoded_output.compress
```  
decompress
```cpp
./main.elf -u output/encoded_output.compress -o output/decoded_output.jpg
```
