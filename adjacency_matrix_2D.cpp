#include <iostream>
using namespace std;

class Graph {
    private:
        int** adjMatrix_2D;
        int numVertices;
    public:
        Graph(int num_Vertices) {
            numVertices = num_Vertices;
            adjMatrix_2D = new int*[numVertices];
            for(int row_cnt = 0; row_cnt < numVertices; row_cnt++) {
                cout << "Allocating memory for adjMatrix_2D[" << row_cnt << "]\n";
                adjMatrix_2D[row_cnt] = new int[numVertices];
	            for(int col_cnt = 0; col_cnt < numVertices; col_cnt++) {
	                adjMatrix_2D[row_cnt][col_cnt] = 0;
	            }
            } 
	   }
	   
	   void addWeightedEdge(int src_vertex, int dst_vertex, int edgeWeight) {
	       adjMatrix_2D[src_vertex][dst_vertex] = edgeWeight;
	       adjMatrix_2D[dst_vertex][src_vertex] = edgeWeight; //since this is a undirected graph
	   }
        
       void removeWeightedEdge(int src_vertex, int dst_vertex) {
           adjMatrix_2D[src_vertex][dst_vertex] = 0;
           adjMatrix_2D[dst_vertex][src_vertex] = 0; //since this is a undirected graph
       }
       
       bool isEdge(int src_vertex, int dst_vertex) {
           if(adjMatrix_2D[src_vertex][dst_vertex])
               return 1;
           else
               return 0;
       }
       
       int edgeWeight(int src_vertex, int dst_vertex) {
           if(adjMatrix_2D[src_vertex][dst_vertex])
               return adjMatrix_2D[src_vertex][dst_vertex];
           else 
               return 0;
       }
       
       void print_adjMatrix(){
           cout <<"\nPrinting Adjacency Matrix below\n";
           for(int row_cnt = 0; row_cnt < numVertices; row_cnt++) {
               cout << row_cnt << ":";
               for(int col_cnt = 0; col_cnt < numVertices; col_cnt++)
                   cout << " " << adjMatrix_2D[row_cnt][col_cnt] << " ";
               cout << "\n" ;
           }
       }
       
        ~Graph() {
            for(int row_cnt = 0; row_cnt < numVertices; row_cnt++) {
	            cout << "deallocating array_2D[" << row_cnt << "]\n";
	            delete [] adjMatrix_2D[row_cnt];
            }
            delete [] adjMatrix_2D;
	    }
            
};

int main() {
    Graph g(4);
    g.addWeightedEdge(1,2,5);
    g.addWeightedEdge(0,3,2);
    g.addWeightedEdge(2,2,3);
    g.addWeightedEdge(3,2,4);
    
    bool is_edge = g.isEdge(0,0);
    cout <<"Edge :" << is_edge << "\n";
    
    int edge_weight = g.edgeWeight(0,0);
    cout <<"Edge Weight :" << edge_weight << "\n";
    
    is_edge = g.isEdge(1,2);
    cout <<"Edge :" << is_edge << "\n";
    
    edge_weight = g.edgeWeight(1,2);
    cout <<"Edge Weight :" << edge_weight << "\n";
    
    g.print_adjMatrix();
	return 0;
}
