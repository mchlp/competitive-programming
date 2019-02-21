#include <bits/stdc++.h>

using namespace std;

int N, M, D;
vector<pair<pair<int, int>, pair<int, int>>> edges;
int parents[1002];

int findParent(int node) {
    while (node != parents[node]) {
        node = parents[node];
    }
    return node;
}
int mst(vector<pair<pair<int, int>, pair<int, int>>> *edges) {
    for (int i = 0; i <= N; i++) {
        parents[i] = i;
    }
    int acount = 0;
    for (pair<pair<int, int>, pair<int, int>> edge : *edges) {
        if (findParent(edge.second.first) != findParent(edge.second.second)) {
            parents[findParent(edge.second.first)] = findParent(edge.second.second);
            if (edge.first.second > N-1) {
                acount++;
            }
        }
    }
    return acount;
}


int main() {
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back(make_pair(make_pair(c, i+1), make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    printf("%d\n", mst(&edges));
}
