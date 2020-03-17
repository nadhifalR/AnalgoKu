/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    bool found = false;
    int n=10;
    int x[n]{10,9,8,7,6,5,4,3,2,1};
    int y;
    cout<<"enter number : ";
    cin>>y;

    do{
        if(x[i]==y){
            found=true;
            cout<<"founded in array number "<<i;
        }
        else
            i++;
    }while((i<n) && (not found));

    return 0;
}
