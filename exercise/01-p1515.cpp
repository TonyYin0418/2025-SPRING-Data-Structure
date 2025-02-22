/*
第一周练习
洛谷P1515 旅行
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a, b, n;
int d[100] = {
    0, 990, 1010, 1970, 2030, 
    2940, 3060, 3930, 4060, 4970, 
    5030, 5990, 6010, 7000
};
int f[100];
int main() {
    cin >> a >> b >> n;
    n += 14;
    for(int i = 14; i < n; i++) cin >> d[i];
    sort(d, d + n);
    f[0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(d[i] - d[j] >= a && d[i] - d[j] <= b) {
                f[i] += f[j];
            }
        }
    }
    cout << f[n - 1] << endl;
    return 0;
}