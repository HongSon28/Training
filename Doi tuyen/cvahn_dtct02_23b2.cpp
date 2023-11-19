#include<bits/stdc++.h>
using namespace std;
void pluss (string &s) {
    int n=s.size();
    int rem=0;
    int t;
    if (s[n-1]>='0'&&s[n-1]<='9') t=s[n-1]-'0';
    else t=s[n-1]-'A'+10;
    t++;
    if (t==16){
        t=0;
        rem=1;
    }
    if (t<=9) s[n-1]=(char) t+'0';
    else s[n-1]=(char) t-10+'A';
    int i=n-2;
    while (rem!=0) {
        if (s[i]>='0'&&s[i]<='9') t=s[i]-'0';
        else t=s[i]-'A'+10;
        t+=rem+1;
        if (t>=16){
            t-=16;
            rem=1;
        } else rem=0;
        if (t<=9) s[i]=(char) t+'0';
        else s[i]=(char) t-10+'A';
        i--;
    }
}
void subtract (string &s) {
    int n=s.size();
    int rem=0;
    int t;
    if (s[n-1]>='0'&&s[n-1]<='9') t=s[n-1]-'0';
    else t=s[n-1]-'A'+10;
    t--;
    if (t<0){
        t+=16;
        rem=1;
    }
    if (t<=9) s[n-1]=(char) t+'0';
    else s[n-1]=(char) t-10+'A';
    int i=n-2;
    while (rem!=0) {
        if (s[i]>='0'&&s[i]<='9') t=s[i]-'0';
        else t=s[i]-'A'+10;
        t-=rem;
        if (t<0){
            t+=16;
            rem=1;
        } else rem=0;
        if (t<=9) s[i]=(char) t+'0';
        else s[i]=(char) t-10+'A';
        i--;
    }
    //cout<<s<<endl;
}
bool check(string s) {
    int a[16]={};
    for (auto i:s) {
        if (i>='0'&&i<='9') a[i-'0']++;
        else a[i-'A'+10]++;
    }
    for (int i=0;i<16;i++)
        if (a[i]>=2) return false;
    return true;
}
int main() {
    freopen("HEXA.INP","r",stdin);
    freopen("HEXA.OUT","w",stdout);
    int n;
    string x;
    while (cin>>n>>x) {
        if (n<=0) {
            while (n++) {
                pluss(x);
                while (!check(x)) pluss(x);
            }
        } else {
            while (n--) {
                subtract(x);
                while (!check(x)) subtract(x);
            }
        }
        cout<<x<<'\n';
    }
}

