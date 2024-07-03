#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> q;
    int n;
    string name;

    cout << "Masukan jumlah nama yang ingin dimasukan ke dalam antrian: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 1; i <= n; ++i) {
        cout << "Masukan nama ke-" << i << " : ";
        getline(cin, name);
        q.push(name);
    }

    cout << "\nNama Dalam Antrian:\n";
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}

