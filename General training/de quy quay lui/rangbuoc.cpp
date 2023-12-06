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
    string s;
    while (getline(cin,s)){
        v.clear();
        cons.clear();
        for (int i=0;i<s.size();i++)
            if (s[i]!=' ')
                v.push_back(s[i]);
        sort(v.begin(),v.end());
        n=v.size();
        getline(cin,s);
        for (int i=0;i<s.size();i++)
            if (s[i]!=' ')
                cons.push_back(s[i]);
        rec(1);
    }
}
