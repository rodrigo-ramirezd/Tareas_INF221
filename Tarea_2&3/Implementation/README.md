# Implementación

En esta sección se explica cada archivo necesario para la ejecución del código, los cuales son: `generate_costs.py`, `brute_force.cpp` y `dynamic_programming.cpp`.

---

## `generate_costs.py`

El archivo **`generate_costs.py`**, implementado en Python, se encarga de crear o modificar, según sea el caso, los archivos `.txt` que contienen los costos para las distintas operaciones: **insert**, **delete**, **replace**, y **transpose**. 

En este archivo, se puede ajustar el rango de valores generados aleatoriamente modificando los parámetros de la función `random.randint(limite_inferior, limite_superior)`. Estos límites controlan el rango de costos asignados a cada operación.

### Modificaciones de los Costos

Las modificaciones se deben realizar en los bloques de código correspondientes, los cuales están separados según el archivo de costos que se genera. Por ejemplo:

![Ejemplo de bloques](./images/image.png)

En la imagen, se aprecian dos bloques. Si se modifica la función `random.randint()` del bloque inferior, se estarían alterando los posibles costos para la operación de **sustitución (replace)**. Por el contrario, si se modifica el bloque superior, se estarían ajustando los costos para la operación de **inserción (insert)**.

---

## `brute_force.cpp` y `dynamic_programming.cpp`

Los archivos **`brute_force.cpp`** y **`dynamic_programming.cpp`** contienen las implementaciones en C++ del problema de la distancia mínima entre dos cadenas, \( S1 \) y \( S2 \). Ambos calculan el costo mínimo necesario para transformar \( S1 \) en \( S2 \) aplicando las operaciones mencionadas.

### Compilación y Ejecución

Para compilar o ejecutar alguno de los dos enfoques, se proporciona un archivo `Makefile` que contiene las instrucciones necesarias. Desde la carpeta `./Implementation`, puedes utilizar el siguiente comando para obtener ayuda:

```bash
make help
