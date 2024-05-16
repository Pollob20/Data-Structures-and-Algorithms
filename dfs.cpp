#include <iostream>
#include <vector>

using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adj_list;

    Graph(int num_of_vertices){
        this->vertices = num_of_vertices;
        adj_list.resize(num_of_vertices);
    }

    
};