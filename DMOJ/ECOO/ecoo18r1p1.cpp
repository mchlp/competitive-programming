#include<bits/stdc++.h>

using namespace std;

int main() {
    int N = 10;
    while (N--) {
        int days, t;
        int empty = 0;
        bool box = false;
        scanf("%d %d", &t, &days);
        int numBox = 0;
        for (int i=0; i<days; i++) {
            char b;
            cin >> b;
            if (b == 'B') {
                numBox++;
                box = true;
            } else {
                if (!box) {
                    empty++;
                }
            }
        }
        printf("%d\n", max(numBox*t+empty - days, 0));
    }
    return 0;
}