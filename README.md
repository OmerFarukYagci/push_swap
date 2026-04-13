*This project has been created as part of the 42 curriculum by omyagci, yfirat.*

# push_swap

## **Description (Açıklama)**

`push_swap` projesi, iki adet yığın (Stack A ve Stack B) ve kısıtlı sayıda işlem (push, swap, rotate, reverse rotate) setini kullanarak verilen rastgele tam sayıları en düşük hamle (işlem) sayısıyla sıralamayı amaçlayan temel bir 42 algoritma projesidir.

Projenin temel amacı, klasik ve yeni veri sıralama algoritmalarını `push_swap` kurallarına uydurmak ve bunu C programlama dili ile uygun veri yapıları kullanarak inşa etmektir. Odaklanılması gereken ana noktalar algoritma maliyet analizleri, performans optimizasyonu ve hafıza (bellek) yönetimidir. Dinamik olarak girilen farklı boyutlardaki veri setlerinde en verimli kararların alınmasını gerektirir.

## **Instructions (Kurulum ve Çalıştırma)**

Projeyi indirip çalıştırmak için sisteminizde Unix/Linux bazlı bir ortam, `gcc`/`cc` derleyicisi ve `make` aracının bulunduğundan emin olun.

### Derleme ve İnşa
Terminalinizde proje dizinine giderek aşağıdaki komutla programı derleyebilirsiniz:
```bash
make
```

### Temizlik İşlemleri
Derlenme sonucunda oluşan sadece obje (.o) dosyalarını silmek için:
```bash
make clean
```
Derlenmiş çalıştırılabilir dosya(lar) ve obje dosyalarının tamamını temizlemek için:
```bash
make fclean
```
Kütüphaneyi tamamen temizleyip yeniden derlemek için:
```bash
make re
```

### Çalıştırma ve Kullanım Argümanları
Program, girilen parametrelerin doğruluğunu tespit edebilmeli ve ardından doğru komut setini terminale alt alta yazdırmalıdır. Sıralanacak parametreler doğrudan integer tam sayılar olmalıdır.

Ayrıca programın davranışını özelleştirmek ve sıralama stratejisini zorlamak için listeyi vermeden **önce** aşağıdaki özel bayraklar (flags) eklenebilir:
- `--adaptive` : Listenin düzensizliğine ve boyutuna göre en uygun algoritmayı otomatik seçer (Varsayılan).
- `--simple` : Zorunlu olarak **Selection Sort** algoritmasını çalıştırır.
- `--medium` : Zorunlu olarak **Chunk Sort** algoritmasını çalıştırır.
- `--complex` : Zorunlu olarak **Radix Sort** algoritmasını çalıştırır.
- `--bench` : Benchmark modunu etkinleştirir ve işlem sonunda harcanan komut sayıları/efor hakkında istatistikleri terminale yazar.

```bash
# Boşluklarla ayrılmış integer bir dizi girilmesi.
./push_swap 2 1 3 6 5 8

# Tırnak içerisinde (" ") tek paket veya birleşik değer girilmesi.
./push_swap "4 67 3 87 23"

# Benchmark modunda ve belirli bir algoritma ile çalıştırma.
./push_swap --bench --simple 5 1 4 2 8
```
Dilerseniz bu argümanlarla algoritmaların sınırlarını deneyebilir veya doğruluk ölçümü için harici bash checker'lardan faydalanabilirsiniz.

## **Resources (Kaynaklar)**

