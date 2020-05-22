/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
using namespace std;

int main(){
    int i,j,y,mid;
    bool found;

    int n=10;
    int x[n]{1,19,27,36,45,54,63,72,81,90};
    i=0;
    j=n;
    found=false;

    cout<<"enter number : ";
    cin>>y;

    do{
        mid=(i+j)/2;

        if(x[mid]==y){
            found=true;
            cout<<"founded in array number "<<mid;
        }
        else{
            if(x[mid]<y){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
    }while((i<=j) && (not found));

    return 0;
}
