import networkx as nx
import matplotlib.pyplot as plt

def plot_graph_from_adjacency_matrix(adj_matrix):
    G = nx.Graph()
    num_nodes = len(adj_matrix)
    
    for i in range(num_nodes):
        for j in range(num_nodes):
            if adj_matrix[i][j] != 0:
                G.add_edge(i, j)
    
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=700, edge_color='gray')
    plt.show()

    return G

def calculate_average_degree(G):
    degrees = [degree for node, degree in G.degree()]
    average_degree = sum(degrees) / len(degrees)
    return average_degree

def find_eulerian_path_or_circuit(G):
    if nx.is_eulerian(G):
        print("O grafo possui um ciclo euleriano.")
        eulerian_circuit = list(nx.eulerian_circuit(G))
        print("Ciclo euleriano:", eulerian_circuit)
    elif nx.has_eulerian_path(G):
        print("O grafo possui um caminho euleriano.")
        eulerian_path = list(nx.eulerian_path(G))
        print("Caminho euleriano:", eulerian_path)
    else:
        print("O grafo não possui um caminho ou ciclo euleriano.")


adj_matrix = [
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
    [0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
    [0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0],
    [0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1],
    [0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0],
    [0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1],
    [0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0],
    [0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0],
    [0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0],
    [1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0],
    [0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1],
    [0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0],
]

graph = plot_graph_from_adjacency_matrix(adj_matrix)
diameter = nx.diameter(graph)
numberoe = graph.number_of_edges()
num_vertices = graph.number_of_nodes()
average_degree = calculate_average_degree(graph)
print(f"O diâmetro do grafo é: {diameter}, a ordem é {num_vertices}, o tamanho é {numberoe}, e o grau medio é {average_degree}")
find_eulerian_path_or_circuit(graph)