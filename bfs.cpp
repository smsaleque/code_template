#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pi(x) pair<x,x>
#define mem(x) memset(x,-1,sizeof(x))
#define all(x) x.begin(),x.end()
#define eps 0.0000001
#define ff first
#define ss second
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define endl '\n'

typedef long long int ll;
typedef long double lld;
const ll mod = 1e9+7;
const int mx = 10000;

int kx[] = {1,-1,0,0};
int ky[] = {0,0,1,-1};

char grid[mx][mx];
bool vis[mx][xm];

bool isvalid(int x,int y){
    if(x>=0 && x<r && y >= 0 && y < c && grid[x][y]!='#') return true;
    else return false;
}

void bfs(pii st){
    for(int i=0;i<mx;i++)
        for(int j=0;j<mx;j++)
            vis[i][j] = 0;
    queue<pii> pq;
    pq.ff = st.ff;
    pq.ss = st.ss;
    vis[st.ff][st.ss] = 1;
    while(!pq.empty()){
        pii top = pq.front();
        pq.pop();
        for(int i=0;i<4;i++){
            int xx = top.ff + kx[i];
            int yy = top.ss + ky[i];
            if(isvalid(xx,yy)){

            }
        }
    }
}
int main(){
    int r,c;
    cin >> r >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> grid[i][j];


}

