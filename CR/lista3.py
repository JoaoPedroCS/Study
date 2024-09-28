import pandas as pd
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

matriz_adjacencia = np.array([
    [0, 0, 0, 0, 10, 0, 1, 1, 10, 0, 0, 0, 90, 0, 0, 1, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 5, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0],
    [10, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0],
    [1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 5],
    [10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6],
    [0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0],
    [90, 5, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 7, 0, 0, 0, 0, 45],
    [0, 0, 0, 1, 0, 9, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 45, 0, 0, 0]

])

G = nx.from_numpy_array(matriz_adjacencia)


mapeamento = {i: i + 1 for i in G.nodes()}
G = nx.relabel_nodes(G, mapeamento)

def desenhar_grafo(grafo, pos, title):
    plt.figure(figsize=(5,5))
    nx.draw(grafo, pos, with_labels=True, node_color='lightblue', edge_color='black', node_size=500, font_size=15, font_weight='bold')
    edge_labels = nx.get_edge_attributes(grafo, 'weight')
    nx.draw_networkx_edge_labels(grafo, pos, edge_labels=edge_labels, font_size=12)
    plt.title(title)
    plt.show()

pos1 = nx.circular_layout(G)

density = nx.density(G)
print(f'Densidade: {density}')

# Calcular o diâmetro
if nx.is_connected(G):
    diameter = nx.diameter(G)
    print(f'Diâmetro: {diameter}')
else:
    print('O grafo não é conexo, portanto não é possível calcular o diâmetro.')

# Calcular o coeficiente de clusterização médio
avg_clustering = nx.average_clustering(G)
print(f'Coeficiente de clusterização médio: {avg_clustering}')

# Calcular a distância média
if nx.is_connected(G):
    avg_shortest_path_length = nx.average_shortest_path_length(G)
    print(f'Distância média: {avg_shortest_path_length}')
else:
    print('O grafo não é conexo, portanto não é possível calcular a distância média.')

desenhar_grafo(G, pos1, "Grafo padrao")

############################################################################################################

