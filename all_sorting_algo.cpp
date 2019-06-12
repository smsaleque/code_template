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
void Insertion_Sort(int *arr,int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void Bubble_Sort(int *arr,int n){
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
void Selection_Sort(int *arr,int n){
    for(int i=0;i<n;i++){
        int mn = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[mn]){
                mn = j;
            }
        }
        swap(arr[i],arr[mn]);
    }
}
void Counting_Sort(int *arr,int n){
    int mx = *max_element(arr,arr+n);
    int tmp[mx+1];
    for(int i=0;i<(mx+1);i++) tmp[i]=0;
    for(int i=0;i<n;i++){
        tmp[arr[i]]++;
    }
    int j = 0;
    for(int i=0;i<=mx;i++){
        int val = tmp[i];
        while(val--){
            arr[j++]=i;
        }
    }
}

void mrg(int *arr, int L,int mid,int R)
{
    int sz1 = mid-L+1;
    int sz2 = R-mid;

    int L_A[sz1];
    int R_A[sz2];

    for(int i=0; i<sz1; i++)
        L_A[i] = arr[L+i];

    for(int i=0; i<sz2; i++)
        R_A[i] = arr[mid+i+1];

    int i=0, j=0, k=L;

    while(i<sz1 && j<sz2)
    {

        if(L_A[i] <= R_A[j])
            arr[k++] = L_A[i++];
        else
        {
            arr[k++] = R_A[j++];
            //cnt += sz1 - i;  // for inversion count
        }

    }

    while(i<sz1)
        arr[k++] = L_A[i++];

    while(j<sz2)
        arr[k++] = R_A[j++];

}

void merge_short(int *arr,int L, int R)
{
    if(L==R)
        return ;

    int mid = (L+R)/2;
    merge_short(arr,L,mid);
    merge_short(arr,mid+1,R);

    mrg(arr,L,mid,R);
}
int main()
{
    int arr[5] = {10,5,2,1,7};
    merge_short(arr,0,5);
    for(int i=0;i<5;i++) cout << arr[i] << endl;
    return 0;
}
