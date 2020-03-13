#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sfi(a) scanf("%d",&a)
#define m_p make_pair
#define ff first
#define ss second
#define pi(x) pair<x,x>
#define mem(x) memset(x,-1,sizeof(x))
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)

typedef long long ll;
const int maxn = 1e5, mod = 1e9+7;

int kdx[] = {-1,-1,-1,1,1,1,0,0};
int kdy[] = {-1,0,1,-1,0,1,-1,1};
char arr[101][101];
int level[101][101];
int n,m;

bool valid(int x,int y){
    if(x>=0&&y>=0&&x<n&&y<m&&arr[x][y]=='.'&&level[x][y]==-1) return true;
    else return false;
}

int bfs(int x,int y){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++) level[i][j] = -1;
    }

    queue<pii> mq;
    mq.push({x,y});
    level[x][y] = 0;
    int ans = 0;
    while(!mq.empty()){
        pii top = mq.front();
        mq.pop();
        for(int i=0;i<8;i++){
            int a = top.ff + kdx[i];
            int b = top.ss + kdy[i];
            if(valid(a,b)){
                level[a][b] = level[top.ff][top.ss] + 1;
                ans = max(ans,level[a][b]);
                mq.push({a,b});
            }
        }
    }

    return ans;
}

int main()
{
    int t; sfi(t);
    while(t--){
        scanf("%d %d",&n, &m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&arr[i][j]);
            }
        }
        printf("%d\n",bfs(0,0));
    }
	return 0;
}
