# Biblioteca para mainpulação de Grafos
Esse é o repositório para os trabalhos da disciplina Teoria dos Grafos (2024.2). Os trabalhos foram feitos por Daniel Barros e Pedro Cintra.

# Como utilizar a biblioteca?

Para utilizar a biblioteca, é necessário ter os arquivos "graph_lib.cpp" e "graph_lib.h" no mesmo repositório do arquivo que usará a biblioteca. Então, basta colocar "#include "graph.h"" no começo do arquivo para que o compilador reconheça de onde estão vindo as funções que serão utilizadas.



# Funções para receber entradas

Foram criadas 3 funções diferentes que recebem a string correspondente ao nome do arquivo de texto (ex.: "grafo_teste.txt") e retornam o grafo em uma das 3 representações pedidas (vetor de adjacência, lista de adjacência e matriz de adjacência).

1. txt_to_adjacency_list
2. txt_to_adjacency_matrix
3. txt_to_adjacencty_vector


# Funções para obter informações sobre o grafo

Cada uma dessas funções é implementada 3 vezes no arquivo que contém as funções (uma para cada representação possível para o grafo). Nós utilizamos da sobrecarga de funções em C++ (funções podem ter o mesmo nome, desde que tenham diferenças nasquantidades ou tipos dos parâmetros) para que as funções de mesmo objetivo tivessem o mesmo nome, independente da representação.

1. minDegree
2. maxDegree
3. averageDegree
4. medianDegree
5. 


