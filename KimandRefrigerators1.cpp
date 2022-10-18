//<-------------kim and refrigerators---------------->

//solved by Dynamic  Programming(Bitmask) (Time Complexity O(n*(2^n))


#include<bits/stdc++.h>
using namespace std ;

#define RESET(a,b) memset(a,b,sizeof(a))

int a[12],b[12];
int dp[(1<<12)][12];
int sx,sy,dx,dy,n;


int distance(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}


bool checkbit(int mask,int bit){
    return (mask &(1<<bit));
}

int solve(int mask,int prev){

    if(mask+1==(1<<n))return distance(a[prev],b[prev],dx,dy);

    int &res=dp[mask][prev];

    if(res!=-1)return res;

    res=INT_MAX;

    for(int bit=0;bit<n;bit++){
        if(!checkbit(mask,bit)){
            res=min(res,solve(mask|(1<<bit),bit)+distance(a[bit],b[bit],a[prev],b[prev]));
        }
    }

    return res;
}


int main()
{
    for(int tc=1;tc<=10;tc++){
        cin>>n;
        cin>>sx>>sy>>dx>>dy;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
        a[0]=sx,b[0]=sy;
        n+=1;
        RESET(dp,-1);
        int ans=solve(0,0);
        cout<<"# "<<tc<<" "<<ans<<endl;
    }
    return 0;
}
