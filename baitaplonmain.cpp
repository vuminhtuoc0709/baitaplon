#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define MAX 10
struct book_st;
void hienThiDSSS(struct book_st*, int);
void hienThiTheoCot();

struct book_st {
	char  ten [30];
	char theloai[30];
	int  giatien,Stt;
};

typedef struct book_st bs;

void cColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
	
}

void nhapN(book_st ds[], int n){
	for(int i=0; i<n; i++){
	    printf("Nhap thong tin sach thu %d:", i+1);
	    printf("\nNhap so thu tu cho sach thu %d :",i+1);
	    scanf("%d",&ds[i].Stt);
	    printf("\nNhap ten sach:\n"); 
		fflush(stdin); 
		gets(ds[i].ten);
        printf("Nhap the loai sach:\n"); 
		fflush(stdin); 
		gets(ds[i].theloai);
        printf("Nhap gia tien cua sach :\n"); 
		scanf("%d", &ds[i].giatien);

    }
}
void xuatN(book_st ds[], int n){
	for(int i=0; i<n; i++){
		printf("Thong tin sach thu %d: \n", i+1);
		printf("So thu tu cua sach la %d\n", ds[i].Stt);
		printf("Ten sach: %s\n", ds[i].ten);
		printf("the loai sach : %s\n", ds[i].theloai);
		printf("Gia cua sach la: %d\n", ds[i].giatien);
	}
}

void hienthithongtinsach(struct book_st bs){
	printf("||%-20d ||%-20s ||%-20s ||%-20d \n",bs.Stt, bs.ten,bs.theloai,bs.giatien);
}

void sapxeptheoten(struct book_st *ds, int n) {
	int i, j;
	for(i = 0; i < n - 1; i++) {
		for(j = n - 1; j > i; j --) {
			if(strcmp(ds[j].ten , ds[j - 1].ten) > 0)  {
				struct book_st a = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = a;
			}
		}
	}
}
void timTheotheloai(struct book_st *ds, int n) {
	char Ten[30];
	printf("Nhap the loai : ");
	fflush(stdin);
	gets(Ten);
	hienThiTheoCot();
	int i, timS = 0;
	for(i = 0; i < n; i++) {
		if(strcmp(Ten, ds[i].theloai) == 0) {
			hienthithongtinsach(ds[i]);
			timS = 1;
		}
	}
	if(timS == 0) {
		printf("\nKhong co the loai %s trong danh sach sach !", Ten);
	}
}
void timtheogiatien(struct book_st *ds ,int n){
	int gia;
	printf("\nNhap gia tien : ");
	scanf("%d",&gia);
	hienThiTheoCot();
	int i,timS = 0;
	for(i = 0 ; i < n ; i++){
		if(gia == ds[i].giatien){
			hienthithongtinsach(ds[i]);
			timS = 1;
		}
	}
	if(timS == 0){
		printf("\nVui long nhap lai gia tien!");
	}
}

void hienThiTheoCot() {
	printf("-----------------------------------------------------"
	"-----------------------------\n");
	printf("||%-20s ||%-20s ||%-20s ||%-30s \n", 
		"STT" , "Ten", "The loai", "Gia tien" 
	);
}

