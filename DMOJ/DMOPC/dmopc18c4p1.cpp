#include<bits/stdc++.h>

double vals[1001][1001];

int main() {
    int K;
    double mx, s, c;

    scanf("%d %lf", &K, &mx);
    while (K--) {
        double x = mx;
        int n;
        scanf("%d", &n);
        while (n--) {
            double a;
            scanf("%lf", &a);
            x += a;
        }
        s += x;
        c++;
    }

    printf("%lf\n", (s/c));

    return 0;
}