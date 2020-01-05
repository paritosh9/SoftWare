#include <iostream>
#include <list>
#include <iterator>
#include "graph.cpp"
using namespace std;


// Method for traversing BFS (Breadth First Search)
void Graph::BFS(int startVertex) {
    bool *visited_vertices = new bool [numVertices];
    for(int cnt = 0; cnt < numVertices ; cnt++) {
        visited_vertices[cnt] = 0;
    }
    
    list <node> queue;
    
    visited_vertices[startVertex] = 1;
    
    int current_vertex = startVertex;
    queue.push_back(*adjList[current_vertex].begin());
    
    while(!queue.empty()) {
        queue.pop_front();
        cout << current_vertex << "-> ";
        for(auto it = adjList[current_vertex].begin(); it != adjList[current_vertex].end(); it++) {
            node iterator_node = *it;
            if(visited_vertices[iterator_node.dest] == 0) {
                queue.push_back(*it);
            }
        }
        current_vertex = queue.front().dest;
        queue.pop_front();
        visited_vertices[current_vertex] = 1;
    }
    
    for(int cnt = 0 ; cnt < numVertices; cnt++){
        cout << "\n" << "visited_vertices[" << cnt << "] : " << visited_vertices[cnt];
    }
    cout << endl;
}
        

int main()
{
    Graph g(4);
    g.addWeightEdge(0,2,1);
    g.addWeightEdge(0,1,9);
    g.addWeightEdge(1,3,2);
    g.addWeightEdge(2,1,3);
    g.addWeightEdge(3,0,4);
    
    g.print_adjList();
    
    g.isEdge(0,2);
    g.isEdge(0,1);
    
    g.BFS(0);
    
    //g.removeWeighEdge(0,2);
    //g.print_adjList();
    return 0;
}
