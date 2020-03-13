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

int fact[maxn+10];

ll bigmod(int a, int b){

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
    for(int i = 1; i < maxn; i++)
	  fact[i] = fact[i-1] * i % mod;
}


ll ncr(int n, int r) {
  if(n < r) return 0;
  return fact[n] * (modinv(fact[r],mod)%mod * modinv(fact[n-r],mod) % mod) % mod;
}

int main()
{
    fun();
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(x%2==0) cnt++;
    }

    cout << ncr(cnt,k) << endl;


	return 0;
}
