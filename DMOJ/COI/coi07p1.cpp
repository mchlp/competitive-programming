#include <bits/stdc++.h>

using namespace std;

double K;
int N;

int main() {
    scanf("%lf%d", &K, &N);
    double dis = 0;
    double time = 0;
    for (int i=0; i<N; i++) {
        double curDis;
        scanf("%lf", &curDis);
        if (curDis - dis - K > 0) {
            time += (curDis - dis - K) * 0.5;
        }
        dis = curDis;
    }

    printf("%.3lf\n", time);

    return 0;
}