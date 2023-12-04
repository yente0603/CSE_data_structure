#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <unistd.h>
using namespace std;

int getRandom(int i) {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return mt_rand() % i;
}

int main(){
    ofstream file;
    file.open("input.txt",ios::out);
    vector<int> scale = {100, 500, 1000, 5000, 10000,
                         50000, 100000, 500000, 1000000, 5000000};
    for(auto i:scale) {
        file << i << endl;
        for(int j = 0; j < i; j++)
            file << getRandom(i) << endl;
    }
    file.close();
    execlp("/bin/mkdir","mkdir","output",NULL);
    return 0;
}