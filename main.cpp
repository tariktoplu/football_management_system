/*****************************************************************************
**								SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**							ÖDEV NUMARASI…...: Proje 1
**							ÖĞRENCİ ADI......: TARIK TOPLU
**							ÖĞRENCİ NUMARASI.: G231210010
**							DERS GRUBU.......: B (İÖ)
****************************************************************************/


#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <locale.h>
#include <cctype>

using namespace std;

class Futbolcu {
private:
	string tcNO;
	string ad;
	string soyad;
	string lisansNo;
	string pozisyon;
	string deger{ 0 };
	string dogumTarih;

	string ktrltakımNo;
	string ktrltakımad;
	string ktrltakımadres;
	string ktrltakımtel;
	string takımyonetici;


public:
	void oyuncuekle() {
		char yanıt = 'e';
		//Yanıt h olana kadar döngü oluşturuluyor
		do {
			ifstream oyuncuKontrol("futbolcu.txt");
			ofstream futbolcuDosyası;
			Futbolcu yeniFutbolcu;
			Futbolcu kontrol;
			bool rakam = false;
			bool sadeceHarf = true;

			//TC numarası hatalıysa tekrar isteniyor
			do {
				cout << "Oyuncu TC No                      : "; cin >> yeniFutbolcu.tcNO;
				//TC numarası 11 hanelimi diye kontrol ediliyor
				if (yeniFutbolcu.tcNO.length() == 11) {
					rakam = true;

					//Her bir eleman kontrol ediliyor
					for (char karakter : yeniFutbolcu.tcNO) {

						//Eğer karakter rakam değilse false dönüyor ve döngüden çıkılıyor
						if (!isdigit(karakter)) {
							rakam = false;
							break;
						}
					}
				}
				//Rakam varsa uyarı döndürülüyor
				else if(!rakam){
					cout << "Geçersiz TC kimlik numarası!\n";
				}
			} while (!rakam);

			//Oyuncu adı hatalıysa tekrar isteniyor
			do {
				cout << "Oyuncu Adı                        : "; cin >> yeniFutbolcu.ad;
				sadeceHarf = true;
				//Bütün karakterler taranıyor
				for (char karakter : yeniFutbolcu.ad) {
					//Harf olup olmadığı kontrol ediliyor
					if (!isalpha(karakter)) {
						sadeceHarf = false;
						break;
					}
				}
				//Harf varsa uyarı veriyor.
				if (!sadeceHarf) {
					cout << "Geçersiz isim!\n";
				}

			} while (!sadeceHarf);

			//Soyad hatalıysa tekrar isteniyor
			do {
				cout << "Oyuncu Soyadı                     : "; cin >> yeniFutbolcu.soyad;
				sadeceHarf = true;

				//Rakam olup olmadığı kontrol ediliyor
				for (char karakter : yeniFutbolcu.soyad) {
					//rakam varsa döngüden çıkıp bool değeri false dönülüyor
					if (!isalpha(karakter)) {
						sadeceHarf = false;
						break;
					}
				}
				//rakam varsa uyar veriyor
				if (!sadeceHarf) {
					cout << "Geçersiz soyisim!\n";
				}

			} while (!sadeceHarf);

			//Lisans No hatalıysa tekrar isteniyor
			do {
				rakam = true;
				cout << "Oyuncunun Lisans No               : "; cin >> yeniFutbolcu.lisansNo;
	
				//Bütün karakterler taranıyor
				for (char karakter : yeniFutbolcu.lisansNo) {

					//Harf olup olmadığı kontrol ediliyor
					if (!isdigit(karakter)) {
						rakam = false;
						break;
					}
				}
				//Harf varsa uyarı veriyor.
				if (!rakam) {
					cout << "Geçersiz lisans numarası!\n";
				}

			} while (!rakam);

			//Oyuncu Pozisyonu hatalıysa tekrar isteniyor
			do {
				cout << "Oyuncunun pozisyonu:(SF,KL,SLK...): "; cin >> yeniFutbolcu.pozisyon;
				sadeceHarf = true;

				//Bütün karakterler taranıyor
				for (char karakter : yeniFutbolcu.pozisyon) {
					//Rakam olup olmadığı kontrol ediliyor
					if (!isalpha(karakter)) {
						sadeceHarf = false;
						break;
					}
				}
				//Rakam varsa uyarı veriyor
				if (!sadeceHarf) {
					cout << "Geçersiz pozisyon!\n";
				}
			} while (!sadeceHarf);

			//Oyuncu değeri hatalıysa tekrar isteniyor
			do {
				rakam = true;
				cout << "Oyuncu değeri(€)                  :"; cin >> yeniFutbolcu.deger;
				
				//Bütün karakterler tek tek taranıyor
				for (char karakter : yeniFutbolcu.deger) {
					//Eğer harf varsa rakam değeri false olup döngüden çıkılıyor
					if (!isdigit(karakter)) {
						rakam = false;
						break;
					}
				}
				//Rakam varsa uyarı veriliyor
				if (!rakam) {
					cout << "Geçersiz futbolcu değeri!\n";
				}

			} while (!rakam);

			cout << "Oyuncunun doğum tarihi(gg.aa.yy)  :"; cin >> yeniFutbolcu.dogumTarih;

			bool oyuncuVar = true;

			//Futbolcu txt si taranıyor
			while (!(oyuncuKontrol.eof())) {
				oyuncuKontrol >> kontrol.tcNO >> kontrol.ad >> kontrol.soyad >> kontrol.lisansNo >> kontrol.pozisyon >> kontrol.deger >> kontrol.dogumTarih;

				//Eğer aynı TC ye sahip oyuncu varsa hata veriliyor
				if (kontrol.tcNO == yeniFutbolcu.tcNO) {
					cout << "Bu TC numarasına sahip oyuncu zaten kayıtlı.\n";
					bool oyuncuVar = false;
					break;
				}

			}
			//Eğer oyuncu yoksa oyuncu yazdırılıyor
			if (oyuncuVar) {

				futbolcuDosyası.open("futbolcu.txt", ios::app);

				futbolcuDosyası << yeniFutbolcu.tcNO << setw(15) << yeniFutbolcu.ad << setw(15) << right << yeniFutbolcu.soyad << setw(15) << right << yeniFutbolcu.lisansNo << setw(15) << right << yeniFutbolcu.pozisyon << setw(15) << right << yeniFutbolcu.deger << setw(15) << right << yeniFutbolcu.dogumTarih << setw(15) << endl;

				cout << "Yeni oyuncu oluşturuldu.\nBaşka oyuncu kaydı yapacak mısınız?(e/h)" << endl;
				cin >> yanıt;
			}

		} while (!(yanıt == 'h' || yanıt == 'H'));

	}

