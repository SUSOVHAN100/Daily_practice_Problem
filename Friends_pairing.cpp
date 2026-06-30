#include <bits/stdc++.h>
using namespace std;

long long countFriendsPairings(int n) {
    if (n <= 2)
        return n;

    long long a = 1;
    long long b = 2;

    for (int i = 3; i <= n; i++) {
        long long c = b + (i - 1) * a;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    cin >> n;

    cout << countFriendsPairings(n);
}