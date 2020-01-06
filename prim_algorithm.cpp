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
    int prev_vertex;
    int lowest_weight;
    node Node;
    node newNode;
    int flag = 0;
    
    list <int> list_vertices;
    list_vertices.push_back(current_vertex);
    
    while(!visited_vertices[current_vertex]) {
        prev_vertex = current_vertex;
        Node.weight = 32567; // max weight as initial value
        //cout << " -> " << current_vertex;
        visited_vertices[current_vertex] = 1; // updating visited_vertices array
        
        /* 
            iterating over neighbouring nodes of current vertex
            Choosing the neigbour with minimum edge weight to traverse
        */
        for(auto it = adjList[current_vertex].begin(); it != adjList[current_vertex].end(); it++) {
            newNode = *it;
            
            // pushing all adjacent vertices to list so as to map graph while traversing
            // this list will help us avoid edges which are disconnected from the graph
            // beacuse they will not show up in the list_vertices as we traverse
            list_vertices.push_back(newNode.dest);
             
            // Normal condition while traversing the graph 
            //using adjecent vertex with lowest edge weight
            if(flag ==0 && newNode.weight < Node.weight && !visited_vertices[newNode.dest]) {    
                lowest_weight = newNode.weight;
                Node = newNode;
            }
            //Once we star traversing non adjacent vertices of current vertex
            //we look into visited_vertices array for this
            else if(flag == 1 && newNode.weight < Node.weight) {
                lowest_weight = newNode.weight;
                Node = newNode;
            }
        }
        
        //Updating current vertex to point to node selected with minimum edge weight
        current_vertex = Node.dest;
        if(current_vertex != prev_vertex) {
            // printing Edges of minimum spanning tree to screen
            cout << "Edge  " << prev_vertex << " -> " << current_vertex << " : " << Node.weight << endl;
        }
        
        /*
            Iterating over vertices to make sure current vertex is not visited
            We do that by looking into visited_vertices array and list_vertices list
            We break from for loop below if current vertex is not visited
            
            If current vertex is already visited, then we find a vertex 
            from list_vertices list which is not visited.
            We use that as current_vertex
            We set flag as 1 when we enter a condition 
            where we start using vertices which are not adjacent to current vertex
            Since we then change condition in above for loop and can use vertex already visited as well
            to determine minimum weight Edge
            
        */
        //for(int cnt = 0; cnt < numVertices ; cnt++) {
        while(!list_vertices.empty()) {
            //cout << "visited_vertices[" << cnt << "]" << visited_vertices[cnt] <<endl;
            int cnt = list_vertices.front();
            if(!visited_vertices[current_vertex]) {
                break;
            }
            if(visited_vertices[current_vertex] && !visited_vertices[list_vertices.front()]) {
                flag =1;
                current_vertex = cnt;
                break;
            }
            list_vertices.pop_front();
        }
        
    }
    
    cout << endl;
    for(int cnt = 0; cnt < numVertices ; cnt++) {
            cout << "visited_vertices[" << cnt << "]" << visited_vertices[cnt] <<endl;
    }
    
}   

int main() {
    Graph g(13);
    g.addWeightEdge(0,2,1);
    g.addWeightEdge(0,1,9);
    g.addWeightEdge(1,3,2);
    g.addWeightEdge(2,1,3);
    g.addWeightEdge(3,0,4);
    g.addWeightEdge(4,3,22);
    g.addWeightEdge(7,3,45);
    g.addWeightEdge(5,2,55);
    g.addWeightEdge(10,9,88);
    g.addWeightEdge(11,5,199);
    g.addWeightEdge(8, 2, 524);
    
    g.print_adjList();
    
    g.isEdge(0,2);
    g.isEdge(0,1);
    
    g.prim_algorithm(0);
    
    //g.removeWeighEdge(0,2);
    //g.print_adjList();
    return 0;
}
