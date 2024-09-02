#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define MAX_YATIRILABILIR_PARA (250000)
#define MAX_CEKILEBILIR_PARA   (10000)
#define MAX_TRANSFER_PARA      (500000)

void paracekme_log(int hesapno, int cekilen_para_miktari)
{
	printf("[SÝSTEM - PARA ÇEKME LOG]: %d hesap numarasýndan %d miktarýnda para çekildi!\n", hesapno, cekilen_para_miktari);
}

void parayatirma_log(int yatir_hNo, int yatirilan_hno, int yatirilan_para_miktari)
{
	printf("[SÝSTEM - PARA YATIRMA LOG]: %d hesap numarasýndan %d hesap numarasýna %d miktarýnda para yatýrýldý!\n", yatir_hNo, yatirilan_hno, yatirilan_para_miktari);
}

void paratransfer_log(int transfer_eden_hNo, int transfer_edilen_hNo, int transfer_edilen_para)
{
	printf("[SÝSTEM - PARA TRANSFER LOG]: %d hesap numarasýndan %d hesap numarasýna %d miktarýnda para transfer edildi!\n", transfer_eden_hNo, transfer_edilen_hNo, transfer_edilen_para);
}

void Sistem_Cikis()
{
	printf("[SÝSTEM]: Sistemden çýkýþ yapýlýyor...\n");
	printf("[SÝSTEM - BÝLGÝ]: Hazneden kartýnýzý almayý unutmayýnýz!\n");
	printf("[SÝSTEM]: Çýkýþ yapýldý, kartýnýz haznede!");
}

