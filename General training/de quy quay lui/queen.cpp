#include<bits/stdc++.h>
using namespace std;
int n, cnt=0;
int a[21];
bool c1[13],c2[23],c3[23];
bool check(int i,int j) {
    if (c1[j]==true&&c2[i-j+11]==true&&c3[i+j-2]==true)
        return true;
    return false;
}
void out() {
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
void rec(int i) {
    for (int j=1;j<=n;j++) {
        if (check(i,j)==true) {
            c1[j]=false;
            c2[i-j+11]=false;
            c3[i+j-2]=false;
            a[i]=j;
            if (i==n)
                out();
            else
                rec(i+1);
            c1[j]=true;
            c2[i-j+11]=true;
            c3[i+j-2]=true;
        }
    }
}
int main() {
    memset(c1,true,sizeof(c1));
    memset(c2,true,sizeof(c2));
    memset(c3,true,sizeof(c3));
    cin>>n;
    rec(1);
}