	void oyuncusil() {
		char cevap = 'e';

		//Cevap h veya H olana kadar döngü devam ediyor
		do {
			string silTCNO;
			cout << "Silincek oyuncunun TC numarası nedir?\n";
			cin >> silTCNO;

			Futbolcu kontrol;

			ifstream DosyaOku("futbolcu.txt"); //Bilgi aldık
			ofstream Gecici("gecicifutbolcu.txt", ios::app); //Geçici dosya açıldı
			ifstream takımOku("takim.txt");
			bool takımaKayıtlı = true;

			//futbolcu.txt dosyası satır satır okunuyor
			while (!DosyaOku.eof())
			{

				Futbolcu silOyuncu;
				DosyaOku >> silOyuncu.tcNO >> silOyuncu.ad >> silOyuncu.soyad >> silOyuncu.lisansNo >> silOyuncu.pozisyon >> silOyuncu.pozisyon >> silOyuncu.deger >> silOyuncu.dogumTarih;

				//Eğer tc numarası eşleşirse dosya okunuyor
				if (silTCNO == silOyuncu.tcNO) {

					//takim.txt okunuyor
					while (!(takımOku.eof())) {

						takımOku >> kontrol.ktrltakımNo >> kontrol.ktrltakımad >> kontrol.ktrltakımadres >> kontrol.ktrltakımtel >> kontrol.takımyonetici;

						string dosyaAdı = "takim_" + kontrol.ktrltakımad + ".txt";

						ifstream takımKontrol(dosyaAdı);

						takımKontrol >> kontrol.tcNO >> kontrol.ad >> kontrol.soyad >> kontrol.lisansNo >> kontrol.pozisyon >> kontrol.deger >> kontrol.dogumTarih;

						//TC numarası takımdaki oyuncuyla eşleşiyorsa uyarı veriyor
						if (silTCNO == kontrol.tcNO) {
							takımaKayıtlı = false;
							cout << "Silmek istediğiniz oyuncu bir takıma kayıtlı lütfen önce takımdan siliniz.\n";
							break;
						}

						//Takıma kayıtlı değilse hiçbir şey dosyaya yazılmıyor
						else if (takımaKayıtlı) {
							cout << "Oyuncu başarıyla silindi.\n";
							break;
						}
					}

				}
				//TC numarası eşleşmiyorsa okunan bilgiler aynen yazılıyor
				else
					Gecici << silOyuncu.tcNO << setw(15) << silOyuncu.ad << setw(15) << right << silOyuncu.soyad << setw(15) << right << silOyuncu.lisansNo << setw(15) << right << silOyuncu.pozisyon << setw(15) << right << silOyuncu.pozisyon << setw(15) << right << silOyuncu.deger << setw(15) << right << silOyuncu.dogumTarih << endl;

			}
			DosyaOku.close();
			Gecici.close();

			remove("futbolcu.txt");
			rename("gecicifutbolcu.txt", "futbolcu.txt");

			cout << "Başka oyuncu silicek misiniz?";

		} while (!(cevap == 'h' || cevap == 'H'));
	}

	void oyunculistele() {
		ifstream Listele("Futbolcu.txt");

		char karakter;

		cout << endl;
		cout << "TC       " << setw(15) << right << "AD" << setw(15) << right << "SOYAD" << setw(15) << right << "LISANS NO" << setw(15) << right << "POZISYON" << setw(15) << right << "DEGER" << setw(15) << right << "DOGUM TARIHI" << right << endl << endl;

		//dosyanın sonuna kadar her karakter yazdırılıyor
		while (Listele.get(karakter))
		{
			cout << karakter;
		}


	}

