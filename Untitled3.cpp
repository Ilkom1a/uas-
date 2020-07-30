/*
________________________________________________
		PROGRAM INPUT DATABASE MAHASISWA
		CREATED BY FAKHRUL & SULAIMAN
------------------------------------------------		
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//modular untuk header
header() 
{
	system("cls");
	printf("========================================================================================\n");
	printf("|                                    DATABASE MAHASISWA                                |\n");
	printf("|                                Created by Fakhrul & Sulaiman                         |\n");
	printf("========================================================================================\n");
}

//pilihan menu utama
menu() 
{
	char pilihan;

	header();
	printf("MENU PILIHAN\t: \n");
	printf("1. Start Program\n2. Help\n3. Exit\n\n");
	printf("Masukkan Pilihan : ");

}

//inputan menu mulai
inputan()
{
	char input;
	printf("1. INPUT DATA BARU\n2. INPUT DATA LAMA\n3. MEMBACA FILE\n");
	printf("\nMASUKKAN PILIHAN : ");
}

//membaca inputan user
void clearbuffer() {
	char gf;
	while ((gf = getchar()) != '\n' && gf != EOF);
}

//USER INPUT DATA YG BARU
int data_baru()
{
	header();
	
	int i, j, k, Ndata;
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	
	/*MENGGUNAKAN DATA STRUCT UNTUK MEMBANDINGKAN DAN SORTING IPK*/
	struct database {
		char nama[25];
		int NPM[25];
		float IPK[25];
	} temp;
	
	struct database mahasiswa[100];

	/*BANYAK DATA YANG AKAN DIINPUT*/
	printf("BANYAK DATA YANG AKAN DIMASUKKAN : ");
	scanf("%d", &Ndata);

	/*INPUT DATA NAMA, NPM, IPK*/
	for(i=0; i<Ndata; i++) {
		printf("\nData ke-%d\n", i+1);
		printf("NAMA\t\t: ");
		scanf("%s", mahasiswa[i].nama);
		clearbuffer();

		printf("NPM\t\t: ");
		scanf("%s", &mahasiswa[i].NPM);
		clearbuffer();

		printf("IPK\t\t: ");
		scanf("%s", &mahasiswa[i].IPK);
		clearbuffer();

		printf("\n");
	}

	/*SORTING STRUCT ASCENDING*/
	for(i=0; i<Ndata-1; i++) {
		for(j=0; j<Ndata-i-1; j++) {
			if(strcmp(mahasiswa[j].IPK, mahasiswa[j+1].IPK)>0) {
				temp=mahasiswa[j];
				mahasiswa[j]= mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	//MEMASUKKAN DATA BARU KE NOTEPAD
	DATABASE=fopen("DATABASE.txt", "w");
	if(DATABASE==NULL) {
		printf("file dibuat\n");
	} else {
		fprintf(DATABASE, "=============================================================================================================\n");
		fprintf(DATABASE, "|                                         DATABASE MAHASISWA                                                |\n");
		fprintf(DATABASE, "=============================================================================================================\n");
		fprintf(DATABASE, "|\t\tNAMA\t\t |\t\tNPM\t\t\t |\t\tIPK\t\t |\n");
		fprintf(DATABASE, "-------------------------------------------------------------------------------------------------------------\n");
	}
	fclose(DATABASE);
	
	//MEMASUKKAN DATA KE NOTEPAD DAN TERURUT
	printf("\nUrutan Data Mahasiswa dari IPK Tertinggi ke Terendah :\n");
	for(i=Ndata; i>-1; i--) {
		//print hasil output dalam program yang dijalankan
		printf("%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);

		DATABASE=fopen("DATABASE.txt", "a");//menambahkan database yg sudah ada dalam file
		if(DATABASE==NULL) {
			printf("file dibuat\n");
		} else {
			fprintf(DATABASE, "|\t\t%s\t\t |\t\t%s\t\t |\t\t%s\t\t |\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);
		}
		fclose(DATABASE);
	}

	printf("\n\nDATA BERHASIL DISIMPAN\n\n");
}

//USER MELANJUTKAN INPUT DATA LAMA
int data_lama()
{
	header();
	
	int i, j, k, Ndata;
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	/*MENGGUNAKAN DATA STRUCT UNTUK MEMBANDINGKAN DAN SORTING IPK*/
	struct database {
		char nama[25];
		int NPM[25];
		float IPK[25];
	} temp;
	
	struct database mahasiswa[100];

	/*BANYAK DATA YANG AKAN DIINPUT*/
	printf("BANYAK DATA YANG AKAN DIMASUKKAN : ");
	scanf("%d", &Ndata);

	/*INPUT DATA NAMA, NPM, IPK*/
	for(i=0; i<Ndata; i++) {
		printf("\nData ke-%d\n", i+1);
		printf("NAMA\t\t: ");
		scanf("%s", mahasiswa[i].nama);
		clearbuffer();

		printf("NPM\t\t: ");
		scanf("%s", &mahasiswa[i].NPM);
		clearbuffer();

		printf("IPK\t\t: ");
		scanf("%s", &mahasiswa[i].IPK);
		clearbuffer();

		printf("\n");
	}

	/*SORTING STRUCT ASCENDING*/
	for(i=0; i<Ndata-1; i++) {
		for(j=0; j<Ndata-i-1; j++) {
			if(strcmp(mahasiswa[j].IPK, mahasiswa[j+1].IPK)>0) {
				temp=mahasiswa[j];
				mahasiswa[j]= mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	//MEMASUKKAN DATA KE NOTEPAD DAN TERURUT
	printf("\nUrutan Data Mahasiswa dari IPK Tertinggi ke Terendah :\n");
	for(i=Ndata; i>-1; i--) {
		//print hasil output dalam program yang dijalankan
		printf("%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);

		DATABASE=fopen("DATABASE.txt", "a");//menambahkan database yg sudah ada dalam file
		if(DATABASE==NULL) {
			printf("file tidak ditemukan\n");
		} else {
			fprintf(DATABASE, "|\t\t%s\t\t |\t\t%s\t\t |\t\t%s\t\t |\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);
		}
		fclose(DATABASE);
	}

	printf("\n\nDATA BERHASIL DISIMPAN\n\n");
}

//membaca file pada Notepad
int baca_file()
{
	header();
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	int ch;
	
	DATABASE=fopen("DATABASE.txt","r");
	if(DATABASE==NULL) {
		puts("Can't open that file!");
		exit(1);
	}
	while((ch=fgetc(DATABASE))!=EOF)
	putchar(ch);
	fclose(DATABASE);
	system("pause");
	
}

//program input data
int mulai() {

	header();
	inputan();
	switch(getch())
	{
		case '1':
			data_baru();
			system("pause");
			return 0;
		case '2':
			data_lama();
			system("pause");
			return 0;
		case '3':	
			baca_file();
			system("pause");
			return 0;
		default:
			salah();
	}
	
	system("pause");
	system("cls");
}

//menu help
help() {
	header();
	printf("Program ini dibuat untuk mempermudah user dalam memasukkan data\n\n");
	printf("Cara Memasukkan Data : \n");
	printf("1. Masukkan jumlah data yang ingin diinput lalu klik enter\n2. Masukkan Nama lalu klik enter\n3. Masukkan NPM lalu klik enter\n3. Masukkan IPK lalu klik enter\n\n");
	printf("PRESS ANY KEY TO CONTINUE\n\n");

	system("pause");
	system("cls");
	return 0;
}

//modular terima kasih
close() {
	header();
	printf("       ooooooooooo  ooooooo     oooo        o     oo          oo         o               \n");
	printf("            o       o           o   o       o     o  o       o o        o o              \n");
	printf("            o       o           o    o      o     o    o   o   o       o   o             \n");
	printf("            o       ooooooo     oooo        o     o      o     o      o     o            \n");
	printf("            o       o           oo          o     o            o     ooooooooo           \n");
	printf("            o       o           o  o        o     o            o    o         o          \n");
	printf("            o       ooooooo     o    o      o     o            o   o           o         \n");
	printf("                                                                                         \n\n");
	printf("                  o   o           o           oooooo    o       o      o                 \n");
	printf("                  o  o           o o          o         o       o      o                 \n");
	printf("                  o o           o   o         o         o       o      o                 \n");
	printf("                  oo           ooooooo        oooooo    o       oooooooo                 \n");
	printf("                  o o         o       o            o    o       o      o                 \n");
	printf("                  o  o       o         o           o    o       o      o                 \n");
	printf("                  o   o     o           o     oooooo    o       o      o                 \n");

	system("pause");
	system("cls");
}

//modular unutk default
salah() {
	system("cls");
	header();
	printf("DATA YANG ANDA MASUKKAN SALAH, SILAKAN ULANGI LAGI\n\n");
	system("pause");
	system("cls");
}

int main() {
	menu();
	//pilihan menu utama
	switch(getch()) { //langsung berjalan tanpa menekan enter
		case '1':
			mulai();//modular program database
			return main();

		case '2':
			help();//program modular menu help
			return main();

		case '3':
			close();//modular close
			return 0;

		default:
			salah();//modular salah input
			return main();
	}
}
