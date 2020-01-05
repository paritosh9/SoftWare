#include <iostream>
#include <list>
#include <iterator>
#include "graph.cpp"
using namespace std;


// Method for traversing DFS (Depth First Search)
void Graph::DFS(int startVertex) {
    // dynamic memory allocation for an array
    // it will hold information wheter vertex is visited or not, will be updated during traversal
    bool *visited_vertices = new bool [numVertices];
    for(int cnt = 0; cnt < numVertices ; cnt++) {
        visited_vertices[cnt] = 0;
    }
    
    // declaring stack which will hold neighbouring vertices of current vertex
    // DFS traversal uses stack data structure, which helps depth wise traversing
    // store new neighbouring nodes on top of stack and use next vertex for traversing from front of stack LIFO (Last in First Out)
    list <node> stack; // we can make list behave as queue or stack by using appropriate functions
    
    // updating startvertex as visited in the array
    visited_vertices[startVertex] = 1;
    int current_vertex = startVertex;
    
    // node is tydef in class Graph in file graph.cpp
    node startNode;
    startNode.dest = current_vertex;
    startNode.weight = 0;
    stack.push_front(startNode);
    
    // loop till stack is not empty
    while(!stack.empty()) {
        current_vertex = stack.front().dest;
        //cout <<current_vertex <<endl;
        stack.pop_front();
        
        cout << " -> " << current_vertex ;
        for(auto it = adjList[current_vertex].begin(); it != adjList[current_vertex].end(); it++) {
            node iterator_node = *it;
            if(not visited_vertices[iterator_node.dest]) {
                visited_vertices[iterator_node.dest] = 1;
                stack.push_front(*it);
            }
        }
        
            
    };
    
    // print to screen value of visited_vertices array to confirm all vertices visited
    for(int cnt = 0 ; cnt < numVertices; cnt++){
        cout << "\n" << "visited_vertices[" << cnt << "] : " << visited_vertices[cnt];
    }
    cout << endl;
}
        

int main()
{
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
    
    g.DFS(0);
    
    //g.removeWeighEdge(0,2);
    //g.print_adjList();
    return 0;
}
