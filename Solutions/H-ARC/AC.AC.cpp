#include <bits/stdc++.h>
using namespace std;

using mat = vector<vector<char>>; 

mat apply_1(mat &input) {
    mat out(4, vector<char>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (input[i][j] != '0') {
                out[i][j] = '0';
            } else {
                out[i][j] = '1';
            }
        }
    }
    return out;
}

mat apply_2(mat &input) {
    mat out(4, vector<char>(4, '0'));
    out[1][1] = input[0][0];
    out[1][2] = input[0][3];
    out[2][1] = input[3][0];
    out[2][2] = input[3][3];
    return out;
}

mat apply_3(mat &input) {
    mat out(4, vector<char>(4, '0'));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (input[i][j + 2] != '0') {
                out[i][1 - j] = input[i][j + 2];
            } else {
                out[i][1 - j] = input[i][1 - j];
            }
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<mat> input(4, mat(4, vector<char>(4))), output(4, mat(4, vector<char>(4)));
    for (int i = 0; i < 3; ++i) {
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                cin >> input[i][x][y];
            }
        }
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                cin >> output[i][x][y];
            }
        }
    }

    mat test(4, vector<char>(4)), ans;
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            cin >> test[x][y];
        }
    }

    bool flag = true;
    for (int i = 0; i < 3; i++) {
        if (apply_1(input[i]) != output[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        ans = apply_1(test);
    }

    flag = true;
    for (int i = 0; i < 3; i++) {
        if (apply_2(input[i]) != output[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        ans = apply_2(test);
    }

    flag = true;
    for (int i = 0; i < 3; i++) {
        if (apply_3(input[i]) != output[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        ans = apply_3(test);
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}