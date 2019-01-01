#include <bits/stdc++.h>

using namespace std;

int M, N, S;
bool graph[11][11];
bool tempGraph[11][11];
vector<int> balls;

void copyGraph(bool fromGraph[11][11], bool toGraph[11][11]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            toGraph[i][j] = fromGraph[i][j];
        }
    }
}


bool check(int len) {
    for (int i=0; i < M; i++) {
        int streak = 0;
        for (int j=0; j<N; j++) {
            if (tempGraph[i][j]) {
                streak++;
                tempGraph[i][j] = false;
            } else {
                streak = 0;
                copyGraph(graph, tempGraph);
            }
            if (streak >= len) {
                copyGraph(tempGraph, graph);
                return true;
            }
        }
    }

    for (int j=0; j < N; j++) {
        int streak = 0;
        for (int i=0; i<M; i++) {
            if (tempGraph[i][j]) {
                streak++;
                tempGraph[i][j] = false;
            } else {
                streak = 0;
                copyGraph(graph, tempGraph);
            }
            if (streak >= len) {
                copyGraph(tempGraph, graph);
                return true;
            }
        }
    }

    return false;
}

int main() {


    scanf("%d %d %d", &M, &N, &S);

    while (S--) {
        int b;
        scanf("%d", &b);
        balls.push_back(b);
    }

    sort(balls.begin(), balls.end());
    scanf("\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char s;
            scanf("%c", &s);
            graph[i][j] = s == '0';
        }
        if (i < M - 1) {
            scanf("\n");
        }
    }

    for (int i=balls.size(); i>=0; i--) {
        if (!check(balls[i])) {
            printf("no");
            return 0;
        }
    }
    printf("yes");

    return 0;
}