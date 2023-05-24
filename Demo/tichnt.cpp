#include<iostream>
#include<vector>
#include<math.h>

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
    while(T>0)
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
        if(!ok) cout<<-1<<endl;
        else
        {
            while(g/P[pos]<=N/P[pos+k])
            {
                g=g/P[pos]*P[pos+k];
                pos++;
            }
            cout<<g<<endl;
        }
        T--;
    }

}
