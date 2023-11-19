#include<bits/stdc++.h>
using namespace std;
long long calc(string x){
    long long t=0;
    for (auto i:x) t+=(long long)i-'0';
    return t;
}
long long conv(string x) {
    long long t=0;
    for (auto i:x) {
        t*=10;
        t+=(long long)i-'0';
    }
    return t;
}
long long change(long long mn,long long m) {
    long long a=mn+1;
    if (calc(to_string(a))<m) {
        string b=to_string(a);
        for (int i=b.length()-1;i>=0;i--) {
            b[i]='9';
            if (calc(b)>m) {
                long long temp=calc(b)-m;
                b[i]-=temp;
                break;
            }
            if (calc(b)==m) break;
        }
        while (calc(b)<m) {
            long long temp=m-calc(b);
            if (temp<=9) b=to_string(temp)+b;
            else b="9"+b;
        }
        return conv(b);
    } else if (calc(to_string(a))>m){
        string b=to_string(a);
        b='0'+b;
        for (int i=b.length()-1;i>=0;i--) {
            if (b[i]=='0') continue;
            b[i]='0';
            for (int j=i-1;j>=0;j--) {
                if (b[j]=='9') b[j]='0';
                else {
                    b[j]++;
                    break;
                }
            }
            if (calc(b)<m) {
                for (int i=b.length()-1;i>=0;i--) {
                    b[i]='9';
                    if (calc(b)>m) {
                        long long temp=calc(b)-m;
                        b[i]-=temp;
                        break;
                    }
                    if (calc(b)==m) break;
                }
                while (calc(b)<m) {
                    long long temp=m-calc(b);
                    if (temp<=9) b=to_string(temp)+b;
                    else b="9"+b;
                }
                return conv(b);
            }
            if (calc(b)==m) return conv(b);
        }
    }
    return a;
}
int main() {
    freopen("S4.INP","r",stdin);
    freopen("S4.OUT","w",stdout);
    long long c,n;
    cin>>c>>n;
    n--;
    while (n--) {
        long long t=calc(to_string(c*4));
        c=change(c,t);
    }
    cout<<c;
}
