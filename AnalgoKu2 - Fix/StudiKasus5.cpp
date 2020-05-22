/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
using namespace std;

int main(){
    int i,j,temp,n=10,x[n]{1,20,12,41,10,32,41,22,92,70};

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(x[j]<x[i]){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++){
        cout<<x[i]<<endl;
    }

    return 0;
}
