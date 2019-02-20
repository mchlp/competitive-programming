#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {

    stack<int> from;
    stack<int> side;

    scanf("%d", &T);
    while (T--) {
        from = stack<int>();
        side = stack<int>();
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            from.push(x);
        }

        int curCar = 1;
        bool good = true;
        while (!from.empty() || !side.empty()) {
            if (!from.empty() && from.top() == curCar) {
                from.pop();
                curCar++;
            } else if (!side.empty() && side.top() == curCar) {
                side.pop();
                curCar++;
            } else {
                if (!from.empty()) {
                    side.push(from.top());
                    from.pop();
                } else {
                    printf("N\n");
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            printf("Y\n");
        }
    }
    return 0;
}