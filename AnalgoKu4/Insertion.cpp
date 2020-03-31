/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include <conio.h>
using namespace std;

int data[100],data2[100],n;

void insertionSort();

int main(){
	cout<<"\nPROGRAM MENGURUTKAN DENGAN INSERTION SORT"<<endl;
    cout<<"-----------------------------------------"<<endl;;
	cout<<"\tMasukkan Jumlah Data : ";cin>>n;
	cout<<endl;
	for(int i=1;i<=n;i++){
	  cout<<"\tMasukkan data ke-"<<i<<" : ";
	  cin>>data[i];
	  data2[i]=data[i];
	}
	cout<<"\n-----------------------------------------" << endl;
	insertionSort();
	cout<<"\tData Setelah di Sort : "<<endl;
	cout<<"\t";
	for(int i=1; i<=n; i++){
	  	cout<<data[i]<<" ";
	}
	cout<<"\n-----------------------------------------"<<endl;;
	getch();
}

void insertionSort(){
	int temp,i,j;
	for(i=1;i<=n;i++){
	    temp = data[i];
		j = i -1;
	    while(data[j]>temp && j>=0){
			data[j+1] = data[j];
	   	    j--;
	    }
	    data[j+1] = temp;
	}
}