	void oyuncuGuncelle() {


		ifstream Acma("futbolcu.txt"); //Bilgi almak için
		ofstream Gecici("Gecicifutbolcu.txt");//Gecici bilgileri tutmak için

		cout << "Güncellemek istediğiniz oyuncunun TC numarasını giriniz :\n";
		string TcNo;
		cin >> TcNo;
		Futbolcu oyuncuGuncelle;
		bool oyuncuVar = true;

		//Bilgiler satrı satır okunuyor
		while (!(Acma.eof()))
		{
			Acma >> oyuncuGuncelle.tcNO >> oyuncuGuncelle.ad >> oyuncuGuncelle.soyad >> oyuncuGuncelle.lisansNo >> oyuncuGuncelle.pozisyon >> oyuncuGuncelle.deger >> oyuncuGuncelle.dogumTarih;
			
			//TC numarası eşleşirse oyuncu güncelleme menüsü ekrana geliyor
			if (TcNo == oyuncuGuncelle.tcNO) {
				cout << "Oyuncu TC No                      : "; cin >> oyuncuGuncelle.tcNO;
				cout << "Oyuncu Adı                        : "; cin >> oyuncuGuncelle.ad;
				cout << "Oyuncu Soyadı                     : "; cin >> oyuncuGuncelle.soyad;
				cout << "Oyuncunun Lisans No               : "; cin >> oyuncuGuncelle.lisansNo;

				cout << "Oyuncunun pozisyonu:(SF,KL,SLK...): "; cin >> oyuncuGuncelle.pozisyon;

				cout << "Oyuncu değeri                     :"; cin >> oyuncuGuncelle.deger;

				cout << "Oyuncunun doğum tarihi            :"; cin >> oyuncuGuncelle.dogumTarih;

				Gecici << oyuncuGuncelle.tcNO << setw(15) << oyuncuGuncelle.ad << setw(15) << right << oyuncuGuncelle.soyad << setw(15) << right << oyuncuGuncelle.lisansNo << setw(15) << right << oyuncuGuncelle.pozisyon << setw(15) << right << oyuncuGuncelle.deger << setw(15) << right << oyuncuGuncelle.dogumTarih << setw(15) << right << endl;
				oyuncuVar = false;
			}
			//TC eşleşmez ise okunan bilgi yazdırılıyor
			else {
				Gecici << oyuncuGuncelle.tcNO << setw(15) << oyuncuGuncelle.ad << setw(15) << right << oyuncuGuncelle.soyad << setw(15) << right << oyuncuGuncelle.lisansNo << setw(15) << right << oyuncuGuncelle.pozisyon << setw(15) << right << oyuncuGuncelle.deger << setw(15) << right << oyuncuGuncelle.dogumTarih << setw(15) << right << endl;
			}
		}
		//Oyuncu yok ise uyarı veriliyor
		if (oyuncuVar) {
			cout << "Oyuncu bulunamadı.\n";
		}
		Acma.close();
		Gecici.close();

		remove("futbolcu.txt");
		rename("Gecicifutbolcu.txt", "futbolcu.txt");

	}
};

class Takım {
private:
	string takımNo;
	string takımad;
	string takımadres;
	string takımtel;
	string takımyonetici;
	string oyuncuTC;
	string oyuncuAd;
	string oyuncuSoyad;
	string oyuncuLisans;
	string oyuncuPozisyon;
	string oyuncuDeger;
	string dogumTarih;
	int puan{ 0 };


public:
	vector<string> tumTakimlar; // Takımların adları tutuluyor.
	vector<string>ilktakimOyuncular;
	vector<string>ikincitakimOyuncular;

