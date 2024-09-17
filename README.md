# Biblioteca para manipulação de Grafos
Esse é o repositório para os trabalhos da disciplina Teoria dos Grafos (2024.2). Os trabalhos foram feitos por Daniel Barros e Pedro Cintra.

# Como utilizar a biblioteca?

Para utilizar a biblioteca, é necessário ter os arquivos `graph_lib.cpp` e `graph_lib.h` no mesmo repositório do arquivo que usará a biblioteca. Então, basta colocar 

```
#include "graph.h"
```

no começo do arquivo para que o compilador reconheça de onde estão vindo as funções que serão utilizadas.

Para compilar, precisamos também explicitar o nome do arquivo ".cpp" que contém as funções da biblioteca.

```
g++ arquivo.cpp graph.cpp -o
```

# Funções para receber entradas

Foram criadas 2 funções diferentes que recebem a string correspondente ao nome do arquivo de texto (ex.: `"grafo_teste.txt"`) e retornam o grafo em uma das duas representações pedidas (vetor de adjacência e matriz de adjacência).

Quando qualquer uma das funções é chamada, é retornado um arquivo contendo algumas informações básicas sobre o grafo: número de vértices e arestas, grau máximo, grau mínimo, grau médio, mediana de grau e informações sobre componentes conexas.

1. `txt_to_adjacency_vector`
2. `txt_to_adjacency_matrix`

Ex.:

```
vector<vector<int>> grafo_teste = txt_to_adjacency_vector(nome_arquivo);
```

# Funções que geram árvores (BFS e DFS):

As funções a seguir percorrem o grafo através de uma Busca em Largura ou Busca em Profundidade e retornam um arquivo ".txt" contendo informações de nível e pai.

Por padrão (caso o usuário omita esse parâmetro), o nome do arquivo é "arvoreDFS.txt" ou "arvoreBFS.txt", mas o usuário pode passar o a string correspondente ao nome do arquivo de saída como parâmetro para essas funções.

1. `BFS_tree`
2. `DFS_tree`

Ex.:

```
DFS_tree(grafo_teste, 1, "arvoreDFS_grafo_teste.txt");
```

# Distância e Diâmetro:

Usando a Busca em Largura (BFS) como base, criamos a função Distancia, que calcula o comprimento do menor caminho entre dois vértices, e a função Diametro, que calcula a maior das menores distâncias entre dois vértices quaisquer de um grafo.

ex.:

```
Diametro(grafo_teste);
Distancia(grafo_teste, 1, 3);
```


