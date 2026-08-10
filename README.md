# C++ Mini E-Ticaret Projesi

Basit bir konsol tabanlı e-ticaret uygulaması örneğidir. Bu proje, bir ürün kataloğu görüntüleme, sepete ürün ekleme, sepeti görüntüleme ve satın alma (checkout) işlemlerini simüle eden küçük bir C++ uygulamasıdır.

## Özellikler

- Ürün kataloğu görüntüleme
- Sepete ürün ekleme ve miktar güncelleme
- Stok kontrolü (yetersiz stok durumunda uyarı)
- Sepeti görüntüleme (adet, birim fiyat, toplam)
- Satın alma işlemi: stoktan düşme ve sepetin temizlenmesi

## Proje Dosyası

- `Mini E-Commerce Project.cpp` — Projenin ana kaynak kodu (konsol uygulaması).

## Gereksinimler

- C++ derleyicisi (g++/clang++). C++11 veya daha yeni bir standart önerilir.

## Derleme ve Çalıştırma

Terminal/komut satırında proje dosyasının bulunduğu dizine gidin ve aşağıdaki komutu çalıştırın:

```bash
g++ -std=c++11 "Mini E-Commerce Project.cpp" -o mini_ecommerce
```

Derleme başarılıysa programı çalıştırmak için:

```bash
./mini_ecommerce
```

Windows üzerinde:

```bash
mini_ecommerce.exe
```

## Kullanım

Program çalıştığında menü şeklinde seçenekler görünecektir:

1. Ürün katalogunu görüntüle
2. Sepete ürün ekle
3. Sepeti görüntüle
4. Siparişi tamamla (Checkout)
5. Çıkış

Sepete ürün eklerken önce ürün ID'sini, ardından eklemek istediğiniz adet bilgilerini giriniz. Program stok kontrolü yapacak ve gerekli uyarıları verecektir.

## Kod Hakkında Notlar

- `Product` sınıfı: ürün bilgilerini ve stok yönetimini tutar.
- `Cart` sınıfı: sepetteki öğeleri ve sepet işlemlerini yönetir.
- `Store` sınıfı: ürünleri barındırır ve kullanıcı arayüzünü (menü) sunar.

Eğer Türkçe karakterlerin konsolda doğru görünmemesi gibi bir durum yaşanırsa, terminalinizin karakter kodlamasını (UTF-8) ve yazı tipini kontrol edebilirsiniz.

## Katkıda Bulunma

Katkıda bulunmak isterseniz lütfen bir issue açın veya pull request gönderin. Küçük iyileştirmeler, hata düzeltmeleri ve ek özellik talepleri memnuniyetle karşılanır.

## Lisans

Bu depo için özel bir lisans dosyası belirtilmemiştir. Eğer bir lisans eklemek isterseniz hangi lisansı kullanmak istediğinizi söyleyin — yardımcı olayım.
