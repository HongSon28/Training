#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k;
    cin>>k>>s;
    int n=s.length();
    int solan[26]={0};
    for (int i=0;i<n;i++) {
        solan[s[i]-'a']++;
    }
    int check=0;
    string chuoi1="";
    for (int i=0;i<26;i++) {
        if (solan[i]!=0) {
            if (solan[i]%k!=0) {
                check+=1;
            } else {
                int lap=solan[i]/k;
                for (int j=0;j<lap;j++) {
                    chuoi1+=char(i+97);
                }
            }
        }
    }
    string kq;
    if (check==0) {
        for (int i=0;i<k;i++) {
            kq+=chuoi1;
        }
    }
    if (check==0) {
        cout<<kq;
    } else {
        cout<<"-1";
    }
}
