#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool balls(ll n, ll k){
    
    ll b=0,n1=n;
    while(n>k){
        b+=k;
        n=n-k;
        n=n-(n/10);
    }
    if(n!=0){
        b+=n;
    }
    return 2*b>=n1;
}
int main()
{
    ll n;
    cin>>n;
    
    ll ans=0;
    ll start=1,end=n;
    ll half=n/2;
    while(start<=end){
        ll mid= (start+end)/2;
        if(balls(n,mid)){
            end=mid-1;
            ans=mid;
        }else{
            start=mid+1;
        }
    }
    cout<<ans;
	return 0;
}
