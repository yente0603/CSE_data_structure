option:  
-c compress file  
-u decompress file  


e.g.  
compress
```cpp
./main.elf -c src/test.txt -o output/encoded_output.compress
```  
decompress
```cpp
./main.elf -u output/encoded_output.compress -o output/decoded_output.txt
```
