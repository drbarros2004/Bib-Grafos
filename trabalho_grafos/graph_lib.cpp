#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

vector<vector<int>> txt_to_adjacency_vector(const string& nome_arquivo, string nome_do_arquivo_de_saida_principal = "resultados.txt") {

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

    // Função para calcular componentes conexas
    vector<vector<int>> componentes;
    vector<int> tamanhos;
    int quant_componentes = 0;
    vector<bool> visitados(graph.size(), false);
    queue<int> fila;
    int iterador = 0;

    for (int node = 1; node < graph.size(); node++) {
        if (!visitados[node]) {
            quant_componentes++;
            componentes.push_back(vector<int>()); 
            tamanhos.push_back(0); 
            fila.push(node);
            visitados[node] = true;
            componentes[iterador].push_back(node);
            tamanhos[iterador]++;

            while (!fila.empty()) {
                int atual = fila.front();
                fila.pop();

                for (int vizinho : graph[atual]) {
                    if (!visitados[vizinho]) {
                        fila.push(vizinho);
                        visitados[vizinho] = true;
                        componentes[iterador].push_back(vizinho);
                        tamanhos[iterador]++;
                    }
                }
            }
            iterador++;
        }
    }

    sort(componentes.begin(), componentes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() > b.size();
    });

    sort(tamanhos.begin(), tamanhos.end());
    reverse(tamanhos.begin(), tamanhos.end());

    // Gravar os resultados no arquivo de saída no modo append (adiciona ao final do arquivo)
    ofstream arquivo_de_saida(nome_do_arquivo_de_saida_principal, std::ios::app);

    if (arquivo_de_saida.is_open()) {
        arquivo_de_saida << "Número de vértices: " << numVertices << endl;
        arquivo_de_saida << "Número de arestas: " << numArestas << endl;
        arquivo_de_saida << "Grau mínimo: " << minDegree << endl;
        arquivo_de_saida << "Grau máximo: " << maxDegree << endl;
        arquivo_de_saida << "Grau médio: " << averageDegree << endl;
        arquivo_de_saida << "Mediana de grau: " << medianDegree << '\n' << endl;

        // Adicionar os resultados das componentes conexas
        arquivo_de_saida << "Número de componentes conexas: " << quant_componentes << endl << endl;
        for (int j = 0; j < tamanhos.size(); j++) {
            arquivo_de_saida << "Componente " << j + 1 << " tem " << tamanhos[j] << " vértices, e eles são: " << endl;
            for (int i = 0; i < componentes[j].size(); i++) {
                arquivo_de_saida << componentes[j][i] << " ";
            }
            arquivo_de_saida << endl << endl << endl;
        }

        arquivo_de_saida.close();
        cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida_principal << endl;
    } else {
        cout << "Erro ao abrir o arquivo de resultados!" << endl;
    }

        return graph;
}


void BFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt"){
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

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < graph.size(); i++){
        arquivo_de_saida  << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
    }

    cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

}

double BFS_tree_vector_with_execution_time(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt"){
    using namespace std::chrono; 
    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    queue <int> fila;

    auto inicio = high_resolution_clock::now();

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

    auto fim = high_resolution_clock::now(); // fim do algoritmo

    duration<double> tempo_execucao = fim - inicio;

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < graph.size(); i++){
        if (nivel[i] != INF) {
            arquivo_de_saida  << "Vértice: " << i << endl;
            arquivo_de_saida << "Nível: " << nivel[i] << endl;
            arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
        }
    }

    //cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

    return tempo_execucao.count();

}


void DFS_tree_vector(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt") {
    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    stack<int> pilha;

    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    pilha.push(origem);

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();
        for (int vizinho : graph[atual]) {
            if (!visitados[vizinho]) {
                pilha.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }
    }

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);

    for (int i = 1; i < graph.size(); i++) {

        arquivo_de_saida << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
        
    }

    arquivo_de_saida.close();
    
    cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;

}

