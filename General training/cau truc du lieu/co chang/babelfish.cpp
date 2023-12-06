#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<string, string> dict;
    for (int i=0;i<n;i++) {
        string a,b;
        cin>>a>>b;
        dict[b]=a;
    }
    cin>>n;
    for (int i=0;i<n;i++) {
        string a;
        cin>>a;
        if (dict.count(a)!=0) {
            cout<<dict[a]<<endl;
        } else {
            cout<<"eh"<<endl;
        }
    }
}
