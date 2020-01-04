*******************************************************************************/

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph {
    private :
        int numVertices;
        list <int> *adjList;
    
    public :
        // Graph Class Constructor 
        Graph(int vertex_count) {
            numVertices = vertex_count;
            adjList = new list<int>[vertex_count];
        }
        
        // Method to addWeightEdge, currently only adds Edge, to be updated to add edge and weight
        void addWeightEdge(int src, int dest) {
            adjList[src].push_back(dest);
        }
        
        //Method to remove Edge
        void removeWeighEdge(int src, int dest) {
            adjList[src].remove(dest);
        }
        
        //Method to return if edge exists or not
        bool isEdge(int src, int dest) {
            for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                if (*it == dest) {
                    return 1;
                }
            }
            return 0;
        }
        
        void print_adjList() {
            cout << "Printing AdjList" << endl;
            
            for(int src = 0; src < numVertices; src++ ) {
                cout << src;
                for(auto it = adjList[src].begin(); it != adjList[src].end(); it++) {
                    cout << " " << *it << " ";
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
    g.addWeightEdge(0,2);
    g.addWeightEdge(1,3);
    g.addWeightEdge(2,2);
    g.addWeightEdge(3,0);
    g.addWeightEdge(0,3);
    
    g.print_adjList();
    g.~Graph();
    
    g.print_adjList();
    return 0;
}

