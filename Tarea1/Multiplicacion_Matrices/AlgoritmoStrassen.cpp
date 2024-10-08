#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        Matrix result(1, vector<int>(1));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Dividir las matrices en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calcular los 7 productos M1 a M7
    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Combinar los resultados en la matriz resultante C
    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    // Unir las submatrices en la matriz final
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

int main() {
    // Leer y llenar matrices NxM:
    int N, M, integer;
    cin >> N >> M;
    Matrix A(N, vector<int>(M));
    Matrix B(M, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> integer;
            A[i][j] = integer;
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> integer;
            B[i][j] = integer;
        }
    }

    // inicio tiempo.
    auto inicio = chrono::high_resolution_clock::now();
    
    Matrix C = strassen(A, B);

    // fin tiempo.
    auto fin = chrono::high_resolution_clock::now();

    // Imprimir tiempo de ejecucion de la funcion "SelectionSort".
    chrono::duration<double, milli> duracion = fin - inicio;
    cout << "Tiempo de ejecucion de algoritmo Strassen: " << duracion.count() << endl;

    ofstream archivosalida("resultado.txt");
    if(!archivosalida){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return -1;
    }

    for (const auto& row : C) {
        for (int val : row)
            archivosalida << val << " ";
        archivosalida << endl;
    }
    archivosalida.close();

    return 0;
}
