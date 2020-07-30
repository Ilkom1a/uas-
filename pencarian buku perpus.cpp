#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct node
{
	int data, tahun;
	char *judul1[11][20];
	char *penulis[11][20];
	node *kiri;
	node *kanan;
};
node *pohon = NULL;

void tambah (node **root,int databaru,char judul2[20],int tahun1,char penulis1[20])
{
	if ((*root) == NULL)
	{
		node *baru;
		baru = new node;
		baru->data = databaru;
		baru->kiri = NULL;
		baru->kanan = NULL;
		baru->judul1[11][20] =& judul2[20];
		baru->tahun = tahun1;
		baru->penulis[11][20] =& penulis1[20];
		(*root) = baru;
		(*root)->kiri = NULL;
		(*root)->kanan = NULL;
 		cout<<endl<<"Data Bertambah !";
	}
	else if (databaru < (*root)->data) 
		
		tambah (&(*root)->kiri,databaru,judul2,tahun1,penulis1);
	
	else if (databaru > (*root)->data)
		
		  tambah (&(*root)->kanan,databaru,judul2,tahun1,penulis1);
	
	else if (databaru == (*root)->data) 
		
		cout<<"Data Sudah Ada";
}


void kop()
{
	cout<<" ----------------------------------------------------------------------- "<<endl;
	cout<<"| Kode Buku	|	Judul Buku		  |	Jenis Buku	|"<<endl;
	cout<<" ----------------------------------------------------------------------- "<<endl;
}

void inOrder(node *root)
{
	int k;
	if (root!=NULL)
	{
		inOrder(root->kiri);
		if(root->data != NULL)
		{
			k=strlen(root->judul1[11][20]);
		cout<<"| "<<root->data<<"		|";
		if ((root->data) >= 11000 && (root->data) <= 11999)
			cout<<" "<<root->judul1[11][20]<<setw(47-k)<<" | Buku Bacaaan		|";
		else if ((root->data) >= 12000 && (root->data) <= 12999)
			cout<<" "<<root->judul1[11][20]<<setw(47-k)<<"  | Buku Pelajaran		|";
		cout<<endl;
		}
	inOrder(root->kanan);
	}
}

//fungsi cari
void search(node **root,int cari) 
{		
		if((*root) == NULL)
			cout<<" Data tidak ditemukan!";
		//jika data yang dicari lebih kecil dari root
		else if(cari < (*root)->data)
			search(&(*root)->kiri, cari);
		
		//jika data yang dicari lebih besar dari root
		else if(cari > (*root)->data)
			search(&(*root)->kanan, cari);
			
		//jika data yang dicari sama dengan root
		else if(cari == (*root)->data)
		{
			cout<<endl;
			cout<<" Berikut adalah data buku dengan kode "<<cari<<endl;
			cout<<" Judul Buku	= "<<(*root)->judul1[11][20]<<endl;
			cout<<" Penulis Buku	= "<<(*root)->penulis[11][20]<<endl;
			cout<<" Tahun Terbit	= "<<(*root)->tahun<<endl;
		}
		else
		{
			cout<<endl<<" Data tidak ditemukan! \n"<<endl;
		}
}

//fungsi untuk mengetahui ketinggian/kedalaman
int height(node *root)
{
		if(root == NULL)
				return -1;
		else{
			int u = height(root->kiri);
			int v = height(root->kanan);
			if(u > v)
				return u + 1;
			else
				return v + 1;
		}
}

//fungsi yang digunakan untuk menghapus suatu node 
void hapus(node **root, int del)
{
		node *curr;
		node *parent;
		curr = (*root);
		
		bool flag = false;
		while(curr != NULL)
		{
				if(curr->data == del)
				{
						flag = true;
						cout<<" ----------------------------------------------------------- ";
						cout<<"                    Data berhasil dihapus                    ";
						cout<<" ----------------------------------------------------------- ";
						break;
				}
				else
				{
					parent = curr;
					if(del > curr->data)
						curr = curr->kanan;
					else
						curr = curr->kiri;
				}
		}
	if(!flag)
	{
		
		cout<<" Data tidak ditemukan. Pengahapusan tidak bisa dilakukan."<<endl;
		return;
	}
		if(height(pohon) == 0)
		{ 
			if(curr->kiri == NULL && curr->kanan == NULL)
			{
					(*root) = NULL;
					return;
			}
	}
	//lebih dari satu tingkat
	else if(height(pohon) > 0)
	{
			//no.1
			if(curr->kiri == NULL && curr->kanan == NULL)
			{
				if(parent->kiri == curr)
				{
					parent->kiri = NULL;
					delete curr;
				}
				else
				{
					parent->kanan = NULL;
					delete curr;
				}
				return;
			}
		
			//no.2
			if((curr->kiri == NULL && curr->kanan != NULL) ||
		   (curr->kiri != NULL && curr->kanan == NULL))
			{
				if(curr->kiri == NULL && curr->kanan != NULL)
				{
					if(parent->kiri == curr)
					{
					parent->kanan = curr->kanan;
					delete curr;
					}
				else
				{
				parent->kiri = curr->kanan;
				delete curr;
				}
				}
			else
			{
				if(parent->kiri == curr)
				{
					parent->kiri = curr;
					delete curr;
				}
				else
				{
				parent->kanan = curr->kiri;
				delete curr;
				}
			}
			return;
			}
			
		//no3
		if (curr->kiri != NULL && curr->kanan != NULL)
		{
			node* bantu;
			bantu = curr->kanan;
	
			if((bantu->kiri == NULL) && (bantu->kanan == NULL))
			{
				curr=bantu;
				delete bantu;
				curr->kanan = NULL;
			}
			else
			{
				if((curr->kanan)->kiri != NULL)
				{
					node* bantu2;
					node* bantu3;
		
					bantu3 = curr->kanan;
					bantu2 = (curr->kanan)->kiri;
					
					while(bantu2->kiri != NULL)
					{
						bantu3 = bantu2;
						bantu2 = bantu2->kiri;
					}
					curr->data = bantu2->data;
					delete bantu2;
					bantu3->kiri = NULL;
				}
				else
				{
					node* tmp;
					tmp = curr->kanan;
					curr->data = tmp->data;
					curr->kanan = tmp->kanan;
					delete tmp;
				}
			}
			return;
		}
	}
}

