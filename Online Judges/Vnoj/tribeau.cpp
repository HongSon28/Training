#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a[3];
    int dem=0;
    long long b;
    cin>>a[0]>>a[1]>>a[2]>>b;
    sort(a,a+3);
    if (a[2]-a[1]>b)
        dem+=1;
    if (a[2]-a[0]>b)
        dem+=1;
    if (a[1]-a[0]>b)
        dem+=1;
    if (dem>=1)
        cout<<"No";
    else
        cout<<"Yes";
}
