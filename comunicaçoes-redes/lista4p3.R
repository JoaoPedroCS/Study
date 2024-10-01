# Instalar o pacote igraph, se necessário
install.packages("igraph")

# Carregar o pacote
library(igraph)

# Carregar o grafo no formato GML
grafo <- read_graph("alunos-cr.gml", format = "graphml")

# Identificar o número de amigos/colaboradores (grau) para o seu RA
meu_ra <- "11202321597"
meu_vertice <- V(grafo)[V(grafo)$ra == meu_ra]
meu_grau <- degree(grafo, v = meu_vertice)

# Identificar o RA do amigo com maior número de amigos/colaboradores
amigos <- neighbors(grafo, meu_vertice)
graus_amigos <- degree(grafo, v = amigos)
maior_amigo <- amigos[which.max(graus_amigos)]
ra_maior_amigo <- V(grafo)[maior_amigo]$ra

# Identificar o RA do aluno do grupo 3 com maior número de amigos/colaboradores
grupo_3 <- V(grafo)[V(grafo)$grupo == 3]
graus_grupo_3 <- degree(grafo, v = grupo_3)
maior_grupo_3 <- grupo_3[which.max(graus_grupo_3)]
ra_maior_grupo_3 <- V(grafo)[maior_grupo_3]$ra

# Determinar o grupo do amigo com maior número de amigos/colaboradores
grupo_maior_amigo <- V(grafo)[maior_amigo]$grupo

# Calcular a distância entre você e o aluno com RA 11111111
ra_alvo <- "11111111"
vertice_alvo <- V(grafo)[V(grafo)$ra == ra_alvo]
distancia <- distances(grafo, v = meu_vertice, to = vertice_alvo)

# Calcular o coeficiente de clusterização para o seu RA
coef_clusterizacao <- transitivity(grafo, type = "local", vids = meu_vertice)

# Verificar se os alunos com RA 44444444 e 55555555 se conhecem
ra1 <- "44444444"
ra2 <- "55555555"
vertice1 <- V(grafo)[V(grafo)$ra == ra1]
vertice2 <- V(grafo)[V(grafo)$ra == ra2]
conhecem <- are.connected(grafo, vertice1, vertice2)

# Calcular o grau médio dos alunos do grupo 2
grupo_2 <- V(grafo)[V(grafo)$grupo == 2]
grau_medio_grupo_2 <- mean(degree(grafo, v = grupo_2))

# Exibir os resultados
resultados <- list(
  "Meu Grau" = meu_grau,
  "RA do Amigo com Maior Grau" = ra_maior_amigo,
  "RA do Aluno do Grupo 3 com Maior Grau" = ra_maior_grupo_3,
  "Grupo do Amigo com Maior Grau" = grupo_maior_amigo,
  "Distância para RA 11111111" = distancia,
  "Coeficiente de Clusterização" = coef_clusterizacao,
  "RA 44444444 e 55555555 se Conhecem" = conhecem,
  "Grau Médio do Grupo 2" = grau_medio_grupo_2
)

print(resultados)