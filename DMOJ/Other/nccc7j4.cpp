#include <bits/stdc++.h>

using namespace std;

int main() {

    char spellStr[10000000];
    char availStr[10000000];

    cin.getline(spellStr, 10000000);
    cin.getline(availStr, 10000000);

    long long buy = 0;
    for (int i=0; i<26; i++) {
        long long diff = count(begin(spellStr), begin(spellStr)+strlen(spellStr), 'A'+i) - count(begin(availStr), begin(availStr)+strlen(availStr), 'A'+i);
        if (diff > 0) {
            buy += diff;
        }
    }

    printf("%lld\n", buy);

    return 0;
}