double DFS_tree_vector_with_execution_time(const vector<vector<int>>& graph, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt") {
    using namespace std::chrono; 

    int INF = 1e9;
    vector<int> nivel(graph.size(), INF);
    vector<int> pai(graph.size(), INF);
    vector<bool> visitados(graph.size(), false);
    stack<int> pilha;
    
    auto inicio = high_resolution_clock::now(); // início do algoritmo

    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    pilha.push(origem);

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();
        for (int vizinho : graph[atual]) {
            if (!visitados[vizinho]) {
                pilha.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }
    }


    auto fim = high_resolution_clock::now(); // fim do algoritmo

    duration<double> tempo_execucao = fim - inicio;

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);

    for (int i = 1; i < graph.size(); i++) {
        arquivo_de_saida << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';

    }

    arquivo_de_saida.close();
    
   // cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    return tempo_execucao.count();

}

int Diametro_aproximado_vector(const vector<vector<int>>& graph){
    int max_distancia = 0;
    for(int i = 0; i < 9; i ++){
        vector<int> dist(graph.size(), -1);
        int origem = rand() % graph.size();
        dist[origem] = 0;
        queue <int> fila;
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
                    }
                }       
            }       
        }  
    }
    cout << "Diametro do grafo aproximado: " << max_distancia << endl;
}


int Diametro_vector(const vector<vector<int>>& graph){

    if(graph.size() >= 50000){
        return Diametro_aproximado_vector(graph);
    }
    else{
        int max_distancia = 0;
        for(int i = 1; i < graph.size(); i ++){
            vector<int> dist(graph.size(), -1);
            int origem = i;
            dist[origem] = 0;
            queue <int> fila;
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
                        }
                    }       
                }       
            }  
        }
        cout << "Diametro do grafo: " << max_distancia << endl;
    }
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
                    cout << "A distancia entre " << origem << " e " << destino << " igual a: " << distancia << endl;
                    return;
                }
            }       
        }       
    }
    cout << "Impossivel ligar os vertices "  << origem << " e " << destino << "." << endl;
} 


vector<vector<bool>> txt_to_adjacency_matrix(const string& nome_arquivo, string nome_do_arquivo_de_saida_principal = "resultados.txt") {
    
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
    vector<vector<bool>> matrix(numVertices + 1, vector<bool>(numVertices + 1, false));

    // Ler as arestas e preencher a matriz de adjacência
    while (arquivo >> u >> v) {
        matrix[u][v] = true;  
        matrix[v][u] = true; 

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

    // Função para calcular componentes conexas
    vector<vector<int>> componentes;
    vector<int> tamanhos;
    int quant_componentes = 0;
    vector<bool> visitados(matrix.size(), false);
    queue<int> fila;
    int iterador = 0;

    for (int node = 1; node < matrix.size(); node++) {
        if (!visitados[node]) {
            quant_componentes++;
            componentes.push_back(vector<int>()); 
            tamanhos.push_back(0); 
            fila.push(node);
            visitados[node] = true;
            componentes[iterador].push_back(node);
            tamanhos[iterador]++;

            while (!fila.empty()) {
                int atual = fila.front();
                fila.pop();

                for (int vizinho = 1; vizinho < matrix.size(); vizinho++) {
                    if (matrix[atual][vizinho] && !visitados[vizinho]) {
                        fila.push(vizinho);
                        visitados[vizinho] = true;
                        componentes[iterador].push_back(vizinho);
                        tamanhos[iterador]++;
                    }
                }
            }
            iterador++;
        }
    }

    sort(componentes.begin(), componentes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() > b.size();
    });

    sort(tamanhos.begin(), tamanhos.end());
    reverse(tamanhos.begin(), tamanhos.end());

    // Gravar os resultados no arquivo de saída
    ofstream arquivo_de_saida(nome_do_arquivo_de_saida_principal, std::ios::app);

    if (arquivo_de_saida.is_open()) {
        arquivo_de_saida << "Número de vértices: " << numVertices << endl;
        arquivo_de_saida << "Número de arestas: " << numArestas << endl;
        arquivo_de_saida << "Grau mínimo: " << minDegree << endl;
        arquivo_de_saida << "Grau máximo: " << maxDegree << endl;
        arquivo_de_saida << "Grau médio: " << averageDegree << endl;
        arquivo_de_saida << "Mediana de grau: " << medianDegree << endl;

        // Adicionar os resultados das componentes conexas
        arquivo_de_saida << "Número de componentes conexas: " << quant_componentes << endl << endl;
        for (int j = 0; j < tamanhos.size(); j++) {
            arquivo_de_saida << "Componente " << j + 1 << " tem " << tamanhos[j] << " vértices, e eles são: " << endl;
            for (int i = 0; i < componentes[j].size(); i++) {
                arquivo_de_saida << componentes[j][i] << " ";
            }
            arquivo_de_saida << endl << endl << endl;

        }

        arquivo_de_saida.close(); 
        cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida_principal << endl;
    } else {
        cout << "Erro ao abrir o arquivo de resultados!" << endl;
    }

    return matrix;
}

