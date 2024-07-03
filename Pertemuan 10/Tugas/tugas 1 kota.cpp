#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int tsp(const vector<vector<int> >& costMatrix, vector<int>& path) {
    int n = costMatrix.size();
    vector<int> vertices;

    for (int i = 1; i < n; i++) {
        vertices.push_back(i);
    }

    int minCost = INT_MAX;

    do {
        int currentCost = 0;
        int k = 0; 
        for (int i = 0; i < vertices.size(); i++) {
            currentCost += costMatrix[k][vertices[i]];
            k = vertices[i];
        }
        currentCost += costMatrix[k][0];

        if (currentCost < minCost) {
            minCost = currentCost;
            path = vertices;
        }

    } while (next_permutation(vertices.begin(), vertices.end()));

    return minCost;
}

int main() {
    int n;

    cout << "masukan jumlah kota: ";
    cin >> n;

    vector<vector<int> > costMatrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        cout << "nilai cost matrix" << endl;
        cout << "cost element baris ke-:" << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
        }
        cout << endl;
    }

    cout << "cost list :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\t";
        for (int j = 0; j < n; j++) {
            cout << costMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> path;
    int minCost = tsp(costMatrix, path);

    cout << "jalur terpendek :" << endl;
    cout << "1--->";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << "--->";
    }
    cout << "1" << endl;

    cout << "minimum cost : " << minCost << endl;

    return 0;
}

