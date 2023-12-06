#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int k,n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>n>>m;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v1.push_back(t);
    }
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        v2.push_back(t);
    }
    while(v1.size()>0&&v2.size()>0)
    {
        int l1=v1.size(),l2=v2.size();
        k=min(k,l1);
        k=min(k,l2);
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end(),greater<int>());
        for(int i=0;i<k;i++)
        {
            int str1=*v1.begin();
            int str2=*v2.begin();
            if(str1>str2)
            {
                v1.push_back(str1-str2);
                v1.erase(v1.begin());
                v2.erase(v2.begin());
            }
            else if(str2>str1)
            {
                v2.push_back(str2-str1);
                v1.erase(v1.begin());
                v2.erase(v2.begin());
            }
            else
            {
                v1.erase(v1.begin());
                v2.erase(v2.begin());
            }
        }
    }
    if(v1.size()==0&&v2.size()==0)
    {
        cout<<"An and Binh draw";
    }
    else if(v1.size()>0)
    {
        cout<<"An wins"<<endl;
        sort(v1.begin(),v1.end(),greater<int>());
        for(auto i:v1)
        {
            cout<<i<<" ";
        }
    }
    else if(v2.size()>0)
    {
        cout<<"Binh wins"<<endl;
        sort(v2.begin(),v2.end(),greater<int>());
        for(auto i:v2)
        {
            cout<<i<<" ";
        }
    }
}

