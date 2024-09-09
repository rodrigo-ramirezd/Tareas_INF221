from faker import Faker
import random

fake = Faker()

# Crear Datasets para el algoritmos de ordenamiento.
# Arreglo desordenado tamaño 1000 (10^3):
with open("Tarea1/SelectionSort_1.txt", 'w') as file:
    file.write("1000\n")
    for i in range(1000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 50000:
with open("Tarea1/SelectionSort_2.txt", 'w') as file:
    file.write("50000\n")
    for i in range(50000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 75000:
with open("Tarea1/SelectionSort_3.txt", 'w') as file:
    file.write("75000\n")
    for i in range(75000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 100000 (10^5):
with open("Tarea1/SelectionSort_4.txt", 'w') as file:
    file.write("100000\n")
    for i in range(100000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo desordenado tamaño 200000:
with open("Tarea1/SelectionSort_5.txt", 'w') as file:
    file.write("200000\n")
    for i in range(200000):
        file.write(f"{random.randint(1, 1000000)}\n")

# Arreglo ordenado tamaño 1000 (10^3):
with open("Tarea1/SelectionSort_6.txt", 'w') as file:
    file.write("1000\n")
    for i in range(1000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 50000:
with open("Tarea1/SelectionSort_7.txt", 'w') as file:
    file.write("50000\n")
    for i in range(50000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 75000:
with open("Tarea1/SelectionSort_8.txt", 'w') as file:
    file.write("75000\n")
    for i in range(75000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 100000 (10^5):
with open("Tarea1/SelectionSort_9.txt", 'w') as file:
    file.write("100000\n")
    for i in range(100000):
        file.write(f"{i}\n")

# Arreglo desordenado tamaño 200000:
with open("Tarea1/SelectionSort_10.txt", 'w') as file:
    file.write("200000\n")
    for i in range(200000):
        file.write(f"{i}\n")
        
# -----------------------------------------------------------------------------------------

# Crear Datasets para algoritmo de multiplicacion de matrices.
