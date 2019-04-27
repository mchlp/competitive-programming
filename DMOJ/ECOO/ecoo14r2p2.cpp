#include <bits/stdc++.h>

using namespace std;

pair<int, int> spots[5];
bool grey[5];

int main() {

    int _ = 10;
    while (_--) {

        memset(grey, true, sizeof grey);

        int N;
        cin >> N;

        for (int i = 0; i < 5; i++) {
            int r, c;
            cin >> r >> c;
            spots[i] = make_pair(r - 1, c - 1);
        }

        for (int i = 1; i <= floor(sqrt(N)); i++) {
            if (N % i == 0) {
                for (int j = 0; j < 5; j++) {
                    if ((spots[j].first / i) % 2 == (spots[j].second / i) % 2) {
                        grey[j] = !grey[j];
                    }
                    if (N / i != i) {
                        if ((spots[j].first / (N / i)) % 2 == (spots[j].second / (N / i)) % 2) {
                            grey[j] = !grey[j];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (grey[i]) {
                printf("G");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }

    return 0;
}