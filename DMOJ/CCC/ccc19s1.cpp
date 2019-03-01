#include <bits/stdc++.h>

using namespace std;

int N;
int mirror[2][2] = {{1, 2},
                    {3, 4}};
int newMirror[2][2];
char seq[1000001];

int main() {

    scanf("%s", &seq[0]);

    bool hflip = false;
    bool vflip = false;

    for (int i = 0; i < strlen(seq); i++) {
        if (seq[i] == 'H') {
            hflip = !hflip;
        } else {
            vflip = !vflip;
        }
    }

    if (hflip && vflip) {
        printf("4 3\n2 1");
    } else if (hflip) {
        printf("3 4\n1 2");
    } else if (vflip){
        printf("2 1\n4 3");
    } else {
        printf("1 2\n3 4");
    }
    return 0;
}