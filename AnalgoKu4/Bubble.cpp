/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int arr[100],n,temp;
	cout<<"\n\tPROGRAM MENGURUTKAN DENGAN BUBBLE SORT"<<endl;
    cout<<"---------------------------------------------------------"<<endl;;
	cout<<"Masukkan banyak elemen yang akan diinputkan : ";cin>>n;
	cout<<endl;
	for(int i=0;i<n;++i){
		cout<<"\tMasukkan Elemen ke-"<<i+1<<" : ";cin>>arr[i];
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<(n-1);j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"---------------------------------------------------------" << endl;
	cout<<"\tHasil dari Bubble Sort : "<<endl;
	cout<<"\t";
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}
	cout<<"\n========================================================="<<endl;
}
