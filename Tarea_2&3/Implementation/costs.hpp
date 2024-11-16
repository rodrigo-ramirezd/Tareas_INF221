#include "costs.hpp"

// Cargar la matriz del archivo "file" a leer, el cual corresponde a un archivo .txt con los costos
void load_matrix(vector<vector<int>> &matrix, const char* file);

void load_array(vector<int> &array, const char* file);

int COST_ARRAY(vector<int> &array, char a);

int COSTO_MATRIX(vector<vector<int>> &matrix, char a, char b);