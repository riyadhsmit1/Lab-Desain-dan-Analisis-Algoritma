#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n, num;

    cout << "Masukan jumlah angka yang ingin dimasukan kedalam queue: ";
    cin >> n;

    cout << "Masukan " << n << " angka:\n";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        q.push(num);
    }

    cout << "Menampilkan angka dari queue:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

