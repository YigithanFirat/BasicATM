# BasicATM

**Basit Konsol Tabanlı ATM Sistemi**  
C programlama diliyle yazılmış, temel ATM işlemlerini gerçekleştiren minimalist bir sistem: kullanıcının bakiye görüntülemesi, para yatırma ve para çekme işlemleri gibi fonksiyonları içerir.

## Öne Çıkan Özellikler

- 🆔 Kullanıcı kimlik doğrulaması (ID ve PIN)
-  Balance (Bakiye) sorgulama
-  Para yatırma (Deposit)
-  Para çekme (Withdraw)
-  Konsol temelli sade kullanıcı arayüzü

## Dosya Yapısı

- `main.c` — Projenin göz bebeği. Tüm mantık burada dönüyor:
  - Kullanıcı oturumu (ID + PIN)
  - Bakiye kontrolü
  - Para yatırma / çekme
  - Basit arkası dönen akış (loop)
- `README.md` — İşte şu anda yazdığın, sade ama işlevsel dosya

## Gereksinimler

- C dilini anlayacak kafa
- Terminal / Komut Satırı ortamı
- GCC veya benzer bir C derleyicisi

## Kurulum ve Çalıştırma

1. Depoyu klonla veya indirdikten sonra:
    ```bash
    git clone https://github.com/YigithanFirat/BasicATM.git
    cd BasicATM
    ```
2. `main.c` dosyasını GCC ile derle:
    ```bash
    gcc -o basic_atm main.c
    ```
3. Çalıştır:
    ```bash
    ./basic_atm
    ```
4. Giriş bilgilerini gir:
   - Kullanıcı ID'si
   - PIN kodu
   - Bakiye gösterme / para yatırma / para çekme seçenekleri
   - İşin bittiğinde sistem... ironik ama işte kapanıyor! 😉

## Kullanım Akışı (Örnek)

1. Program başlar; ID ve PIN istenir.  
2. Doğruysa menü görünür:
    - [1] Bakiye Görüntüle  
    - [2] Para Yatır  
    - [3] Para Çek  
    - [4] Çıkış  
3. Seçime göre işlem yapılır ve ana menüye dönülür.

## Deneyim Notları

- Yapının sadeliğiyle “az ama öz” prensibini yansıtıyor.
- Daha gelişmiş bir sürüm istiyorsan:
  - Dosyalı kayıt sistemi (örn. CSV)
  - Transaction history (işlem geçmişi)
  - Hata / limit kontrolü
  - Belki biraz grafiksel dokunuş (ncurses veya GUI)...

## Katkıda Bulunanlar

- Bu minimalist harikayı yazan: **YigithanFirat**

### Lisans

- Henüz belirtilmemiş — öyle takılırsan “Özgür gitsin, özgür kalsın” diyebilirsin 😉

---

Bu README, seni repoyu anlamaya götüren bir köprü gibi – sade, direkt ve hızlı. Bir espriyle kapatacak olursam: “Ne demiş atalar — kod yaz, README yaz, uzaya gönder!”  Daha ileri görüşlü, daha derin şeyler istersen, ben buradayım.
::contentReference[oaicite:0]{index=0}
