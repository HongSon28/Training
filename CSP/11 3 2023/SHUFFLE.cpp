#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int s1[maxn],s2[maxn],s3[maxn];
int a[maxn];
int undo(int index, int pos) {
    int i=s1[index],m=s2[index],j=s3[index];
    if (pos<j||pos>j+m-1) return pos;
    else return pos-j+i;
}
int main() {
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=1;i<=x;i++) cin>>s1[i]>>s2[i]>>s3[i];
    for (int i=1;i<=n;i++) {
        a[i]=i;
    }
    for (int i=1;i<=k;i++) {
        int pos=i;
        for (int j=x;j>=1;j--) {
            pos=undo(j,pos);
            cout<<pos<<' ';
        }
        cout<<pos<<endl;
    }
}
