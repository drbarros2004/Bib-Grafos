# Biblioteca para manipulação de Grafos
Esse é o repositório para os trabalhos da disciplina Teoria dos Grafos (2024.2). Os trabalhos foram feitos por Daniel Barros e Pedro Cintra.

# Como utilizar a biblioteca?

Para utilizar a biblioteca, é necessário ter os arquivos `graph_lib.cpp` e `graph_lib.h` no mesmo repositório do arquivo que usará a biblioteca. Então, basta colocar 

```
#include "graph_lib.h"
```

no começo do arquivo para que o compilador reconheça de onde estão vindo as funções que serão utilizadas.

Para compilar, precisamos também explicitar o nome do arquivo ".cpp" que contém as funções da biblioteca.

```
g++ arquivo.cpp graph_lib.cpp -o
```

# Funções para receber entradas

Foram criadas 2 funções diferentes que recebem a string correspondente ao nome do arquivo de texto de entrada (ex.: `"grafo_teste.txt"`) e retornam o grafo em uma das duas representações pedidas (vetor de adjacência ou matriz de adjacência).

Quando qualquer uma das funções é chamada, é retornado um arquivo contendo algumas informações básicas sobre o grafo: número de vértices e arestas, grau máximo, grau mínimo, grau médio, mediana de grau e informações sobre componentes conexas.

1. `txt_to_adjacency_vector`
2. `txt_to_adjacency_matrix`

Ex.:

```
vector<vector<int>> grafo_teste = txt_to_adjacency_vector(nome_arquivo);
```

# Funções que geram árvores (BFS e DFS):

As funções a seguir percorrem o grafo através de uma Busca em Largura ou Busca em Profundidade a partir de um vértice escolhido pelo usuário e retornam um arquivo ".txt" contendo informações de nível e pai, representando a árvore relacionada à busca.

Por padrão (caso o usuário omita esse parâmetro), o nome do arquivo é "arvoreDFS.txt" ou "arvoreBFS.txt", mas o usuário pode passar a string correspondente ao nome do arquivo de saída como parâmetro para essas funções.

1. `BFS_tree_vector`
2. `DFS_tree_vector`
3. `BFS_tree_matrix`
4. `DFS_tree_matrix`

Ex.:

```
DFS_tree_vector(grafo_teste, 1, "arvoreDFS_grafo_teste.txt");
```

Ou, usando uma BFS para matriz de adjacência:

```
BFS_tree_vector(grafo_teste, 3, "arvoreBFS_grafo_teste.txt");
```

# Distância e Diâmetro:

Usando a Busca em Largura (BFS) como base, criamos a função Distancia, que calcula o comprimento do menor caminho entre dois vértices, e a função Diametro, que calcula a maior das menores distâncias entre dois vértices quaisquer de um grafo.

Novamente, implementamos essas duas funções para cada uma das representações possíveis.

ex.:

```
Diameter_vector(grafo_teste);
Distance_matrix(grafo_teste, 1, 3);
```

# Funções para cálculo de tempo de execução:

Por fim, modificamos um pouco as nossas funções de busca para retornarem o valor do tempo de execução do algoritmo. Essa parte está mais relacionada aos estudos de caso feitos no relatório.

Ex.:

1. `DFS_tree_vector_with_execution_time(grafo_teste, 1, "arvoreDFS_grafo_teste.txt")`
2. `BFS_tree_matrix_with_execution_time(grafo_teste, 3, "arvoreBFS_grafo_teste.txt")`


