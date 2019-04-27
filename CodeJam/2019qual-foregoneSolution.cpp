#include<bits/stdc++.h>

using namespace std;

int N;

bool hasFour(int num) {
    if (num % 10 == 4) {
        return true;
    }
    for (int i = 1; i < ceil(log(num)); i++) {
        if (num % (int) (pow(10, i)) / (int) (pow(10, i - 1)) == 4) {
            return true;
        }
    }
    return false;
}

int main() {

    scanf("%d", &N);
    for (int _ = 1; _ <= N; _++) {
        int num;
        scanf("%d", &num);

        int num1 = 0;
        int num2 = 0;

        for (int i = 0; i <= ceil(log(num)); i++) {
            if (num % (int) (pow(10, i)) / (i == 0 ? 1 : (int) (pow(10, i - 1))) == 4) {
                num1 += 3 * (int) pow(10 , i-1);
                num2 += (int) pow(10 , i-1);
            } else {
                num1 += num % (int) (pow(10, i)) / (i == 0 ? 1 : (int) (pow(10, i - 1))) * (int) pow(10 , i-1);
            }
        }

        printf("Case #%d: %d %d\n", _, num1, num2);
    }

    return 0;
}