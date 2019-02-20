#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, vector<int>> edges[1002][1002];
int graph[102][102];

int parent[102];
vector<pair<int, pair<int, int>>> insideEdges;
vector<pair<int, pair<int, int>>> outsideEdges;

int getParent(int node) {
    while (parent[node] != node) {
        node = parent[node];
    }
    return node;
}

int mst(vector<pair<int, pair<int, int>>>* edges) {

    for (int i=0; i<=N; i++) {
        parent[i] = i;
    }

    int weight = 0;

    for (pair<int, pair<int, int>> edge : *edges) {
        if (getParent(edge.second.first) != getParent(edge.second.second)) {
            parent[getParent(edge.second.second)] = parent[getParent(edge.second.first)];
            weight += edge.first;
        }
    }

    return weight;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int numEdges;
        scanf("%d", &numEdges);
        vector<int> corners;
        vector<int> weights;
        for (int j = 0; j < numEdges; j++) {
            int x;
            scanf("%d", &x);
            corners.push_back(x);
        }
        for (int j = 0; j < numEdges; j++) {
            int x;
            scanf("%d", &x);
            weights.push_back(x);
        }
        for (int j = 1; j < numEdges; j++) {
            edges[corners[j - 1]][corners[j]].first = weights[j - 1];
            edges[corners[j]][corners[j - 1]].first = weights[j - 1];
            edges[corners[j - 1]][corners[j]].second.push_back(i);
            edges[corners[j]][corners[j - 1]].second.push_back(i);
        }
        edges[corners[0]][corners[numEdges - 1]].first = weights[numEdges - 1];
        edges[corners[numEdges - 1]][corners[0]].first = weights[numEdges - 1];
        edges[corners[0]][corners[numEdges - 1]].second.push_back(i);
        edges[corners[numEdges - 1]][corners[0]].second.push_back(i);
    }

    memset(&graph[0][0], -1, sizeof graph);

    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            if (edges[i][j].second.size() == 1) {
                if (graph[0][edges[i][j].second[0]] == -1 || graph[0][edges[i][j].second[0]] > edges[i][j].first) {
                    graph[0][edges[i][j].second[0]] = edges[i][j].first;
                    graph[edges[i][j].second[0]][0] = edges[i][j].first;
                }
                outsideEdges.push_back(make_pair(edges[i][j].first, make_pair(0, edges[i][j].second[0])));

            } else if (edges[i][j].second.size() == 2) {
                if (graph[edges[i][j].second[1]][edges[i][j].second[0]] == -1 ||
                    graph[edges[i][j].second[1]][edges[i][j].second[0]] > edges[i][j].first) {
                    graph[edges[i][j].second[1]][edges[i][j].second[0]] = edges[i][j].first;
                    graph[edges[i][j].second[0]][edges[i][j].second[1]] = edges[i][j].first;
                }
                insideEdges.push_back(make_pair(edges[i][j].first, make_pair(edges[i][j].second[0], edges[i][j].second[1])));
                outsideEdges.push_back(make_pair(edges[i][j].first, make_pair(edges[i][j].second[0], edges[i][j].second[1])));
            }
        }
    }

    sort(insideEdges.begin(), insideEdges.end());
    sort(outsideEdges.begin(), outsideEdges.end());

    int insideSum = mst(&insideEdges);
    int outsideSum = mst(&outsideEdges);

    printf("%d\n", min(insideSum, outsideSum));

    return 0;
}