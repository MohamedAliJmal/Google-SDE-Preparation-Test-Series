#include <bits/stdc++.h>

using namespace std;

// bool find(vector<string> &res,string& perm)
// {
//     for(auto i:res) if(i==perm) return 1;
//     return 0;
// }

void search(string S,vector<string> &res,array<int,26>& visited,string perm)
{
    //goal mta3na nousslou ngeneraytiw kelma length mta3ha 9ad input
    if(perm.length()==S.length())
    {

        if(find(res.begin(),res.end(),perm)==res.end())
            res.push_back(perm);
        return ;
    }

    //lhana naraw ahana win wchnowa caractere ili bach na5tarouwah
    //ba3d inzidou wina9sou

    for(int i{0};i<S.length();i++)
    {
        if(visited[i]) continue;
        //hna yebda wtrack
        visited[i]=1;
        perm.insert(perm.end(),S[i]);
        search(S,res,visited,perm);
        //backtrack
        visited[i]=0;
        perm.pop_back();
    }
}

vector<string> permutation(string S)
{
    //na3mlou initialisation llcontainer win nhotou resultat wba3d lazemna haja bach na3rfou ahana fi ama harf wachlazemna na5tarou harf a5er 
    // ou container bach narmiw fiha sub task(kelma)
    vector<string> res;
    array<int,26> visited{0};
    search(S,res,visited,"");
    return res;

    
}


int main()
{
    string str;
    cin>>str;
    for(auto i:permutation(str)) cout<<i<<'\n';
    return 0;
}