	void fikstur() {

		Takım fikstur;

		srand(time(0));

		ifstream takımOku;
		takımOku.open("takim.txt");

		//Takımlar adları vektöre kayıt edildi
		while (!takımOku.eof()) {
			takımOku >> fikstur.takımNo >> fikstur.takımad >> fikstur.takımadres >> fikstur.takımtel >> fikstur.takımyonetici;

			tumTakimlar.push_back(fikstur.takımad);

		}
		takımOku.close();

		int maxmac = (tumTakimlar.size() + 1) / 2;
		int macsayisi = rand() % maxmac;

		int ilktakimSkor;
		int ikincitakimSkor;

		string ilktakim;
		string ikincitakim;

		ofstream fiksturYaz("HaftalikFikstur.txt", ios::app);

		string dosyaAdı;

		ifstream puanOku;
		puanOku.open("puandurumu.txt");

		ofstream GeciciPuan("GeciciPuan", ios::app);

		//Mac sayısı kadar döngü oluşturuldu
		for (int i = 0; i < macsayisi; i++) {
			ilktakim = rand() % tumTakimlar.size() + 1;

			//İlk takım ile ikinci takımın aynı olması engellendi
			do {
				ikincitakim = rand() % tumTakimlar.size() + 1;
			} while (ikincitakim == ilktakim);

			ilktakimSkor = rand() % 6;
			ikincitakimSkor = rand() % 6;


			//Puan durumları güncelleniyor
			while (!puanOku.eof()) {

				puanOku >> takımad >> puan;

				if (ilktakimSkor > ikincitakimSkor) {

					if (takımad == ilktakim) {
						puan += 3;
						GeciciPuan << takımad << setw(10) << puan << right;

					}
					else if (takımad == ikincitakim) {
						puan += 0;
						GeciciPuan << takımad << setw(10) << puan << right;

					}
				}
				else if (ilktakimSkor == ikincitakimSkor) {
					if (takımad == ilktakim) {
						puan += 0;
						GeciciPuan << takımad << setw(10) << puan << right;

					}
					else if (takımad == ikincitakim) {
						puan += 0;
						GeciciPuan << takımad << setw(10) << puan << right;

					}

				}
				else if (ikincitakimSkor > ilktakimSkor) {
					if (takımad == ikincitakim) {
						puan += 3;
						GeciciPuan << takımad << setw(10) << puan << right;

					}
					else if (takımad == ilktakim) {
						puan += 0;
						GeciciPuan << takımad << setw(10) << puan << right;

					}
				}

			}

			fiksturYaz << ilktakim << setw(10) << right << ilktakimSkor << "-" << ikincitakimSkor << setw(10) << right << ikincitakim << right << endl
				<< "Gol Atan Oyuncular:\n" << ilktakim << ": ";

			ilktakimOyuncular.clear();

			dosyaAdı = "takim_" + ilktakim + ".txt";

			ifstream oyuncuOku;
			oyuncuOku.open(dosyaAdı.c_str());

			//İlk takımın oyuncu bilgileri alınıyor
			while (!oyuncuOku.eof()) {
				oyuncuOku >> oyuncuTC >> oyuncuAd >> oyuncuSoyad >> oyuncuLisans >> oyuncuPozisyon >> oyuncuDeger >> dogumTarih;
				string OyuncuAdSoyad = oyuncuAd + " " + oyuncuSoyad;

				ilktakimOyuncular.push_back(OyuncuAdSoyad);
			}

			int randomOyuncu{ 0 };

			//İlk takım için gol atan oyuncular seçiliyor
			for (int j = 0; j < ilktakimSkor; j++) {
				randomOyuncu = rand() % ilktakimOyuncular.size();
				fiksturYaz << ilktakimOyuncular[randomOyuncu] << ", ";
			}
			oyuncuOku.close();

			dosyaAdı = "takim_" + ikincitakim + ".txt";
			oyuncuOku.open(dosyaAdı.c_str());

			fiksturYaz << endl << ikincitakim << ": ";

			ikincitakimOyuncular.clear();

			//İkinci takımın oyuncu bilgileri alınıyor
			while (!oyuncuOku.eof()) {
				oyuncuOku >> oyuncuTC >> oyuncuAd >> oyuncuSoyad >> oyuncuLisans >> oyuncuPozisyon >> oyuncuDeger >> dogumTarih;

				string OyuncuAdSoyad = oyuncuAd + " " + oyuncuSoyad;

				ikincitakimOyuncular.push_back(OyuncuAdSoyad);
			}

			//İkinci takım için gol atan oyuncular seçilip dosyaya yazılıyor
			for (int k = 0; k < ikincitakimSkor; k++) {

				//Oyuncular okunuyor
				randomOyuncu = rand() % ikincitakimOyuncular.size();
				fiksturYaz << ikincitakimOyuncular[randomOyuncu] << ", ";
			}

			fiksturYaz << endl << "Oyuncu Değişiklikleri:\n" << ilktakim << ": ";

			oyuncuOku.close();

			int ilkOyuncuDegsklk = rand() % 5;
			int ikinciOyuncuDegsklk = rand() % 5;

			int cıkanOyuncu{ 0 };
			int girenOyuncu{ 0 };

			//İlk takımın oyuncu değişikliği kadar oyuncular seçiliyor
			for (int l = 0; l < ilkOyuncuDegsklk; l++) {

				//Aynı oyuncunun seçilmeme durumu kontrol ediliyor
				do {
					cıkanOyuncu = rand() % ilktakim.size();
					girenOyuncu = rand() % ilktakim.size();
				} while (cıkanOyuncu = girenOyuncu);

				fiksturYaz << ilktakimOyuncular[girenOyuncu] << "-->" << ilktakimOyuncular[cıkanOyuncu] << ", ";

			}
			//İkinci takımın oyuncu değişikliği kadar oyuncular seçiliyor
			for (int l = 0; l < ikinciOyuncuDegsklk; l++) {

				//Aynı oyuncunun seçilmeme durumu kontrol ediliyor
				do {
					cıkanOyuncu = rand() % ilktakim.size();
					girenOyuncu = rand() % ilktakim.size();
				} while (cıkanOyuncu = girenOyuncu);

				fiksturYaz << ikincitakimOyuncular[girenOyuncu] << "-->" << ikincitakimOyuncular[cıkanOyuncu] << ", ";

			}


		}
		remove("puandurumu.txt");
		rename("GeciciPuan.txt", "puandurumu.txt");

		puanOku.close();
		fiksturYaz.close();
		GeciciPuan.close();

		cout << "\nFikstur Başarıyla Oluşturuldu!\n";
	}

