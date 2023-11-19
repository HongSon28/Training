#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool check(int x) {
    int t=x;
    while (t>0) {
        int temp=t%10;
        if (temp==0) return false;
        t/=10;
        if (x%temp!=0) return false;
    }
    return true;
}
int main() {
    int l,r;
    cin>>l>>r;
    for (int i=l;i<=r;i++)
        if (check(i)) v.push_back(i);
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i<<' ';
}
