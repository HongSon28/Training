#include<bits/stdc++.h>
using namespace std;
char c[10];
char a[10];
bool sd[10];
int n,cnt=0;
vector<string>kq;
void xuat() {
    string temp;
    cnt++;
    for (int i=1;i<=n;i++)
        temp+=a[i];
    kq.push_back(temp);
}
void dequy(int k) {
    for(int i=0;i<n;i++) {
        if (sd[i]==true) {
            a[k]=c[i];
            sd[i]=false;
            if (k==n) {
                xuat();
            } else {
                dequy(k+1);
            }
            sd[i]=true;
        }
    }
}
int main() {
    memset(sd,true,sizeof(sd));
    string s;
    cin>>s;
    n=s.length();
    for (int i=0;i<s.length();i++) {
        c[i]=s[i];
    }
    dequy(1);
    sort(kq.begin(),kq.end());
    for (int i=0;i<cnt;i++) {
        if (kq[i]!=kq[i+1])
            cout<<kq[i]<<endl;
    }
}
