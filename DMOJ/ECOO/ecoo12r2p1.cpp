#include <bits/stdc++.h>

using namespace std;

bool primes[500001];

int main() {

    memset(primes, true, sizeof primes);
    for (int i=2; i<708; i++) {
        for (int j=i*2; j<500001; j+=i) {
            primes[j] = false;
        }
    }

    int _=5;
    while (_--) {
        int n;
        vector<long long> nums;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            long long x;
            scanf("%lld", &x);
            nums.push_back(x);
        }

        for (int i=2; i<500001; i++) {
            if (primes[i]) {
                bool good = true;
                string msg = "";
                for (long long num : nums) {
                    if (num % i == 0) {
                        int ognum = num / i;
                        int num1 = ognum / 100;
                        int num2 = ognum % 100;
                        if (num1 >= 0 && num1 < 31 && num2 >= 0 && num2 < 31) {
                            if (num1 == 0) {
                                msg += ' ';
                            } else if (num1 == 27) {
                                msg += '.';
                            } else if (num1 == 28) {
                                msg += ',';
                            } else if (num1 == 29) {
                                msg += '!';
                            } else if (num1 == 30) {
                                msg += '?';
                            } else {
                                msg += (char)('A' + num1-1);
                            }

                            if (num2 == 0) {
                                msg += ' ';
                            } else if (num2 == 27) {
                                msg += '.';
                            } else if (num2 == 28) {
                                msg += ',';
                            } else if (num2 == 29) {
                                msg += '!';
                            } else if (num2 == 30) {
                                msg += '?';
                            } else {
                                msg += (char)('A' + num2-1);
                            }
                        } else {
                            good = false;
                            break;
                        }
                    } else {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    cout << msg << endl;
                    break;
                }
            }
        }
    }

    return 0;
}