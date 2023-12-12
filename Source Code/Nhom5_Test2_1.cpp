// Test case ngẫu nhiên
#include <iostream>
#include <fstream>
#include <cstdlib>  

using namespace std;

void TestCase(const char* fileName, int N, int maxValue, int M) {
    ofstream file(fileName);

    // Ghi số N
    file << N << endl;

    // Ghi mảng A
    for (int i = 0; i < N; ++i) {
        file << rand() % (maxValue + 1) << " ";
    }
    file << endl;

    // Ghi số M
    file << M << endl;

    // Ghi M số nguyên K
    for (int i = 0; i < M; ++i) {
        file << rand() % (maxValue + 1) << endl;
    }

    file.close();
}

int main() { 
    // Tạo test case với N = 10, maxValue = 100, M = 5
    TestCase("inpLN.txt", 10, 100, 5);
    return 0;
}
