// Test case trường hợp đặc biệt
#include <iostream>
#include <fstream>

using namespace std;

void SpecialTest(ofstream& file) {
    // Test case với ma trận 3x3 có 1 vùng liên thông
    file << "3 3\n";
    file << "X O X\n";
    file << "X O X\n";
    file << "O X O\n";

    // Test case với ma trận 4x4 không có vùng liên thông
    /*
    file << "4 4\n";
    file << "X O X O\n";
    file << "O X O X\n";
    file << "X O X O\n";
    file << "O X O X\n"; */

}

int main() {
    ofstream outputFile("inpLT.txt");
    SpecialTest(outputFile);
    outputFile.close();
    return 0;
}
