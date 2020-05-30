#include<bits/stdc++.h>
using namespace std;

vector<int>phi;

void phi_1_to_n(int n) {
    phi.resize(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}

int main()
{
    int n=10;
    phi_1_to_n(n);
    cout<<phi[n]<<endl;
    return 0;
}
