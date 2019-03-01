#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> places;
vector<int> prefix;
vector<int> suffix;

int main() {

    scanf("%d%d", &N, &K);
    int maxplace = 0;

    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        places.push_back(x);
        if (x > maxplace) {
            maxplace = x;
        }
        prefix.push_back(maxplace);
    }

    int maxsuffix = 0;
    for (int i=N-1; i>=0; i--) {
        if (places[i] > maxsuffix) {
            maxsuffix = places[i];
        }
        suffix.push_back(maxsuffix);
    }

    reverse(suffix.begin(), suffix.end());

    int maxscore = 0;
    for (int i=N-K-1; i<K; i++) {
        int maxright = suffix[i+1];
        int maxleft = prefix[i];
        if (maxleft + maxright > maxscore && maxleft != maxright) {
            maxscore = maxleft + maxright;
        }
    }

    if (K == N) {
        maxscore = maxplace;
    }

    printf("%d\n", maxscore);

    return 0;
}