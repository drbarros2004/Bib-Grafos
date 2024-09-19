#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <fstream>
#include <list>
using namespace std;

// Funções de receber entrada

vector<vector<int>> txt_to_adjacency_matrix(const string& nome_arquivo, string nome_do_arquivo_de_saida = "resultados.txt");
vector<vector<int>> txt_to_adjacency_vector(const string& nome_arquivo, string nome_do_arquivo_de_saida = "resultados.txt");

// Funções para obter informações básicas do grafo (vetor de adjacência):

int minDegree(const vector<vector<int>>& grafo);
int maxDegree(const vector<vector<int>>& grafo);
double averageDegree(const vector<vector<int>>& grafo);
double medianDegree(const vector<vector<int>>& grafo);

void ComponentesConexas_vector(const vector<vector<int>>& graph);

// Funções para percorrer o grafo (vetor de adjacência):

void BFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");
void DFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");

void Distancia_vector(const vector<vector<int>>& graph, int origem, int destino);
void Diametro_vector(const vector<vector<int>>& graph);


// Funções para percorrer o grafo (matriz de adjacência):

void DFS_tree_matrix(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt");
void BFS_tree_matrix(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt");

#endif
