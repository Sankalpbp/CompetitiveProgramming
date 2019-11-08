#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], long int n){
    
    if(n==0||n==1){
        return true;
    }
    
    return (arr[0]<=arr[1])&&isSorted(arr+1,n-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        int arr[n];
        for(long int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for(long int i=0;i<n-1;i++){
            if(arr[i+1]==arr[i]-1){
                swap(arr[i+1],arr[i]);
            }
        }
        if(isSorted(arr,n)){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
        
    }
	return 0;
}
