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
#define pb push_back
#define mem(x,val) memset(x,val,sizeof(x))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define sqr(x) ((x)*(x))

typedef long long ll;
const ll mod = 1e9+7;
const int sz = 1e5;
ll Hash[sz];
ll power[sz];
unordered_map<char,int> mp;
void pre_hash(string str){
    int val = 1;
    for(char c = 'a';c<='z';c++) mp[c] = val++;
    Hash[0] = mp[str[0]];
    for(int i=1;i<str.size();i++){
        Hash[i] = ((26*(Hash[i-1]%mod))%mod + mp[str[i]])%mod;
    }
}
void pre_power(){
    power[0] = 1;
    power[1] = 26;
    for(int i=2;i<sz;i++){
        power[i] = (26*(power[i-1]%mod))%mod;
    }
}
ll hash_substring(string str){
    ll sum = 0;
    int p_w = str.size()-1;
    for(int i=0;i<str.size();i++){
        ll val = (mp[str[i]]*power[p_w--])%mod;
        sum += val;
        sum %= mod;
    }
    return sum;
}
ll gethash(int l,int r,int p){
    return (Hash[r] - (Hash[l-1]*power[p])+mod*mod)%mod;
}
vector<int> all_occurence(string str1,string str2,ll subval){
    int len = str2.size();
    vector<int> ans;
    ll val = Hash[len-1];
    if(val==subval) ans.push_back(0);
    for(int i=len;i<str1.size();i++){
        int l = i-len+1,r=i;
        val = gethash(l,r,len);
        if(val==subval){
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    string mainstring,substring;
    cin >> mainstring >> substring;
    pre_power();
    pre_hash(mainstring);
    ll subval = hash_substring(substring);
    vector<int> vec = all_occurence(mainstring,substring,subval);
    if(vec.size()>0) puts("YES");
    else puts("NO");
    return 0;
}

