#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("NUMBER.INP","r",stdin);
    freopen("NUMBER.OUT","w",stdout);
    int d,k;
    while (cin>>d>>k) {
        vector<int>a,b;
        a.push_back(d);
        b.push_back(a[0]*k%10);
        int rem=a[0]*k/10;
        while (b[b.size()-1]!=d||rem!=0) {
            a.push_back(b[b.size()-1]);
            int t=a[a.size()-1]*k+rem;
            b.push_back(t%10);
            rem=t/10;
        }
        if (a[a.size()-1]==0)
            cout<<-1;
        else
            for (int i=a.size()-1;i>=0;i--) cout<<a[i];
        cout<<endl;
        //for (int i=b.size()-1;i>=0;i--) cout<<b[i];
    }
}
