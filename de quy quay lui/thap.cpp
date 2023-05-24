#include<bits/stdc++.h>
using namespace std;
void rec(int n,char a,char b,char c) {
    if (n==1) {
        cout<<a<<"->"<<c<<endl;
        return;
    }
    rec(n-1,a,c,b);
    rec(1,a,b,c);
    rec(n-1,b,a,c);
}
int main() {
    int n;
    cin>>n;
    char a='A',b='B',c='C';
    rec(n,a,b,c);
}