void Islemler(int hesapno, int islem)
{
	switch(islem)
	{
		case 1:
		{
			int cekmek_istenilen_para = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[SÝSTEM]: Çekmek istediðiniz para miktarýný giriniz: ");
			scanf("%d", &cekmek_istenilen_para);
			if(cekmek_istenilen_para < 0)
			{
				printf("[SÝSTEM - HATA]: Çekmek istediðiniz miktar 0'ýn altýnda olmamalýdýr!\n");
				printf("[SÝSTEM]: Çekmek istediðiniz para miktarýný giriniz: ");
				scanf("%d", &cekmek_istenilen_para);
			}
			while(cekmek_istenilen_para > MAX_CEKILEBILIR_PARA)
			{
				printf("[SÝSTEM - HATA]: Çekmek istediðiniz miktar çekilebilir limitin üstünde!\n");
				printf("[SÝSTEM - BÝLGÝ]: Maksimum çekilebilir para miktarý: %d\n", MAX_CEKILEBILIR_PARA);
				printf("[SÝSTEM]: Çekmek istediðiniz para miktarýný giriniz: ");
				scanf("%d", &cekmek_istenilen_para);
			}
			paracekme_log(hesapno, cekmek_istenilen_para);
			printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[SÝSTEM - HATA]: Hatalý istek ID girdiniz!\n");
				printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
				printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[SÝSTEM - HATA]: Hatalý hesap no istek ID girdiniz!\n");
					printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
					printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[SÝSTEM - HATA]: Bankamýza ait olmayan bir hesap numarasý girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!");
						printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 2:
		{
			int yatirilmak_istenilen_para = 0, yatirilan_hesapno = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[SÝSTEM]: Yatýrmak istediðiniz para miktarýný giriniz: ");
			scanf("%d", &yatirilmak_istenilen_para);
			if(yatirilmak_istenilen_para < 0)
			{
				printf("[SÝSTEM - HATA] Yatýrmak istediðiniz miktar 0'ýn altýnda olmamalýdýr!\n");
				printf("[SÝSTEM]: Yatýrmak istediðiniz para miktarýný giriniz: ");
				scanf("%d", &yatirilmak_istenilen_para);
			}
			while(yatirilmak_istenilen_para > MAX_YATIRILABILIR_PARA)
			{
				printf("[SÝSTEM - HATA] Yatýrmak istediðiniz miktar yatýrýlabilir limitin üstünde!\n");
				printf("[SÝSTEM - BÝLGÝ]: Maksimum yatýrýlabilir para miktarý: %d\n", MAX_YATIRILABILIR_PARA);
				printf("[SÝSTEM]: Yatýrmak istediðiniz para miktarýný giriniz: ");
				scanf("%d", &yatirilmak_istenilen_para);
			}
			printf("[SÝSTEM]: Yatýrmak istediðiniz hesap numarasýný giriniz: ");
			scanf("%d", &yatirilan_hesapno);
			while(yatirilan_hesapno < 10000 || yatirilan_hesapno > 99999)
			{
				printf("[SÝSTEM - HATA]: Hesap numaranýz bankamýza ait deðil!\n");
				printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!\n");
				printf("[SÝSTEM]: Yatýrmak istediðiniz hesap numarasýný giriniz: ");
				scanf("%d", &yatirilan_hesapno);
			}
			parayatirma_log(hesapno, yatirilan_hesapno, yatirilmak_istenilen_para);
			printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[SÝSTEM - HATA]: Hatalý istek ID girdiniz!\n");
				printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
				printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[SÝSTEM - HATA]: Hatalý hesap no istek ID girdiniz!\n");
					printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
					printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[SÝSTEM - HATA]: Bankamýza ait olmayan bir hesap numarasý girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!");
						printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 3:
		{
			int transfer_hesapno = 0, transfer_para = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[SÝSTEM]: Transfer edilecek hesap numarasýný giriniz: ");
			scanf("%d", &transfer_hesapno);
			while(transfer_hesapno < 10000 || transfer_hesapno > 99999)
			{
				printf("[SÝSTEM - HATA]: Hesap numaranýz bankamýza ait deðil!\n");
				printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!\n");
				printf("[SÝSTEM]: Transfer edilecek hesap numarasýný giriniz: ");
				scanf("%d", &transfer_hesapno);
			}
			printf("[SÝSTEM]: Transfer edilecek para miktarýný giriniz: ");
			scanf("%d", &transfer_para);
			while(transfer_para > MAX_TRANSFER_PARA)
			{
				printf("[SÝSTEM - HATA]: Transfer edilebilir para miktarýnýn üstünde deðer girdiniz!\n");
				printf("[SÝSTEM - BÝLGÝ]: Maksimum transfer edilebilir para miktarý: %d\n", MAX_TRANSFER_PARA);
				printf("[SÝSTEM]: Transfer edilecek para miktarýný giriniz: ");
				scanf("%d", &transfer_para);
			}
			paratransfer_log(hesapno, transfer_hesapno, transfer_para);
			printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[SÝSTEM - HATA]: Hatalý istek ID girdiniz!\n");
				printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
				printf("[SÝSTEM]: Farklý bir iþlem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[SÝSTEM - HATA]: Hatalý hesap no istek ID girdiniz!\n");
					printf("[SÝSTEM - BÝLGÝ]: 0 veya 1 olarak deðer girmelisiniz!\n");
					printf("[SÝSTEM]: Ýþlem yapacaðýnýz hesap numarasýný deðiþtirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[SÝSTEM - HATA]: Bankamýza ait olmayan bir hesap numarasý girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!");
						printf("[SÝSTEM]: Yeni iþlem yapmak istediðiniz hesap numarasýný giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para Çekme\n");
					printf("2 - Para Yatýrma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden Çýkýþ\n");
					printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[SÝSTEM - HATA]: Hatalý iþlem ID girdiniz!\n");
						printf("[SÝSTEM - BÝLGÝ]: Ýþlem ID'leri 1-4 arasýndadýr!\n");
						printf("[SÝSTEM]: Yapýlacak iþlemi seçiniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 4:
		{
			Sistem_Cikis();
			break;
		}
	}
}

int main(int argc, char *argv[]) 
{
	system("cls");
	system("color 4F");
	setlocale(LC_ALL, "Turkish");
	int islem = 0, hesapno = 0;
	printf("Hesap numaranýzý giriniz: ");
	scanf("%d", &hesapno);
	while(hesapno < 10000 || hesapno > 99999)
	{
		printf("[SÝSTEM - HATA]: Hesap numaranýz bankamýza ait deðil!\n");
		printf("[SÝSTEM - BÝLGÝ]: Bankamýza ait hesap numaralarý 10000-99999 arasýndadýr!\n");
		printf("Hesap numaranýzý giriniz: ");
		scanf("%d", &hesapno);
	}
	printf("1 - Para Çekme\n");
	printf("2 - Para Yatýrma\n");
	printf("3 - Para Transferi\n");
	printf("4 - Sistemden Çýkýþ\n");
	printf("Ýþlemi seçiniz: ");
	scanf("%d", &islem);
	while(islem < 1 || islem > 4)
	{
		printf("[SÝSTEM - HATA]: Geçersiz iþlem ID!\n");
		printf("[SÝSTEM - BÝLGÝ]: Bankamýzda 4 iþlem ID bulunmaktadýr!\n");
		printf("1 - Para Çekme\n");
		printf("2 - Para Yatýrma\n");
		printf("3 - Para Transferi\n");
		printf("4 - Sistemden Çýkýþ\n");
		printf("Ýþlemi seçiniz: ");
		scanf("%d", &islem);
	}
	Islemler(hesapno, islem);
	return 0;
}
