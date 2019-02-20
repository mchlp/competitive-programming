#include <bits/stdc++.h>

using namespace std;

int N;
bool start[200001];
bool final[200001];

void press(int x) {
    if (start[x] == start[x + 1]) {
        start[x] = !start[x];
        start[x + 1] = !start[x + 1];
    }
}

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);
        start[i] = (c == 'F');
    }
    scanf("\n");
    for (int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);
        final[i] = c == 'F';
    }

    int X = 10000;
    while (X--) {
        bool same = true;
        for (int j = 0; j < N; j++) {
            if (start[j] != final[j]) {
                same = false;
                break;
            }
        }
        if (!same) {
            for (int i = 0; i < N; i++) {
                if (start[i] != final[i]) {
                    if (i < N - 1) {
                        if (start[i] == start[i + 1]) {
                            press(i);
                        }
                    } else {
                        if (start[i] == start[i-1]) {
                            press(i-1);
                        }
                    }
                }
            }
        } else {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}