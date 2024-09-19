#include <bits/stdc++.h>
#include "graph_lib.h"
typedef long long ll;
using namespace std;

int main() {

    string nome_arquivo = "grafo_teste.txt";
    vector<vector<int>> grafo = txt_to_adjacency_matrix(nome_arquivo);

    DFS_tree_matrix(grafo, 1, "arvoreBFS_matrix.txt");
    // ComponentesConexas_vector(grafo);
    // Distancia_vector(grafo, 1, 3);
    // Diametro_vector(grafo);

    return 0;

    //  g++ teste.cpp graph_lib.cpp -o output
    // ./output.exe

}
