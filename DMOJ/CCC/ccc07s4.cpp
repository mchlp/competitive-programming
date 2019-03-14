#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[10001];
int ways[10001];

int main() {

    memset(ways, 0, sizeof ways);
    scanf("%d", &N);

    while (true) {
        int a, b;g
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0) {
            break;
        }
        graph[a].push_back(b);
    }

    ways[1] = 1;
    for (int i=1; i<=N; i++) {
        for (int adj : graph[i]) {
            ways[adj] += ways[i];
        }
    }

    printf("%d\n", ways[N]);

    return 0;
}