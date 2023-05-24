#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    while (s[0]!=' ') {
        cout<<s[0];
        s.erase(0,1);
    }
    s.erase(0,1);
    int n=s.length();
    int m=n;
    string temp=s;
    cout<<endl;
    int dem=0;
    while (temp[n-1]!=' ') {
        temp.erase(n-1,1);
        n-=1;
        dem+=1;
    }
    cout<<temp<<endl;
    s.erase(0,m-dem);
    cout<<s;
}
