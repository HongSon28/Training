#include<bits/stdc++.h>
using namespace std;
bool check(string s,int n) {
    int temp=s.length();
    int dem[123]={};
    for (int i=0;i<temp;i++) {
        dem[(int)s[i]]++;
    }
    for (int i=97;i<=122;i++) {
        if (dem[i]%n!=0)
            return false;
    }
    return true;
}
int main() {
    int q;
    cin>>q;
    bool kq[q];
    for (int i=0;i<q;i++) {
        int n;
        cin>>n;
        string s[n];
        for (int j=0;j<n;j++) {
            cin>>s[j];
        }
        int dem[123];
        string temp="";
        for (int j=0;j<n;j++) {
            temp+=s[j];
        }
        if (check(temp,n)==true)
            kq[i]=true;
        else
            kq[i]=false;
    }
    for (int i=0;i<q;i++) {
        if (kq[i]==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
