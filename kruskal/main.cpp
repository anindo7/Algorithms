#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef struct edge{
int source,dest;
int value;
}E;

vector<E> e;

void mergesort(int l,int r){
    int m=int((r+l)/2);
    int n1,n2,x,y,i;
    if(l<r-1){
        mergesort(l,m);
        mergesort(m,r);
        n1=m-l;
        n2=r-m;
        E la[n1+1],ra[n2+1];
        for(i=0;i<n1;i++)
            la[i]=e[l+i];
        for(i=0;i<n2;i++)
            ra[i]=e[m+i];
        E p;
        p.value=9999;
        la[n1]=p;
        ra[n2]=p;
        x=0;y=0;
        for(i=l;i<r;i++){
            if(la[x].value<ra[y].value){
                e[i]=la[x];x++;}
            else{
                e[i]=ra[y];y++;}
        }
    }
}

typedef struct tree{
    int r;
    int value;
    struct tree *parent;
}S;

S p[10];

void makeset(int v){
    p[v-1].value=v;
    p[v-1].r=0;
    p[v-1].parent=&p[v-1];
}

S * findset(int n){
    return p[n-1].parent;
}

void uni(int a,int b){
    p[b-1].parent=p[a-1].parent;
}

void kruskal(int n){
    vector<E> g;
    for(int i=1;i<=n;i++)
        makeset(i);
    for(int i=0;i<e.size();i++){
        if(findset(e[i].source)!=findset(e[i].dest)){
            //cout<<"Same Set ";
            g.push_back(e[i]);
            uni(e[i].source,e[i].dest);
        }
    }
    cout<<"Spanning tree:"<<endl;
    for(int i=0;i<g.size();i++)
        cout<<g[i].source<<" "<<g[i].dest<<" "<<g[i].value<<endl;
}

int main()
{
    int v;
    cout<<"Enter no of vertices";
    cin>>v;
    while(1){
        E s;
        cout<<"Enter source, 9 to exit";
        cin>>s.source;
        if(s.source==9)
            break;
        cout<<"Enter destination";
        cin>>s.dest;
        cout<<"Enter value";
        cin>>s.value;
        e.push_back(s);
    }
    mergesort(0,e.size());
    cout<<"Edges of the graph"<<endl;
    for(int i=0;i<e.size();i++){
        cout<<e[i].source<<" "<<e[i].dest<<" "<<e[i].value<<endl;
    }
    kruskal(v);
    for(int i=0;i<v;i++){
        cout<<p[i].parent->value<<endl;
    }
    return 0;
}
