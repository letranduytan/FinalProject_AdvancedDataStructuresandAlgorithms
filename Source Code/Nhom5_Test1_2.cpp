// Test case ngau nhien
#include <iostream>
#include <fstream>
#include <cstdlib>  

using namespace std;

const int MAX_SIZE = 100;

void Testcase(int M, int N, ofstream& file) {
    file << M << " " << N << endl;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            char cellValue = (rand() % 2 == 0) ? 'X' : 'O';
            file << cellValue << " ";
        }
        file << endl;
    }
}

int main() {
 
    ofstream outputFile("inpLT.txt");
    Testcase(6, 6, outputFile);
    outputFile.close();

    return 0;
}
