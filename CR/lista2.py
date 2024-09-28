import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.nx_pydot import graphviz_layout

matriz_adjacencia = np.array([
    [0, 6, 10, 1, 1, 0, 90, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [10, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 8, 1, 0, 0, 0],
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 6],
    [90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 4, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 8, 8, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0],
    [0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 8, 0, 0, 0],
    [0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0],
    [0, 0, 0, 0, 9, 0, 0, 0, 0, 5, 8, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 45],
    [0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0]
])

G = nx.from_numpy_array(matriz_adjacencia)

# Renomear os nós para começarem em 1
mapeamento = {i: i + 1 for i in G.nodes()}
G = nx.relabel_nodes(G, mapeamento)

# Função de busca em profundidade com prioridade para nós de menor índice
def dfs_prioridade_menor_indice(grafo, start):
    visitados = set()
    resultado = []

    def dfs(v):
        visitados.add(v)
        resultado.append(v)
        vizinhos = sorted(grafo.neighbors(v))
        for vizinho in vizinhos:
            if vizinho not in visitados:
                dfs(vizinho)

    dfs(start)
    return resultado
def dfs_prioridade_maior_indice(grafo, start):
    visitados = set()
    resultado = []

    def dfs1(v):
        visitados.add(v)
        resultado.append(v)
        vizinhos = sorted(grafo.neighbors(v), reverse=True)
        for vizinho in vizinhos:
            if vizinho not in visitados:
                dfs1(vizinho)

    dfs1(start)
    return resultado

def desenhar_grafo(grafo, pos, title):
    plt.figure(figsize=(5,5))
    nx.draw(grafo, pos, with_labels=True, node_color='lightblue', edge_color='black', node_size=500, font_size=15, font_weight='bold')
    edge_labels = nx.get_edge_attributes(grafo, 'weight')
    nx.draw_networkx_edge_labels(grafo, pos, edge_labels=edge_labels, font_size=12)
    plt.title(title)
    plt.show()

dfs_tree = nx.dfs_tree(G, source=1)
dfs_tree_sorted = nx.dfs_tree(G, source=1, sort_neighbors=lambda x: sorted(x, reverse=True))


distancia = nx.dijkstra_path_length(G, 1, 15, weight='weight')

mst = nx.minimum_spanning_tree(G, algorithm='prim')
custo_total = mst.size(weight='weight')

pos1 = nx.circular_layout(G)
pos2 = nx.circular_layout(dfs_tree)
pos3 = nx.circular_layout(dfs_tree_sorted)
pos4 = nx.bfs_layout(mst, 1)


# Exibir o resultado
print("Resultado da busca em profundidade, menor indice:", list(nx.dfs_preorder_nodes(G, source=1)))
print("Resultado da busca em profundidade, maior indice:", list(nx.dfs_preorder_nodes(G, source=1, sort_neighbors=lambda x: sorted(x, reverse=True))))
print("distancia:", distancia)
print("Custo total:", custo_total)
desenhar_grafo(G, pos1, "Grafo padrao")
desenhar_grafo(dfs_tree, pos2, "Grafo profundidade menor indice")
desenhar_grafo(dfs_tree_sorted, pos3, "Grafo profundidade maior indice")
desenhar_grafo(mst, pos4, "Árvore Geradora Mínima (Algoritmo de Prim)")