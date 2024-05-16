#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
      int vertices;
      vector<vector<int>> adj_list;
public:
      Graph(int num_of_vertices){
            this->vertices = num_of_vertices;
            adj_list.resize(num_of_vertices);
      }

      void add_edge(int source, int destination){
            adj_list[source].push_back(destination);
            adj_list[destination].push_back(source);
      }

      void bfs(int source){
            vector<bool> visited(vertices, false);
            queue<int> q;

            q.push(source);
            visited[source] = true;

            while(!q.empty()){
                  int current = q.front();
                  q.pop();

                  cout << current << " ";
                  for(int neighbor : adj_list[current]){
                        if(!visited[neighbor]){
                              visited[neighbor] = true;
                              q.push(neighbor);
                        }
                  }        
            }
      }

      void print_graph(){
            for(int i = 0; i < adj_list.size(); i++){
                  cout << "list " << i << ": ";
                  for(auto j : adj_list[i]){
                        cout << j << " ";
                  }
                  cout << '\n';
            }
      }
};

int main(){
      Graph g(5);
      g.add_edge(0, 1);
      g.add_edge(0, 2);
      g.add_edge(1, 3);
      g.add_edge(3, 4);
      g.add_edge(2, 3);

      cout << "bfs traversal is: ";
      g.bfs(0);
      cout << '\n';
      g.print_graph();
      return 0;
}
