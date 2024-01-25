// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.11.10
/* Purpose: Given a sequence of numbers, determine those numbers that appear 2n+1 times,
           where n is an interger ane n greater or equal to 0. */
// compiler standard: g++11
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class BST;
class treeNode {
private:
    int value;
    treeNode *left,*right;
public:
    treeNode(int value) : value(value), left(nullptr), right(nullptr){}
    int getLeft() { return left ? left->value : 0; }
    int getRight() { return right ? right->value : 0; }
    friend class BST;
};

class BST {
private:
    treeNode *root;
public:
    BST(int n) { root = new treeNode(n); }

    // find the minimim value
    treeNode *minValueNode(treeNode* node) {
        treeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    
    // find the value whether it exist in the tree or not
    treeNode *find(int value, treeNode *node) {
        if(node == nullptr)
            return nullptr;
        else if(value == node->value)
            return node;
        else if(value > node->value)
            return find(value, node->right);
        else if(value < node->value)
            return find(value, node->left);
    }

    // if the value exist in tree, then delete it
    treeNode *remove(int value, treeNode *deleteNode) {
        if(deleteNode == nullptr)
            return deleteNode;
        if(value > deleteNode->value)
            deleteNode->right = remove(value, deleteNode->right);
        else if(value < deleteNode->value)
            deleteNode->left = remove(value, deleteNode->left);
        else {
            if(deleteNode->left == nullptr){ // left-sutree is empty
                treeNode *newNode = deleteNode->right;
                delete deleteNode;
                return newNode;
            }
            else if(deleteNode->right == nullptr){ // right-sutree is empty
                treeNode *newNode = deleteNode->left;
                delete deleteNode;
                return newNode;
            }

            treeNode *temp = minValueNode(deleteNode->right);
            deleteNode->value = temp->value;
            deleteNode->right = remove(temp->value, deleteNode->right);
        }
        return deleteNode;

    }

    // if the value nonexist in tree, then insert it
    treeNode *insert(int value, treeNode *insertNode) {
        if(insertNode == nullptr)
            return new treeNode(value);
        else if(value < insertNode->value)
            insertNode->left =  insert(value, insertNode->left);
        else if(value > insertNode->value)
            insertNode->right = insert(value, insertNode->right);
        return insertNode;
    }

    void add(int n) {
        treeNode *node = find(n, root);
        root = (node) ? remove(n, root) : insert(n, root);
    }

    treeNode *getRoot() const { return root; }

    // the inorder tree
    void inorder(vector<tuple<int, int, int>> &recorder, treeNode *node) {
        if(node) {
            inorder(recorder, node->left);
            recorder.push_back(make_tuple(node->value, node->getLeft(), node->getRight()));
            inorder(recorder, node->right);
        }
    }

    vector<tuple<int, int, int>> inorder() {  
        vector<tuple<int, int, int>> recorder;  
        inorder(recorder, root);  
        return recorder; 
    }
};

int main() {
    int n;
    while(cin >> n) {
        // input
        BST tree(n);
        while(cin >> n && n != -1)
            tree.add(n);

        vector<tuple<int, int, int>> recorder = tree.inorder();
        //tree.inorder(recorder,tree.getRoot());

        cout << "node: ";
        for(auto i : recorder)
            cout << get<0>(i) << " ";
        cout << endl << "left: ";
        for(auto i : recorder)
            cout << get<1>(i) << " ";
        cout << endl << "right: ";
        for(auto i : recorder)
            cout << get<2>(i) << " ";
        cout<<endl;
    }
    return 0;
}