library(igraph)

# Caminho para o arquivo GML
caminho_arquivo <- "C:/Users/joaoh/OneDrive/Documentos/Coding/CR/alista3/11202321629-lista3.gml"

# Ler o arquivo GML
g <- read_graph(caminho_arquivo, format = "graphml")

# Visualizar o grafo
num_vertices <- vcount(g)
top_20_percent <- round(0.20 * num_vertices)
vertex_degrees <- degree(g)
top_vertices <- order(vertex_degrees, decreasing = TRUE)[1:top_20_percent]

subgraph_g <- induced_subgraph(g, vids = top_vertices)

rich_club_coeff <- function(graph, vertex_set) {
  subgraph <- induced_subgraph(graph, vids = vertex_set)
  num_edges <- ecount(subgraph)
  num_vertices <- vcount(subgraph)
  if (num_vertices > 1) {
    possible_edges <- num_vertices * (num_vertices - 1) / 2
    return(num_edges / possible_edges)
  } else {
    return(NA)
  }
}

rich_club_value <- rich_club_coeff(g, top_vertices)


# Diâmetro
diametro <- diameter(g, directed = FALSE)

# Grau médio
grau_medio <- mean(degree(g))

# Densidade
densidade <- edge_density(g)

# Coeficiente de clusterização médio
coef_clusterizacao_medio <- transitivity(g, type = "average")

# Distância média
distancia_media <- mean_distance(g, directed = FALSE)

# Número de componentes conexas
componentes_conexas <- components(g)
num_componentes_conexas <- componentes_conexas$no

# Número de vértices da maior componente conexa
maior_componente <- which.max(componentes_conexas$csize)
num_vertices_maior_componente <- componentes_conexas$csize[maior_componente]

# Resultados
lista_resultados <- list(
  Diâmetro = diametro,
  "Grau Médio" = grau_medio,
  Densidade = densidade,
  "Coeficiente de Clusterização Médio" = coef_clusterizacao_medio,
  "Distância Média" = distancia_media,
  "Número de Componentes Conexas" = num_componentes_conexas,
  "Número de Vértices da Maior Componente Conexa" = num_vertices_maior_componente
)

lista_resultados
print(lista_resultados)
print("clube rico:")
print(rich_club_value)
#plot(g)
