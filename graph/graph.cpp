#include <iostream>
#include <vector>
#include <queue>

class Graph{
    private:
        int num_vertices;
        std::vector<std::vector<int>> adj_list;
    
    public:
        Graph(int vertices): num_vertices(vertices){
            adj_list.resize(num_vertices);
        }

        void addEdge(int src, int dst);
        void printGraph() const;
        void Bfs(const int start_node);
        void Dfs(const int& vertex);
        void DfsHelper(const int& vertex, std::vector<bool>& visited);
};

void Graph::addEdge(int src, int dst){
    adj_list[src].push_back(dst);
    //adj_list[dst].push_back(src); // Remove this if you have directed graph.
}

void Graph::printGraph() const{

    for(int i = 0; i < num_vertices; i++){
        std::cout<<"Vertex "<<i<<":";
        for(auto& val: adj_list[i]){
            std::cout<<"-> "<<val;
        }
        std::cout<<"\n";
    }
}

void Graph::Bfs(const int start_node){

    std::vector<bool> visited(num_vertices, false);
    std::queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    int current;

    while(!q.empty()){
        current = q.front();
        std::cout<<current<<" ";
        q.pop();

        for(auto& vertex: adj_list[current]){
            if(visited[vertex] == false){
                q.push(vertex);
                visited[vertex] = true;
            }
        }
    }
    std::cout<<std::endl;
}
void Graph::Dfs(const int& vertex){
    std::vector<bool> visited(num_vertices, false);
    DfsHelper(vertex, visited);
    std::cout<<"\n";
}
void Graph::DfsHelper(const int& vertex, std::vector<bool>& visited){

    visited[vertex] = true;
    std::cout<<vertex<<" ";

    for(auto& v:adj_list[vertex]){
        if(visited[v] == false){
            DfsHelper(v, visited);
        }
    }
    
}

int main(){
    Graph* g = new Graph(5);

    g->addEdge(0,1);
    g->addEdge(0,4);
    g->addEdge(1,2);
    g->addEdge(1,3);
    g->addEdge(1,4);
    g->addEdge(2,3);
    g->addEdge(3,4);
    g->addEdge(4,2);

    g->printGraph();

    g->Bfs(0);

    g->Dfs(0);
    delete g;
}