	void takımolustur() {
		char yanıt = 'e';

		//Yanıt h olana kadar dongü devam ediyor
		do {
			ofstream takimDosyasi;
			Takım yeniTakım;
			bool sadeceRakam = true;
			bool sadeceHarf = true;

			//Takım No hatalıysa tekrar isteniyor
			do {

				cout << " Takım No      : "; cin >> yeniTakım.takımNo;
				//Takım No karakterleri kontol ediliyor
				for (char karakter : yeniTakım.takımNo) {

					//Rakam varsa döngüden çıkılıyor
					if (!isdigit(karakter)) {
						sadeceRakam = false;
						break;
					}
				}
				//Harf varsa hata veriyor
				if (!sadeceRakam) {
					cout << "Hatalı takım numarası!\n";

				}
			} while (!sadeceRakam);
			
			//Takım ad hatalıysa tekrar isteniyor
			do {
				cout << " Takım Adı     : "; cin >> yeniTakım.takımad;

				//Karakterler tek tek okunuyor
				for (char karakter : yeniTakım.takımad) {

					//Rakam varsa false değeri dönüyor ve döngüden çıkılıyor
					if (!isalpha(karakter)) {
						sadeceHarf = false;
						break;
					}
				}
				//Rakam varsa uyarı veriyor
				if (!sadeceHarf) {
					cout << "Hatalı takım adı!\n";
				}

			} while (!sadeceHarf);

			cin.ignore();
			cout << " Adres         : "; ; getline(cin,yeniTakım.takımadres);

			do {
				sadeceRakam = true;
				cout << " Telefon       : "; cin >> yeniTakım.takımtel;
				
				for (char karakter : yeniTakım.takımtel) {

					//Rakam varsa döngüden çıkılıyor
					if (!isdigit(karakter)) {
						sadeceRakam = false;
						break;
					}
				}
				//Harf varsa hata veriyor
				if (!sadeceRakam) {
					cout << "Hatalı takım telefon numarası!\n";

				}
			} while (!sadeceRakam);

			do {
				sadeceHarf = true;
				cout << " Yönetici İsmi : "; cin >> yeniTakım.takımyonetici;
				//Karakterler tek tek okunuyor
				for (char karakter : yeniTakım.takımyonetici) {

					//Rakam varsa false değeri dönüyor ve döngüden çıkılıyor
					if (!isalpha(karakter)) {
						sadeceHarf = false;
						break;
					}
				}
				//Rakam varsa uyarı veriyor
				if (!sadeceHarf) {
					cout << "Hatalı takım yönetici adı!\n";
				}

			} while (!sadeceHarf);

			takimDosyasi.open("takim.txt", ios::app);

			takimDosyasi << yeniTakım.takımNo << setw(10) << right << yeniTakım.takımad << setw(10) << right << yeniTakım.takımadres << setw(10) << right << yeniTakım.takımtel << setw(10) << right << yeniTakım.takımyonetici << right << endl;

			takimDosyasi.close();

			string dosyaAdı = "takim_" + yeniTakım.takımad + ".txt";

			takimDosyasi.open(dosyaAdı.c_str());

			cout << "Takım oluşturuldu.\nBaşka takım kaydı yapacak mısınız?(e/h)" << endl;
			cin >> yanıt;
		} while (!(yanıt == 'h' || yanıt == 'H'));
	}

	void takımSil()
	{
		Takım silTakım;

		string silTakımNo;
		cout << "Silincek takımın numarası nedir?\n";
		cin >> silTakımNo;

		bool takımBulundu = true;

		ifstream DosyaOku("takim.txt"); //Bilgi aldık
		ofstream Gecici("gecici.txt"); //Geçici dosya açıldı

		//Takım silmek için dosya sonuna gelene kadar yazılıyor
		while (!DosyaOku.eof())
		{
			DosyaOku >> silTakım.takımNo >> silTakım.takımad >> silTakım.takımadres >> silTakım.takımtel >> silTakım.takımyonetici;

			//Takım numarası eşleşirse takım siliniyor
			if (silTakımNo == silTakım.takımNo) {
				takımBulundu = false;

				cout << "Başarıyla takım silindi.";

			}
			//Numara eşleşmiyorsa okuduğu bilgiyi yazdırıyor
			else {
				Gecici << silTakım.takımNo << setw(10) << silTakım.takımad << setw(10) << silTakım.takımadres << setw(10) << silTakım.takımtel << setw(10) << silTakım.takımyonetici << endl;
			}
		}

		//Eğer takım bulunamadıysa uyarı veriyor
		if (takımBulundu) {
			cout << "Bu numaraya sahip takım bulunamadı.\n";
		}
		DosyaOku.close();
		Gecici.close();

		string dosyaAdı = "takim_" + silTakım.takımad + ".txt";
		remove(dosyaAdı.c_str());
		rename("gecici.txt", "takim.txt");
	}

