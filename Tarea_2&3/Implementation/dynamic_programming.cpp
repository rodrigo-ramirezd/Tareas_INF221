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

// Algoritmo de Programación Dinámica
int dynamic_programming(const vector<char> &s1, const vector<char> &s2) {
    size_t n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    // Inicialización de casos base
    dp[0][0] = 0;
    for (size_t i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + COST_ARRAY(delete_array, s1[i - 1]);
    }
    for (size_t j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + COST_ARRAY(insert_array, s2[j - 1]);
    }

    // Rellenar la tabla
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            // Costos de las operaciones básicas
            int cost_ins = dp[i][j - 1] + COST_ARRAY(insert_array, s2[j - 1]);
            int cost_del = dp[i - 1][j] + COST_ARRAY(delete_array, s1[i - 1]);
            int cost_rep = dp[i - 1][j - 1] + COST_MATRIX(replace_matrix, s1[i - 1], s2[j - 1]);

            // Costos de la operación de transposición
            int cost_trans = INT_MAX;
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                cost_trans = dp[i - 2][j - 2] + COST_MATRIX(transpose_matrix, s1[i - 2], s1[i - 1]);
            }

            // Almacenar el costo mínimo en la celda actual
            dp[i][j] = min({cost_ins, cost_del, cost_rep, cost_trans});
        }
    }

    // El costo total mínimo está en la esquina inferior derecha de la tabla
    return dp[n][m];
}

// Funcion para obtener el tiempo.
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

        // Calcular la distancia mínima usando programación dinámica
        int min_distance = dynamic_programming(s1, s2);

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
