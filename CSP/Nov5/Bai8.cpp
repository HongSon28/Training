#include<bits/stdc++.h>
using namespace std;
bool check(string a, string b ,int n) {
    string temp=b;
    for (int i=0;i<n-1;i++) {
        b+=temp;
    }
    if (b==a)
        return true;
    return false;
}
int main() {
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    if (n>m) {
        swap(s,t);
        swap(n,m);
    }
    int cnf=0;
    for (int i=n;i>=1;i--) {
        if (n%i==0&&m%i==0) {
            string temp=s.substr(0,i);
            if (check(s,temp,n/i)==true) {
                if (check(t,temp,m/i)==true) {
                    cout<<temp;
                    cnf++;
                    break;
                }
            }
        }
    }
    if (cnf==0)
        cout<<"NO";
}
