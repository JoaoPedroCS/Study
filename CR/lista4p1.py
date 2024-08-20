import numpy as np

def read_adjacency_matrix(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    matrix = []
    for line in lines[1:]:  # Ignora o cabeçalho
        row = list(map(int, line.strip().split()[1:]))  # Ignora o primeiro elemento (rótulo do vértice)
        matrix.append(row)
    
    return np.array(matrix)

def calculate_modularity(adjacency_matrix, modules):
    def get_internal_edges(matrix, module):
        indices = module
        submatrix = matrix[np.ix_(indices, indices)]
        return np.sum(submatrix) / 2

    def get_external_edges(matrix, module):
        total_edges = np.sum(matrix) / 2
        internal_edges = get_internal_edges(matrix, module)
        return total_edges - internal_edges

    def get_degrees(matrix, module):
        degrees = np.sum(matrix, axis=0)
        return degrees[module]

    def modularity(module, matrix):
        internal_edges = get_internal_edges(matrix, module)
        external_edges = get_external_edges(matrix, module)
        degrees = get_degrees(matrix, module)
        m = np.sum(matrix) / 2
        k = np.sum(degrees)
        expected_edges = np.sum(degrees**2) / (2 * m)
        return (internal_edges - expected_edges) / (2 * m)

    modularity_scores = {}
    
    for i, module in enumerate(modules):
        modularity_scores[f'Módulo {i+1}'] = modularity(module, adjacency_matrix)
    
    return modularity_scores

# Caminho para o arquivo de matriz de adjacência
file_path = 'lista4/11202321597-lista4.txt'

# Ler a matriz de adjacência do arquivo
adjacency_matrix = read_adjacency_matrix(file_path)

# Definição dos módulos
modules = [
    [0, 1, 2, 3, 4],  # Módulo 1
    [5, 6, 7, 8, 9],  # Módulo 2
    [10, 11, 12],     # Módulo 3
    [13, 14, 15, 16, 17, 18, 19]  # Módulo 4
]

# Calcular a modularidade para cada módulo
modularity_scores = calculate_modularity(adjacency_matrix, modules)

# Imprimir os resultados
for module, score in modularity_scores.items():
    print(f'{module}: {score:.3f}')
