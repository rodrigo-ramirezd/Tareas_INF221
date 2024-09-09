#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    // Asignar elementos al arreglo de tamaño "size".
    int size, integer;
    cin >> size;
    vector<int> arreglo(size);
    for(int i = 0; i < size; i++){
        cin >> integer;
        arreglo[i] = integer;
    }

    // inicio tiempo.
    auto inicio = chrono::high_resolution_clock::now();
    
    mergeSort(arreglo, 0, arreglo.size() - 1);

    // fin tiempo.
    auto fin = chrono::high_resolution_clock::now();

    // Imprimir tiempo de ejecucion de la funcion "SelectionSort".
    chrono::duration<double, milli> duracion = fin - inicio;
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

    // Imprimir resultado para comprobar el ordenamiento en "resultado.txt".
    ofstream archivosalida("resultado.txt");
    if(!archivosalida){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return -1;
    }

    for (int i : arreglo){
        archivosalida << i << endl;
    }
    archivosalida.close();
    return 0;
}
