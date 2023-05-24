#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int dem=0;
    int n=s.size();
    for(int i=0;i<s.size();i++){
    string k[1000];
    for (int i=1;i<n-1;i++) {
        if ((s[i]==' ')&&(s[i+1]!=' ')) {
        int start=0;
        string temp=s.substr(start,i-start);
        start=i+1;
        k[dem]=temp;
        dem++;
     }
}}
string temp=s.substr(start,n-start);
k[dem]=temp;
dem++;
cout<<dem<<'/n'<<temp<<" ";
}
