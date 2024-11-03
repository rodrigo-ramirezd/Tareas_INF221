import random

# Crear Datasets para el algoritmos de ordenamiento.
# LISTAS DESORDENADAS:
# Arreglo desordenado tamaño 1000 (10^3):
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Desordenada_1.txt", 'w') as file:
    file.write("1000\n")
    for i in range(1000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 50000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Desordenada_2.txt", 'w') as file:
    file.write("50000\n")
    for i in range(50000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 75000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Desordenada_3.txt", 'w') as file:
    file.write("75000\n")
    for i in range(75000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 100000 (10^5):
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Desordenada_4.txt", 'w') as file:
    file.write("100000\n")
    for i in range(100000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 200000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Desordenada_5.txt", 'w') as file:
    file.write("200000\n")
    for i in range(200000):
        file.write(f"{random.randint(1, 1000000)}\n")

# LISTAS ORDENADAS:
# Arreglo ordenado tamaño 1000 (10^3):
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Ordenada_1.txt", 'w') as file:
    file.write("1000\n")
    for i in range(1000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 50000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Ordenada_2.txt", 'w') as file:
    file.write("50000\n")
    for i in range(50000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 75000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Ordenada_3.txt", 'w') as file:
    file.write("75000\n")
    for i in range(75000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 100000 (10^5):
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Ordenada_4.txt", 'w') as file:
    file.write("100000\n")
    for i in range(100000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 200000:
with open("Tarea1/Algoritmos_Ordenamiento/Lista_Ordenada_5.txt", 'w') as file:
    file.write("200000\n")
    for i in range(200000):
        file.write(f"{i}\n")
        
# -----------------------------------------------------------------------------------------

# Crear Datasets para algoritmo de multiplicacion de matrices.
# MATRICES DE DIFERENTE DIMENSION NxM:
# Arreglo de arreglos de tamaño 131x115 * 115x131:
with open("Tarea1/Multiplicacion_Matrices/Matriz_1.txt", 'w') as file:
    file.write("131\n115\n")
    for i in range(131):
        for j in range(115):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(115):
        for j in range(131):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")

# Arreglo de arreglos de tamaño 1031x915 * 915x1031:
with open("Tarea1/Multiplicacion_Matrices/Matriz_2.txt", 'w') as file:
    file.write("1031\n915\n")
    for i in range(1031):
        for j in range(915):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(915):
        for j in range(1031):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")

# Arreglo de arreglos de tamaño 4750x3915 * 3915x4750:
with open("Tarea1/Multiplicacion_Matrices/Matriz_3.txt", 'w') as file:
    file.write("4750\n3915\n")
    for i in range(4750):
        for j in range(3915):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(3915):
        for j in range(4750):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")

# MATRICES CUADRAS NxN:
# Arreglo de arreglos de tamaño 512x512:
with open("Tarea1/Multiplicacion_Matrices/Matriz_cuadrada_1.txt", 'w') as file:
    file.write("512\n512\n")
    for i in range(512):
        for j in range(512):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(512):
        for j in range(512):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")

# Arreglo de arreglos de tamaño 11024x1024:
with open("Tarea1/Multiplicacion_Matrices/Matriz_cuadrada_2.txt", 'w') as file:
    file.write("1024\n1024\n")
    for i in range(1024):
        for j in range(1024):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(1024):
        for j in range(1024):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")

# Arreglo de arreglos de tamaño 2048x2048:
with open("Tarea1/Multiplicacion_Matrices/Matriz_cuadrada_3.txt", 'w') as file:
    file.write("2048\n2048\n")
    for i in range(2048):
        for j in range(2048):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")
    file.write("\n")
    for i in range(2048):
        for j in range(2048):
            file.write(f"{random.randint(10,50)} ")
        file.write("\n")