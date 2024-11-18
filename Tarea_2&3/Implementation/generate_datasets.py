import string
import random

def generar_entradas(nombre_archivo, rango):
    """
    Genera entradas aleatorias de letras minúsculas y las escribe en un archivo.

    :param nombre_archivo: Nombre del archivo donde se guardarán las entradas.
    :param rango: Tupla que contiene el rango de longitud de las cadenas (min, max).
    """
    with open(nombre_archivo, 'w') as file:
        letras = string.ascii_lowercase  # Letras minúsculas
        cantidad_letras = random.randint(rango[0], rango[1])

        # Casos específicos según el tipo de archivo
        if "input_transpose" in nombre_archivo:
            # Generar cadena base
            cadena_base = ''.join(random.choice(letras) for _ in range(cantidad_letras))
            file.write(f"{cadena_base}\n")

            # Generar cadena modificada con transposiciones
            cadena_modificada = list(cadena_base)
            for i in range(0, len(cadena_modificada) - 1, 2):  # Transposición en pares
                cadena_modificada[i], cadena_modificada[i + 1] = cadena_modificada[i + 1], cadena_modificada[i]
            file.write(f"{''.join(cadena_modificada)}\n")

        elif "input_semiordered" in nombre_archivo:
            # Generar dos cadenas semiordenadas
            mitad_longitud = cantidad_letras // 2
            mitad1 = ''.join(random.choice(letras) for _ in range(mitad_longitud))
            mitad2 = ''.join(random.choice(letras) for _ in range(mitad_longitud))
            cadena1 = mitad1 + mitad2
            cadena2 = mitad2 + mitad1
            file.write(f"{cadena1}\n")
            file.write(f"{cadena2}\n")

        else:  # Para input_disordered
            # Generar dos cadenas completamente aleatorias
            for _ in range(2):
                cadena = ''.join(random.choice(letras) for _ in range(cantidad_letras))
                file.write(f"{cadena}\n")


# Especificaciones para cada archivo
entradas = [
    ("./input_transpose1.txt", (2, 3)),
    ("./input_transpose2.txt", (4, 6)),
    ("./input_transpose3.txt", (7, 8)),
    ("./input_transpose4.txt", (9, 10)),
    ("./input_transpose5.txt", (11, 12)),
    ("./input_semiordered1.txt", (2, 3)),
    ("./input_semiordered2.txt", (4, 6)),
    ("./input_semiordered3.txt", (7, 8)),
    ("./input_semiordered4.txt", (9, 10)),
    ("./input_semiordered5.txt", (11, 12)),
    ("./input_disordered1.txt", (2, 3)),
    ("./input_disordered2.txt", (4, 6)),
    ("./input_disordered3.txt", (7, 8)),
    ("./input_disordered4.txt", (9, 10)),
    ("./input_disordered5.txt", (11, 12)),
]

# Generar los archivos
for archivo, rango in entradas:
    generar_entradas(archivo, rango)
