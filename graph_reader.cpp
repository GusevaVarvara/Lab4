#include <iostream>
#include <fstream>
#include <vector>
#include "graph_reader.h"

std::vector<std::vector<int>> readGraph(const std::string& filename, int& V, int& E) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    file >> V >> E; 

    std::vector<std::vector<int>> adjacencyMatrix(V, std::vector<int>(V, 0));

    int u, v;
    for (int i = 0; i < E; ++i) {
        file >> u >> v;
      
        adjacencyMatrix[u - 1][v - 1] = 1; 
        adjacencyMatrix[v - 1][u - 1] = 1; 
    }

    file.close();

    return adjacencyMatrix;
}

