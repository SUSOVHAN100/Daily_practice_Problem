#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 2; i <= n; i++) {
        int temp = i;
        int cnt = 0;

        for (int j = 2; j * j <= temp; j++) {
            if (temp % j == 0) {
                cnt++;

                while (temp % j == 0)
                    temp /= j;
            }
        }

        if (temp > 1)
            cnt++;

        if (cnt == 2)
            ans++;
    }

    cout << ans;

    return 0;
}