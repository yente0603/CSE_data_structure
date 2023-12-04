#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct huffmanNode{
    char data;
    unsigned frequency;
    huffmanNode *left, *right;
    
    huffmanNode(char data, unsigned frequency, huffmanNode *left = nullptr, huffmanNode *right = nullptr) 
     : data(data), frequency(frequency), left(left), right(right){}
};

/* Structure to compare the frequency of the Huffman tree nodes*/
struct compare{
    bool operator()(huffmanNode *left, huffmanNode *right){
        return (left->frequency > right->frequency);
    }
};

huffmanNode *huffmanTree(vector<char> &data, vector<unsigned> &frequency){
    priority_queue<huffmanNode*, vector<huffmanNode*>, compare> pq;
    for(int i = 0; i< data.size(); i++) // push into priority queue and make min heap
        pq.push(new huffmanNode(data[i], frequency[i]));

    while(pq.size() != 1){
        huffmanNode *left = pq.top();
        pq.pop();

        huffmanNode *right = pq.top();
        pq.pop();

        huffmanNode *top = new huffmanNode('$', left->frequency+right->frequency, left, right);
        pq.push(top);
    }
    return pq.top();
};

void printEncode(huffmanNode *node, string str){
    if(!node)
        return;
    if(node->data != '$')
        cout << node->data << ": " << str << endl;
    printEncode(node->left, str + "0");
    printEncode(node->right, str + "1");
}

void deleteTree(huffmanNode* node) {
    if (node == nullptr) 
        return;
    
    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

int main(){
    vector<char> data = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i'};
    vector<unsigned> frequency = {15, 6, 7, 12, 25, 4, 6, 1, 15};
    
    huffmanNode *node = huffmanTree(data, frequency);
    printEncode(node, "");
    deleteTree(node); // to free memory
    return 0;
}
