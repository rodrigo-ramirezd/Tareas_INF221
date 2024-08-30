#include <iostream>
#include <vector>
using namespace std;

void transposeMatrix(vector<vector<int>>& B) {
    int n = B.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(B[i][j], B[j][i]);
        }
    }
}

void multiplyMatricesOptimized(const vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    transposeMatrix(B);  // Transponer la matriz B

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[j][k];  // Se accede de manera continua a la memoria
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    vector<vector<int>> C(n, vector<int>(n));

    multiplyMatricesOptimized(A, B, C);

    for (const auto& row : C) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
