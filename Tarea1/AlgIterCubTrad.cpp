#include <iostream>
#include <vector>
using namespace std;

void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    vector<vector<int>> C(n, vector<int>(n));

    multiplyMatrices(A, B, C);

    for (const auto& row : C) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
