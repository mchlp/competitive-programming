#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int N;
vector<int> nums;

int main() {
    scanf("%d", &N);

    int onecount = 0;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            onecount++;
        }
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    long long minSum;
    long long maxSum;
    if (onecount > 0) {
        minSum = 1;
        if (onecount > 4) {
            long long maxProduct = 0;
            for (int i=2; i<onecount; i++) {
                long long curProduct = ((long long) pow(i, (onecount/i)) % MOD) *  max(1, (onecount - (i*(onecount/i))));
                if (curProduct > maxProduct) {
                    maxProduct = curProduct % MOD;
                }
            }
            maxSum = maxProduct;
        } else {
            maxSum = onecount;
        }
    } else {
        minSum = nums[0];
        maxSum = nums[0];
        onecount++;
    }

    for (int i = onecount; i < N; i++) {
        if (nums[i] == 1) {
            maxSum++;
        } else {
            if (minSum == 1) {
                minSum *= nums[i] % MOD;
            } else {
                minSum += nums[i] % MOD;
            }
            if (maxSum == 1) {
                maxSum += nums[i] % MOD;
            } else {
                maxSum *= nums[i] % MOD;
            }
        }
    }

    printf("%lld\n%lld\n", minSum % MOD, maxSum % MOD);

    return 0;
}