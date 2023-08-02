#include <bits/stdc++.h>

using namespace std;

int majorityElement(int a[], int size)
{
        
        // your code here
        // the easy way
       /*  int freq=size/2;
        map<int,int> test;
        for(int i{0};i<size;i++)
        {
            test[*(a+i)]++;
        }
        for(auto i:test)
        {
            if(i.second>freq)
                return i.first;
        }
        return -1; */

        // the optimal solution Moore's voting algorithm 
        int count{1};
        int element=*a;
        for(int i{1};i<size;i++)
        {
            if(*(a+i)==element) count++;
            else count--;

            if(count==0)
            { 
                element=*(a+i);
                count++;
            }

        }
        count=0;
        for(int i{0};i<size;i++)
        {
            if(*(a+i)==element) count++;
        }
        return count>(size/2)?element:-1;


        
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i{0};i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<majorityElement(arr,size)<<'\n';
}
