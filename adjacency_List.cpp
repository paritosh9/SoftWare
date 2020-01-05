#include <iostream>
#include <list>
#include <iterator>
using namespace std;

typedef struct nodes {
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
        }
        
        //Method to remove Edge
        void removeWeighEdge(int src, int dest, int weight) {
            /*node newNode;
            newNode.dest   = dest;
            newNode.weight = weight;
            adjList[src].remove(newNode);
            */
            
            node newNode;
            newNode.dest   = dest;
            for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                node iterator_node = *it;
                if (iterator_node.dest == newNode.dest) {
                    adjList[src].erase(it);
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
                    return 1;
                }
            }
            return 0;
        }
        
        void print_adjList() {
            cout << "Printing AdjList" << endl;
            
            for(int src = 0; src < numVertices; src++ ) {
                cout << src << "  ";
                for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                    node iterator_node = *it;
                    cout << "  node dest - " << iterator_node.dest << "  node weight - " << iterator_node.weight ;
                }
                cout << endl;
            }
        }
        
        ~Graph() {
            cout << "deleting" << endl;
            //adjList->clear();
            delete [] adjList;
        }
};

int main()
{
    Graph g(4);
    g.addWeightEdge(0,2,1);
    g.addWeightEdge(1,3,2);
    g.addWeightEdge(2,2,3);
    g.addWeightEdge(3,0,4);
    g.addWeightEdge(0,3,6);
    
    g.print_adjList();
    //g.~Graph();
    
    //g.print_adjList();
    return 0;
}

