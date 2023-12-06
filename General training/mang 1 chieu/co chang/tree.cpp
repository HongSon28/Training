#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x[n];
    vector<int>res(n),p(n);
    int mn=n;
    for (int i=1;i<=1000;i++) {
        x[0]=i;
        for (int j=1;j<n;j++) {
            x[j]=x[j-1]+k;
        }
        int cnt=0;
        for (int j=0;j<n;j++) {
            if (x[j]-a[j]!=0) {
                cnt++;
                p[j]=x[j]-a[j];
            } else {
                p[j]=0;
            }
        }
        if (cnt<mn) {
            mn=cnt;
            res=p;
        }
    }
    cout<<mn<<endl;
    for (int i=0;i<n;i++) {
        if (res[i]!=0) {
            if (res[i]>0) {
                cout<<"+ "<<i+1<<" "<<abs(res[i])<<endl;
            } else {
                cout<<"- "<<i+1<<" "<<abs(res[i])<<endl;
            }
        }
    }
}
