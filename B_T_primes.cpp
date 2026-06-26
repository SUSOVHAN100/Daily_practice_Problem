#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int limit = 1000000;

    vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                prime[j] = false;
        }
    }

    int n;
    cin >> n;

    while (n--)
    {
        long long x;
        cin >> x;

        long long root = sqrt((long double)x);

        if (root * root == x && prime[root])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}