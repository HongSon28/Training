#include<bits/stdc++.h>
using namespace std;
long long temp=13051984;
int comp (string a, string b) {
    if (a.length()>b.length())
        return 1;
    if (a.length()<b.length())
        return -1;
    for (int i=0;i<a.length();i++) {
        if (a[i]>b[i]) {
            return 1;
        } else if (a[i]<b[i]) {
            return -1;
        }
    }
    return 0;
}
string operator + (string a, string b) {
    string res;
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)+(b[i]-48)+rem;
        rem=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if (rem!=0) {
        res=char(rem+48)+res;
    }
    return res;
}
string operator / (string a, long long b) {
    string res;
    long long t=0;
    for (auto k:a) {
        t=t*10+(k-48);
        long long x=t/b;
        t=t%b;
        res=res+char(x+48);
    }
    while (res[0]=='0')
        res.erase(0,1);
    if (res.empty()==true) {
        res='0';
    }
    return res;
}
long long operator % (string a, long long b) {
    long long t=0;
    for (auto k:a) {
        t=t*10+(k-48);
        t=t%b;
    }
    return t;
}
int main() {
    int n,k;
    cin>>n>>k;
    bool a[n+1];
    memset(a,false,sizeof(a));
    for (int i=0;i<k;i++) {
        int temp;
        cin>>temp;
        a[temp]=true;
    }
    string fi[1001];
    fi[0]="1";
    if (a[1]==true) fi[1]="0";
    else fi[1]="1";
    for (int i=2;i<=n;i++) {
        if (a[i]==true) fi[i]="0";
        else fi[i]=fi[i-1]+fi[i-2];
    }
    cout<<fi[n]%temp;
}
