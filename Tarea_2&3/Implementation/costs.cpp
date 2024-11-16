void load_matrix(vector<vector<int>> &matrix, const char* file) {
    ifstream infile(file); // Abre el archivo en modo lectura.
    
    if (!infile.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (!(infile >> matrix[i][j])) { // Lee el archivo en la matriz.
                throw runtime_error("Error al leer el archivo. Verifique el formato.");
            }
        }
    }

    infile.close(); // Cierra el archivo después de leerlo.
    return;
}

void load_array(vector<int> &array, const char* file) {
    ifstream infile(file); // Abre el archivo en modo lectura.
    
    if (!infile.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    for (int i = 0; i < 26; i++) {
        if (!(infile >> array[i])) { // Lee el archivo en la matriz.
            throw runtime_error("Error al leer el archivo. Verifique el formato.");
        }
    }

    infile.close(); // Cierra el archivo después de leerlo.
    return;
}

int COST_ARRAY(vector<int> &array, char a){
    int cost, index;
    index = a - 'a';
    cost = array[index];
    return cost;
}

int COSTO_MATRIX(vector<vector<int>> &matrix, char a, char b){
    int cost, index_a, index_b;
    index_a = a - 'a';
    index_b = b - 'a';
    cost = matrix[index_a][index_b];
    return cost;
}