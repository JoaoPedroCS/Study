library(igraph)

# Caminho para o arquivo GML
caminho_arquivo <- "alista3/11202321597-lista3.gml"

# Ler o arquivo GML
g <- read_graph(caminho_arquivo, format = "graphml")

# Calcular as métricas individuais
clustering_coeff <- transitivity(grafo, type = "local")
closeness_centrality <- closeness(grafo)
degree_centrality <- degree(grafo)
eccentricity <- eccentricity(grafo)

# Combinar as métricas em um data frame
metrics <- data.frame(
  ClusteringCoefficient = clustering_coeff,
  ClosenessCentrality = closeness_centrality,
  DegreeCentrality = degree_centrality,
  Eccentricity = eccentricity
)

# Calcular os coeficientes de correlação entre os pares de métricas
corr_clustering_closeness <- cor(metrics$ClusteringCoefficient, metrics$ClosenessCentrality, use = "complete.obs")
corr_clustering_degree <- cor(metrics$ClusteringCoefficient, metrics$DegreeCentrality, use = "complete.obs")
corr_clustering_eccentricity <- cor(metrics$ClusteringCoefficient, metrics$Eccentricity, use = "complete.obs")
corr_closeness_degree <- cor(metrics$ClosenessCentrality, metrics$DegreeCentrality, use = "complete.obs")
corr_closeness_eccentricity <- cor(metrics$ClosenessCentrality, metrics$Eccentricity, use = "complete.obs")
corr_degree_eccentricity <- cor(metrics$DegreeCentrality, metrics$Eccentricity, use = "complete.obs")

# Exibir os coeficientes de correlação
correlation_results <- data.frame(
  Pairs = c("Clustering vs Closeness", "Clustering vs Degree", "Clustering vs Eccentricity",
            "Closeness vs Degree", "Closeness vs Eccentricity", "Degree vs Eccentricity"),
  Correlation = c(corr_clustering_closeness, corr_clustering_degree, corr_clustering_eccentricity,
                  corr_closeness_degree, corr_closeness_eccentricity, corr_degree_eccentricity)
)

print(correlation_results)