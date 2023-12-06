#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<long> s(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++)
    {
        int j = 0;
        while (j<n && (a[i]<=a[j]||j<=i))
        {
            if (a[j]<a[i])
                s[i] = 0;
            else
                s[i]+=a[i];
            j++;
        }
    }
    cout << *max_element(s.begin(), s.end());
}
