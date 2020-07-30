#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

//pendeklarasian tree awal
struct Node
{
    int data,tahun;
    char *judul1[11][20];
    char *penulis[11][20];
    Node *kiri;
    Node *kanan;
};
Node *pohon = NULL;

//fungsi untuk menambahkan node baru
void tambah (Node **root,int databaru,char judul2[20],int tahun1,
				 char penulis1[20])
{
	 //jika root masih kosong
    if ((*root) == NULL)
       {
        Node *baru;       //pembuatan node baru
        baru = new Node;  //pengalokasian memori dari node yang telah dibuat
        //inisialisasi awal node baru
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        baru->judul1[11][20] = &judul2[20];
        baru->tahun = tahun1;
        baru->penulis[11][20] = &penulis1[20];
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        //jika menunjuk ke NULL artinya tidak mempunyai child
        cout<<endl<<" Data Bertambah!"<<endl;
       }

    //jika data yang akan dimasukkan lebih kecil dari root,
    //maka diletakkan di node sebelah kiri
    else if (databaru < (*root)->data)
    	tambah(&(*root)->kiri,databaru,judul2,tahun1,penulis1);

    //jika data yang akan dimasukkan lebih besar dari root,
    //maka diletakkan di node sebelah kanan
    else if (databaru > (*root)->data)
    	tambah(&(*root)->kanan,databaru,judul2,tahun1,penulis1);

    //jika data yang akan dimasukkan sama dengan root
    else if (databaru == (*root)->data)
    	cout<<" Data Sudah ada!";
}


//fungsi tampilan kop inOrder
void kop()
{
 cout<<" ----------------------------------------------------------- "<<endl;
 cout<<"| Kode Buku |         Judul Buku         |    Jenis Buku    |"<<endl;
 cout<<" ----------------------------------------------------------- "<<endl;
}


//fungsi untuk mencetak tree secara inOrder
void inOrder(Node *root)
{      int k;
       if(root != NULL)
       {
           inOrder(root->kiri);
           if(root->data != NULL)
           {
               k=strlen(root->judul1[11][20]);
               cout<<"|   "<<root->data<<"   |";
               if ((root->data) >= 11000 && (root->data) <= 11999)
                     	cout<<" "<<setw(10)<<root->judul1[11][20]<<setw(47-k)<<
                        "|  Buku Bacaan     |";
               else if((root->data) >= 12000 && (root->data) <= 12999)
                     	cout<<" "<<setw(10)<<root->judul1[11][20]<<setw(47-k)<<
                        "|  Buku Pelajaran  |";
               cout<<endl;
           }
           inOrder(root->kanan);
        }
}


//fungsi untuk melakukan pencarian data
void search(Node **root, int cari)
{
    if((*root) == NULL)
        cout<<" Data tidak ditemukan!";

    //jika data yang dicari lebih kecil dari root
    else if(cari < (*root)->data)
        search(&(*root)->kiri , cari);

    //jika data yang dicari lebih besar dari root
    else if(cari > (*root)->data)
        search(&(*root)->kanan , cari);

    //jika data yang dicari sama dengan root
    else if(cari == (*root)->data)
    {
        cout<<endl;
        cout<<" Berikut adalah data buku dengan kode "<<cari<<endl;
        cout<<" Judul Buku   = "<<(*root)->judul1[11][20]<<endl;
        cout<<" Penulis Buku = "<<(*root)->penulis[11][20]<<endl;
        cout<<" Tahun Terbit = "<<(*root)->tahun<<endl;
    }
    else
    {
         system("cls");
         cout<<" Data tidak ditemukan!"<<endl;
    }
}

