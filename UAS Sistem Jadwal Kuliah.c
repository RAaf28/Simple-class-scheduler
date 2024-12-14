#include <stdio.h>  // untuk mengakses fitur input/output
#include <stdlib.h> // untuk mengakses fitur alokasi memori
#include <string.h> // untuk mengakses fitur manipulasi string

// Mendefinisikan struct bernama 'kelas' untuk merepresentasikan sebuah kelas
typedef struct kelas
{
    char matkul[50];    // Array untuk menyimpan nama mata kuliah
    char dosen[50];     // Array untuk menyimpan nama dosen
    char ruangan[50];   // Array untuk menyimpan nomor ruangan
    char jadwal[50];    // Array untuk menyimpan jadwal
    char id_matkul[50]; // Array untuk menyimpan ID mata kuliah
    int sks;            // Integer untuk menyimpan jumlah SKS
    struct kelas *next; // Pointer ke struct 'kelas' berikutnya dalam linked list
} kelas;

// Fungsi untuk menambahkan kelas baru ke dalam linked list
void tambah_kelas(kelas **head, char *matkul, char *dosen, char *ruangan, char *jadwal, char *id_matkul, int sks)
{
    kelas *newKelas = (kelas *)malloc(sizeof(kelas)); // Mengalokasikan memori untuk struct 'kelas' baru

    strcpy(newKelas->matkul, matkul);       // Menyalin nama mata kuliah ke dalam struct baru
    strcpy(newKelas->dosen, dosen);         // Menyalin nama dosen ke dalam struct baru
    strcpy(newKelas->ruangan, ruangan);     // Menyalin nomor ruangan ke dalam struct baru
    strcpy(newKelas->jadwal, jadwal);       // Menyalin jadwal ke dalam struct baru
    strcpy(newKelas->id_matkul, id_matkul); // Menyalin ID mata kuliah ke dalam struct baru
    newKelas->sks = sks;                    // Mengatur jumlah SKS di dalam struct baru
    newKelas->next = *head;                 // Menghubungkan struct baru dengan kepala list saat ini
    *head = newKelas;                       // Memperbarui pointer kepala untuk menunjuk ke struct baru
    printf("Kelas berhasil ditambahkan\n"); // Mencetak pesan sukses
}

// Fungsi untuk menghapus kelas dari linked list
void hapus_kelas(kelas **head, char *id_matkul)
{
    kelas *prev = NULL;     // Pointer untuk menyimpan node sebelumnya, diinisialisasi dengan NULL
    kelas *current = *head; // Pointer untuk menyimpan node saat ini, dimulai dari kepala list

    // Loop untuk menelusuri linked list
    while (current != NULL)
    {
        // Cek apakah ID mata kuliah saat ini sama dengan ID yang ingin dihapus
        if (strcmp(current->id_matkul, id_matkul) == 0)
        {
            // Jika node yang ingin dihapus adalah node pertama
            if (prev == NULL)
            {
                *head = current->next; // Update kepala list untuk menunjuk ke node berikutnya
            }
            else
            {
                prev->next = current->next; // Lewati node saat ini dengan menghubungkan node sebelumnya ke node berikutnya
            }
            free(current);                      // Bebaskan memori yang dialokasikan untuk node yang dihapus
            printf("Kelas berhasil dihapus\n"); // Tampilkan pesan bahwa kelas berhasil dihapus
            return;                             // Keluar dari fungsi setelah penghapusan
        }
        prev = current;          // Pindah ke node saat ini untuk iterasi berikutnya
        current = current->next; // Pindah ke node berikutnya dalam list
    }
    // Jika mencapai sini, berarti kelas dengan ID yang diberikan tidak ditemukan
    printf("Kelas dengan ID %s tidak ditemukan\n", id_matkul); // Tampilkan pesan bahwa kelas tidak ditemukan
}

// Fungsi untuk mencari kelas berdasarkan ID mata kuliah
void cari_kelas(kelas **head, char *id_matkul)
{
    kelas *current = *head; // Pointer untuk menyimpan node saat ini
    // Loop untuk menelusuri linked list
    while (current != NULL)
    {
        // Cek apakah ID mata kuliah saat ini sama dengan ID yang dicari
        if (strcmp(current->id_matkul, id_matkul) == 0)
        {
            printf("-----------------------------\n");
            printf("Kelas ditemukan!\n");
            printf("Nama Kelas: %s\n", current->matkul);        // Menampilkan nama kelas
            printf("ID Mata Kuliah: %s\n", current->id_matkul); // Menampilkan Id mata kuliah
            printf("Dosen pengampu: %s\n", current->dosen);     // Menampilkan Dosen pengampu
            printf("Ruangan: %s\n", current->ruangan);          // Menampilkan ruangan
            printf("Jadwal: %s\n", current->jadwal);            // Menampilkan jadwal
            printf("Jumlah SKS: %d\n", current->sks);           // Menampilkan jumlah SKS
            printf("-----------------------------\n");
            return; // Keluar dari fungsi setelah menemukan kelas
        }
        current = current->next; // Pindah ke node berikutnya dalam list
    }

    printf("Kelas dengan ID %s tidak ditemukan\n", id_matkul); // Tampilkan pesan bahwa kelas tidak ditemukan
}

