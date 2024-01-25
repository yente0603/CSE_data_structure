#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <cstdlib>
using namespace std;

map<char, string> frequencyTable;        // frequcncy table
map<string, char> reverseFrequencyTable; // reverse frequency table
int zeroPadding = 0;                     // record more 0 for bytes

struct huffmanNode
{
    unsigned char data;
    unsigned frequency;
    huffmanNode *left, *right;

    huffmanNode(unsigned char data, unsigned frequency, huffmanNode *left = nullptr, huffmanNode *right = nullptr)
        : data(data), frequency(frequency), left(left), right(right) {}
};

/* Structure to compare the frequency of the Huffman tree nodes*/
struct compare
{
    bool operator()(huffmanNode *left, huffmanNode *right)
    {
        // rule 2: considering set and frequency
        if (left->frequency != right->frequency)
            return left->frequency > right->frequency;
        else
            return (left->data > right->data);
    }
};

huffmanNode *huffmanTree(vector<unsigned char> &data, vector<unsigned> &frequency)
{
    priority_queue<huffmanNode *, vector<huffmanNode *>, compare> pq;
    for (int i = 0; i < data.size(); i++) // push into priority queue and make min heap
        pq.push(new huffmanNode(data[i], frequency[i]));

    while (pq.size() != 1)
    {
        huffmanNode *left = pq.top();
        pq.pop();

        huffmanNode *right = pq.top();
        pq.pop();

        if (left->data > right->data)
            swap(left, right);
        huffmanNode *top = new huffmanNode(127, left->frequency + right->frequency, left, right);
        pq.push(top);
    }
    return pq.top();
};

void buildEncodingtTable(huffmanNode *node, string str)
{
    if (!node)
        return;
    if (!node->left && !node->right) // boundary condition
        frequencyTable[node->data] = (str.empty() ? "0" : str);
    if (node->data != 127) // '127' = delete in ASCII
        frequencyTable[node->data] = str;
    buildEncodingtTable(node->left, str + "0");
    buildEncodingtTable(node->right, str + "1");
}

void calculateFrequency(string filename, vector<unsigned char> &data, vector<unsigned> &frequency)
{
    map<char, unsigned> frequencyMap;

    ifstream file(filename, ios::binary);
    if (!file.is_open())
        cout << "Unable to open file!" << endl;
    else
    {
        char c; // read byte per unit
        while (file.read(&c, sizeof(c)))
            ++frequencyMap[c]; // read char to map and nenew its frequency
        file.close();
    }

    for (auto &pair : frequencyMap)
    { // map change to vector
        data.push_back(pair.first);
        frequency.push_back(pair.second);
    }
}

void deleteTree(huffmanNode *node)
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

void writeFrequencytable(string filename)
{
    ofstream file(filename, ios::binary | ios::out);
    if (!file.is_open())
    {
        cout << "could not write file header of encoding table." << endl;
        return;
    }
    for (auto &code : frequencyTable)
    {
        file.put(code.first);                                // Write the character, including special characters like '\n'
        file.write(": ", 2);                                 // Write the separator
        file.write(code.second.c_str(), code.second.size()); // Write the Huffman code
        file.put('\n');                                      // Write a newline character
    }
    file.close();
}

long getFileSize(string filename)
{
    ifstream file(filename, ios::binary | ios::ate); // "ios::ate" open file at the end
    if (!file.is_open())
        return -1;
    long size = file.tellg(); // get the size of file
    file.close();
    return size;
}

int compressFile(string inputfile, string outputfile)
{
    ifstream infile(inputfile, ios::binary);
    ofstream outfile(outputfile, ios::binary | ios::out);
    zeroPadding = 0;
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "Could not open file for encoding." << endl;
        return 0;
    }

    /* convert from char to unsigned char to access vector elements*/
    string buffer;
    char c;
    while (infile.read(&c, sizeof(c)))
    {
        buffer += frequencyTable[c];
        while (buffer.size() >= 8)
        {
            bitset<8> binary(buffer.substr(0, 8));
            char byte = binary.to_ulong();
            outfile.write(&byte, sizeof(byte));
            buffer = buffer.substr(8);
        }
    }
    /*zero paddind*/
    zeroPadding = 8 - buffer.size();
    while (buffer.size() < 8)
        buffer += "0";
    bitset<8> lastByte(buffer);
    char byte = lastByte.to_ulong();
    outfile.write(&byte, sizeof(byte));
    // cout << zeroPadding << endl;
    infile.close();
    outfile.close();

    ofstream file("output/frequency_table.txt", ios::binary | ios::app);
    file << zeroPadding;

    return 0;
}

