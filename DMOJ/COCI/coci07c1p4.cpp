#include<bits/stdc++.h>

using namespace std;

int N, mod = 100000, flag = 0;
long long dp[202][202];
char line[202];

bool openBracket(int p) {
    return line[p] == '(' || line[p] == '[' || line[p] == '{';
}

bool closeBracket(int p) {
    return line[p] == ')' || line[p] == ']' || line[p] == '}';
}

long long getDp(int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (dp[left][right] == -1) {
        dp[left][right] = 0;
        for (int middle = left + 1; middle <= right; middle += 2) {
            if (closeBracket(left) || openBracket(middle)) {
                continue;
            }
            if (line[left] == '?' && line[middle] == '?') {
                dp[left][right] += 3LL * getDp(left + 1, middle) * getDp(middle+1, right);
            } else if (line[left] == '?' || line[middle] == '?' || (line[left] == '(' && line[middle] == ')') || (line[left] == '[' && line[middle] == ']') || (line[left] == '{' && line[middle] == '}')) {
                dp[left][right] += 1LL * getDp(left+1, middle-1)*getDp(middle+1, right);
            }
        }
        if (dp[left][right] >= mod) {
            flag = 1;
            dp[left][right] %= mod;
        }
    }
    return dp[left][right];
}

int main() {

    scanf("%d\n", &N);
    scanf("%s", &line[0]);

    memset(dp, -1, sizeof dp);
    long long ans = getDp(0, N-1);
    if (flag) {
        printf("%05lld\n", ans);
    } else {
        printf("%lld\n", ans);
    }

    return 0;
}