// Fungsi menampilkan semua kelas
void tampilkan_kelas(kelas **head)
{
    kelas *current = *head; // Pointer untuk menyimpan node saat ini

    // Cek apakah list kosong
    if (current == NULL)
    {
        printf("Tidak ada kelas yang tersedia.\n");
        return; // Keluar dari fungsi jika tidak ada kelas
    }

    // Loop untuk menampilkan semua kelas
    while (current != NULL)
    {
        printf("-----------------------------\n");
        printf("Nama Kelas: %s\n", current->matkul);        // Menggunakan nama field yang benar
        printf("ID Mata Kuliah: %s\n", current->id_matkul); // Menggunakan nama field yang benar
        printf("Dosen pengampu: %s\n", current->dosen);
        printf("Ruangan: %s\n", current->ruangan); // Menampilkan ruangan
        printf("Jadwal: %s\n", current->jadwal);   // Menampilkan jadwal
        printf("Jumlah SKS: %d\n", current->sks);  // Menampilkan jumlah SKS
        printf("-----------------------------\n"); // Pemisah antar kelas
        current = current->next;                   // Pindah ke node berikutnya dalam list
    }
}

int main()
{
    kelas *head = NULL;                                                 // Inisialisasi pointer kepala linked list dengan NULL
    int pilihan;                                                        // Variabel untuk menyimpan pilihan menu dari pengguna
    char matkul[50], dosen[50], ruangan[50], jadwal[50], id_matkul[50]; // Array untuk menyimpan input pengguna
    int sks;                                                            // Variabel untuk menyimpan jumlah SKS

    do
    {
        // Menampilkan menu pilihan
        printf("\nMenu:\n");
        printf("1. Tambah Kelas\n");
        printf("2. Hapus Kelas\n");
        printf("3. Cari Kelas\n");
        printf("4. Tampilkan Semua Kelas\n");
        printf("5. Keluar\n");
        printf("Pilih opsi (1-5): ");
        scanf("%d", &pilihan); // Membaca pilihan pengguna
        getchar();             // Menghapus karakter newline dari buffer input

        switch (pilihan) // Memilih tindakan berdasarkan pilihan pengguna
        {
        case 1: // Kasus untuk menambah kelas
            printf("Masukkan nama mata kuliah: ");
            fgets(matkul, 50, stdin);             // Membaca nama mata kuliah dari input
            matkul[strcspn(matkul, "\n")] = '\0'; // Menghapus newline dari input

            printf("Masukkan nama dosen: ");
            fgets(dosen, 50, stdin);            // Membaca nama dosen dari input
            dosen[strcspn(dosen, "\n")] = '\0'; // Menghapus newline dari input

            printf("Masukkan ruangan: ");
            fgets(ruangan, 50, stdin);              // Membaca nomor ruangan dari input
            ruangan[strcspn(ruangan, "\n")] = '\0'; // Menghapus newline dari input

            printf("Masukkan jadwal: ");
            fgets(jadwal, 50, stdin);             // Membaca jadwal dari input
            jadwal[strcspn(jadwal, "\n")] = '\0'; // Menghapus newline dari input

            printf("Masukkan ID mata kuliah: ");
            fgets(id_matkul, 50, stdin);                // Membaca ID mata kuliah dari input
            id_matkul[strcspn(id_matkul, "\n")] = '\0'; // Menghapus newline dari input

            printf("Masukkan jumlah SKS: ");
            scanf("%d", &sks); // Membaca jumlah SKS dari input
            getchar();         // Menghapus newline dari buffer input

            tambah_kelas(&head, matkul, dosen, ruangan, jadwal, id_matkul, sks); // Menambahkan kelas baru ke linked list
            break;

        case 2: // Kasus untuk menghapus kelas
            printf("Masukkan ID mata kuliah yang ingin dihapus: ");
            fgets(id_matkul, 50, stdin);                // Membaca ID mata kuliah yang ingin dihapus
            id_matkul[strcspn(id_matkul, "\n")] = '\0'; // Menghapus newline dari input

            hapus_kelas(&head, id_matkul); // Menghapus kelas berdasarkan ID yang diberikan
            break;

        case 3: // Kasus untuk mencari kelas
            printf("Masukkan ID mata kuliah yang ingin dicari: ");
            fgets(id_matkul, 50, stdin);                // Membaca ID mata kuliah yang ingin dicari
            id_matkul[strcspn(id_matkul, "\n")] = '\0'; // Menghapus newline dari input

            cari_kelas(&head, id_matkul); // Mencari kelas berdasarkan ID yang diberikan
            break;

        case 4:                     // Kasus untuk menampilkan semua kelas
            tampilkan_kelas(&head); // Menampilkan semua kelas yang ada dalam linked list
            break;

        case 5:                               // Kasus untuk keluar dari program
            printf("Exiting the program.\n"); // Menampilkan pesan keluar
            break;

        default:
            printf("Pilihan tidak tersedia.\n"); // Menampilkan pesan jika pilihan tidak valid
            break;
        }

    } while (pilihan != 5); // Mengulangi menu sampai pengguna memilih untuk keluar

    // Membebaskan memori linked list untuk menghindari kebocoran memori
    kelas *current = head; // Pointer untuk menelusuri linked list
    while (current != NULL)
    {
        kelas *temp = current;   // Menyimpan node saat ini
        current = current->next; // Pindah ke node berikutnya
        free(temp);              // Membebaskan memori untuk node yang disimpan
    }

    return 0; // Akhir dari program
}