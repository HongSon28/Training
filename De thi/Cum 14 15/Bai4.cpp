#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int i=0,num=0;
    set<int>st;
    while (i<s.size()) {
        while (s[i]>='0'&&s[i]<='9') {
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
    cout<<st.size()<<endl;
    for (auto i:st) cout<<i<<endl;
}
