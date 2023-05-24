#include<bits/stdc++.h>
using namespace std;
int main() {
    string x;
    string a;
    getline(cin,x);
    getline(cin,a);
    int n=a.length();
    int dem=0;
    vector <int> index;
    for (int i=0;i<n;i++) {
        string temp=a.substr(i,1);
        if (temp==x) {
            dem++;
            index.push_back(i);
        }
    }
    cout<<dem<<endl;
    for (int i=0;i<dem;i++) {
        cout<<index[i]<<" ";
    }
}
