#include <iostream>
#include <list>
#include <iterator>
#include "graph.cpp"
using namespace std;


// Prim algorithm implementation
void Graph::prim_algorithm(int startVertex) {
    bool* visited_vertices = new bool [numVertices];
    for(int cnt = 0; cnt < numVertices ; cnt++) {
        visited_vertices[cnt] = 0;
    }
    
    int current_vertex = startVertex;
    int lowest_weight;
    node Node = *adjList[current_vertex].begin();
    node newNode;
    int i;
    while(!visited_vertices[current_vertex]) {
        //Node = *adjList[current_vertex].begin();
        i = 0;
        cout << " -> " << current_vertex;
        visited_vertices[current_vertex] = 1;
        for(auto it = adjList[current_vertex].begin(); it != adjList[current_vertex].end(); it++) {
            newNode = *it;
            if(visited_vertices[newNode.dest]) {
                continue;
            }
            else if(i == 0) {
                Node = newNode;
                i++;
            }
            else if(i != 0 && newNode.weight < Node.weight && !visited_vertices[newNode.dest]) {
                lowest_weight = newNode.weight;
                current_vertex = newNode.dest;
                Node = newNode;
            }
            
        }
        current_vertex = Node.dest;
        //cout << current_vertex << endl;
    
        int flag = 0;
        for(int cnt = 0; cnt < numVertices ; cnt++) {
            //cout << "visited_vertices[" << cnt << "]" << visited_vertices[cnt] <<endl;
            if(!visited_vertices[current_vertex]) {
                break;
            }
            if(visited_vertices[current_vertex] && !visited_vertices[cnt]) {
                if(adjList[cnt].empty()){
                    continue;
                }
                current_vertex = cnt;
                break;
            }
        }
        
    
    }
    cout << endl;
}   

int main() {
    Graph g(8);
    g.addWeightEdge(0,2,1);
    g.addWeightEdge(0,1,9);
    g.addWeightEdge(1,3,2);
    g.addWeightEdge(2,1,3);
    g.addWeightEdge(3,0,4);
    g.addWeightEdge(4,3,22);
    g.addWeightEdge(7,3,45);
    g.addWeightEdge(5,2,55);
    
    g.print_adjList();
    
    g.isEdge(0,2);
    g.isEdge(0,1);
    
    g.prim_algorithm(0);
    
    //g.removeWeighEdge(0,2);
    //g.print_adjList();
    return 0;
}