void BFS_tree_matrix(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt"){
    int INF = 1e9;
    vector<int> nivel(matrix.size(), INF);
    vector<int> pai(matrix.size(), INF);
    vector<bool> visitados(matrix.size(), false);
    queue <int> fila;
    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    fila.push(origem);
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        for(int vizinho = 1; vizinho < matrix.size(); vizinho ++){
            if(matrix[atual][vizinho] == 1 & !visitados[vizinho]){
                fila.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }      
    }

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < matrix.size(); i++){
        arquivo_de_saida  << "Vértice: " << i << endl;
        arquivo_de_saida << "Nível: " << nivel[i] << endl;
        arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
    }

    cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

}

double BFS_tree_matrix_with_execution_time(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreBFS.txt"){
    using namespace std::chrono;

    int INF = 1e9;
    vector<int> nivel(matrix.size(), INF);
    vector<int> pai(matrix.size(), INF);
    vector<bool> visitados(matrix.size(), false);
    queue <int> fila;

    auto inicio = high_resolution_clock::now();

    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    fila.push(origem);
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        for(int vizinho = 1; vizinho < matrix.size(); vizinho ++){
            if(matrix[atual][vizinho] == 1 & !visitados[vizinho]){
                fila.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }      
    }

    auto fim = high_resolution_clock::now(); // fim do algoritmo

    duration<double> tempo_execucao = fim - inicio;

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < matrix.size(); i++){
        
            arquivo_de_saida  << "Vértice: " << i << endl;
            arquivo_de_saida << "Nível: " << nivel[i] << endl;
            arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';
    }


    //cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

    return tempo_execucao.count();

}

void DFS_tree_matrix(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt"){
    int INF = 1e9;
    vector<int> nivel(matrix.size(), INF);
    vector<int> pai(matrix.size(), INF);
    vector<bool> visitados(matrix.size(), false);
    stack <int> pilha;
    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    pilha.push(origem);
    while(!pilha.empty()){
        int atual = pilha.top();
        pilha.pop();
        for(int vizinho = 1; vizinho < matrix.size(); vizinho ++){
            if(matrix[atual][vizinho] == 1 & !visitados[vizinho]){
                pilha.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }      
    }

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < matrix.size(); i++){
        if (nivel[i] != 1e9) {

            arquivo_de_saida  << "Vértice: " << i << endl;
            arquivo_de_saida << "Nível: " << nivel[i] << endl;
            arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';

        }
    }

    cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

}

