#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int N=0,M=0;

int median(int *a,int m,int n){
    int mean,s,x;s=0;
    for(int i=m;i<=n;i++)
        s+=a[i];
    mean=int(s/(n+1-m));
    s=mean-a[m];
    for(int i=m+1;i<=n;i++){
        if(abs(s)>abs(mean-a[i])){
            s=mean-a[i];
            x=i;
        }
    }
    return x;
}

int random(int l,int r){
    srand(time(0));
    int x=rand()%(r-l);
    cout<<"Random element:"<<l+x<<endl;
    return l+x;
}

void inline mswap(int *a,int x,int y){
    int t;
    t=a[x];
    a[x]=a[y];
    a[y]=t;
    N++;
}

int medianOfMedians(int *a,int n,int x){
    int b[int(n/x)];
    for(int i=0;i<n;i=i+x){
        M++;
        b[int(i/x)]=a[i+int(x/2)];
    }
    for(int i=0;i<int(n/x);i++)
        cout<<b[i]<<" ";
    cout<<endl;
    if(int(n/x)==1)
        return b[0];
    return medianOfMedians(b,int(n/x),x);
}

void quicksort(int *a,int l,int r){
    int i,j,v;
    //int p=random(l,r);
    int p=r-1;
    if(r-1>l){
        v=a[p];i=l-1;j=r;
        while(1){
            while((i<r-1)&&(a[++i]<v))N++;
            while(a[--j]>v)N++;
            if(i>=j)break;
            mswap(a,i,j);
        }
        for(int x=l;x<r;x++)
            cout<<a[x]<<" ";
        cout<<endl;
        mswap(a,i,p);
        for(int x=l;x<r;x++)
            cout<<a[x]<<" ";
        cout<<endl;
        quicksort(a,l,i);
        quicksort(a,i+1,r);
    }
}

int main()
{
    int n,x,k;
    cout<<"Enter no of elements";
    cin >>n;
    int a[n];
    default_random_engine generator(time(NULL));
    normal_distribution<double>distribution(4000,1000);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i]=rand()%n;
        /*x=distribution(generator);
        a[i]=int(x%n);*/
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    //k=medianOfMedians(a,n,3);
    //k=median(a,0,n-1);
    //cout<<k<<endl;
    //a[n-1]=k;
    quicksort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"No of operations: "<<N<<endl;
    return 0;
}
