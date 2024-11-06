#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct Node {
    char ch; // Character
    int freq; // Frequency of character
    Node* left; // Left child
    Node* right; // Right child

    // Constructor
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparison object to be used in priority queue for min-heap
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Traverse the Huffman Tree and store Huffman codes in a map
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // If the node is a leaf node (contains a character)
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
string decode(Node* root, string& encodedString) {
    string decodedString = "";
    Node* currentNode = root;

    for (char bit : encodedString) {
        if (bit == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        // If a leaf node is reached
        if (!currentNode->left && !currentNode->right) {
            decodedString += currentNode->ch;
            currentNode = root; // Return to root for the next character
        }
    }

    return decodedString;
}

// Build Huffman Tree and generate codes
void buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add to priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        // Remove two nodes with the highest priority (lowest frequency)
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        // The frequency of the new node is the sum of the two nodes' frequencies
        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of the Huffman Tree
    Node* root = pq.top();

    // Generate Huffman codes by traversing the tree
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Print the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    // Encode the input text
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    cout << "\nEncoded String:\n" << encodedString << "\n";

    // Decode the encoded string
    string decodedString = decode(root, encodedString);

    cout << "\nDecoded String:\n" << decodedString << "\n";
}

int main() {
    //string text = "huffman coding is fun";
    string text ="India is my country";

    buildHuffmanTree(text);

    return 0;
}
