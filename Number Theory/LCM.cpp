/*Count the number of divisors*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n,cnt=0;cin>>n;
    for(long long i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
