#include <iostream>
#include <list>
#include <iterator>
using namespace std;

typedef struct {
    int dest;
    int weight;
}node;

class Graph {
    private :
        int numVertices;
        list <node> *adjList;
    
    public :
        // Graph Class Constructor 
        Graph(int vertex_count) {
            numVertices = vertex_count;
            adjList = new list <node>[vertex_count];
        }
        
        // Method to addWeightEdge, currently only adds Edge, to be updated to add edge and weight
        void addWeightEdge(int src, int dest, int weight) {
            node newNode;
            newNode.dest   = dest;
            newNode.weight = weight;
            adjList[src].push_back(newNode);
            
            // Since this is an undirected Graph
            newNode.dest   = src;
            newNode.weight = weight;
            adjList[dest].push_back(newNode);
        }
        
        //Method to remove Edge - Not Working
        void removeWeighEdge(int src, int dest) {
            /*node newNode;
            newNode.dest   = dest;
            newNode.weight = weight;
            adjList[src].remove(newNode);
            */
            
            node newNode;
            newNode.dest   = dest;
            for(list<node>::iterator it = adjList[src].begin(); it != adjList[src].end(); it++) {
                node iterator_node = *it;
                if (iterator_node.dest == newNode.dest) {
                    //adjList[src].erase(it);
                }
            }
        }
        
        //Method to return if edge exists or not
        bool isEdge(int src, int dest) {
            node newNode;
            newNode.dest   = dest;
            for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                node iterator_node = *it;
                if (iterator_node.dest == newNode.dest) {
                    cout << src << " -> " << dest << " Is an Edge" << endl;
                    return 1;
                }
            }
            cout << src << " -> " << dest << " Not an Edge" << endl;
            return 0;
        }
        
        // Method to print adjList on screen
        void print_adjList() {
            cout << "Printing AdjList" << endl;
            
            for(int src = 0; src < numVertices; src++ ) {
                cout << src << "  ";
                for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                    node iterator_node = *it;
                    cout << "  node dest - " << iterator_node.dest << "  node weight - " << iterator_node.weight << " ||||" ;
                }
                cout << endl;
            }
        }
        
        void BFS(int startVetex);
        void DFS(int startVetex);
    
        // Destructor
        ~Graph() {
            cout << "deleting" << endl;
            //adjList->clear();
            delete [] adjList;
        }
};
