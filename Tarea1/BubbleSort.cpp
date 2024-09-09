#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Repetir hasta que no haya más intercambios
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Pasar a través del array de izquierda a derecha
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento es mayor que el siguiente, intercambiarlos
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Si no hubo intercambios en la iteración actual, la lista ya está ordenada
        if (!swapped) break;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Array original: \n";
    for (int i : arr) cout << i << " ";
    cout << endl;

    // Llamar a la función de ordenamiento
    bubbleSort(arr);
    
    // Mostrar el array ordenado
    cout << "Array ordenado: \n";
    for (int i : arr) cout << i << " ";
    cout << endl;
    
    return 0;
}
