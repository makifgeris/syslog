#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tek yönlü baðlý liste düðümü
struct Log {
    char veri[256];  
    struct Log* ileri;  
};

// Yeni düðüm oluþturma
struct Log* dugumEkle(char* metin) {
    struct Log* yeni = (struct Log*)malloc(sizeof(struct Log));
    if (yeni == NULL) return NULL;  

    strcpy(yeni->veri, metin);
    yeni->ileri = NULL;
    return yeni;
}

// Liste sonuna düðüm ekleme
struct Log* sonaEkle(struct Log* bas, char* metin) {
    struct Log* yeni = dugumEkle(metin);
    if (!yeni) return bas;  

    if (bas == NULL) return yeni;  

    struct Log* gecici = bas;
    while (gecici->ileri != NULL)  
        gecici = gecici->ileri;  

    gecici->ileri = yeni;
    return bas;
}

// Syslog dosyasýný okuma
struct Log* syslogOku() {
    FILE* dosya = fopen("/var/log/syslog", "r");  
    if (dosya == NULL) return NULL;  

    struct Log* bas = NULL;
    char satir[256];

    while (fgets(satir, sizeof(satir), dosya))  
        bas = sonaEkle(bas, satir);  

    fclose(dosya);
    return bas;
}

// Listeyi ekrana yazdýrma
struct Log* listeGoster(struct Log* bas) {
    struct Log* temp = bas;
    while (temp) {
        printf("%s", temp->veri);
        temp = temp->ileri;
    }
    return bas;
}

// Ana fonksiyon
int main() {
    struct Log* bas = syslogOku();  
    bas = listeGoster(bas);  
    return 0;
}
