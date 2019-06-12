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
bool isp[sz+1];
LL bigmod(int a,int b,int M){
    if(b==0) return 1;
    if(b%2==0){
        LL res = bigmod(a,b/2,M)%M;
        return (res*res)%M;
    }
    else {
        LL res = ((a%M)*(bigmod(a,b-1,M))%M)%M;
        return res;
    }
}

int main()
{

    return 0;
}
