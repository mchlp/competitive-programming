#include<bits/stdc++.h>

using namespace std;

char word[10001];

int main() {
    scanf("%s", &word[0]);
    long long lcount = 0;
    long long ocount = 0;
    long long vcount = 0;
    long long ecount = 0;
    for (int i=strlen(word)-1; i>=0; i--) {
        if (word[i] == 'l') {
            lcount += ocount;
        } else if (word[i] == 'o') {
            ocount += vcount;
        } else if (word[i] == 'v') {
            vcount += ecount;
        } else if (word[i] == 'e') {
            ecount++;
        }
    }
    printf("%lld\n", lcount);
}