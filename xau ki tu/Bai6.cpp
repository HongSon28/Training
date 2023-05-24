#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string bp;
    int n=s.length();
    for (int i=n-3;i>=0;i-=3) {
        int n=((int)s[i]-48)*100+((int)s[i+1]-48)*10+(int)s[i+2]-48;
        int dem=0, temp=0;
        while (n!=0) {
            temp=temp+(n%10)*pow(2,dem);
            n/=10;
            dem+=1;
        }
        string x=to_string(temp);
        bp.insert(0,x);
    }
    int k=n%3;
    if (k==1) {
        int n=(int)s[0]-48;
        int dem=0, temp=0;
        while (n!=0) {
            temp=temp+(n%10)*pow(2,dem);
            n/=10;
            dem+=1;
        }
        string x=to_string(temp);
        bp.insert(0,x);
    }
    if (k==2) {
        int n=((int)s[0]-48)*10+((int)s[1]-48);
        int dem=0, temp=0;
        while (n!=0) {
            temp=temp+(n%10)*pow(2,dem);
            n/=10;
            dem+=1;
        }
        string x=to_string(temp);
        bp.insert(0,x);
    }
    while (bp[0]=='0') {
        bp.erase(0,1);
    }
    cout<<bp;
}
