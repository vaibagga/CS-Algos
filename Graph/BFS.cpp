#include <iostream>
#include <queue>
#define MAXSIZE 10
using namespace std;
queue <int> q;
int adjacency_matrix[MAXSIZE][MAXSIZE]={0};
// initially no node is visited
bool visited[MAXSIZE] = {false};
int num_vertices, num_edges;
//used to convert the edges to an adjacency matrix
void inputGraph(int n){
    for (int i = 0; i < n; i++){
        cout << "Enter the nodes which are connected by edge: ";
        int node1, node2;
        cin >> node1 >> node2;
        adjacency_matrix[node1][node2] = 1;
    }
}
//breadth first traversal
void breadthFirst(int num_node){
    if (!visited[num_node]){
        visited[num_node] = true;//the node is marked as visited
        cout << num_node << " ";
    }
    for  (int i = 0; i < num_vertices;i++){
        if (adjacency_matrix[num_node][i]&&!visited[i]){
            q.push(i);
        }
    }
    int popped = q.front();
    if (q.empty()){
        return;
    }
    q.pop();
    breadthFirst(popped);
}
void printAdj(){
    for (int i = 0; i < num_vertices; i++){
        for (int j = 0; j < num_vertices; j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
//function to print the adjacency matrix formed
int main(){
    cout << "Enter the number of vertices and edges: ";
    cin >> num_vertices >> num_edges;
    inputGraph(num_edges);
    breadthFirst(0);
    cout << endl;
    return 0;
}
