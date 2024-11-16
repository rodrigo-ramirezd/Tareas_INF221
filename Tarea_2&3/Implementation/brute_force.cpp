#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

// Declaración de estructuras globales
vector<int> insert_array(26), delete_array(26);
vector<vector<int>> replace_matrix(26, vector<int>(26)), transpose_matrix(26, vector<int>(26));

// Función para cargar una matriz desde un archivo
void load_matrix(vector<vector<int>> &matrix, const char* file) {
    ifstream infile(file);
    if (!infile.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (!(infile >> matrix[i][j])) {
                throw runtime_error("Error al leer el archivo. Verifique el formato.");
            }
        }
    }
    infile.close();
}

// Función para cargar un arreglo desde un archivo
void load_array(vector<int> &array, const char* file) {
    ifstream infile(file);
    if (!infile.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    for (int i = 0; i < 26; i++) {
        if (!(infile >> array[i])) {
            throw runtime_error("Error al leer el archivo. Verifique el formato.");
        }
    }
    infile.close();
}

// Funciones de costo
int COST_ARRAY(const vector<int> &array, char a) {
    return array[a - 'a'];
}

int COST_MATRIX(const vector<vector<int>> &matrix, char a, char b) {
    return matrix[a - 'a'][b - 'a'];
}

// Algoritmo de Fuerza Bruta
int brute_force(const vector<char> &s1, const vector<char> &s2, size_t i, size_t j) {    
    if (i == s1.size()) {
        // Costos de inserción restantes en s2
        int total_cost = 0;
        for (size_t k = j; k < s2.size(); k++) {
            total_cost += COST_ARRAY(insert_array, s2[k]);
        }
        return total_cost;
    } else if (j == s2.size()) {
        // Costos de eliminación restantes en s1
        int total_cost = 0;
        for (size_t k = i; k < s1.size(); k++) {
            total_cost += COST_ARRAY(delete_array, s1[k]);
        }
        return total_cost;
    } else if (s1[i] == s2[j]) {
        // No hay costo si los caracteres son iguales
        return brute_force(s1, s2, i + 1, j + 1);
    } else {
        // Calcular costos de las operaciones
        int cost_ins = COST_ARRAY(insert_array, s2[j]) + brute_force(s1, s2, i, j + 1);
        int cost_del = COST_ARRAY(delete_array, s1[i]) + brute_force(s1, s2, i + 1, j);
        int cost_rep = COST_MATRIX(replace_matrix, s1[i], s2[j]) + brute_force(s1, s2, i + 1, j + 1);

        int cost_trans = INT_MAX;
        if (i + 1 < s1.size() && j + 1 < s2.size() && s1[i] == s2[j + 1] && s1[i + 1] == s2[j]) {
            cost_trans = COST_MATRIX(transpose_matrix, s1[i], s1[i + 1]) + brute_force(s1, s2, i + 2, j + 2);
        }

        // Retornar el costo mínimo entre todas las opciones
        return min({cost_ins, cost_del, cost_rep, cost_trans});
    }
}

long obtenerTiempo(){
    struct timeval inicio;
    // gettimeofdat devuelve el tiempo del reloj de la computadora
    gettimeofday(&inicio, NULL);
    // Retornamos el tiempo en segundo multiplicado por un millon que será 00:00:00 + el tiempo en microsegundos
    return inicio.tv_sec*1000000+inicio.tv_usec;
}

int main(int argc, char const *argv[]) {
    long final, inicio; // instancia inicial
    double tiempoEnSegundos;
    long tiempoEnMicrosegundos;

    try {
        // Cargar costos desde archivos
        load_matrix(replace_matrix, "cost_replace.txt");
        load_matrix(transpose_matrix, "cost_transpose.txt");
        load_array(insert_array, "cost_insert.txt");
        load_array(delete_array, "cost_delete.txt");

        // Leer las cadenas desde la entrada
        string word;
        getline(cin, word);
        vector<char> s1(word.begin(), word.end());
        getline(cin, word);
        vector<char> s2(word.begin(), word.end());

        inicio = obtenerTiempo();

        // Calcular la distancia mínima
        int min_distance = brute_force(s1, s2, 0, 0);

        final = obtenerTiempo(); // instancia final
        // restamos el tiempo total final menos el tiempo de incio 
        tiempoEnMicrosegundos = final - inicio;
        // transformamos a segundos
        tiempoEnSegundos = tiempoEnMicrosegundos * pow(10, -6);

        // impresion del tiempo en microsegundos y segundos
        cout << "Distancia mínima: " << min_distance << endl << endl;
        cout << "EL tiempo de ejecucion en segundos es: " << tiempoEnSegundos << endl << endl;
        cout << "El tiempo de ejecucion en microsegundos es: " << tiempoEnMicrosegundos << endl << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
