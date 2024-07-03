#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <map>
#include <algorithm> 

using namespace std;

void tambahkanSisi(map<int, vector<pair<int, int> > >& graf, int u, int v, int w) {
    graf[u].push_back(make_pair(v, w));
    graf[v].push_back(make_pair(u, w));
}

pair<int, vector<int> > dijkstra(map<int, vector<pair<int, int> > >& graf, int asal, int tujuan) {
    map<int, int> jarak;
    map<int, int> pred;
    set<pair<int, int> > pq;
    
    for (map<int, vector<pair<int, int> > >::iterator it = graf.begin(); it != graf.end(); ++it) {
        jarak[it->first] = numeric_limits<int>::max();
    }
    jarak[asal] = 0;
    pq.insert(make_pair(0, asal));
    
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        
        if (u == tujuan) {
            break;
        }
        
        vector<pair<int, int> >& tetangga = graf[u];
        for (vector<pair<int, int> >::iterator it = tetangga.begin(); it != tetangga.end(); ++it) {
            int v = it->first;
            int berat = it->second;
            
            if (jarak[u] + berat < jarak[v]) {
                pq.erase(make_pair(jarak[v], v));
                jarak[v] = jarak[u] + berat;
                pred[v] = u;
                pq.insert(make_pair(jarak[v], v));
            }
        }
    }

    vector<int> rute;
    if (jarak[tujuan] != numeric_limits<int>::max()) {
        for (int at = tujuan; at != asal; at = pred[at]) {
            rute.push_back(at);
        }
        rute.push_back(asal);
        reverse(rute.begin(), rute.end());
    }
    return make_pair(jarak[tujuan], rute);
}

int main() {
    map<int, vector<pair<int, int> > > graf;

    tambahkanSisi(graf, 1, 2, 7);
    tambahkanSisi(graf, 1, 3, 9);
    tambahkanSisi(graf, 1, 6, 14);
    tambahkanSisi(graf, 2, 3, 10);
    tambahkanSisi(graf, 2, 4, 15);
    tambahkanSisi(graf, 3, 4, 11);
    tambahkanSisi(graf, 3, 6, 2);
    tambahkanSisi(graf, 4, 5, 6);
    tambahkanSisi(graf, 5, 6, 9);

    int asal, tujuan;
    cout << "Masukkan simpul asal (1-6): ";
    cin >> asal;
    cout << "Masukkan simpul tujuan (1-6): ";
    cin >> tujuan;
    
    pair<int, vector<int> > hasil = dijkstra(graf, asal, tujuan);
    int jarak_terpendek = hasil.first;
    vector<int> rute = hasil.second;

    if (jarak_terpendek != numeric_limits<int>::max()) {
        cout << "Jarak dari simpul " << asal << " ke simpul " << tujuan << " adalah " << jarak_terpendek << endl;
        cout << "Rute terpendek: ";
        for (size_t i = 0; i < rute.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << rute[i];
        }
        cout << endl;
    } else {
        cout << "Tidak ada jalur dari simpul " << asal << " ke simpul " << tujuan << endl;
    }
    
    return 0;
}

