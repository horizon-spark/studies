#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int edges;
    cout << "Insert a number of edges" << endl;
    cin >> edges;
    vector<vector<int>> listOfEdges(edges,vector<int>(2,0));
    int node1, node2, vertices = 0;
    for (int i = 0; i < edges; i++) {
        cin >> node1 >> node2;
        if (max(node1,node2) > vertices) vertices = max(node1,node2);
        listOfEdges[i][0] = node1;
        listOfEdges[i][1] = node2;
    }
    vertices++;
    vector<vector<int>> matrix(vertices,vector<int>(vertices,0));
    for (int i = 0; i < edges; i++) {
        matrix[listOfEdges[i][0]][listOfEdges[i][1]] = 1;
        matrix[listOfEdges[i][1]][listOfEdges[i][0]] = 1;
    }
    bool isolatedFlag = true;
    vector<int> isolated;
    vector<int> loops;
    vector<int> degrees(vertices,0);
    for (int i = 0; i < vertices; i++) {
        isolatedFlag = true;
        for (int j = 0; j < vertices; j++) {
            if (j > i) break;
            if (matrix[i][j] == 1) {
                if (i != j) isolatedFlag = false;
                if (i == j) {
                    loops.push_back(i);
                } 
                degrees[i]++;
            }
        }
        if (isolatedFlag) isolated.push_back(i);
    }
    
    cout << "\t\tOUTPUT" << endl;
    cout << "Adjacency matrix" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "The number of vertices is " << vertices << endl;
    cout << "The number of edges is " << edges << endl;
    cout << "The number of isolated edges is " << isolated.size() << endl;
    if (!(isolated.empty())) {
        for (int i = 0; i < isolated.size(); i++) {
            cout << isolated[i] << "\t";
        }
        cout << endl;
    }
    cout << "The number of loops is " << loops.size() << endl;
    if (!(loops.empty())) {
        for (int i = 0; i < loops.size(); i++) {
            cout << loops[i] << "\t";
        }
        cout << endl;
    }
    sort(degrees.begin(),degrees.end(),greater<int>());
    cout << "Vertices degrees in decreasing order" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << degrees[i] << "\t";
    }
}