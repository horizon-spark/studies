#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

set<int> vertices;
int weightsSumMST = 0; 

class Edge
{
    public:
        int v1, v2;
        int weight;

        Edge(int v1, int v2, int weight)
        {
            this->v1 = v1;
            this->v2 = v2;
            this->weight = weight;
        }
};

vector<Edge> readGraph(string filename)
{
    vector<Edge> result;
    ifstream input(filename);
    if (input.is_open()) {
        int v1, v2, weight;
        while (input >> v1 >> v2 >> weight) {
            result.push_back(Edge(v1, v2, weight));
            vertices.insert(v1);
            vertices.insert(v2);
        }
    }
    input.close();
    return result;
}

void printGraph(vector<Edge>& graph)
{
    for (int i = 0; i < graph.size(); i++) {
        cout << '(' << graph[i].v1 << ", " << graph[i].v2 << ", " << graph[i].weight << ')' << endl;
    }
    return;
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
}

vector<Edge> PrimAlgorithm(int numberV, vector<Edge> E)
{
    vector<Edge> notUsedE = E;
    vector<Edge> MST;
    vector<int> usedV, notUsedV; 
    for (int i = 1; i <= numberV; i++) {
        notUsedV.push_back(i);
    }
    usedV.push_back(notUsedV.back());
    notUsedV.pop_back();
    while (notUsedV.size() > 0) {
        int minE = -1;
        for (int i = 0; i < notUsedE.size(); i++) {
            if ((find(usedV.begin(), usedV.end(), notUsedE[i].v1) != usedV.end()) && 
            (find(notUsedV.begin(), notUsedV.end(), notUsedE[i].v2) != notUsedV.end()) ||
            (find(usedV.begin(), usedV.end(), notUsedE[i].v2) != usedV.end()) &&
            (find(notUsedV.begin(), notUsedV.end(), notUsedE[i].v1) != notUsedV.end())) {
                if (minE != -1) {
                    if (notUsedE[i].weight < notUsedE[minE].weight)
                        minE = i;
                } else 
                    minE = i;
            }
        }
        if (find(usedV.begin(), usedV.end(), notUsedE[minE].v1) != usedV.end()) {
            usedV.push_back(notUsedE[minE].v2);
            notUsedV.erase(find(notUsedV.begin(), notUsedV.end(), notUsedE[minE].v2));
        } else {
            usedV.push_back(notUsedE[minE].v1);
            notUsedV.erase(find(notUsedV.begin(), notUsedV.end(), notUsedE[minE].v1));
        }
        weightsSumMST += notUsedE[minE].weight;
        MST.push_back(notUsedE[minE]);
        notUsedE.erase(notUsedE.begin() + minE);
    }
    return MST;
}  

int main()
{
    int numberV, numberE;
    vector<Edge> E = readGraph("input.txt");
    cout << "The initial graph: " << endl;
    printGraph(E);
    vector<Edge> MST = PrimAlgorithm(vertices.size(),E);
    cout << "MST graph: " << endl;
    printGraph(MST);
    cout << "The sum of edges in MST graph: " << weightsSumMST << endl;
}