#include <bits/stdc++.h>
using namespace std;

int N, M, integer;

void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Leer y llenar matrices NxM:
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> B(M, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N));

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

    multiplyMatrices(A, B, C);

    // fin tiempo.
    auto fin = chrono::high_resolution_clock::now();

    // Imprimir tiempo de ejecucion de la funcion "SelectionSort".
    chrono::duration<double, milli> duracion = fin - inicio;
    cout << "Tiempo de ejecucion de algoritmo tradicional: " << duracion.count() << endl;

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
