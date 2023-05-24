#include<bits/stdc++.h>
using namespace std;
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
string operator - (string a, string b) {
    string res;
    if (a==b)
        return "0";
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)-(b[i]-48)-rem;
        if (t<0) {
            rem=1;
            t+=10;
        } else {
            rem=0;
        }
        res=char(t+48)+res;
    }
    while (res[0]=='0')
        res.erase(0,1);
    return res;
}
string operator * (string a, string b) {
    int mul=0;
    string c;
    int rem=0;
    for (int i=b.length()-1;i>=0;i--) {
        string res;
        for (int j=a.length()-1;j>=0;j--) {
            int t=(b[i]-48)*(a[j]-48)+rem;
            rem=t/10;
            t=t%10;
            res=char(t+48)+res;
        }
        for (int i=0;i<mul;i++)
            res.push_back('0');
        mul++;
        c=c+res;
    }
    if (rem!=0) {
        c=char(rem+48)+c;
    }
    while (c[0]=='0')
        c.erase(0,1);
    if (c=="")
        c="0";
    return c;
}
string operator / (string a, string b) {
    string t[11];
    for (int i=0;i<=10;i++)
    {
        string j=to_string(i);
        t[i]=b*j;
    }
    string x,c;
    for (int i=0;i<a.size();i++) {
        x=x+a[i];
        int k=0;
        while (comp(t[k],x)<=0) k++;
        k--;
        c=c+char(k+48);
        x=x-t[k];
    }
    while (c[0]=='0')
        c.erase(0,1);
    if (c=="")
        c='0';
    return c;
}
string operator % (string a, string b)
{
    string t[11];
    for (int i=0;i<=10;i++)
    {
        string j=to_string(i);
        t[i]=b*j;
    }
    string x= "", c = "";
    for (int i =0; i<=a.size()-1; i++)
    {
        x = x + a[i];
        int k =0;
        while (comp(t[k],x)<=0) k++;
        k --;
         x = x - t[k];
    }
    return x;
}
int main() {
    string a,b,c,m;
    cin>>a>>b>>c>>m;
    string x=a,y=b,z=c;
    if (x[0]=='-')
        x.erase(0,1);
    if (y[0]=='-')
        y.erase(0,1);
    if (z[0]=='-')
        z.erase(0,1);
    string mx="0";
    if ((a[0]=='-'&&b[0]=='-')||(a[0]!='-'&&b[0]!='-')) {
        string mul=x*y;
        if (comp(mul,mx)==1)
            mx=mul;
    }
    if ((b[0]=='-'&&c[0]=='-')||(b[0]!='-'&&c[0]!='-')) {
        string mul=y*z;
        if (comp(mul,mx)==1)
            mx=mul;
    }
    if ((a[0]=='-'&&c[0]=='-')||(a[0]!='-'&&c[0]!='-')) {
        string mul=x*z;
        if (comp(mul,mx)==1)
            mx=mul;
    }
    cout<<mx%m;
}