//menu utama
int main ()
{
	char pil,judulbku[20],penulis2[20];
	int tahun2, dell, cari, kode, i;
	char judulbuku[11][20]={"","Matematika Mudah","Asal Usul Surabaya","Makan Tempe","M","Aa","Me","se","saf","awf","aww"};
	int tahunbuku[11]={2000,2019,2020,1900,1992,1888,2009,2001,2021,2023,2020 };
	char pnlsbuku[11][20]={"","arik","putu","waw","afif","sinta","cici","wawan","ziad","hana","waw"};
	int kode1[11]={12001,12007,11118,11101,11102,12103,12111,11112,11113,11117, };
	
	for(i=0;i<11;i++)
	tambah(&pohon, kode1[i], judulbuku[i], tahunbuku[i], pnlsbuku[i]);
	system("cls");
	ulangi:
		cout<<" ------------------------------------------------ "<<endl;
		cout<<"|		PERPUSTAKAAN TESTING		 |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"| Menu :					 |"<<endl;
		cout<<"|	1. Tamplikan daftar buku		 |"<<endl;
		cout<<"|	2. Lihat detail buku			 |"<<endl;
		cout<<"|	3. Tambah data buku			 |"<<endl;
		cout<<"|	4. Hapus data buku			 |"<<endl;
		cout<<"|	5. Keluar				 |"<<endl;
		cout<<" ------------------------------------------------ "<<endl<<endl;
		cout<<" Masukan Pilihan Anda : ";
		cin>>pil;
		fflush(stdin);
	 	
		switch(pil) 
		{
			case '1' :
				if(pohon != NULL) 
				{
					kop();
					inOrder(pohon);
				}
				else 
					{
					cout<<" Data Masih Kososng !";
					}
					cout<<" ----------------------------------------------------------------------- "<<endl;
					system("pause");
					_getch();
					break;
					
			case '2' :
				if(pohon != NULL)
				{
					kop() ;
					inOrder(pohon) ;
					cout<<"--------------------------------------------------------------------------"<<endl;
					cout<<" Masukkan kode buku yang ingin dicari : ";
					cin>>cari;
					cout<<" ----------------------------------------------------------------------- "<<endl;
					search (&pohon, cari);
					cout<<endl<<" ----------------------------------------------------------------------- "<<endl;
					cout<<endl;
    			}
    			else
				{
				cout<<endl<<" Masih kosong !";
				}
  				  system("pause");
  				  _getch();
 				  break;

   			 case '3' :
    			tambah:
    				cout<<endl;
    				cout<<" ==== Format Kode Buku ===="<<endl;
    				cout<<"  Buku Bacaan    =>  11xxx "<<endl;
    				cout<<"  Buku Pelajaran =>  12xxx "<<endl;
    				cout<<" =========================="<<endl;
    				cout<<" Masukkan Kode Buku : ";
   			 		cin>>kode;
   			 		
				if (kode>= 11000 && kode <= 11999)
    				cout<<" Jenis -> buku pelajaran "<<endl<<endl;
    			else if(kode >= 12000 && kode <= 12999)
    		  		cout<<" Jenis -> buku pelajaran "<<endl<<endl;
    			else
    			{
    				system("cls");
    				cout<<" !!! Kode buku salah, isikam sesuai format !!!"
    			    <<endl<<endl;
    			    
    			goto tambah;
				}
					cout<<" Tulis data buku baru!"<<endl;
					cout<<" Judul buku	= "; 
					cin>>judulbku;
					cout<<" Nama penulis	= ";
					cin>>penulis2; 
					cout<<" Tahun terbit	= "; 
					cin>>tahun2;
				tambah(&pohon,kode,penulis2,tahun2,penulis2);
				system("pause");
				system("cls");
				_getch();
				break;
			
			case '4':
				if(pohon != NULL)
				{
					cout<<" Daftar Buku Sebelum Penghapusan:            "<<endl<<endl;
					kop();
					inOrder (pohon);
					cout<<" ----------------------------------------------------------------";
					cout<<" PENGHAPUSAN DATA"<<endl;
					cout<<" Masukkan kode buku yang ingin dihapus:  ";
					cin>>dell;
					cout<<endl;
					hapus (&pohon , dell);
				}
				else
		    		cout<<endl<<" Masih kosong! ";
					cout<<endl<<" ( Tekanan tombol apapun untuk ke menu )";
				getch();
				break;
		
			case '5':
				goto akhir;
				break;
			
			default:
				goto ulangi;
   		}
goto ulangi;
akhir:
	return 0;
}
