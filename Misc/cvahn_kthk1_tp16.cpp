#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    stack<long long>st;
    cin>>n;
    while (n>0) {
        st.push(n%16);
        n/=16;
    }
    while (!st.empty()) {
        long long temp=st.top();
        st.pop();
        if (temp<=9) cout<<temp;
        else if (temp==10) cout<<"A";
        else if (temp==11) cout<<"B";
        else if (temp==12) cout<<"C";
        else if (temp==13) cout<<"D";
        else if (temp==14) cout<<"E";
        else cout<<"F";
    }
}
