#include <iostream>
#include <climits>
using namespace std;
int findMinVertex(int *weights, bool *visited, int n) {
    int minVertex = -1; // Initialized to -1 means there is no vertex till now
    for (int i = 0; i < n; i++) {
        // Conditions : the vertex must be unvisited and either minVertex value is -1
        // or if minVertex has some vertex to it, then weight of currentvertex
        // should be less than the weight of the minVertex.
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **edges, int n) {
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];
    // Initially, the visited array is assigned to false and weights array to infinity.
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    // Values assigned to vertex 0.(the selected starting vertex to begin with)
    parent[0] = -1;
    weights[0] = 0;
    for (int i = 0; i < n-1; i++) {
        // Find min vertex
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;
        // Explore unvisited neighbors
        for (int j = 0; j < n; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                if(edges[minVertex][j] < weights[j]) {
                    // updating weight array and parent array
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    // Final MST printed
    for (int i = 1; i < n; i++) {
        if (parent[i] < i) {
            cout << parent[i] << " " << i << " " <<weights[i] << endl;
        }
        else {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}
int main() {
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int*[n]; // Adjacency matrix used to store the graph
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0; // Initially all pairs are assigned 0 weight which
            // means that there is no edge between them
        }
    }
    for (int i = 0; i < e; i++) {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    prims(edges, n);
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}