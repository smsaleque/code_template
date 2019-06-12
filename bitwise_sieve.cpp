#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define sfi(a) scanf("%d",&a)
#define sfi2(a,b) scanf("%d %d",&a,&b)
#define sfi3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define inf 1e7
#define m_p make_pair
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define mem(x,val) memset(x,val,sizeof(x))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define sqr(x) ((x)*(x))

typedef long long ll;
const ll mod = 1e9+7;
const ll sz = 1e6;
/// bitwise sieve starts
bitset<100000010>isP;

void sieve()
{
    isP.reset();
    for(int i=2;i*i<=100000000;i++)
    {
        if(isP[i]==0)
        {
            for(int j=i*i;j<=100000000;j+=i)
            {
                isP[j] = 1;
            }
        }
    }
}

/// bitwise sieve ends

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve(1000005);
    int t,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        printf("%d\n",ev[num]);
    }
    return 0;
}