//Fungsi untuk mengetahui ketinggian/kedalaman
int height(Node *root)
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
void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
                     cout<<" ----------------------------------------------------------- "<<endl;
                     cout<<"                 Data berhasil dihapus                       "<<endl;
                     cout<<" ----------------------------------------------------------- "<<endl<<endl;
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
        system("cls");
        cout<<" Data tidak ditemukan. Penghapusan tidak bisa dilakukan."<<endl;
        return;
    }

       //hanya satu tingkat, dengan kata lain hanya terdapat root
       //jika hanya terdapat root, maka curr node tidak punya parent
       if(height(pohon) == 0)
       {
              if(curr->kiri == NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                     return;
              }
       }

       //lebih dari satu tingkat, sehingga node curr mempunyai parent
       else if(height(pohon) > 0)
       {
              //1. jika node yang dihapus tidak memiliki anak
              if(curr->kiri == NULL && curr->kanan == NULL)
              {
                     //jika node merupakan anak kiri dari parent
                     if(parent->kiri == curr)
                     {
                           //replace parent->kiri dengan NULL
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else //jika node merupakan anak kanan dari parent
                     {
                           //replace parent->kanan dengan NULL
                           parent->kanan = NULL;
                           delete curr;
                     }
                     return;
              }

              //2. Jika node memiliki anak tunggal (anak kiri/anak kanan)
              if((curr->kiri == NULL && curr->kanan != NULL) ||
                 (curr->kiri != NULL && curr->kanan == NULL))
              {
                     //jika curr memiliki anak tunggal di sebelah kanan
                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           //jika curr(data yang ingin dihapus) merupakan anak
                           //kiri dari parent
                           if(parent->kiri == curr)
                           {
                              //ganti isi parent->kiri dengan curr->kanan
                              parent->kiri = curr->kanan;
                              delete curr;
                         }
                         else //jika curr(data yang ingin dihapus) bukan
                              //merupakan anak kiri dari parent
                         {
                              //ganti isi parent->kanan dengan curr->kanan
                              parent->kanan = curr->kanan;
                              delete curr;
                         }
                     }
                  else //jika curr memiliki anak tunggal di sebelah kiri
                  {
                           //jika curr(data yang ingin dihapus) merupakan anak
                           //kiri dari parent
                           if(parent->kiri == curr)
                           {      //ganti isi parent->kiri dengan curr->kiri
                                  parent->kiri = curr->kiri;
                                  delete curr;
                           }
                           else //jika curr(data yang ingin dihapus)
                                //bukan merupakan anak kiri dari parent
                           {
                           	//ganti isi parent->kanan dengan curr->kiri
                               parent->kanan = curr->kiri;
                               delete curr;
                            }
                   }
                   return;
              }

              //3. Node dengan dua anak
              //ganti node dengan nilai terkecil dari Sub Tree Kanan
              if (curr->kiri != NULL && curr->kanan != NULL)
              {
              //variabel bantu ini digunakan agar posisi curr asli tidak berubah, (tetap pada posisi node yang akan dihapus)
              //variabel bantu digunakan untuk mengarah ke suatu node
                     Node* bantu;
                     bantu = curr->kanan;

                     //jika subtree kanan dari posisi node sekarang
                     //(curr,node yang akan dihapus) tidak memiliki anak
                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {
                           //ganti node curr dengan bantu
                           // sama dengan curr = (curr->kanan)->kanan
                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else //jika child kanan dari node curr memiliki child
                     {
                           //jika node child kanan dari curr memiliki child kiri
                           if((curr->kanan)->kiri != NULL)
                           {
                                  //variabel bantu ini digunakan agar posisi curr asli tidak berubah, (tetap pada posisi node yang akan dihapus)
                                  //variabel bantu digunakan untuk mengarah ke
                                  //suatu node
                                  Node* bantu2;
                                  Node* bantu3;
                                  //berlaku sebagai parent dari bantu 2
                                  bantu3 = curr->kanan;         //!perhatikan
                                  bantu2 = (curr->kanan)->kiri; //!perhatikan

                                  //mengarahkan posisi node ke node terkiri(untuk
                                  // menuju ke node yang memiliki nilai terkecil)
                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  //replace nilai dari node curr dengan nilai
                                  //dari node bantu
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else //jika node child kanan dari curr tidak memiliki
                             //child kiri
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              //replace nilai dari node curr dengan nilai dari
                              //node tmp (curr->kanan)
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }
                     }
                     return;
              }
       }
}


