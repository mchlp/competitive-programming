#include<bits/stdc++.h>

using namespace std;

int main() {
    int jelly = 0;
    bool j = false;
    for (int i = 0; i < 7; i++) {
        char c;
        scanf("%c\n", &c);
        if (c == 'J') {
            if (!j) {
                j = true;
                jelly++;
            }
        } else {
            j = false;
        }
    }
    printf("%d\n", jelly);
}