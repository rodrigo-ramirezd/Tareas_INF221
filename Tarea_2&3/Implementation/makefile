# Variables para los nombres de los ejecutables y los archivos fuente
BRUTE_FORCE_SRC = brute_force.cpp
BRUTE_FORCE_EXEC = brute_force
DYNAMIC_PROG_SRC = dynamic_programming.cpp
DYNAMIC_PROG_EXEC = dynamic_programming

# Flags de compilación
CXX = g++
CXXFLAGS = -Wall
CXXVALGRIND = valgrind --leak-check=yes

# Compilar y ejecutar brute_force
compilar_brute_force: $(BRUTE_FORCE_SRC)
	$(CXX) -g $(CXXFLAGS) $< -o $(BRUTE_FORCE_EXEC)

ejecutar_brute_force: $(BRUTE_FORCE_EXEC)
	$(CXXVALGRIND) ./$(BRUTE_FORCE_EXEC)

# Compilar y ejecutar dynamic_programming
compilar_dynamic_programming: $(DYNAMIC_PROG_SRC)
	$(CXX) -g $(CXXFLAGS) $< -o $(DYNAMIC_PROG_EXEC)

ejecutar_dynamic_programming: $(DYNAMIC_PROG_EXEC)
	$(CXXVALGRIND) ./$(DYNAMIC_PROG_EXEC)

# Regla general para limpiar ejecutables
clean:
	rm -f $(BRUTE_FORCE_EXEC) $(DYNAMIC_PROG_EXEC)

# Ayuda para listar los comandos disponibles
help:
	@echo "Opciones disponibles:"
	@echo "  compilar_brute_force         Compila el archivo brute_force.cpp"
	@echo "  ejecutar_brute_force         Ejecuta el programa brute_force"
	@echo "  compilar_dynamic_programming Compila el archivo dynamic_programming.cpp"
	@echo "  ejecutar_dynamic_programming Ejecuta el programa dynamic_programming"
	@echo "  clean                        Elimina los ejecutables generados"
