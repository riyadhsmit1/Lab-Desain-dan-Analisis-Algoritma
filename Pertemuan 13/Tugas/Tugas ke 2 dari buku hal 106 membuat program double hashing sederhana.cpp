#include <bits/stdc++.h>

using namespace std;

#define TABLE_SIZE 7
#define PRIME 7

vector < int > hash_table(TABLE_SIZE, -1);
int size = 0;

int h1(int key) {
  return (key % TABLE_SIZE);
}

int h2(int key) {
  return (PRIME - (key % PRIME));
}

void insert(int key) {
  if (size == TABLE_SIZE)
    return;

  int idx = h1(key);

  if (hash_table[idx] != -1) {
    int idx2 = h2(key);
    int i = 1;
    while (1) {
      int newidx = (idx + i * idx2) % TABLE_SIZE;

      if (hash_table[newidx] == -1) {
        hash_table[newidx] = key;
        break;
      }
      i++;
    }
  } else
    hash_table[idx] = key;
  size++;
}

void display() {
  cout << "Hash Table" << endl;
  for (int i = 0; i < TABLE_SIZE; i++)
    if (hash_table[i] != -1)
      cout << i << " --> " << hash_table[i] << endl;
    else
      cout << i << " --> Ø" << endl;
}

int main() {
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    insert(x);
  }

  display();
  return 0;
}
