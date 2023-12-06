#include<bits/stdc++.h>
using namespace std;
bool check(int n) {
    if (n<2)
        return false;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0)
            return false;
    }
    return true;
}
int main() {
    ifstream inp("prime.inp");
    ofstream out("prime.out");
    string s;
    inp>>s;
    set <int> a;
    int n=s.length();
    for (int i=0;i<n;i++) {
        string temp=s.substr(i,1);
        int x=stoi(temp);
        a.insert(x);
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            string temp=s.substr(i,j-i+1);
            int x=stoi(temp);
            a.insert(x);
        }
    }
    int res=0;
    for (auto i:a) {
        if (check(i)==true)
            res++;
    }
    if (res==0)
        out<<"NO PRIMES";
    else
        out<<res;
}
