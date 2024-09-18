#include <bits/stdc++.h>
#include "graph.h"
typedef long long ll;
using namespace std;

int main() {

    string nome_arquivo = "grafo_teste.txt";
    vector<vector<int>> grafo = txt_to_adjacency_vector(nome_arquivo);

    DFS_tree_vector(grafo, 1);
    Distancia_vector(grafo, 1, 3);
    Diametro_vector(grafo);

    return 0;

    //  g++ file_name.cpp
    // ./a.exe

}