//fungsi utama
int main()
{
   //inisialisasi data awal
   char pil,judulbku[20],penulis2[20];
   int tahun2, dell, cari, kode,i;
   char judulbuku[11][20]={"Matematika Mudah","Asal Usul Surabaya","Bahasa Jawa",
   								"Gemar Matematika","Matematika Kelas 6A",
                           "Dongeng Si Kancil","Belajar Menghitung",
                           "Matematika Kelas 1A","Suka Membaca",
                           "99 Tips Sukses UN","Sains Kelas 3A"};
   int  tahunbuku[11]={2000,1999,2012,2018,2019,2000,2001,2009,2010,2019, };
   char pnlsbuku[11][20]={"Annisa Nur", "Nur Farita", "Fariha Hasanah",
   							  "Zakiyah Irfiani","Farita Zakiyah", "Annisa Fariha",
                          "Nur Farita Zakiyah", "Nur Hasanah",
                          "Farita", "Annisa","Annisa dan Farita"};
   int  kode1[11]={11112,12331,11123,12345,11234,11221,12211,11541,12255,12555, };

   for(i=0;i<11;i++)
   	tambah(&pohon, kode1[i], judulbuku[i], tahunbuku[i], pnlsbuku[i]);

     ulangi:
      system("cls");
		cout<<" ---------------------------------- "<<endl;
      cout<<"|        Selamat Datang di         |"<<endl;
      cout<<"|     PERPUSTAKAAN SD GEMILANG     |"<<endl;
      cout<<"|----------------------------------|"<<endl;
      cout<<"| Menu Pilihan :                   |"<<endl;
      cout<<"|    1. Tampilkan Daftar Buku      |"<<endl;
      cout<<"|    2. Lihat Detail Buku          |"<<endl;
      cout<<"|    3. Tambah Data Buku           |"<<endl;
      cout<<"|    4. Hapus Data Buku            |"<<endl;
      cout<<"|    5. Keluar                     |"<<endl;
      cout<<" ---------------------------------- "<<endl<<endl;
      cout<<" Masukkan pilihan Anda : ";
      cin>>pil;
      fflush(stdin); //mengosongkan buffering
      system("cls");

      switch(pil)
        {
              //Tampilkan daftar buku
              case '1':
                     if(pohon != NULL)
                     {
                           //panggil fungsi untuk mencetak data secara inOrder
                           kop();
                           inOrder(pohon);
                     }
                     else
                           cout<<" Data masih Kosong!!!";
                     cout<<" ----------------------------------------------------------- "<<endl;
                     cout<<endl<<" ( Tekan tombol apapun untuk kembali ke menu ) ";
                     _getch();
                     break;

              //Lihat detail buku
              case '2':
                     if(pohon != NULL)
                     {
                     	kop();
                        inOrder(pohon);
                        cout<<" ----------------------------------------------------------- "<<endl<<endl;
                        cout<<" Masukkan kode buku yang ingin dicari : ";
                        cin>>cari;
                        //panggil fungsi untuk melakukan pencarian sekaligus
                        //menampilkan detail buku
                        search(&pohon, cari);
                        cout<<endl;
                     }
                     else
                     	cout<<endl<<" Masih kosong!";
                     cout<<endl<<" ( Tekan tombol apapun untuk kembali ke menu )";
                     _getch();
                     break;

              //Tambah data buku
              case '3':
            			tambah:
                      cout<<" ==== Format Kode Buku ===="<<endl;
                      cout<<"  Buku Bacaan    => 11xxx  "<<endl;
                      cout<<"  Buku Pelajaran => 12xxx  "<<endl;
                      cout<<" =========================="<<endl;
            			 cout<<" Masukkan Kode Buku : ";
                      cin>>kode;
                     if (kode >= 11000 && kode <= 11999)
                     	cout<<" Jenis -> buku bacaan"<<endl<<endl;
                     else if(kode >= 12000 && kode <= 12999)
                     	cout<<" Jenis -> buku pelajaran "<<endl<<endl;
                     else
                     {
                        system("cls");
                     	cout<<" !!! Kode buku salah, isikan sesuai format !!!"
                            <<endl<<endl;
                        goto tambah;
                     }
                     cout<<" Tulis data buku baru!"<<endl;
                     cout<<" Judul buku       = "; gets(judulbku);
                     cout<<" Nama penulis     = "; gets(penulis2);
                     cout<<" Tahun terbit     = "; cin>>tahun2;
                     //panggil fungsi untuk menambah node berisi data pada tree
                     tambah(&pohon,kode,judulbku,tahun2,penulis2);
                     cout<<endl<<" ( Tekan tombol apapun untuk kembali ke menu )";
                     _getch();
                     break;

              //Hapus data buku
              case '4':
                     if(pohon != NULL)
                     {
                           cout<<" Daftar Buku Sebelum Penghapusan:       "<<endl<<endl;
                           kop();
                           inOrder(pohon);
                           cout<<" ----------------------------------------------------------- "<<endl<<endl;
                           cout<<" PENGHAPUSAN DATA"<<endl;
                           cout<<" Masukkan kode buku yang ingin dihapus: ";
                           cin>>dell;
                           cout<<endl;
                           //panggil fungsi yang digunakan untuk melakukan
                           //penghapusan pada suatu node
                           hapus(&pohon , dell);
							}
                     else
                           cout<<endl<<" Masih kosong!";
                     cout<<endl<<" ( Tekan tombol apapun untuk kembali ke menu )";
                     _getch();
                     break;

              //Keluar
              case '5':
                     goto akhir;
                     break;

              default:
              			system("cls");
                  	goto ulangi;
        }
      goto ulangi;
getch();
akhir:
	return 0;
}
