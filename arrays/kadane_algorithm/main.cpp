#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long best=*arr;//maximum mta3 array
        long long local{best};//akbar haja t3adit 3liha
        for(int i{1};i<n;i++)
        {
            local=max((long long)*(arr+i),local+*(arr+i));
            best=max(best,local);
            

            /* if(local+*(arr+i)>max)
            {
             local+=(*(arr+i));
             max=local;
             
             }
            else if(*(arr+i)>local) local=*(arr+i);
            else local+=(*(arr+i)); */
           /*  for(int j=i;j<n;j++)
            {
                if(local+*(arr+j)>max) 
                {
                    max=local+*(arr+j);
                    
                }
                local+=*(arr+j);
            }
            local=arr[i]; */
        }
        return best;
}

int main()
{
    int n;
    cin>>n;
    int arr[n]{0};
    for(int i{0};i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxSubarraySum(arr,n)<<'\n';
   
}