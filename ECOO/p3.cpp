#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> ranges;

void leftFold(int P) {

}

void rightFold(int P) {

}

int main(){

    freopen("DATA31.txt", "r", stdin);

    int _=10;
    while (_--) {
        int N, M;
        ranges.clear();
        scanf("%d%d\n", &N, &M);

        ranges[0] = 1;
        ranges[N] = -1;

        for (int i=0; i<M; i++) {
            char c;
            int p;
            cin >> p >> c;
        }

        int len = ranges[ranges.size()-1] - ranges[0];

        int maxT = 0;
        int curT = 0;

        for (int i=0; i<ranges.size(); i++) {
            curT += ranges[i];
            if (curT > maxT) {
                maxT = curT;
            }
        }

        printf("%d %d\n", len, maxT);
    }

    return 0;
}
