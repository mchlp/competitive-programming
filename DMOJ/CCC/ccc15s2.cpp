#include <bits/stdc++.h>

using namespace std;

int J, A;
char shirts[1000001];

int main() {

    for (int i = 0; i < 1000001; i++) {
        shirts[i] = 'X';
    }

    scanf("%d%d", &J, &A);
    for (int i = 0; i < J; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'S')
            shirts[i + 1] = 0;
        else if (c == 'M')
            shirts[i + 1] = 1;
        else if (c == 'L')
            shirts[i + 1] = 2;
    }

    int count = 0;
    for (int i = 0; i < A; i++) {
        char c;
        int n;
        int s;
        scanf(" %c%d", &c, &n);
        if (c == 'S')
            s = 0;
        else if (c == 'M')
            s = 1;
        else if (c == 'L')
            s = 2;
        if (n < 1 || n > J) {
            continue;
        }
        if (s <= shirts[n]) {
            count++;
            shirts[n] = -1;
        }
    }
    printf("%d\n", count);

    return 0;
}