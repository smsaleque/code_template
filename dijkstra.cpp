#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define sfi(a) scanf("%d",&a)
#define sfi2(a,b) scanf("%d %d",&a,&b)
#define sfi3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define inf 1e15
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
const int sz = 500000;
struct node
{
    int v,cost;
    node(){}
    node(int _v,int _c)
    {
        v = _v;
        cost = _c;
    }
    bool operator>(const node& a)const
    {
        return cost>a.cost;
    }
};
priority_queue<node, vector<node>, greater<node>> pq;
vector<int> adj[sz+1],cost[sz+1];
ll dis[sz+1];
int par[sz+1];
void dijstra(int src){
    for(int i=0;i<sz;i++) dis[i] = inf;
    pq.push(node(src,0));
    dis[src] = 0;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        int parent = top.v;
        for(int i=0;i<(int)adj[parent].size();i++){
            int child = adj[parent][i];
            ll edge_cost = cost[parent][i];
            if(dis[child]>(dis[parent]+edge_cost)){
                dis[child] = (dis[parent]+edge_cost);
                pq.push(node(child,dis[child]));
                par[child] = parent;
            }
        }
    }
}
void path_print(int n){
    if(n!=1) path_print(par[n]);
    cout << n << " ";
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    sfi2(n,m);
    while(m--){
        int x,y,z;
        sfi3(x,y,z);
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    dijstra(1);
    if(dis[n]==inf) cout << -1;
    else path_print(n);
    cout << endl;
    return 0;
}
