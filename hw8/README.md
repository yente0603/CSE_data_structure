Usage:./main.elf $(option) $(inputfile) -o $(outputfile)\n


option:
-c compress file
-u decompress file


e.g.
compress
```cpp
e.g. ./main.elf -c src/test2.jpg -o output/encoded_output.compress
```  
decompress
```cpp
e.g. ./main.elf -u output/encoded_output.compress -o output/decoded_output.jpg
``
