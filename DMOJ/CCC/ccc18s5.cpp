#include <bits/stdc++.h>

using namespace std;

int N, M, P, Q;
vector<pair<int, pair<int, int>>> edges;
int root[40402];

int find(int node) {
    int parent = node;
    while (parent != root[parent]) {
        parent = root[parent];
    }
    return parent;
}

int main() {
    scanf("%d%d%d%d", &N, &M, &P, &Q);
    for (int i=0; i<P; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for (int j=0; j<N; j++) {
            edges.emplace_back(make_pair(c, make_pair(j*M+(a-1), j*M+(b-1))));
        }
    }

    for (int i=0; i<Q; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for (int j=0; j<M; j++) {
            edges.emplace_back(make_pair(z, make_pair((x-1)*M+j, (y-1)*M+j)));
        }
    }

    sort(edges.begin(), edges.end());

    long long savedEnergy = 0;

    for (int i=0; i<=N*M; i++) {
        root[i] = i;
    }

    for (int i=0; i<edges.size(); i++) {
        pair<int, pair<int, int>> curEdge = edges[i];
        if (find(curEdge.second.first) != find(curEdge.second.second)) {
            root[find(curEdge.second.second)] = curEdge.second.first;
        } else {
            savedEnergy += curEdge.first;
        }
    }

    printf("%lld\n", savedEnergy);

    return 0;
}