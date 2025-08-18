#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

vector<vector<int>> readGraph(string filename)
{
    vector<vector<int>> result;
    vector<int> buf;
    ifstream input(filename);
    int size, num;
    if (input.is_open()) {
        input >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                input >> num;
                if (num >= 0)
                    buf.push_back(num);
                else 
                    buf.push_back(INT_MAX);
            }
            result.push_back(buf);
            buf.clear();
        }
    }
    input.close();
    return result;
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == INT_MAX) {
            if (i < arr.size() - 1) cout << "inf, ";
            else cout << "inf" << endl; 
        } else {
            if (i < arr.size() - 1) cout << arr[i] << ", ";
            else cout << arr[i] << endl;
        }
    }
}

void printGraph(vector<vector<int>> graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - 1) {
                if (graph[i][j] == INT_MAX) cout << "i ";
                else cout << graph[i][j] << ' ';
            } else {
                if (graph[i][j] == INT_MAX) cout << "i" << endl;
                else cout << graph[i][j] << endl;
            }
        }
    }
}

vector<int> DijkstraAlgorithm(vector<vector<int>>& graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        D[i] = graph[start][i];
    }
    D[start] = 0;
    int index = 0, u = 0;
    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && D[j] < min) {
                min = D[j];
                index = j;
            }
        }
        u = index;
        visited[u] = true;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != INT_MAX && D[u] != INT_MAX && 
            (D[u] + graph[u][j] < D[j])) {
                D[j] = D[u] + graph[u][j];
            }
        }
    }
    return D;
}

int main()
{
    int start;
    vector<vector<int>> graph = readGraph("input.txt");
    printGraph(graph);
    cout << "Insert a vertex from which to find shortest paths: ";
    cin >> start;
    vector<int> D = DijkstraAlgorithm(graph, start);
    cout << "The array of chortest paths from vertex " << start << endl;
    printArray(D);
}
