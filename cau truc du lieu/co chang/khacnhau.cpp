#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>s;
    int x;
    while (cin>>x) {
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    int res=1;
    for (int i=1;i<s.size();i++) {
        if (s[i]!=s[i-1])
            res++;
    }
}
