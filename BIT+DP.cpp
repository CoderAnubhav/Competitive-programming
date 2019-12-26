/********************AUTHOR:THE CODER***********************/
/*                                                         */
/*                                                         */
/************************************************************/
#include<bits/stdc++.h>
#define MOD 1000000007
#define INF LLONG_MAX
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vl vector<long long>
#define vll vector<long long,long long>
#define pll pair<long long,long long>
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repe(i,a,n) for(ll i=a;i<=(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define repre(i,n,a) for(ll i=n;i>=(long long)a;--i)
#define endl '\n'
#define MAX 100005
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define start_clock auto start = high_resolution_clock::now()
#define stop_clock auto stop = high_resolution_clock::now()
#define clock_duration auto duration = duration_cast<microseconds>(stop - start)
#define time_taken cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef long long ll;
typedef long double ld;
using namespace std;
using namespace std::chrono;
ll n=0,bits[MAX];
vl a(MAX);
void update(ll x,ll val)
{
    for(;x<n;x+=x&-x)bits[x]+=val;
}
ll sumb(ll x)                                                   //Update and Sum operation of BIT
{
    ll sum=0;
    for(;x;x-=x&-x)sum+=bits[x];
    return sum;
}
ll find_subsq(ll p)
{
    ll dp[n+1][p+1];
    memset(dp,0,sizeof dp);
    repe(i,1,n)dp[i][1]=1;
    repe(k,2,p)
    {
        memset(bits,0,sizeof bits);
        repe(i,2,n)
        {
            update(a[i-1],dp[i-1][k-1]);                        //Dp Table
            dp[i][k]+=sumb(a[i]-1);
        }
    }
    ll ans=0;
    repe(i,1,n)ans+=dp[i][p];
    return ans;
}
int main(){
    FASTER;
        ll  k;
        cin>>n>>k;
        for(ll i=1;i<=n;i++)cin>>a[i];
        cout<<find_subsq(k+1)<<"\n";
    return 0;
}
