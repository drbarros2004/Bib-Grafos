#include <bits/stdc++.h>
#include "graph_lib.h"
#include <chrono>
using namespace std;

int main() {

    string nome_arquivo = "grafo_6.txt";
    string saida_arquivo = "estudo_de_caso6_vector.txt";
    string saida_arquivo_2 = "estudo_de_caso6_matriz.txt";

    vector<vector<int>> grafo6_vector = txt_to_adjacency_vector(nome_arquivo, saida_arquivo);

    // SEÇÃO DOS TESTES DE TEMPO DE EXECUÇÃO:

    // Abra o arquivo no modo append para garantir que ele não seja sobrescrito
    ofstream arquivo_de_saida(saida_arquivo, std::ios::app);

    // Verifique se o arquivo foi aberto corretamente
    if (!arquivo_de_saida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }

    // Teste de tempo da DFS (vetor):
    double tempo_total_dfs_vector = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dfs_vector += DFS_tree_vector_with_execution_time(grafo6_vector, rand() % grafo6_vector.size());
    }

    double tempo_medio_dfs_vector = tempo_total_dfs_vector / 100;
    arquivo_de_saida << "Tempo medio da DFS (vetor): " << tempo_medio_dfs_vector << endl;

    // Teste de tempo da BFS (vetor):
    double tempo_total_bfs_vector = 0;

    for (int i = 0; i < 100; i++) {
        tempo_total_bfs_vector += BFS_tree_vector_with_execution_time(grafo6_vector, rand() % grafo6_vector.size());
    }

    double tempo_medio_bfs_vector = tempo_total_bfs_vector / 100;
    arquivo_de_saida << "Tempo medio da BFS (vetor): " << tempo_medio_bfs_vector << endl;

    BFS_tree_vector(grafo6_vector, 1, "arvoreBFS_1.txt");
    BFS_tree_vector(grafo6_vector, 2, "arvoreBFS_2.txt");
    BFS_tree_vector(grafo6_vector, 3, "arvoreBFS_3.txt");
    DFS_tree_vector(grafo6_vector, 1, "arvoreDFS_1.txt");
    DFS_tree_vector(grafo6_vector, 2, "arvoreDFS_2.txt");
    DFS_tree_vector(grafo6_vector, 3, "arvoreDFS_3.txt");

    // Distâncias e diâmetros:

    Distancia_vector(grafo6_vector, 10, 20);
    Distancia_vector(grafo6_vector, 10, 30);
    Distancia_vector(grafo6_vector, 20, 30);
    Diametro_vector(grafo6_vector);

    // Desalocar o grafo6_vector
    grafo6_vector = vector<vector<int>>();
    arquivo_de_saida.close();

    // Converte a matriz para o próximo teste
    vector<vector<bool>> grafo6_matrix = txt_to_adjacency_matrix(nome_arquivo, saida_arquivo_2);

    // Teste de tempo da BFS (matriz):
    double tempo_total_bfs_matrix = 0;

    ofstream arquivo_de_saida_2(saida_arquivo_2, std::ios::app);
    
    srand(time(0)); 

    for (int i = 0; i < 100; i++) {
        tempo_total_bfs_matrix += BFS_tree_matrix_with_execution_time(grafo6_matrix, rand() % grafo6_matrix.size());
    }

    double tempo_medio_bfs_matrix = tempo_total_bfs_matrix / 100;
    arquivo_de_saida_2 << "Tempo medio da BFS (matriz): " << tempo_medio_bfs_matrix << endl;

    // Teste de tempo da DFS (matriz):
    double tempo_total_dfs_matrix = 0;
    
    srand(time(0));  

    for (int i = 0; i < 100; i++) {
        tempo_total_dfs_matrix += DFS_tree_matrix_with_execution_time(grafo6_matrix, rand() % grafo6_matrix.size());
    }

    double tempo_medio_dfs_matrix = tempo_total_dfs_matrix / 100;
    arquivo_de_saida_2 << "Tempo medio da DFS (matrix): " << tempo_medio_dfs_matrix << endl;

    // Fechar o arquivo após escrever todas as informações
    arquivo_de_saida_2.close();

    return 0;
}