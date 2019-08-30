#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    bool rotated[matrix.size()][matrix.size()];
    memset(&rotated[0][0], false, sizeof(rotated));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (!rotated[j][i]) {
                int x = j;
                int y = i;
                int temp = matrix[y][x];
                for (int k = 0; k < 4; k++) {
                    rotated[y][x] = true;
                    int newTemp = matrix[x][matrix.size() - y - 1];
                    matrix[x][matrix.size() - y - 1] = temp;
                    temp = newTemp;
                    int tempX = x;
                    x = matrix.size() - y - 1;
                    y = tempX;
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    rotate(matrix);
    return 0;
}