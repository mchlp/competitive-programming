#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> verts;

long long getDisSquared(pair<int, int> v1, pair<int, int> v2) {
    return (v1.first - v2.first) * (v1.first - v2.first) + (v1.second - v2.second) * (v1.second - v2.second);
}

bool same(pair<int, int> v1, pair<int, int> v2) {
    return (v1.first == v2.first && v1.second == v2.second);
}

int main() {
    freopen("DATA22.txt", "r", stdin);
    int _ = 10;
    while (_--) {
        verts.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            verts.push_back(make_pair(x, y));
        }

        if (N % 2 == 1) {
            printf("0\n");
        } else {
            int numSym = 0;
            for (int i = 0; i < N / 2; i++) {
                pair<int, int> top = verts[i];
                pair<int, int> bottom = verts[i + N / 2];

                bool sym = true;

                for (int j = 0; j < N / 2; j++) {
                    int v1Ind = ((i + j) + N) % N;
                    int v2Ind = ((i - j) + N) % N;
                    if (!same(top, verts[v1Ind]) && !same(bottom, verts[v1Ind]) && !same(top, verts[v2Ind]) &&
                        !same(bottom, verts[v2Ind])) {

                        pair<long long, long long> curDis;
                        curDis.first = getDisSquared(top, verts[v1Ind]);
                        curDis.second = getDisSquared(bottom, verts[v1Ind]);

                        pair<long long, long long> oppDis;
                        oppDis.first = getDisSquared(top, verts[v2Ind]);
                        oppDis.second = getDisSquared(bottom, verts[v2Ind]);

                        if (!same(curDis, oppDis)) {
                            sym = false;
                            break;
                        }
                    }
                }

                if (sym) {
                    numSym++;
                }

            }
            printf("%d\n", numSym);
        }
    }
}