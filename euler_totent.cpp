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
/// Euler phi
/// 2 3 5 7 11 13 17 19 23
int eulerPhi(int n) /// O(nlogn)
{
    int cnt = 0;
    for(int i=1;i<=n;i++) /// O(n)
    {
        if(__gcd(i,n) == 1) cnt++; /// O(logn)
    }
    return cnt;
}
/// given a number from 1 to N. 1<=N<=10^6
/// calculate, phi(N) = n*multiplication(1-(1/pi))
/// 2 3 5 7 11 13 17 19 23
int eulerPhie(int n) ///o(sqrt(n/logn))
{
    int value = n;
    /// value = n((p1-1)/p1) * ((p2-1)/p2)

    for(int i=2;i*i<=n;i++) /// i = 2,3,5,7,11,...,N O(sqrt(n)) --> O(sqrt(n/logn))
    {
        if(n%i==0)
        {
            value/=i;
            value*=(i-1);
            while(n%i==0)
            {
                n=n/i;
            }
        }
    }
    if(n>1)
    {
        value/=n;
        value*=(n-1);
    }
    return value;
}

int ev[1000050];
bool isP[1000050];
///euler totient

void sieve(int n)
{
    /// init
    for(int i=1;i<=n;i++)
    {
        ev[i] = i;
        isP[i] = 0;
    }
    /// sieve
    for(int i=2;i<=n;i++)
    {
        if(isP[i]==0) ///isP[2]=0
        {
            ev[i] = i-1; /// ev[2] = 2-1
            for(int j=i+i; j<=n; j+=i)
            {
                isP[j] = 1;
                ev[j]/=i;
                ev[j]*=(i-1);
            }
        }
    }
}

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
