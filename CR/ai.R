

# Carregar o pacote
library(igraph)

# Carregar o grafo no formato GML
grafo <- read_graph("alunos-cr.gml", format = "graphml")
# Definir as cores dos vértices com base no grupo
V(grafo)$color <- ifelse(V(grafo)$grupo == 1, "red", 
                         ifelse(V(grafo)$grupo == 2, "blue", "green"))

# Definir tamanho dos vértices e rótulos (vértices menores)
V(grafo)$size <- 3
V(grafo)$label <- V(grafo)$ra
V(grafo)$label.cex <- 0.3  # Tamanho do rótulo menor para ajustar à imagem

# Definir tamanho das arestas (linhas mais finas)
E(grafo)$width <- 0.2

# Salvar o grafo como uma imagem PNG de alta resolução
png("grafo_amizades_10000x10000.png", width = 15000, height = 15000)
plot(grafo, main = "Grafo de Amizades/Colaborações dos Alunos")
dev.off()