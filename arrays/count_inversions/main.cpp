#include <bits/stdc++.h>

using namespace std;

long long counter{0};

void merge(long long arr[],int begin,int mid,int end)
{
    

    int size1=mid-begin; 

    int size2=end-mid+1; 

        long long *left=new long long int[size1]; 

        long long *right=new long long int[size2];

        for(int i=0;i<size1;++i){

            left[i]=arr[begin+i]; 

        }

        for(int i=0;i<size2;++i){

            right[i]=arr[mid+i]; 

        }

    int i{0} //win yebdaw les element gauches
    ,j{0} // win yebdaw les elements droits
    ,k{begin}; //win tebda sorted array

    while(i<size1 && j<size2)
    {
        if(left[i]>right[j])
        {
            arr[k++]=right[j++];
            counter+=size1-i;
        }else
        {
            arr[k++]=left[i++];
        }

    }
    while(i<size1)
    {
        arr[k++]=left[i++];
    }
    while(j<size2)
    {
        arr[k++]=right[j++];
    }

    delete [] left;
    delete [] right;


}

void mergeSort(long long arr[],int begin,int end)
{
    
    if(begin<end)
    {
        int mid=(begin+end)/2;
        mergeSort(arr,begin,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,begin,mid+1,end);
    }
    
}

long long int inversionCount(long long arr[],int N)
{
    // brute force O(n²)
  /*   int count{0};
    for(int i{0};i<N;i++)
    {
        for(int j{i};j<N;j++)
        {
            if(arr[i]>arr[j]) count++;
        }

    } */

    // nejem nesta3mel merge sort wnahseb koll mara na3mel permutation
    mergeSort(arr,0,N);
    return counter;

}

int main()
{
    ifstream file;
    file.open("fileInput.txt");
    int n;
    file>>n;
    long long arr[n];
    for(int i{0};i<n;i++)
    {
        file>>arr[i];
    }
    cout<<inversionCount(arr,n);
    file.close();
}