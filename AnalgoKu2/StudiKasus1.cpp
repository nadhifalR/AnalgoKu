/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
using namespace std;

int main()
{
    int i=0;
    int n=10;
    int x[n]{1,20,12,41,10,32,41,22,92,70};
    int maks = x[0];

    do{
        if(x[i]>maks){
            maks=x[i];
        }
        i++;
    }while(i<n);

    cout<<"Maks : "<<maks;

    return 0;
}
