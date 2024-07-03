#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <map>

using namespace std;

void tambahkanSisi(map<char, vector<pair<char, int> > >& graf, char u, char v, int w) {
    graf[u].push_back(make_pair(v, w));
    graf[v].push_back(make_pair(u, w));
}

int dijkstra(map<char, vector<pair<char, int> > >& graf, char asal, char tujuan) {
    map<char, int> jarak;
    set<pair<int, char> > pq;

    for (map<char, vector<pair<char, int> > >::iterator it = graf.begin(); it != graf.end(); ++it) {
        jarak[it->first] = numeric_limits<int>::max();
    }
    jarak[asal] = 0;
    pq.insert(make_pair(0, asal));
    
    while (!pq.empty()) {
        char u = pq.begin()->second;
        pq.erase(pq.begin());
        
        if (u == tujuan) {
            return jarak[u];
        }
        
        vector<pair<char, int> >& tetangga = graf[u];
        for (vector<pair<char, int> >::iterator it = tetangga.begin(); it != tetangga.end(); ++it) {
            char v = it->first;
            int berat = it->second;
            
            if (jarak[u] + berat < jarak[v]) {
                pq.erase(make_pair(jarak[v], v));
                jarak[v] = jarak[u] + berat;
                pq.insert(make_pair(jarak[v], v));
            }
        }
    }
    return -1; 
}

int main() {
    map<char, vector<pair<char, int> > > graf;

    tambahkanSisi(graf, 'A', 'B', 1);
    tambahkanSisi(graf, 'A', 'C', 2);
    tambahkanSisi(graf, 'A', 'E', 5);
    tambahkanSisi(graf, 'B', 'D', 5);
    tambahkanSisi(graf, 'C', 'D', 2);
    tambahkanSisi(graf, 'D', 'E', 2);
    tambahkanSisi(graf, 'D', 'F', 2);
    tambahkanSisi(graf, 'E', 'F', 1);
    
    cout << "Representasi matriks:" << endl;
    cout << "A -1- B\n|     | \\\n2|     5  1\n|     |   \\\nC -2- D -2-E\n          |    /\n          2   1\n          |  /\n           F\n" << endl;
    
    char asal, tujuan;
    cout << "Masukkan simpul asal (A-F): ";
    cin >> asal;
    cout << "Masukkan simpul tujuan (A-F): ";
    cin >> tujuan;
    
    int jarak_terpendek = dijkstra(graf, asal, tujuan);
    if (jarak_terpendek != -1) {
        cout << "Jarak dari simpul " << asal << " ke simpul " << tujuan << " adalah " << jarak_terpendek << endl;
    } else {
        cout << "Tidak ada jalur dari simpul " << asal << " ke simpul " << tujuan << endl;
    }
    
    return 0;
}

