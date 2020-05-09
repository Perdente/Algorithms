//Time complexity O(sqrt(n))
//https://tutorialspoint.dev/algorithm/mathematical-algorithms/find-divisors-natural-number-set-1
#include<bits/stdc++.h>
using namespace std;
void divisor(long long n)
{
 	vector<long long>v;
 	for(int i=1;i*i<=n;++i)
 	{
 		if(n%i==0)
 		{
 			if(n/i==i)v.push_back(i);
	 		else 
	 		{
	 			v.push_back(i);
	 			v.push_back(n/i);
			}	
		}
	}
	for(auto i:v)cout<<i<<" ";
}
/*// function to print the divisors in sorted order
void Divisor(int n) 
{ 
    // Vector to store half of the divisors 
    vector<int> v; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i) // check if divisors are equal 
                printf("%d ", i); 
            else
            { 
                printf("%d ", i); 
  
                // push the second divisor in the vector 
                v.push_back(n/i); 
            } 
        } 
    } 
  
    // The vector will be printed in reverse 
    for (int i=v.size()-1; i>=0; i--) 
        printf("%d ", v[i]); 
} */ 
int main()
{
	long int n,i;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<endl<<"Divisors of "<<n<<" are: ";
 	divisor(n);
	return 0;
}
