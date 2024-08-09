#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length();
    int tong=0;
    int temp=0;
    for (int i=0;i<n;i++) {
        if (s[i]>='0'&&s[i]<='9') {
            if (s[i+1]>='0'&&s[i+1]<='9') {
                temp*=10;
                temp=temp+s[i]-48;
            } else {
                temp*=10;
                temp=temp+s[i]-48;
                tong+=temp;
                temp=0;
            }
        }
    }
    cout<<tong;
}