	void takımaoyuncuEkle() {
		char cevap = 'e';

		//cevap h olana kadar oyuncu eklenebiliyor
		do {
			Takım takımaekle;
			cout << "Oyuncu eklemek istediğiniz takımın numarasını girin:\n";

			string takımKontrol;
			cin >> takımKontrol;

			ifstream Acma("takim.txt");
			ifstream Acmafutbolcu("Futbolcu.txt");
			bool takımaKayıtlı = true;
			bool takımVar = true;

			//Bilgiler satır satır okunuyor
			while (!(Acma.eof()))
			{
				Acma >> takımaekle.takımNo >> takımaekle.takımad >> takımaekle.takımadres >> takımaekle.takımtel >> takımaekle.takımyonetici;

				//Takım numarası eşleşirse oyuncu ekleme seçenekleri geliyor
				if (takımKontrol == takımaekle.takımNo) {
					takımVar = false;
					cout << "Eklencek Oyuncunun TC Numarasını girin:";
					string TCkontrol;
					cin >> TCkontrol;
					ofstream takımaEkle;

					Acmafutbolcu >> oyuncuTC >> oyuncuAd >> oyuncuSoyad >> oyuncuLisans >> oyuncuPozisyon >> oyuncuDeger >> dogumTarih;

					ifstream takımOku("takim.txt");

					//Eğer tc eşleşiyorsa koşula giriyor
					if (TCkontrol == oyuncuTC) {

						//Oyuncunun başka bir takıma olup olmadığı kontrol ediliyor
						while (!takımOku.eof()) {

							takımOku >> takımaekle.takımNo >> takımaekle.takımad >> takımaekle.takımadres >> takımaekle.takımtel >> takımaekle.takımyonetici;

							string dosyaAdı = "takim_" + takımaekle.takımad + ".txt";

							ifstream dosyaKontrol(dosyaAdı.c_str(), ios::in);

							dosyaKontrol >> takımaekle.oyuncuTC >> takımaekle.oyuncuAd >> takımaekle.oyuncuSoyad >> takımaekle.oyuncuLisans >> takımaekle.oyuncuPozisyon >> takımaekle.oyuncuDeger >> takımaekle.dogumTarih;

							//Eğer oyuncu takıma kayıtlıysa uyarı veriyor
							if (takımaekle.oyuncuTC == oyuncuTC) {
								cout << "Bu oyuncu zaten bir takıma kayıtlı lütfen ilk önce kayıtlı takımdan silin.\n";

								takımaKayıtlı = false;
								break;
							}
							//Takıma kayıtlı değilse oyuncu ekleniyor
							else if (takımaKayıtlı) {
								takımaEkle.open(dosyaAdı, ios::app);
								takımaEkle << oyuncuTC << setw(15) << right << oyuncuAd << setw(15) << right << oyuncuSoyad << setw(15) << right << oyuncuLisans << setw(15) << right << oyuncuPozisyon << setw(15) << right << oyuncuDeger << setw(15) << right << dogumTarih << endl;
								cout << "Oyuncu başarıyla eklendi.";
								takımaEkle.close();
								break;
								
							}

						}
					}

				}
				//Eğer takım bulunamazsa uyarı veriyor
				else if (Acma.eof() && takımVar) {
					cout << "Bu numaraya sahip takım bulunamadı.\n\n";
					break;
				}

			}
			cout << "Baska oyuncu eklemek istiyor musunuz?(e/h)\n";
			cin >> cevap;
		} while (!(cevap == 'h' || cevap == 'H'));
	}

	void takımdanOyuncuSil() {
		ifstream dosyaOku;
		ofstream dosyaYaz;

		string silTakımNo;
		cout << "Hangi takımdan oyuncu silmek istiyorsunuz?\n";
		cin >> silTakımNo;
		dosyaOku.open("takim.txt");
		bool takımBulunmadı = true;

		string dosyaAdı;

		//Takımı bulmak için takim.txt satır satır okunuyor
		while ((!dosyaOku.eof())) {

			dosyaOku >> takımNo >> takımad >> takımadres >> takımtel >> takımyonetici;

			//Takım numarası eşleşirse oyuncu silme seçeceği yazdırılıyor
			if (takımNo == silTakımNo) {
				takımBulunmadı = false;
				string silOyuncuTC;
				cout << "Silmek istediğiniz oyuncunun TC numarasını girin:\n";
				cin >> silOyuncuTC;

				dosyaAdı = "takim_" + takımad + ".txt";

				dosyaOku.open(dosyaAdı);
				dosyaYaz.open("gecici.txt", ios::app);

				//Takımın dosyası okunuyor 
				while (!(dosyaOku.eof())) {
					dosyaOku >> oyuncuTC >> oyuncuAd >> oyuncuSoyad >> oyuncuLisans >> oyuncuPozisyon >> oyuncuDeger >> dogumTarih;
					//Oyuncu tc leri eşleşiyorsa hiçbir şey yazılmıyor
					if (oyuncuTC == silOyuncuTC) {
						cout << "Oyuncu Başarıyla silindi.\n";

					}
					//Tc farklı ise okuduğu oyuncu bilgilerini yazdırıyor
					else {
						dosyaYaz << oyuncuTC << setw(15) << oyuncuAd << setw(15) << right << oyuncuSoyad << setw(15) << right << oyuncuLisans << setw(15) << right << oyuncuPozisyon << setw(15) << right << oyuncuDeger << setw(15) << right << dogumTarih << setw(15) << endl;
					}
				}
				remove(dosyaAdı.c_str());
				rename("gecici.txt", dosyaAdı.c_str());
			}
			//Takım yoksa uyarı veriliyor
			else if (takımBulunmadı)
				cout << "Bu numaraya sahip takım bulunamadı.\n";

		}
	}

