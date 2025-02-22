# Syslog Okuma ve Listeleme Programı

Bu program, Linux sistemlerinde bulunan **/var/log/syslog** dosyasını okur ve içeriğini tek yönlü bağlı liste veri yapısı kullanarak saklar. Daha sonra syslog verilerini ekrana yazdırır.

## Kullanılan Veri Yapısı
Programda **tek yönlü bağlı liste** yapısı kullanılmıştır. Her bir düğüm, **Log** yapısı içinde saklanır.

### Yapı Tanımı
```c
struct Log {
    char veri[256];  // Satır verisi
    struct Log* ileri;  // Sonraki düğüm
};
```

## Fonksiyonlar

### 1. **dugumEkle(char* metin)**
Yeni bir düğüm oluşturur ve içeriğine **metin** parametresini kopyalar.

### 2. **sonaEkle(struct Log* bas, char* metin)**
Bağlı listenin sonuna yeni bir düğüm ekler. Eğer liste boşsa, yeni baş düğüm olarak atanır.

### 3. **syslogOku()**
**/var/log/syslog** dosyasını okur ve her satırı bağlı listeye ekler.

### 4. **listeGoster(struct Log* bas)**
Bağlı listedeki verileri ekrana yazdırır.

## Çalıştırma

### Derleme
Programı derlemek için aşağıdaki komutu kullanabilirsiniz:
```sh
gcc syslog_reader.c -o syslog_reader
```

### Çalıştırma
Programı çalıştırmak için:
```sh
./syslog_reader
```

**Not:** **/var/log/syslog** dosyasına erişim için root yetkisi gerekebilir. Bu nedenle programı **sudo** ile çalıştırmalısınız:
```sh
sudo ./syslog_reader
```

## Önemli Notlar
- Program yalnızca Linux sistemlerinde çalışır.
- Syslog dosyasını okumak için **root yetkisi** gereklidir.
- **/var/log/syslog** bazı sistemlerde farklı bir konumda olabilir.

Hazırlayan: Mehmet Akif Geriş Daha fazla bilgi için www.linkedin.com/in/makifgeris

