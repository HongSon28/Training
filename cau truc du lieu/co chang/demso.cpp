#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>a;
    int x;
    while (cin>>x) {
        a.push_back(x);
    }
    cout<<a[a.size()/2];
}
