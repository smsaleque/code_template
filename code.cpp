#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define sfi(a) scanf("%d",&a)
#define mp make_pair
#define pi(x) pair<x,x>
#define mem(x) memset(x,-1,sizeof(x))
#define eps 0.0000001
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)

// sort a set
struct lex_compare {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        if(a.first==b.first){
            return (a.second > b.second);
        }
        else return (a.first < b.first );

    }
};

struct student{
    string name;
    int accurate,velocity,stupidity;
};

bool cmp(student a, student b){
    if(a.accurate==b.accurate){
        if(a.velocity==b.velocity){
            if(a.stupidity==b.stupidity){
                return a.name < b.name;
            }
            else return a.stupidity < b.stupidity;
        }
        else return a.velocity > b.velocity;
    }
    else return a.accurate > b.accurate;
}

// bitwise seieve
const int mx = 100000000;
bitset<mx> bit;
int pos = 0;
int arr[mx+10];
void sieve(){
    bit.reset();
    bit[0]=bit[1]=1;
    for(int i=2;i*i<=mx;i++){
        if(!bit[i]){
            for(int j=i*2;j<=mx;j+=i) bit[j] = 1;
        }
    }

    for(int i=2;i<=mx;i++){
        if(!bit[i]){
            arr[pos++] = i;
        }
    }
}

// totent function
const int MX = 1000010;

int EV[MX+10];

void fun(){

    for(int i=1;i<=MX;i++){
        EV[i] = i;
    }

    for(int i=2;i<=MX;i++){
        if(EV[i]==i){
            EV[i] = i-1;
            for(int j=i*2;j<=MX;j+=i){
                EV[j]/=i;
                EV[j]*=(i-1);
            }
        }
    }

}

// divisors
const int MX = 1000010;

int arr[MX];
void fun(){
    for(int i=1;i<=MX;i++){
        for(int j=i;j<=MX;j+=i){
           arr[j]++;
        }
    }
}

// prime factorize
const int sz = 1000010;

int spf[sz+10];
void sieve(){

    spf[1] = 1;
    for(int i=2;i<=sz;i++) spf[i] = i;

    for(int i=4;i<=sz;i+=2) spf[i] = 2;

    for(int i=3;i*i<=sz;i++){

        if(spf[i]==i){
            for(int j=i*2;j<=sz;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }

    }

}

vector<int> fun(int x){

    vector<int> ret;
    while(x!=1){
        ret.push_back(spf[x]);
        x /= spf[x];
    }

    return ret;

}

// factoriztion


ll fun(ll x){
    ll ans = -1;
    int cnt = 0;
    for(int i=0;i<pos && prime[i]*prime[i]<=x;i++){
        if(x%prime[i]==0){
            ans = prime[i];
            cnt++;
            while(x%prime[i]==0) x/=prime[i];
        }
    }
    if(x>1ll){
        ans = max(ans,x);
        cnt++;
    }
    if(cnt==1) ans = -1;
    return ans;
}

// modinverse
void fun1(){

    inv[maxn-1] = modinv(fact[maxn-1],mod);
    for(ll i = maxn-2; i >= 0; i--)
      inv[i] = inv[i+1] * (i+1) % mod;

}

int main()
{
	set<pair<int,int>, lex_compare> st;
    map<int,int> mp;
	auto lo = mp.lower_bound(s1);
    auto hi = mp.upper_bound(s2);
    while(lo!=hi){
        cout << (*lo).ff << " " << (*lo).ss << endl;
        lo++;
    }

	int lo,hi;
    if(binary_search(arr,arr+n,x)) lo = lower_bound(arr,arr+n,x) - arr;
    else lo = upper_bound(arr,arr+n,x) - arr;

    if(binary_search(arr,arr+n,y)) hi = upper_bound(arr,arr+n,y) - arr;
    else hi = lower_bound(arr,arr+n,y) - arr;


    // binary search
    while(st<=en) /// st<=en
    {
        mid = (st+en)/2;
        if(arr[mid]>v)
        {
            en = mid-1;
        }
        else if(arr[mid]<v)
        {
            st = mid+1;
        }
        else if(arr[mid]==v)
        {
            found = true;
            cout << "Found " << mid << "\n";
            break;
        }
    }



	return 0;
}