	void takımOyuncuListele() {
		string listtakımNo;
		cout << "Listelemek istediğiniz takımın numarasını girin:";
		cin >> listtakımNo;
		bool takımVar = true;

		ifstream takımOku("takim.txt");

		//takin.txt satır satır okunuyor
		while (!takımOku.eof()) {
			takımOku >> takımNo >> takımad >> takımadres >> takımtel >> takımyonetici;

			//Takım numarası eşleşirse oyuncular yazdrılıyor
			if (takımNo == listtakımNo) {
				takımVar = false;
				string dosyaAdı = "takim_" + takımad + ".txt";
				takımOku.open(dosyaAdı);
				char karakter;
				cout << "\n\nTakımdaki Oyuncular:\n";

				//Oyuncular listeleniyor
				while (takımOku.get(karakter)) {
					cout << karakter;
				}

			}
			//Takım yoksa uyarı veriliyor
			else if (takımVar) {
				cout << "Bu numaraya sahip takım bulunamadı!\n\n";
				break;
			}
		}
	}

	void takımOyuncuGuncelle() {
		ifstream takımkontrol("takim.txt");
		ifstream oynckontrol;

		ifstream oyncGuncelOku("futbolcu.txt");
		ofstream oyncGuncel("gecicifutbolcu.txt",ios::app);
		oyncGuncel.open("takim.txt");
		ofstream oyncYaz;
		oyncYaz.open("GeciciTakım.txt");

		cout << "Güncellemek istediğiniz takımın tam adını girin:";

		string kntrlNo;
		cin >> kntrlNo;
		Takım oyncGuncelle;

		string dosyaAdı;

		bool takımYok = true;
		bool oyncYok = true;

		//Bilgiler satır satır okunuyor
		while (!takımkontrol.eof()) {

			takımkontrol >> oyncGuncelle.takımNo >> oyncGuncelle.takımad >> oyncGuncelle.takımadres >> oyncGuncelle.takımtel >> oyncGuncelle.takımyonetici;

			//takım numarası eşleşirse oyuncu güncellemesi isteniyor
			if (kntrlNo == oyncGuncelle.takımNo) {
				bool takımYok = false;
				cout << "Güncellemek istediğiniz oyuncunun TC numarasını girin:";
				string oyncNo;
				cin >> oyncNo;

				takımYok = false;

				dosyaAdı = "takim_" + oyncGuncelle.takımad + ".txt";

				oynckontrol.open(dosyaAdı);

				//Oyuncunun olup olmadığı bilgiler okunup kontrol ediliyor
				while (!oynckontrol.eof()) {
					oynckontrol >> oyncGuncelle.oyuncuTC >> oyncGuncelle.oyuncuAd >> oyncGuncelle.oyuncuSoyad >> oyncGuncelle.oyuncuLisans >> oyncGuncelle.oyuncuPozisyon >> oyncGuncelle.oyuncuDeger >> oyncGuncelle.dogumTarih;

					//Oyuncu tc si eşleşiyorsa oyuncu guncelleme menüsü çıkıyor
					if (oyncNo == oyncGuncelle.oyuncuTC) {
						oyncYok = false;

						cout << "Oyuncu TC No                      : "; cin >> oyuncuTC;
						cout << "Oyuncu Adı                        : "; cin >> oyuncuAd;
						cout << "Oyuncu Soyadı                     : "; cin >> oyuncuSoyad;
						cout << "Oyuncunun Lisans No               : "; cin >> oyuncuLisans;
						cout << "Oyuncunun pozisyonu:(SF,KL,SLK...): "; cin >> oyuncuPozisyon;
						cout << "Oyuncu değeri                     :"; cin >> oyuncuDeger;
						cout << "Oyuncunun doğum tarihi            :"; cin >> dogumTarih;



						oyncYaz << oyuncuTC << setw(15) << setw(15) << oyuncuAd << setw(15) << right << oyuncuSoyad << setw(15) << right << oyuncuLisans << setw(15) << right << oyuncuPozisyon << setw(15) << right << oyuncuDeger << setw(15) << right << dogumTarih << right << endl;

					}
					//TC aynı değilse okunan bilgiler dosyaya yazılıyor
					else {
						oyncYaz << oyncGuncelle.oyuncuTC << setw(15) << oyncGuncelle.oyuncuAd << setw(15) << right << oyncGuncelle.oyuncuSoyad << setw(15) << right << oyncGuncelle.oyuncuLisans << setw(15) << right << oyncGuncelle.oyuncuPozisyon << setw(15) << right << oyncGuncelle.oyuncuDeger << setw(15) << right << oyncGuncelle.dogumTarih << right << endl;
					}
				}
				//bilgiler satır satır okunuyor
				while (!oyncGuncelOku.eof()) {
					oyncGuncelOku>>oyncGuncelle.oyuncuTC >> oyncGuncelle.oyuncuAd >> oyncGuncelle.oyuncuSoyad >> oyncGuncelle.oyuncuLisans >> oyncGuncelle.oyuncuPozisyon >> oyncGuncelle.oyuncuDeger >> oyncGuncelle.dogumTarih;
					
					//oyncNo ile okunan TC eşleşiyorsa bilgiler güncelleniyor
					if (oyncNo == oyncGuncelle.oyuncuTC) {
						oyncGuncel<< oyuncuTC << setw(15) << setw(15) << oyuncuAd << setw(15) << right << oyuncuSoyad << setw(15) << right << oyuncuLisans << setw(15) << right << oyuncuPozisyon << setw(15) << right << oyuncuDeger << setw(15) << right << dogumTarih << right << endl;

					}
					//TC eşleşmiyorsa okunan bilgiler yazdırılıyot
					else {
						oyncGuncel<<oyncGuncelle.oyuncuTC << setw(15) << oyncGuncelle.oyuncuAd << setw(15) << right << oyncGuncelle.oyuncuSoyad << setw(15) << right << oyncGuncelle.oyuncuLisans << setw(15) << right << oyncGuncelle.oyuncuPozisyon << setw(15) << right << oyncGuncelle.oyuncuDeger << setw(15) << right << oyncGuncelle.dogumTarih << right << endl;

					}

				}
				remove("futbolcu.txt");
				rename("gecicifutbolcu.txt", "futbolcu.txt");


			}

		}
		//Takım bulunamazsa uyarı veriyor
		if (takımYok) {
			cout << "Bu numaraya sahip takım bulunamadı!\n\n";
		}
		//Oyuncu bulunamazsa uyarı veriyor
		else if (oyncYok) {
			cout << "Bu TC numaraya sahip kayıtlı oyuncu bulunamadı!\n\n";

		}
		//Oyuncu varsa dosyaların adı güncelleniyor
		else if (!oyncYok) {
			remove(dosyaAdı.c_str());
			rename("GeciciTakim", dosyaAdı.c_str());
		}


	}
};

