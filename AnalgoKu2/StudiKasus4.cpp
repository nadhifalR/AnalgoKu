/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
using namespace std;

int main(){
    int i,j,ins,n=10,x[n]{1,20,12,41,10,32,41,22,92,70};

    for(i=1;i<n;i++){
        ins=x[i];
        j=i;

        while((j>0)&&(x[j-1]>ins)){
            x[j]=x[j-1];
            j=j-1;
        };
        x[j]=ins;
    }

    for(i=0;i<n;i++){
        cout<<x[i]<<endl;
    }

    return 0;
}
