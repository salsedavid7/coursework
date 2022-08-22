#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Min_Heap_Node {
    char data;
    unsigned freq;
    Min_Heap_Node *left, *right;

Min_Heap_Node(char data, unsigned freq) {
    left = right = NULL;
    this->data = data;
    this->freq = freq;
    }
};

struct compare {
    bool operator()(Min_Heap_Node* l, Min_Heap_Node* r) {
    return (l->freq > r->freq);
    }
};

void printCodes(struct Min_Heap_Node* root, char ans , string str) {
    if (!root) {
        return;
    }

    if (root->data != '$') {
        if(ans == root->data)
            cout << root->data << ":" << str << "\n";
}

    printCodes(root->left,ans, str + "0");
    printCodes(root->right,ans, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct Min_Heap_Node *left, *right, *top;
    priority_queue<Min_Heap_Node*, vector<Min_Heap_Node*>, compare> minHeap;
    for (int i = 0; i < size; ++i) {
        minHeap.push(new Min_Heap_Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Min_Heap_Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    for (int i = 0; i < 6; i++){
        printCodes(minHeap.top(),data[i], "");
    }
}

int main() {
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int freq[6] ;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0;i < size; i++) {
        cin >> freq[i];
    }
    HuffmanCodes(arr, freq, size);
    return 0;
}