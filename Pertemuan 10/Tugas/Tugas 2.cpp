#include <iostream>
#include <vector>
using namespace std;

void tambahEdgeTidakBerarah(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void tambahEdgeBerarah(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void tambahEdgeBerbobot(vector<pair<int, int> > adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

void cetakGrafTidakBerarah(const vector<int> adj[], int V) {
    cout << "daftar ketetanggaan (graf tidak berarah) :" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "simpul " << v << ":";
        for (size_t i = 0; i < adj[v].size(); ++i)
            cout << " -> " << adj[v][i];
        cout << endl;
    }
    cout << endl;
}

void cetakGrafBerarah(const vector<int> adj[], int V) {
    cout << "daftar ketetanggaan (graf berarah) :" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "simpul " << v << ":";
        for (size_t i = 0; i < adj[v].size(); ++i)
            cout << " -> " << adj[v][i];
        cout << endl;
    }
    cout << endl;
}

void cetakGrafBerbobot(const vector<pair<int, int> > adj[], int V) {
    cout << "daftar ketetanggaan (graf berbobot) :" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "simpul " << v << ":";
        for (size_t i = 0; i < adj[v].size(); ++i)
            cout << " -> (" << adj[v][i].first << ", " << adj[v][i].second << ")";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int V = 5; 

    vector<int> adjTidakBerarah[V];
    tambahEdgeTidakBerarah(adjTidakBerarah, 0, 1);
    tambahEdgeTidakBerarah(adjTidakBerarah, 0, 4);
    tambahEdgeTidakBerarah(adjTidakBerarah, 1, 2);
    tambahEdgeTidakBerarah(adjTidakBerarah, 1, 3);
    tambahEdgeTidakBerarah(adjTidakBerarah, 1, 4);
    tambahEdgeTidakBerarah(adjTidakBerarah, 2, 3);
    tambahEdgeTidakBerarah(adjTidakBerarah, 3, 4);
    cetakGrafTidakBerarah(adjTidakBerarah, V);

    vector<int> adjBerarah[V];
    tambahEdgeBerarah(adjBerarah, 0, 1);
    tambahEdgeBerarah(adjBerarah, 0, 4);
    tambahEdgeBerarah(adjBerarah, 1, 2);
    tambahEdgeBerarah(adjBerarah, 1, 3);
    tambahEdgeBerarah(adjBerarah, 1, 4);
    tambahEdgeBerarah(adjBerarah, 2, 3);
    tambahEdgeBerarah(adjBerarah, 3, 4);
    cetakGrafBerarah(adjBerarah, V);

    vector<pair<int, int> > adjBerbobot[V];
    tambahEdgeBerbobot(adjBerbobot, 0, 1, 10);
    tambahEdgeBerbobot(adjBerbobot, 0, 4, 20);
    tambahEdgeBerbobot(adjBerbobot, 1, 2, 30);
    tambahEdgeBerbobot(adjBerbobot, 1, 3, 40);
    tambahEdgeBerbobot(adjBerbobot, 1, 4, 50);
    tambahEdgeBerbobot(adjBerbobot, 2, 3, 60);
    tambahEdgeBerbobot(adjBerbobot, 3, 4, 70);
    cetakGrafBerbobot(adjBerbobot, V);

    return 0;
}