Proje geliştirme sürecinde, C programlama dilinin veri yapıları konseptinden ve pek çok makaleden faydalanılmıştır. Bunlardan en önemlileri aşağıdadır:
- [Radix Sort Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection Sort - GeeksforGeeks](https://www.geeksforgeeks.org/selection-sort/)
- Zaman/İşlem Karmaşıklığı (Big-O Notation) rehber kaynakları.

## **Technical Choices and Algorithms Selected (Teknik Seçimler ve Algoritmalar)**

Projemizde, kullanılacak sıralama algoritmasının belirlenmesinde iki ana karar mekanizması mevcuttur:

1. **Manuel Yönlendirme (Bayrak / Flag Kullanımı):** Kullanıcı, programı çalıştırırken özel parametreler (`--simple`, `--medium`, `--complex`) vererek algoritma seçimini doğrudan kendisi dikte edebilir.
2. **Dinamik Seçim (Düzensizlik / Disorder Ölçeği):** Varsayılan veya `--adaptive` senaryosunda ise, program dizinin karmaşıklık/düzensizlik oranını (`disorder`) kendisi hesaplar. Elde edilen orana bağlı olarak listeyi hedef en az işlem (hamle) sayısıyla sıralayabilmek için otomatik olarak `radix_sort`, `selection_sort` veya `chunk_sort` çözümlerinden uygun olanına geçer. Böylece gereksiz adımların doğrudan önüne geçilmiş olur.

Uygulanan algoritmaların işleyiş ayrıntıları şu şekildedir:

### 1. Radix Sort (Taban Sıralaması)
**Detay:** `push_swap` programına bit (bitwise) düzeyinde entegre edilmiş geleneksel Radix algoritmasıdır. İşlem öncesi orijinal sayılar kendi değerlerine göre `0`'dan `N-1`'e kadar (normalize edilerek) indekslenir. Bu sayede negatif, uç veya birbirinden çok uzak devasa tam sayılar sorunsuzca işlenir. Stack A'daki indeks bitleri her iterasyonda `0` ve `1` olarak taranır; `0` olanlar B'ye (`pb`) yollanırken, `1` olanlar A'da döndürülür (`ra`).
**Neden ve Ne Zaman Seçilir?:** Liste fazlasıyla dağınık ve yüksek oranda karmakarışık olduğunda (`disorder >= 0.5f`) devreye girer. Değerlerin tamamen kaotik şekilde sıralandığı zorlu (yüksek düzensizlikteki) senaryolarda hamle tasarrufu ve başarı oranı açısından en kararlı algoritmadır.

### 2. Selection Sort (Seçmeli Sıralama)
**Detay:** Sürekli olarak Stack A'daki en küçük sayının bulunup, komut mesafesine göre en uygun hamleyle (`ra` veya `rra`) tepeye çekilmesi ve Stack B'ye (`pb`) yollanması esasına dayanır. Stack A boşalınca liste, Stack B'den tam tersi sıralanmış olacak şekilde Stack A'ya tekrar toplanır (`pa`).
**Neden ve Ne Zaman Seçilir?:** Liste halihazırda sorunsuz bir dizilime çok yakınsa (düzensizlik çok düşükse: `disorder < 0.2f`) tercih edilir. Zaten düzenli sayılabilecek böyle "temiz" bir listeye, Radix veya Chunk Sort gibi tüm sistemi baştan aşağı inceleyen ağır algoritmalar uygulamak yerine direkt doğru elemanları yerine koyan bu basit yapıyı kullanmak büyük miktarda hamle tasarrufu sağlar.

### 3. Chunk Sort (Parçalara / Bloklara Ayırarak Sıralama)
**Detay:** Sayıları belirli sınır (hedef) değerlerine göre gruplandırma mantığıyla çalışır. Baştan aşağı tüm sayıların aralığı belirli küçük gruplara veya dilimlere ("chunk") bölünür. Yığın taranırken sadece hedef grubun sınırları içinde kalan sayılar Stack B'ye aktarılır. Bu sayede Stack B'ye dolan sayılar rastgele değil, kendi grupları (dilimleri) içinde kısmen alt-sıralanmış halde birikir. Son hamlede ise B yığını taranıp sadece en büyük sayılar tek tek bulunup Stack A'nın en üstüne yerleştirilerek sıralama sonlandırılır.
**Neden ve Ne Zaman Seçilir?:** Listenin düzensizlik parametresi ortalama (Medium) sayılacak bir durumda ise (`disorder >= 0.2f` ve `< 0.5f`) seçilir. Ne Selection sort kadar düzenli, ne de Radix sort kadar kaos durumu içermeyen "yarı düzeysel" seriler için en idealdir. Radix'in bit sayısından kaynaklı sürekli yığını kaydırma dezavantajını ekarte ederek çok daha optimize komut sayıları üretir.