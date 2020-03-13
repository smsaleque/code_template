#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sfi(a) scanf("%d",&a)
#define mp make_pair
#define pi(x) pair<x,x>
#define mem(x) memset(x,-1,sizeof(x))
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)

typedef long long ll;
const int maxn = 1e5, mod = 1e9+7;

ll fact[maxn+10];
ll inv[maxn+10];

ll bigmod(ll a, ll b){

    if(b==0) return 1;
    if(b%2==0){
        ll res = bigmod(a,b/2) % mod;
        return (res*res)%mod;
    }
    else {
        ll res = ((a%mod) * (bigmod(a,b-1)%mod))%mod;
        return res;
    }

}


ll modinv(ll n, ll m) {
  return bigmod(n,m-2);
}

void fun(){
    fact[0] = 1;
    for(ll i = 1; i < maxn; i++)
    fact[i] = fact[i-1] * i % mod;
}

void fun1(){

    inv[maxn-1] = modinv(fact[maxn-1],mod);
    for(ll i = maxn-2; i >= 0; i--)
      inv[i] = inv[i+1] * (i+1) % mod;

}

ll ncr(int n, int r) {
  if(n < r) return 0;
  return fact[n] * (inv[r] * inv[n-r] % mod) % mod;
}

int main()
{
    fun(); fun1();
    cout << ncr(10,5);


  return 0;
}