void hienThiDSSS(struct book_st *ds, int n) {
	hienThiTheoCot();
	int i;
	for(i = 0; i < n; i++) {
		hienthithongtinsach(ds[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------\n");
}
void ghiFile(struct book_st* ds, int n) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for(i = 0; i < n; i++) {
		struct book_st bs = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-20d\n",bs.Stt,bs.ten,bs.theloai,bs.giatien	);
	}
	fclose(fOut);
}

void docFile(struct book_st* ds, int* n) {
	FILE* fOut = fopen("book.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct book_st bs;
			fscanf(fOut,"%10d %10s %20s %20d\n",&bs.Stt,bs.ten,bs.theloai,&bs.giatien);
			ds[i++] = bs;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*n = i;
}
/*
void Ghidanhsachvaoteptin( struct book_st *ds , int n)
{
   FILE *fp;
 
   printf("\n\t\tGHI DANH SACH VAO TEP TIN:");
   fp=fopen("Thuviensach.txt","w");
   if(fp==NULL)
   {
       return;
   }
   // ghi du lieu vao file
 
   for (int i = 0; i < n; i++)
   {
       fwrite(&ds[i],sizeof(struct book_st),1,fp);
    }
 
   fclose(fp);
   printf("\nBam enter de tiep tuc.");
   getch();
}

void Docdanhsachsachtuteptin(struct book_st *ds , int n)
{
    int i = 0;
   FILE *fp;
 
   // mo file o che do doc.
   fp=fopen("thuviensach.txt","r");
   if(fp==NULL)
   {
       printf("Loi roi!");
      return;
   }
   //doc het.
   while(!feof(fp))
   {
        fread(&ds[i],sizeof(struct book_st),1,fp);
       i++;
   }
   n = i-1;
   printf("\t\nTong so sach trong thu vien la:%d",n);
   fclose(fp);
   printf("\nBam enter de tiep tuc.");
   getch();
}
*/

int main(){
	int key,n;
	system("color 30");
	struct book_st ds[MAX];
	bool daNhap = false;
	do{
		printf("\nNhap so luong sach ");
		scanf("%d",&n);
	}while(n<=0);
	while(true){
		system("cls");
		printf("                       ------------------------------------------------------\n");
		printf("                       |          Chuong Trinh Quan Li Thu Vien             |\n");
		printf("                       |      1. Nhap du lieu cua tung quyen sach.          |\n");
		printf("                       |      2. Hien thi thong tin cac loai sach.          |\n");
		printf("                       |      3. Sap xep sach theo thu tu Z->A.             |\n");
		printf("                       |      4. Tim sach theo the loai.                    |\n");
		printf("                       |      5. Tim sach theo gia tien.                    |\n");
		printf("                       |      6. Ghi vao tap tin nhi phan book.txt.         |\n");
		printf("                       |      0. Thoat chuong trinh.                        |\n");
		printf("                       ------------------------------------------------------\n");
		printf("                       ------------------- Ban chon ?------------------------\n");
		scanf("%d",&key);
		switch(key){
			case 1:
				printf("Ban da chon nhap thong tin cho sach\n");
				nhapN(ds,n);
				printf("Ban da nhap thanh cong !\n");
				daNhap = true;
				printf("Bam bat ki phim nao de tiep tuc !");
				getch();
				break;
			case 2:
			if (daNhap){
				printf("Ban da  chon hien thi thong tin sach! \n");
				hienThiDSSS(ds,n);
				}
				else {
					printf("Ban can phai nhap thong tin sach truoc! \n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 3:
				if(daNhap){
					printf("Ban da chon sap xep theo thu tu Z -> A \n");
					printf("Thong tin sach sau khi sap xep :\n");
					sapxeptheoten(ds,n);
					hienThiDSSS(ds,n);
				}
				else{
					printf("Ban phai nhap thong tin sach truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc!");
				getch();
				break;
			
			case 4:
				if(daNhap){
					printf("Ban da chon tim sach theo the loai !\n");
					timTheotheloai(ds,n);
				}
				else{
					printf("Ban phai nhap thong tin cho sach truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 5:
				if(daNhap){
					printf("Ban da chon tim sach theo gia tien !\n");
					timtheogiatien(ds,n);
				}
				else{
					printf("Ban phai nhap thong tin cho sach truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 6:
				if(daNhap){
					printf("Ban da chon ghi vao tap tin nhi phan book.txt !\n");
				ghiFile(ds,n);
				}
				else{
					printf("Ban phai nhap thong tin cho sach truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 0:
				printf("May ban da bi nhiem virus !\n");
				getch();
				return 0;
			default :
				printf("Khong co chuc nang nay\n");
				printf("Bam phim bat ki de tiep tuc!");
				getch();
				break;	
			}	
		}
	}
