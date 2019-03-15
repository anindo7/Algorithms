#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector< vector<int> > graph;

vector<int> f;

int connect=0;

long long findpairsum(){
    int n=f.size();
    long sum=0;
    long long sq=0;
    for(int i=0;i<n;i++){
        sum+=f[i];
        sq+=(long long)f[i]*f[i];
    }
    long long squ=(long long)sum*sum;
    return (squ-sq)/2;
}

void dfs(int a){
    connect++;
    //cout<<a<<" ";
    visited[a]=true;
    vector<int> :: iterator i;
    for(i=graph[a].begin();i!=graph[a].end();++i){
        if(visited[*i]==false)
            dfs(*i);
    }
}

int main()
{
    int t;
    //cin>>t;
    //while(t--){
        int n,m;
        cin>>n>>m;
        graph=vector< vector<int> > (n);
        visited=vector<bool> (n,0);
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            //x--;y--;
            graph[x].push_back(y);
            graph[x].push_back(z);
            graph[y].push_back(x);
            graph[y].push_back(z);
        }
        //long long cap=0;
        //int c=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true)
                continue;
            connect=0;
            //c++;
            dfs(i);
            //cout<<endl;
            f.push_back(connect);
        }
        cout<<findpairsum()<<endl;
    //}
    return 0;
}
