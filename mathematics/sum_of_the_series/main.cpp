#include <bits/stdc++.h>

#define arith_sum(N,A) ((N/A))*(2*A+((N/A)-1)*A)/2 //sum of arithmetic progression

long long Gcd(int a,int b) //pgcd
{
    if(a==0) return b;
    return Gcd(b%a,a);
}

long long Lcm(int a,int b) //ppcm
{
    return (a/Gcd(a,b))*b;
}

//nahesbou sum mta3 a3dad yet9asmou 3la A ba3d la3dad ili yet9assmou 3la b ba3d neterhou ili yet9assmou 3la zouz
long long calculateSum(int N,long long A, long long B) { 
        // code here
        long long sum_of_A=arith_sum(N,A);
        long long sum_of_B=arith_sum(N,B);
        long long lcm=Lcm(A,B);
        long long sum_of_duplicates=arith_sum(N,lcm);
        return sum_of_A+sum_of_B-sum_of_duplicates;

        
}



int main()
{
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    int N,A,B;
    std::cin>>N>>A>>B;
    std::cout<<calculateSum(N,A,B)<<'\n';
}