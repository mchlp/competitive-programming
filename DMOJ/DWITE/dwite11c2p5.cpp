#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> names;
int N;
int parent[100000];


int find(int n) {
    while (n != parent[n]) {
        n = parent[n];
    }
    return n;
}

void compress(int n, int p) {
    while (n != parent[n]) {
        int lastn = n;
        n = parent[n];
        parent[lastn] = p;
    }
    parent[n] = p;
}

void connect(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    compress(a, min(pa, pb));
    compress(b, min(pa, pb));
}

int main() {
    int _=5;
    while (_--) {
        memset(parent, -1, sizeof parent);
        names.clear();
        int cityCount = 0;
        cin >> N;
        while (N--) {
            char s;
            string a, b;
            cin >> s >> a >> b;
            if (s == 'p') {
                if (names.count(a) == 0) {
                    names[a] = cityCount;
                    parent[names[a]] = names[a];
                    cityCount++;
                }
                if (names.count(b) == 0) {
                    names[b] = cityCount;
                    parent[names[b]] = names[b];
                    cityCount++;
                }

                connect(min(names[a], names[b]), max(names[a], names[b]));
            } else {
                if ((names.count(a) != 0 && names.count(b) !=0 && find(names[a]) == find(names[b])) || a == b) {
                    printf("connected\n");
                } else {
                    printf("not connected\n");
                }
            }
        }
    }


    return 0;
}