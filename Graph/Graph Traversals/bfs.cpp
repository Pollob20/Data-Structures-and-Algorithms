#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int vertices;                      // Number of vertices
    vector<vector<int>> adj_list;      // Adjacency list

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int num_of_vertices) {
        this->vertices = num_of_vertices;
        adj_list.resize(num_of_vertices);
    }

    // Method to add an edge to the graph (undirected)
    void add_edge(int source, int destination) {
        adj_list[source].push_back(destination);
        adj_list[destination].push_back(source);
    }

    // BFS traversal method starting from a given source vertex
    void bfs(int source) {
        vector<bool> visited(vertices, false); // Track visited nodes
        queue<int> q;                          // Queue for BFS

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " "; // Process current node
            for (int neighbor : adj_list[current]) {
                if (!visited[neighbor]) { // Visit unvisited neighbors
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Method to print the adjacency list of the graph
    void print_graph() {
        for (int i = 0; i < adj_list.size(); i++) {
            cout << "list " << i << ": ";
            for (auto j : adj_list[i]) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(3, 4);
    g.add_edge(2, 3);

    cout << "bfs traversal is: ";
    g.bfs(0);  // Perform BFS starting from vertex 0
    cout << '\n';
    g.print_graph(); // Print the graph's adjacency list

    return 0;
}
