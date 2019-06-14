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
const ll mod = 100000007;
const int sz = 2000010;
int N;
int grid[11][11];

bool isValid(int x,int y){
    for(int i=0;i<N;i++){
        if(grid[x][i]==1) return false;
    }
    int i=x-1,j=y-1;
    while(i>=0&&j>=0){
        if(grid[i][j]==1) return false;
        i--,j--;
    }
    i=x+1,j=y+1;
    while(i<N&&j<N){
        if(grid[i][j]==1) return false;
        i++,j++;
    }
    i=x-1,j=y+1;
    while(i<N&&j<N){
        if(grid[i][j]==1) return false;
        i--,j++;
    }
    i=x+1,j=y-1;
    while(i<N&&j<N){
        if(grid[i][j]==1) return false;
        i++,j--;
    }

    return true;
}

void print_ans(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
void N_queen(int col){
    if(col>=N){
        print_ans();
        exit(0);
    }

    for(int row=0;row<N;row++){
        if(isValid(row,col)){
            grid[row][col] = 1;
            N_queen(col+1);
            grid[row][col] = 0;
        }
    }
}


int main()
{
    sfi(N);
    if(N==2||N==3) {puts("Not possible");return 0;}
    N_queen(0);
    return 0;
}
