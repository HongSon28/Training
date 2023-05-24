#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int dem[8]={};
    for (int i=0;i<=37;i++) {
        string temp=s.substr(i,3);
        if (temp=="TTT")
            dem[0]++;
        else if (temp=="TTH")
            dem[1]++;
        else if (temp=="THT")
            dem[2]++;
        else if (temp=="THH")
            dem[3]++;
        else if (temp=="HTT")
            dem[4]++;
        else if (temp=="HTH")
            dem[5]++;
        else if (temp=="HHT")
            dem[6]++;
        else
            dem[7]++;
    }
    for (int i=0;i<8;i++)
        cout<<dem[i]<<" ";
}
