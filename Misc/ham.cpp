#include<bits/stdc++.h>
#define mm 2700000
#define UL unsigned long long
using namespace std;
vector<UL>P;
 void sang()
{
    bool *A=new bool [mm+5];
    for(UL i=3;i<=mm;i+=2)A[i]=true;
    P.push_back(2);
    for(UL i=3;i*i<=mm;i+=2)
    if(A[i])    for(UL j=i*i;j<=mm;j+=i) A[j]=false;
    for(UL i=3;i<=mm;i+=2) if(A[i]) P.push_back(i);
    delete []A;
}
int main()
{
    sang();
    UL N,k,T;
    cin>>T;
    unsigned long long kq[T];
    for (int i=0;i<T;i++)
    {
        cin>>N>>k;
        UL pos=0;
        UL g=1;
        bool ok=true;
        for(UL i=0;i<k;i++)
        {
            if(g>N/P[i]) {ok=false;break;}
            g*=P[i];
        }
        if(!ok) kq[i]=0;
        else
        {
            while(g/P[pos]<=N/P[pos+k])
            {
                g=g/P[pos]*P[pos+k];
                pos++;
            }
            kq[i]=g;
        }
    }
    for (int i=0;i<T;i++) {
        if (kq[i]==0)
            cout<<"-1"<<endl;
        else
            cout<<kq[i]<<endl;
    }
}
