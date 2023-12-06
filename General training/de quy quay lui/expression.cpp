#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int s[10];
int used[50];
bool flag=false;
bool check() {
    int sum=b[0];
    for (int i=1;i<=4;i++) {
        //cout<<s[i]<<' '<<sum<<endl;
        if (s[i]==1) sum+=b[i];
        else if (s[i]==2) sum-=b[i];
        else sum*=b[i];
    }
    if (sum==23) return true;
    return false;
}
void rec2(int k) {
    for (int i=1;i<=3;i++) {
        s[k]=i;
        if (k==4) {
            if (check()) {
                flag=true;
                return;
            }
        } else rec2(k+1);
    }
}
void rec1(int k) {
    for (int i=0;i<5;i++) {
        if(used[a[i]]>0) {
            b[k-1]=a[i];
            used[a[i]]--;
            if (k==5) {
                rec2(1);
            } else {
                rec1(k+1);
            }
            used[a[i]]++;
        }
    }
}
int main() {
    while (cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]) {
        memset(used,0,sizeof(used));
        flag=false;
        if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==0) break;
        for (int i=0;i<5;i++) used[a[i]]++;
        rec1(1);
        if (flag) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
}
