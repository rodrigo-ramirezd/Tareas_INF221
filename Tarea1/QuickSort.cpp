#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arreglo, 0, arreglo.size() - 1);
    
    // fin tiempo.
    auto fin = chrono::high_resolution_clock::now();

    // Imprimir tiempo de ejecucion de la funcion "SelectionSort".
    chrono::duration<double, milli> duracion = fin - inicio;
    cout << "Tiempo de ejecucion de SelectionSort: " << duracion.count() << endl;

    // Imprimir resultado para comprobar el ordenamiento en "resultado.txt".
/*    ofstream archivosalida("resultado.txt");
    if(!archivosalida){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return -1;
    }

    for (int i : arreglo){
        archivosalida << i << endl;
    }
    archivosalida.close();*/
    return 0;
}
