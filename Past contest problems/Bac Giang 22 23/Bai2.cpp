#include <bits/stdc++.h>
using namespace std;
bool check(int n) {
    if (n<2) return false;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int i=0,num=0,cnt=0;
    set<int>st;
    while (i<s.size()) {
        while (s[i]>='0'&&s[i]<='9') {
            cnt++;
            int temp=(int)s[i]-48;
            num*=10;
            num+=temp;
            i++;
        }
        if (num!=0) {
            st.insert(num);
            num=0;
        }
        i++;
    }
    for (int i=0;i<s.size()-1;i++) {
        if (s[i]=='0'&&s[i+1]>'9') {
            st.insert(0);
            break;
        }
    }
    int mx=0;
    cout<<cnt<<endl;
    for (auto i:st) {
        if (check(i)==true) mx=max(mx,i);
    }
    cout<<mx;
}

