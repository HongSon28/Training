#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    long long sum[n+1][n+1];
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<n+1;j++) {
            if ((i==0)||(j==0)) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i-1][j-1];
            }
        }
    }
    int mx=INT_MIN;
    int dong,cot,cao,rong;
    for (int i=0;i<=n-2;i++) {
        for (int j=0;j<=n-2;j++) {
            for (int i1=i+1;i1<n;i1++) {
                for (int j1=j+1;j1<n;j1++) {
                    int tong=sum[i1+1][j1+1]-sum[i1+1][j]-sum[i][j1+1]+sum[i][j];
                    if (mx<tong) {
                        mx=tong;
                        dong=i+1;
                        cot=j+1;
                        cao=i1-i+1;
                        rong=j1-j+1;
                    }
                }
            }
        }
    }
    cout<<dong<<" "<<cot<<" "<<cao<<" "<<rong<<endl;
    cout<<mx;
}
