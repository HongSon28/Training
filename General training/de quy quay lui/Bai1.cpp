#include<bits/stdc++.h>
using namespace std;
int n,dem=0;
bool sd[21]={};
int a[21];
string res[4000001];
void luu(int k) {
    for (int i=1;i<=n;i++) {
        string temp=to_string(a[i]);
        res[k]+=temp+" ";
    }
}
void dequy(int k) {
    for (int i=1;i<=n;i++) {
        if (sd[i]==false) {
            a[k]=i;
            sd[i]=true;
            if (k==n) {
                luu(dem);
                dem++;
            } else {
                dequy(k+1);
            }
            sd[i]=false;
        }
    }
}
int main() {
    cin>>n;
    dequy(1);
    for (int i=0;i<dem;i++)
        cout<<res[i]<<endl;
}
