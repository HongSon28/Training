#include<bits/stdc++.h>
using namespace std;
int comp(string a, string b)
{
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
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
int main() {
    string a,b;
    string fi[40001];
    cin>>a>>b;
    fi[1]="1";
    fi[2]="1";
    long long res=0;
    long long i=2;
    if (comp(fi[1],a)>=0)
        res++;
    while (comp(fi[i],b)<=0) {
        fi[i+1]=fi[i]+fi[i-1];
        if (comp(fi[i],a)>=0)
            res++;
        i++;
    }
    cout<<res;
}
