#include <bits/stdc++.h>

using namespace std;

long double pic[1001][1001];
int N, M;

long double checkExposure(long double c) {
    long double total = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            total += pic[i][j] * c > 1 ? 1 : pic[i][j] * c;
        }
    }
    return total/(N*M);
}

int main() {
    scanf("%d%d", &N, &M);
    long double total = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%Lf", &pic[i][j]);
            total += pic[i][j];
        }
    }

    long double expose = total/(N*M);
    if (expose - 0.48 < -0.001) {
        printf("underexposed\n");
    } else if (expose - 0.48 > 0.001) {
        printf("overexposed\n");
    } else {
        printf("correctly exposed\n");
        return 0;
    }

    long double start = 0;
    long double end = 1000;
    while (true) {
        long double check = (start + end)/2;
        expose = checkExposure(check);
        if (abs(expose - 0.48) < 10e-10) {
            printf("%Lf\n", check);
            break;
        } else if (expose > 0.48) {
            end = check;
        } else {
            start = check;
        }
    }

}