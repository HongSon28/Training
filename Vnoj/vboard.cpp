#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int a[N+5][N+5];
int q;
int sum_white[N+5][N+5];
int sum_black[N+5][N+5];
int i1,j11,i2,j2;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if ((i+j)%2==0) {
                sum_white[i][j]=sum_white[i-1][j]+sum_white[i][j-1]-sum_white[i-1][j-1]+a[i][j];
                sum_black[i][j]=sum_black[i-1][j]+sum_black[i][j-1]-sum_black[i-1][j-1];
            } else {
                sum_white[i][j]=sum_white[i-1][j]+sum_white[i][j-1]-sum_white[i-1][j-1];
                sum_black[i][j]=sum_black[i-1][j]+sum_black[i][j-1]-sum_black[i-1][j-1]+a[i][j];
            }
        }
    }
    cin>>q;
    while(q--) {
        cin>>i1>>j11>>i2>>j2;
        int sum1=sum_white[i2][j2]-sum_white[i1-1][j2]-sum_white[i2][j11-1]+sum_white[i1-1][j11-1];
        int sum2=sum_black[i2][j2]-sum_black[i1-1][j2]-sum_black[i2][j11-1]+sum_black[i1-1][j11-1];
        cout<<abs(sum1-sum2)<<endl;
    }
}
