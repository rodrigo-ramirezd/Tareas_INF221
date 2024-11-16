import random

# Create datasets for differents files relationated with a operational cost.
# COSTS x OPERATION:

# 1.-Matriz de costos para "cost_delete.txt":
with open("./cost_delete.txt", 'w') as file:
    for i in range(26):
        file.write(f"{random.randint(1,5)} ")

# 2.-Matriz de costos para "cost_insert.txt":
with open("./cost_insert.txt", 'w') as file:
    for i in range(26):
        file.write(f"{random.randint(1,5)} ")

# 3.-Matriz de costos para "cost_replace.txt":
with open("./cost_replace.txt", 'w') as file:
    for i in range(26):
        for j in range(26):
            if (i == j):
                file.write("%d " %0)
            else:
                file.write(f"{random.randint(1,5)} ")
        file.write("\n")
    file.write("\n")

# 4.-Matriz de costos para "cost_transpose.txt":
with open("./cost_transpose.txt", 'w') as file:
    for i in range(26):
        for j in range(26):
            if (i == j):
                file.write("%d " %0)
            else:
                file.write(f"{random.randint(1,5)} ")
        file.write("\n")
    file.write("\n")