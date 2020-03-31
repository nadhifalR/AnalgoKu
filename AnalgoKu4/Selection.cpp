/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include<conio.h>
using namespace std;

int data[100],data2[100];
int n;

void swtch(int a, int b);
void selectionSort();

int main(){
	cout<<"\nPROGRAM MENGURUTKAN DENGAN SELECTION SORT"<<endl;
    cout<<"-----------------------------------------"<<endl;;
	cout<<"\tMasukkan Jumlah Data : ";cin>>n;
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<"\tMasukkan data ke-"<<i<<" : ";
		cin>>data[i];
		data2[i]=data[i];
	}
	selectionSort();
	cout << "-----------------------------------------" << endl;
	cout<<"\tData Setelah di Sort : "<<endl;
	cout<<"\t";
	for(int i=1; i<=n; i++){
	  	cout<<" "<<data[i];
	}
	cout << "\n=========================================\n";
	getch();
}

void swtch(int a, int b){
	int t;
	t = data[b];
	data[b] = data[a];
	data[a] = t;
}

void selectionSort(){
	int pos,i,j;
	for(i=1;i<=n-1;i++) {
	    pos = i;
	    for(j = i+1;j<=n;j++) {
		   if(data[j] < data[pos]) pos = j;
		}
        if(pos != i) swtch(pos,i);
    }
}
