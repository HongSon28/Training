#include <bits/stdc++.h>
using namespace std;
const int maxArr = 1e6;
int m,n,pos[maxArr],du,len,thuong;
string res="";
int main()
{
    ifstream inp("Thapphan.inp");
    ofstream out("Thapphan.out");
    memset(pos,0,sizeof(pos));
    inp>>m>>n;
    du=m%n,thuong=m/n;
    if(du==0)
    {
        out<<thuong;
        return 0;
    }
    res+=to_string(thuong)+",";
    len=res.length();
    while(du!=0)
    {
        du*=10;
        if(pos[du]==0)
        {
            thuong=du/n;
            pos[du]=len;
            len++;
            res+=to_string(thuong);
            du=du%n;
        }
        else
        {
            res.insert(pos[du],"(");
            res+=")";
            break;
        }
    }
    out<<res;
}
