#include<bits/stdc++.h>
using namespace std;
bool c[10];
bool check(int n) {
    while (n!=0) {
        if (c[n%10]==false)
            return false;
        n/=10;
    }
    return true;
}
int main() {
    ifstream inp("boi.inp");
    ofstream out("boi.out");
    int n,m;
    inp>>n>>m;
    set<int>s;
    for (int i=1;i<=10;i++) {
        s.insert(n*i%10);
    }
    memset(c,false,sizeof(c));
    for (int i=0;i<m;i++) {
        int temp;
        cin>>temp;
        c[temp]=true;
    }
    int cnt=0;
    for (auto i:s) {
        if (c[i]==true)
            cnt++;
    }
    if (cnt==0) {
        out<<'0';
        return 0;
    }
    int i=1;
    while (true) {
        if (check(n*i)==true) {
            out<<n*i;
            return 0;
        }
        i++;
    }
    out<<"0";
}
