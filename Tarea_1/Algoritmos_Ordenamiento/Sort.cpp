#include <bits/stdc++.h>
using namespace std;

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
    
    sort(arreglo.begin(), arreglo.end());

    // fin tiempo.
    auto fin = chrono::high_resolution_clock::now();

    // Imprimir tiempo de ejecucion de la funcion "SelectionSort".
    chrono::duration<double, milli> duracion = fin - inicio;
    cout << "Tiempo de ejecucion del Sort: " << duracion.count() << endl;

/*    // Imprimir resultado para comprobar el ordenamiento en "resultado.txt".
    ofstream archivosalida("resultado.txt");
    if(!archivosalida){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return -1;
    }

    for (int i : arreglo){
        archivosalida << i << endl;
    }
    archivosalida.close();
*/    
    return 0;
}