void Ratio(string filename, long originalSize)
{
    ofstream file(filename, ios::binary | ios::out);
    if (!file.is_open())
        cout << "could not write file header of encoding table." << endl;
    else
    {
        long compressedSize = getFileSize("output/encoded_output.compress");

        double compressionRatio = compressedSize / (double)originalSize;

        file << "Original Size: " << originalSize << " bytes" << endl;
        file << "Compressed Size: " << compressedSize << " bytes" << endl;
        file << "Compression Ratio: " << compressionRatio << endl;
        file.close();
    }
}

void readFrequencyTable(string inputFile)
{
    ifstream file(inputFile, ios::binary);
    if (!file.is_open())
    {
        cout << "unable to open frequency table file.\n";
        return;
    }

    char curChar;
    while (file.get(curChar))
    { // Get the first character (even if it's a special character)
        string curCode;
        file.ignore(2);         // Ignore the ": " separator
        getline(file, curCode); // Read the Huffman code until newline
        reverseFrequencyTable[curCode] = curChar;
    }
    file.close();
}

int decompressFile(string inputfile, string outputfile)
{
    readFrequencyTable("output/frequency_table.txt");
    ifstream infile(inputfile, ios::binary);
    ofstream outfile(outputfile, ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "Could not open file for decoding." << endl;
        return 0;
    }

    /*find zeroPadding*/

    char zeroPaddingChar;
    ifstream paddingFile("output/frequency_table.txt", ios::binary);
    if (paddingFile.is_open())
    {
        paddingFile.seekg(-1, ios::end);  // move to the text -1 of the end of file
        paddingFile.get(zeroPaddingChar); // get and store into zeroPaddingChar
        paddingFile.close();
        zeroPadding = zeroPaddingChar - '0'; // char to int
    }
    else
    {
        cout << "Could not read the zero padding information." << endl;
        return 0;
    }

    size_t file_size = getFileSize(inputfile);
    size_t cur_size = 0;
    string code = "";
    char byte;

    while (infile.read(&byte, sizeof(byte)))
    {
        cur_size += sizeof(byte);

        /* find until correspond code */
        int bitsToRead = (cur_size == file_size) ? (8 - zeroPadding) : 8;

        /* convert code to bit string */
        for (int i = 7; i >= (8 - bitsToRead); --i)
        {
            code += (byte & (1 << i)) ? '1' : '0';
            if (reverseFrequencyTable.find(code) != reverseFrequencyTable.end())
            {
                outfile << reverseFrequencyTable[code];
                code = "";
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}

void compress(string inputFilePath, string outputFileName)
{
    vector<unsigned char> data;
    vector<unsigned> frequency;

    string inputFile = inputFilePath;
    string frequency_table = "output/frequency_table.txt";
    string ratio = "output/ratio.txt";
    string compress_output = outputFileName;

    /*step 1: calculate the frequency*/
    calculateFrequency(inputFile, data, frequency);
    huffmanNode *node = huffmanTree(data, frequency);

    /*step2: get the frequency table*/
    buildEncodingtTable(node, "");

    /*step3: write the frequency table into file header*/
    writeFrequencytable(frequency_table);

    /* Step 4: Encode the original file and write to new file */
    compressFile(inputFile, compress_output);

    /*step 5: calculation the compression ratio*/
    Ratio(ratio, getFileSize(inputFile));

    deleteTree(node); // to free memory
    cout << "compress done!" << endl;
}

void decompress(string inputFilePath, string outputFileName)
{
    /*step 6: decompress the compress to original file*/
    decompressFile(inputFilePath, outputFileName);
    cout << "decompress done!" << endl;
}
