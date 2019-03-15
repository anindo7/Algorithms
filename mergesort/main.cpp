#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>

using namespace std;
int N=0;
void mergesort(int *a,int l,int r){
    int i,m,n1,n2,x,y;x=y=0;
    if(l<r-1){
        m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m,r);
        n1=m-l;
        n2=r-m;
        int la[n1+1],ra[n2+1];
        for(i=0;i<n1;i++)
            la[i]=a[l+i];
        for(i=0;i<n2;i++)
            ra[i]=a[m+i];
        la[n1]=9999;
        ra[n2]=9999;
        for(i=l;i<r;i++){
            N++;
            if(la[x]<ra[y]){
                a[i]=la[x];x++;}
            else{
                a[i]=ra[y];y++;}
        }
    }
}

int main()
{
    int n,x;
    cout<<"Enter no of elements";
    cin >>n;
    int a[n];
    default_random_engine generator(time(NULL));
    normal_distribution<double>distribution(50,5);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i]=rand()%n;
        //distribution(generator);
        //a[i]=int(x%n);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    mergesort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"No of operations: "<<N<<endl;
    return 0;
}
