#include <bits/stdc++.h>

using namespace std;

map<int, int> ranges;
map<int, int> newRanges;

void leftFold(int P) {
    newRanges = ranges;
    if (P > ranges.begin()->first && P <= (--ranges.end())->first) {
        int thick = 0;
        for (auto iter = ranges.begin(); iter != ranges.end(); iter++) {
            if (iter->first >= P) {
                break;
            }

            int ind = iter->first;
            int val = iter->second;

            thick += val;

            newRanges.erase(iter->first);

            if (newRanges.count(P + (P - ind)) == 0) {
                newRanges[P + (P - ind)] = -val;
            } else {
                newRanges[P + (P - ind)] -= val;
            }
        }

        if (newRanges.count(P) == 0) {
            newRanges[P] = thick * 2;
        } else {
            newRanges[P] += thick*2;
        }
    }
    ranges = newRanges;
}

void rightFold(int P) {
    newRanges = ranges;
    if (P >= ranges.begin()->first && P < (--ranges.end())->first) {
        int thick = 0;
        for (auto iter = ranges.rbegin(); iter != ranges.rend(); iter++) {
            if (iter->first <= P) {
                break;
            }

            int ind = iter->first;
            int val = iter->second;

            thick -= val;

            newRanges.erase(iter->first);

            if (newRanges.count(P - (ind - P) + 2) == 0) {
                newRanges[P - (ind - P) + 2] = -val;
            } else {
                newRanges[P - (ind - P) + 2] -= val;
            }
        }

        if (newRanges.count(P + 1) == 0) {
            newRanges[P + 1] = -thick * 2;
        } else {
            newRanges[P + 1] -= (thick + thick);
        }
    }
    ranges = newRanges;
}

int main() {

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
