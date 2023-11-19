#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long power(long long base,long long exp) {
    long long res=1;
    for (int i=1;i<=exp;i++) res*=base;
    return res;
}
long long cnt(long long x) {
    long long c=0;
    while (x!=0) {
        x/=10;
        c++;
    }
    return c;
}
int main() {
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin>>n>>t;
    long long digit=1;
    long long num=9;
    while (true) {
        t-=num*digit;
        if (t<0) {
            t+=num*digit;
            long long temp1=t%digit;
            long long temp2=t/digit;
            if (temp1==0) {
                temp1=digit;
                temp2--;
            }
            long long k=power(10,digit-1)+temp2;
            long long e=k;
            n-=temp1;
            stack<long long>st;
            while (true) {
                k--;
                if (k==0) {
                    break;
                }
                n-=cnt(k);
                st.push(k);
                if (n<0) {
                    n+=cnt(k);
                    st.pop();
                    break;
                }
            }
            while (n-->0&&k!=0) {
                st.push(k%10);
                k/=10;
            }
            while (n-->0) cout<<' ';
            while (!st.empty()) {
                cout<<st.top();
                st.pop();
            }
            int m=digit-temp1;
            while (m--) e/=10;
            cout<<e;
            return 0;
        }
        digit++;
        num*=10;
    }
}
