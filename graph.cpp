#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// gerar_saida     (falta transformar em função e colocar informações de componentes conexos)
     // falta mediana de grau

// gerar_arvore_bfs   (é atualmente a bfs detalhada)
// gerar_arvore_dfs

// podemos codar bfs e dfs sem saída, porque provavelmente vai ser usado
// distancia (u, v)
// diametro (g)

// int quant_arestas(vector<vector<int>>& grafo){
//     int quant_arestas = 0;
    
// }

// Funções para receber o grafo:

vector<vector<int>> txt_to_adjacency_vector(const string& nome_arquivo, string nome_do_arquivo_de_saida = "resultados.txt") {

    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo de entrada!");
    }

    int numVertices, numArestas, u, v, degreeSum;
    arquivo >> numVertices;
    numArestas = 0;
    degreeSum = 0;
    vector<int> degrees(numVertices + 1, 0);

    vector<vector<int>> graph(numVertices + 1); 

    while (arquivo >> u >> v) {
        graph[u].push_back(v);
        graph[v].push_back(u);

        numArestas++;
        degrees[u]++;
        degrees[v]++;
        degreeSum += 2;
    }

    arquivo.close();

    // Ordenar os graus
    sort(degrees.begin() + 1, degrees.end());

    // Encontrar grau máximo, mínimo e calcular estatísticas
    int maxDegree = degrees[numVertices];
    int minDegree = degrees[1];
    double averageDegree = static_cast<double>(degreeSum) / numVertices;
    double medianDegree;

    // Calcular a mediana do grau
    if (numVertices % 2 == 0) {
        medianDegree = (degrees[numVertices / 2] + degrees[(numVertices / 2) + 1]) / 2.0;
    } else {
        medianDegree = degrees[(numVertices + 1) / 2];
    }

    // Gravar os resultados no arquivo de saída
    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);

    if (arquivo_de_saida.is_open()) {
        arquivo_de_saida << "Número de vértices: " << numVertices << endl;
        arquivo_de_saida << "Número de arestas: " << numArestas << endl;
        arquivo_de_saida << "Grau mínimo: " << minDegree << endl;
        arquivo_de_saida << "Grau máximo: " << maxDegree << endl;
        arquivo_de_saida << "Grau médio: " << averageDegree << endl;
        arquivo_de_saida << "Mediana de grau: " << medianDegree << endl;
        arquivo_de_saida.close(); 
        cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    } else {
        cout << "Erro ao abrir o arquivo de resultados!" << endl;
    }


    return graph;
}

void BFS_tree_vector(const vector<vector<int>>& graph, int origem, ofstream& arquivo_de_saida){
    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    queue <int> fila;
    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    fila.push(origem);
    while(!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for(int vizinho : graph[atual]){
            if(!visitados[vizinho]){
                fila.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }       
        }       
    }   
    for(int i = 1; i < graph.size(); i++){
        arquivo_de_saida  << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
    }
    
} 

void DFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt"){
    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    stack <int> pilha;
    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    pilha.push(origem);
    while(!pilha.empty()){
        int atual = pilha.top();
        pilha.pop();
        for(int vizinho : graph[atual]){
            if(!visitados[vizinho]){
                pilha.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }      
    }

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < graph.size(); i++){
        arquivo_de_saida  << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
    }

    cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

}

void Diametro_vector(const vector<vector<int>>& graph){
    vector<int> dist(graph.size(), -1);
    queue <int> fila;
    int max_distancia = 0;
    int origem = 1;
    int vertice_mais_distante = origem;
    for(int i = 0; i < 2; i ++){
        fill(dist.begin(), dist.end(), -1);
        dist[origem] = 0;
        fila.push(origem);
        while(!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            for(int vizinho : graph[atual]){
                if(dist[vizinho] == -1){
                    dist[vizinho] = dist[atual] + 1;
                    fila.push(vizinho);
                    if (dist[vizinho] > max_distancia) {
                        max_distancia = dist[vizinho];
                        vertice_mais_distante = vizinho;
                    }
                }       
            }       
        }  
        origem = vertice_mais_distante;
    }
    cout << "O diâmetro do grafo é: " << max_distancia << endl;
}

void Distancia_vector(const vector<vector<int>>& graph, int origem, int destino){
    vector<int> dist(graph.size(), -1);
    vector<bool> visitados(graph.size(), false);
    queue <int> fila;
    int distancia = -1;
    visitados[origem] = true;
    dist[origem] = 0;
    fila.push(origem);
    while(!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for(int vizinho : graph[atual]){
            if(!visitados[vizinho]){
                fila.push(vizinho);
                visitados[vizinho] = true;
                dist[vizinho] = dist[atual] + 1;
                if(vizinho == destino){    
                    distancia = dist[vizinho];
                }
            }       
        }       
    }
    cout << "A distância entre " << origem << " e " << destino << " é: " << distancia << endl;
} 

// A PARTIR DAQUI É MATRIZ DE ADJACÊNCIA

vector<vector<int>> txt_to_adjacency_matrix(const string& nome_arquivo, string nome_do_arquivo_de_saida = "resultados.txt") {
    
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo de entrada!");
    }

    int numVertices, numArestas, u, v, degreeSum;
    
    // Ler o número de vértices
    arquivo >> numVertices;
    numArestas = 0;
    degreeSum = 0;

    // Inicializar o vetor de graus e a matriz de adjacência com base no número de vértices
    vector<int> degrees(numVertices + 1, 0);
    vector<vector<int>> matrix(numVertices + 1, vector<int>(numVertices + 1, 0));

    // Ler as arestas e preencher a matriz de adjacência
    while (arquivo >> u >> v) {
        matrix[u][v] = 1;  
        matrix[v][u] = 1; 

        numArestas++;
        degrees[u]++;
        degrees[v]++;
        degreeSum += 2;
    }

    arquivo.close();

    // Ordenar os graus
    sort(degrees.begin() + 1, degrees.end());

    // Encontrar grau máximo, mínimo e calcular estatísticas
    int maxDegree = degrees[numVertices];
    int minDegree = degrees[1];
    double averageDegree = static_cast<double>(degreeSum) / numVertices;
    double medianDegree;

    // Calcular a mediana do grau
    if (numVertices % 2 == 0) {
        medianDegree = (degrees[numVertices / 2] + degrees[(numVertices / 2) + 1]) / 2.0;
    } else {
        medianDegree = degrees[(numVertices + 1) / 2];
    }

    // Gravar os resultados no arquivo de saída
    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);

    if (arquivo_de_saida.is_open()) {
        arquivo_de_saida << "Número de vértices: " << numVertices << endl;
        arquivo_de_saida << "Número de arestas: " << numArestas << endl;
        arquivo_de_saida << "Grau mínimo: " << minDegree << endl;
        arquivo_de_saida << "Grau máximo: " << maxDegree << endl;
        arquivo_de_saida << "Grau médio: " << averageDegree << endl;
        arquivo_de_saida << "Mediana de grau: " << medianDegree << endl;
        arquivo_de_saida.close(); 
        cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    } else {
        cout << "Erro ao abrir o arquivo de resultados!" << endl;
    }

    arquivo_de_saida.close();

    return matrix;
}






int DFS(const vector<vector<int>>& graph, int origem){
    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    for(int vizinho : graph[origem]){
        if(!visitados[vizinho]){
            visitados[vizinho] = true;
            nivel[vizinho] = nivel[origem] + 1;
            pai[vizinho] = origem;
            return DFS(graph, vizinho);
        }
    }
}

