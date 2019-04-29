#include <bits/stdc++.h>

using namespace std;

map<int, int> ranges;

void leftFold(int P) {
    if (P > 0) {
        int thick = 0;
        for (auto iter = ranges.begin(); iter != ranges.end(); iter++) {
            if (iter->first >= P) {
                break;
            }

            int ind = iter->first;
            int val = iter->second;

            thick += val;

            ranges.erase(iter->first);

            if (ranges.count(P + (P - ind)) == 0) {
                ranges[P + (P - ind)] = -val;
            } else {
                ranges[P + (P - ind)] -= val;
            }
        }

        if (ranges.count(P) == 0) {
            ranges[P] = thick * 2;
        } else {
            ranges[P] += thick + thick + ranges[P];
        }
    }
}

void rightFold(int P) {

}

int main() {

    freopen("DATA31.txt", "r", stdin);

    int _ = 10;
    while (_--) {
        int N, M;
        ranges.clear();
        scanf("%d%d\n", &N, &M);

        ranges[0] = 1;
        ranges[N] = -1;

        for (int i = 0; i < M; i++) {
            char c;
            int p;
            cin >> p >> c;
            if (c == 'L') {
                leftFold(p - 1);
            } else {
                rightFold(p - 1);
            }
        }

        int len = (--ranges.end())->first - (ranges.begin())->first;

        int maxT = 0;
        int curT = 0;

        for (auto ele : ranges) {
            curT += ele.second;
            if (curT > maxT) {
                maxT = curT;
            }
        }

        printf("%d %d\n", len, maxT);
    }

    return 0;
}
