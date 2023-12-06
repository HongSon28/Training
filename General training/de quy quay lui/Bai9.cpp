#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int sum=0;
bool c1[12],c2[12];
int n,k;
int mx=0,cnt=1;
void dequy(int m,int li) {
    for (int i=li;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (c1[i]==true&&c2[j]==true) {
                c1[i]=false;
                c2[j]=false;
                sum+=a[i][j];
                if (m==k) {
                    if (sum>mx) {
                        mx=sum;
                        cnt=1;
                    } else if (sum==mx) {
                        cnt++;
                    }
                } else {
                    dequy(m+1,i+1);
                }
                c1[i]=true;
                c2[j]=true;
                sum-=a[i][j];
            }
        }
    }
}
int main() {
    memset(c1,true,sizeof(c1));
    memset(c2,true,sizeof(c2));
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    dequy(1,1);
    cout<<mx<<" "<<cnt;
}
