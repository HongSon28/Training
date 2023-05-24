#include<bits/stdc++.h>
using namespace std;
char c[11];
bool used[1000];
int pos[1000];
vector<char>v,cons;
int n;
void out() {
    for (int i=1;i<=n;i++) cout<<c[i];
    cout<<endl;
}
bool check() {
    for (int i=1;i<=n;i++) {
        pos[(int)c[i]]=i;
        //cout<<(int)c[i];
        //cout<<endl;
    }
    for (int i=0;i<cons.size()/2;i++) {
        int a=(int)(cons[i*2]),b=(int)(cons[i*2+1]);
        //cout<<a<<' '<<b<<' '<<pos[a]<<' '<<pos[b]<<endl<<endl;
        if (pos[a]>=pos[b]) return false;
    }
    return true;
}
void rec(int k) {
    //cout<<k<< ' ';
    for (int i=0;i<n;i++) {
        if (used[(int)v[i]]==false) {
            //cout<<k<<' '<<i<<endl;
            c[k]=v[i];
            used[(int)v[i]]=true;
            if (k==n) {
                if (check())
                    out();
            }
            else {
                rec(k+1);
            }
            used[(int)v[i]]=false;
        }
    }
}
int main() {
    string s,s2;
    while (getline(cin,s),getline(cin,s2)){
        v.clear();
        cons.clear();
        for (int i=0;i<s.size();i++)
            if (s[i]!=' ')
                v.push_back(s[i]);
        n=v.size();
        for (int i=0;i<s2.size();i++)
            if (s2[i]!=' ')
                cons.push_back(s2[i]);
        rec(1);
        cout<<endl;
    }
}
