#include <vector>
#include <queue>
#include <map>

extern map<char, string> frequencyTable; // frequcncy table
extern map<string, char> reverseFrequencyTable; // reverse frequency table

huffmanNode *huffmanTree(vector<unsigned char> &data, vector<unsigned> &frequency);
void buildEncodingtTable(huffmanNode *node, string str);
void calculateFrequency(string filename, vector<unsigned char>& data, vector<unsigned>& frequency);
void deleteTree(huffmanNode* node);
void writeFrequencytable(string filename);
long getFileSize(string filename);
void compressFile(string inputfile, string outputfile);
void Ratio(string filename, long originalSize);
void readFrequencyTable(string inputFile);
void decompressFile(string inputfile, string outputfile);
void compress(string inputFilePath, string outputFileName);
void decompress(string inputFilePath, string outputFileName);
