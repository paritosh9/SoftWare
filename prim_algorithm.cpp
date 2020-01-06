
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
    node Node;
    node newNode;
    int i;
    
    while(!visited_vertices[current_vertex]) {
        Node.weight = 32567; // max weight as initial value
        cout << " -> " << current_vertex;
        visited_vertices[current_vertex] = 1; // updating visited_vertices array
        
        /* 
            iterating over neighbouring nodes of current vertex
            Choosing the neigbour with minimum edge weight to traverse
        */
        for(auto it = adjList[current_vertex].begin(); it != adjList[current_vertex].end(); it++) {
            newNode = *it;
            if(newNode.weight < Node.weight && !visited_vertices[newNode.dest]) {    
                lowest_weight = newNode.weight;
                Node = newNode;
            }
        }
        
        //Updating current vertex to point to node selected with minimum edge weight
        current_vertex = Node.dest;
        
        /*
            Iterating over vertices to make sure current vertex is not visited
            We do that by looking into visited_vertices array
            We break from for loop below if current vertex is not visited
            
            If current vertex is already visited, then we find a vertex 
            from visited_vertices array which is not visited.
            We use that as current_vertex
            There is a corner case where non visited vertex
            might not be connected to other vertices
            We check that using adjList[cnt].empty() and ignore that vertex
        */
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
    for(int cnt = 0; cnt < numVertices ; cnt++) {
            cout << "visited_vertices[" << cnt << "]" << visited_vertices[cnt] <<endl;
    }
    
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
