//Md. Saidul Islam
//Codeforces: saidul_1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BinaryExponential(ll base, ll power, ll MOD){
    ll ans=1;base%=MOD;
    while(power>0){
        if(power%2){
            ans=(ans*(base%MOD))%MOD;
        }
        base=(base*base)%MOD;
        power/=2;
    }
    return ans%MOD;
}
int main(){
    ll i,t,n,k,leading,trailing;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n>>k;
        /*  x=n^k;
            log(x)=klong(n); x=10^(klog(n));
            ans=x/(10^int(log(x))-2);//make it 3digit
               = {10^(klog(n))} /(10^int(log( {10^(klog(n))} ))-2);
               ={10^(klog(n))}/(10^int(klog(n))-2);//base10 of the log and the power removed
               =10^(klog(n)-int(klog(n))+2);
        */
        leading=pow(10,k*log10(n)-int(k*log10(n))+2);
        trailing=BinaryExponential(n,k,1000);
        cout<<"Case "<<i<<": "<<leading<<" ";
        if(trailing<10)cout<<"00";
        else if(trailing<100)cout<<"0";
        cout<<trailing<<"\n";
    }
    return 0;
}
