#include <iostream>
#include <fstream>

using namespace std;

struct nutbst {
    int data;
    nutbst* left;
    nutbst* right;
};

nutbst* taonut(int value) {
    nutbst* newnut = new nutbst;
    newnut->data = value;
    newnut->left = newnut->right = nullptr;
    return newnut;
}

nutbst* insert(nutbst* root, int value) {
    if (root == nullptr) {
        return taonut(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int Max(nutbst* root, int k) {
    int result = k;
    while (root != nullptr) {
        if (root->data < k) {
            result = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return result;
}

int main() {
    ifstream inputFile("inpLN.txt");
    ofstream outputFile("outLN.txt");

    int N;
    inputFile >> N;

    nutbst* root = nullptr;

    for (int i = 0; i < N; ++i) {
        int value;
        inputFile >> value;
        root = insert(root, value);
    }

    int M;
    inputFile >> M;

    for (int i = 0; i < M; ++i) {
        int K;
        inputFile >> K;
        int result = Max(root, K);
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
