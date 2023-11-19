#include<bits/stdc++.h>
using namespace std;
int n;
int res=INT_MAX,sum;
int a[100][100];
int c1[100],c2[100],c3[100];
bool check(int i,int j) {
    if (c1[j]==false&&c2[i-j+11]==false&&c3[i+j-2]==false)
        return true;
    return false;
}
void rec(int i) {
    for (int j=1;j<=n;j++) {
        if (check(i,j)==true) {
            c1[j]=true;
            c2[i-j+11]=true;
            c3[i+j-2]=true;
            sum+=a[i][j];
            if (i==n) res=min(res,sum);
            else rec(i+1);
            c1[j]=false;
            c2[i-j+11]=false;
            c3[i+j-2]=false;
            sum-=a[i][j];
        }
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    rec(1);
    cout<<res;
}
