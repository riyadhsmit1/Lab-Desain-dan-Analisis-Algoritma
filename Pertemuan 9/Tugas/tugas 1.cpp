#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menambahkan edge ke dalam graf
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Karena graf tidak berarah
}

// Fungsi untuk mencetak daftar ketetanggaan
void printGraph(const vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "simpul " << v << ":";
        for (size_t i = 0; i < adj[v].size(); ++i)
            cout << " -> " << adj[v][i];
        cout << endl;
    }
}

int main() {
    int V = 5; // Jumlah simpul dalam graf
    vector<int> adj[V];

    // Menambahkan edge
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Mencetak daftar ketetanggaan
    cout << "daftar ketetanggaan (graf tidak berarah)" << endl;
    printGraph(adj, V);

    return 0;
}

