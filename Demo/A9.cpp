#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d;
    cin>>n>>d;
    float v[n];
    float t[n];
    for (int i=0;i<n;i++) {
        cin>>v[i];
        t[i]=d/v[i]+i;
    }
    int res=0;
    for (int i=1;i<n;i++) {
        for (int j=i-1;j>=0;j--) {
            if (t[i]<t[j])
                res++;
        }
    }
    cout<<res;
}
