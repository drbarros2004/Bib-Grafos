#include <bits/stdc++.h>
#include "graph_lib.h"
#include <chrono>
typedef long long ll;
using namespace std;

using namespace std;

int main() {

  // Vai comentando e descomentando de acordo com o teste que está sendo feito.

    string nome_arquivo = "grafo_1.txt";
    
    // vector<vector<int>> grafo1_vector = txt_to_adjacency_vector(nome_arquivo);

    vector<vector<int>> grafo1_matrix = txt_to_adjacency_matrix(nome_arquivo);


    // SEÇÃO DOS TESTES DE TEMPO DE EXECUÇÃO:


    // // Teste de tempo da DFS (vetor):

    // double tempo_total_dfs_vector = 0;
    
    // srand(time(0));  

    // for (int i = 0; i < 100; i++) {
    //     tempo_total_dfs_vector += DFS_tree_vector_with_execution_time(grafo1_vector, rand() % grafo1_vector.size());
    // }

    // double tempo_medio_dfs_vector = tempo_total_dfs_vector / 100;
    // cout << "Tempo medio da DFS (vetor): " << tempo_medio_dfs_vector << endl;






    // // Teste de tempo da BFS (vetor):

    // double tempo_total_bfs_vector = 0;

    // for (int i = 0; i < 100; i++) {
    //     tempo_total_bfs_vector += BFS_tree_vector_with_execution_time(grafo1_vector, rand() % grafo1_vector.size());
    // }

    // double tempo_medio_bfs_vector = tempo_total_bfs_vector / 100;
    // cout << "Tempo medio da BFS (vetor): " << tempo_medio_bfs_vector << endl;





    // // Teste de tempo da BFS (matriz):

    // double tempo_total_bfs_matrix = 0;
    
    // srand(time(0)); 

    // for (int i = 0; i < 100; i++) {
    //     tempo_total_bfs_matrix += BFS_tree_matrix_with_execution_time(grafo1_matrix, rand() % grafo1_matrix.size());
    // }

    // double tempo_medio_bfs_matrix = tempo_total_bfs_matrix / 100;
    // cout << "Tempo medio da BFS matriz: " << tempo_medio_bfs_matrix << endl;





    // Tempo total da DFS (matriz):

    double tempo_total_dfs_matrix = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dfs_matrix += DFS_tree_matrix_with_execution_time(grafo1_matrix, rand() % grafo1_matrix.size());
    }

    double tempo_medio_dfs_matrix = tempo_total_dfs_matrix / 100;
    cout << "Tempo medio da DFS (vetor): " << tempo_medio_dfs_matrix << endl;

    return 0;
}
