#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct position {
    int x, y;
};

bool testxy(int x, int y, int M, int N) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}


void dfs(int x, int y, int mark, int M, int N, char A[100][100], int B[100][100], int& count) {
    B[x][y] = mark;
    count++;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (testxy(newX, newY, M, N) && A[newX][newY] == 'X' && B[newX][newY] == 0) {
            dfs(newX, newY, mark, M, N, A, B, count);
        }
    }
}

int main() {
    ifstream inputFile("inpLT.txt");
    ofstream outputFile("outLT.txt");

    int M, N;
    inputFile >> M >> N;

    char A[100][100];
    int B[100][100] = {0}; 

    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> A[i][j];
        }
    }

    int countlt = 0, dem = 0;    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 'X' && B[i][j] == 0) {
                int count = 0;
                dfs(i, j, ++countlt, M, N, A, B,count);
                if (count == 1) {
                    dem++;
                }
            }
        }
    }

    outputFile << dem << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            outputFile << B[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}