double DFS_tree_matrix_with_execution_time(const vector<vector<bool>>& matrix, int origem, string nome_do_arquivo_de_saida = "arvoreDFS.txt"){
    using namespace std::chrono;

    int INF = 1e9;
    vector<int> nivel(matrix.size(), INF);
    vector<int> pai(matrix.size(), INF);
    vector<bool> visitados(matrix.size(), false);
    stack <int> pilha;

    auto inicio = high_resolution_clock::now(); // início do algoritmo


    visitados[origem] = true;
    nivel[origem] = 0;
    pai[origem] = -1;
    pilha.push(origem);
    while(!pilha.empty()){
        int atual = pilha.top();
        pilha.pop();
        for(int vizinho = 1; vizinho < matrix.size(); vizinho ++){
            if(matrix[atual][vizinho] && !visitados[vizinho]){
                pilha.push(vizinho);
                visitados[vizinho] = true;
                nivel[vizinho] = nivel[atual] + 1;
                pai[vizinho] = atual;
            }
        }      
    }

    auto fim = high_resolution_clock::now(); // fim do algoritmo

    duration<double> tempo_execucao = fim - inicio;

    ofstream arquivo_de_saida(nome_do_arquivo_de_saida);
    
    for(int i = 1; i < matrix.size(); i++){
        if (nivel[i] != 1e9) {

            arquivo_de_saida  << "Vértice: " << i << endl;
            arquivo_de_saida << "Nível: " << nivel[i] << endl;
            arquivo_de_saida << "Pai: " << pai[i] << '\n' << '\n';

        }
    }

    //cout << "Resultados gravados no arquivo " << nome_do_arquivo_de_saida << endl;
    arquivo_de_saida.close();

    return tempo_execucao.count();

}

int Diametro_aproximado_matrix(const vector<vector<bool>>& matrix){
    int max_distancia = 0;
    for(int i = 0; i < 9; i ++){
        vector<int> dist(matrix.size(), -1);
        int origem = rand() % matrix.size();
        dist[origem] = 0;
        queue <int> fila;
        fila.push(origem);
        while(!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            for(int vizinho = 1; vizinho < matrix.size(); vizinho++){
                if(matrix[atual][vizinho] && dist[vizinho] == -1){
                    dist[vizinho] = dist[atual] + 1;
                    fila.push(vizinho);
                    if (dist[vizinho] > max_distancia) {
                        max_distancia = dist[vizinho];
                    }
                }       
            }       
        }  
    }
    cout << "Diametro do grafo aproximado: " << max_distancia << endl;
}
 

int Diametro_matrix(const vector<vector<bool>>& matrix){

    if(matrix.size() >= 50000){
        return Diametro_aproximado_matrix(matrix);
    }
    else{
        int max_distancia = 0;
        for(int i = 1; i < matrix.size(); i ++){
            vector<int> dist(matrix.size(), -1);
            int origem = i;
            dist[origem] = 0;
            queue <int> fila;
            fila.push(origem);
            while(!fila.empty()) {
                int atual = fila.front();
                fila.pop();
                for(int vizinho = 1; vizinho < matrix.size(); vizinho++){
                    if(matrix[atual][vizinho] && dist[vizinho] == -1){
                        dist[vizinho] = dist[atual] + 1;
                        fila.push(vizinho);
                        if (dist[vizinho] > max_distancia) {
                            max_distancia = dist[vizinho];
                        }
                    }       
                }       
            }  
        }
        cout << "Diametro do grafo: " << max_distancia << endl;
    }
}


void Distancia_matrix(const vector<vector<bool>>& matrix, int origem, int destino){
    vector<int> dist(matrix.size(), -1);
    vector<bool> visitados(matrix.size(), false);
    queue <int> fila;
    int distancia = -1;
    visitados[origem] = true;
    dist[origem] = 0;
    fila.push(origem);
    while(!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for(int vizinho = 1; vizinho < matrix.size(); vizinho++){
            if(matrix[atual][vizinho] && !visitados[vizinho]){
                fila.push(vizinho);
                visitados[vizinho] = true;
                dist[vizinho] = dist[atual] + 1;
                if(vizinho == destino){   
                    distancia = dist[vizinho];
                    cout << "A distancia entre " << origem << " e " << destino << " igual a: " << distancia << endl; 
                    return;
                }
            }       
        }       
    }
    cout << "Impossivel ligar os vertices " << origem << " e " << destino << "." << endl;
} 

