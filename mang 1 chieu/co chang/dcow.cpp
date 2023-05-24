#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c[1001]={};
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        c[temp]++;
    }
    int res=0;
    for (int i=0;i<=1000;i++)
        res+=c[i]*(c[i]-1)/2;
    cout<<res;
}
