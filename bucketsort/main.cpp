#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

int N=0;

void bucketsort(float *a,int l,int r){
    vector<float> b[128];
    for(int i=0;i<128;i++){
        b[i].push_back(-0.99);N++;
        }
    int k;
    for(int i=l;i<r;i++){
        int x=int(128*a[i]);
        b[x].push_back(a[i]);
        float v=a[i];k=b[x].size()-1;
        while(b[x][k-1]>v){
            b[x][k]=b[x][k-1];k--;N++;
            }
        b[x][k]=v;
    }
    int x=0;
    for(int i=0;i<128;i++)
        cout<<b[i].size()<<endl;
    for(int i=0;i<128;i++){
        for(int j=1;j<b[i].size();j++){
            a[x++]=b[i][j];N++;}
    }
}

int main()
{
    int n;
    default_random_engine generator(time(NULL));
    normal_distribution<float>distribution(0.5,0.2);
    cout<<"Enter no of elements";
    cin>>n;
    float p[n];
    //for(int i=0;i<10;i++)p[i]=0;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        float x=distribution(generator);
        //double x=double(double(rand())/(RAND_MAX+1));
        p[i]=abs(x);
    }
    for(int i=0;i<n;i++)cout<< p[i]<<" ";
    cout<<endl;
    bucketsort(p,0,n);
    for(int i=0;i<n;i++)cout<< p[i]<<" ";
    cout<<endl;
    cout<<"No of operations: "<<N<<endl;
    return 0;
}
