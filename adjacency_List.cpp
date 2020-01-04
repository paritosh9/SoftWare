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
};

int main()
{
    Graph(4);

    return 0;
}