int main() {

	setlocale(LC_ALL, "Turkish");

	int secim;

	//seçim 0 olana kadar menü seçenekleri ekrana gelir
	do {
		cout << "----- Futbol Lig Takip Sistemi -----\n";
		cout << "1- Takım Oluşturma" << setw(50) << right << "2- Takım Silme\n";
		cout << "3- Takıma Futbolcu Ekleme" << setw(50) << right << "    4- Takımdan Futbolcu Silme\n";
		cout << "5- Takımdaki Futbolcuları Listeleme" << setw(50) << right << "       6- Takımdaki Bir Futbolcuyu Güncelleme\n\n";
		cout << "----- OYUNCU MENÜ SEÇENEKLERİ -----\n\n";
		cout << "7- Oyuncu ekleme                               8-Oyuncu silme (takıma atanan oyuncu önce takımdan silinmelidir.)\n";
		cout << "9- Oyuncu güncelleme" << setw(50) << right << "10-Oyuncular listeleme\n\n" << right;
		cout << "-----FİKSTUR-----\n\n11-Bir hafta ileri git ve fikstur oluştur\n";
		cout << "0- Çıkış" << endl << endl;
		cout << "Seçiminiz: ";

		cin >> secim;

		switch (secim) {
		//secim 1 ise takımoluşturulur
		case 1: {
			Takım yeniTakım;
			yeniTakım.takımolustur();

			break;
		}
		//secim iki ise takımsilinir
		case 2: {
			Takım takımsilici;
			takımsilici.takımSil();

			break;
		}
		//secim 3 ise oyuncu eklenir
		case 3: {
			Takım takımaoyuncuEkle;
			takımaoyuncuEkle.takımaoyuncuEkle();

			break;

		}
		//secim 4 ise oyuncu silinir
		case 4: {
			Takım takımdanoyuncuSil;
			takımdanoyuncuSil.takımdanOyuncuSil();
		}

		//secim 5 ise takımdaki oyuncular listelenir
		case 5: {
			Takım takımOyuncuList;
			takımOyuncuList.takımOyuncuListele();
			break;
		}
		//secim 6 ise takımdaki oyuncu güncellenir
		case 6: {
			Takım oyncgunclTakım;
			oyncgunclTakım.takımOyuncuGuncelle();
			break;
		}
		//secim 7 ise takıma yeni oyuncu eklenir
		case 7: {
			Futbolcu yeniFutbolcu;
			yeniFutbolcu.oyuncuekle();
			break;

		}
		//secim 8 ise oyuncu silinir
		case 8: {
			Futbolcu oyuncuSil;
			oyuncuSil.oyuncusil();
			break;
		}
		//secim 9 ise oyuncu güncellenir
		case 9: {
			Futbolcu futbolcuguncelle;
			futbolcuguncelle.oyuncuGuncelle();
			break;
		}
		//secim 10 ise oyuncular listelenir
		case 10: {
			Futbolcu futbolcuListe;
			futbolcuListe.oyunculistele();
			break;
		}
		//secim 11 ise fikstur oluşturulur
		case 11: {
			Takım fikstur;
			fikstur.fikstur();
			break;
		}
		}

	} while (!(secim == 0));

	return{ 0 };
}