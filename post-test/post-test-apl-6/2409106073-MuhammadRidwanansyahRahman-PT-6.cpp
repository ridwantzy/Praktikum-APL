#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct StokHarga {
    int stok;
    int harga;
};

struct Barang {
    string nama;
    StokHarga detail;
};

struct User {
    string username;
    string password;
    string role;
};

const int MAX_BARANG = 20;
const int MAX_USER = 10;
Barang barang[MAX_BARANG];
User users[MAX_USER];
int jumlahBarang = 0;
int jumlahUser = 0;
bool running = true;


void SortNamabubble(Barang arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama > arr[j + 1].nama) {
                Barang temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SortHargaSelection(Barang arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j].detail.harga > arr[max_idx].detail.harga) 
            {
                max_idx = j;
            }
        }
        Barang temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

void SortStokInsertion(Barang arr[], int n) {
    for (int i = 1; i < n; i++) 
    {
        Barang key = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j].detail.stok < key.detail.stok) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int hitungTotalHarga(int* harga, int* jumlah) {
    if (*jumlah == 0) {
        return 0;
    }
    (*jumlah)--;
    return *harga + hitungTotalHarga(harga, jumlah);
}

void tampilkanBarang() {
    for (int i = 0; i < jumlahBarang; i++) {
        cout << setw(5) << i + 1 << setw(20) << barang[i].nama 
             << setw(10) << barang[i].detail.stok 
             << setw(10) << barang[i].detail.harga << "\n";
    }
}

void updateStokBarang(Barang *barangPtr, int newStok) {
    if (barangPtr != nullptr) {
        barangPtr->detail.stok = newStok;
    }
}

void updateHargaBarang(Barang *barangPtr, int newHarga) {
    if (barangPtr != nullptr) {
        barangPtr->detail.harga = newHarga;
    }
}

void tambahBarang() {
    if (jumlahBarang < MAX_BARANG) {
        cin.ignore();
        cout << "Masukkan Nama Barang: ";
        getline(cin, barang[jumlahBarang].nama);

        int stok, harga;

        cout << "Masukkan Stok Barang: ";
        cin >> stok;
        barang[jumlahBarang].detail.stok = stok;

        cout << "Masukkan Harga Barang: ";
        cin >> harga;
        barang[jumlahBarang].detail.harga = harga;

        jumlahBarang++;
        system("cls");
        cout << "\n==============================================" << endl;
        cout << "           BARANG BERHASIL DITAMBAHKAN          " << endl;
        cout << "==============================================" << endl;
        cout << "Barang dengan nama " << barang[jumlahBarang - 1].nama << endl;
        cout << "Jumlah barang: " << barang[jumlahBarang - 1].detail.stok << endl;
        cout << "Harga barang: " << barang[jumlahBarang - 1].detail.harga << endl;
        cout << "==============================================" << endl;
        cout << "Klik Enter untuk kembali ke menu utama...";
        cin.ignore();
        cin.get();
    } else {
        cout << "Kapasitas barang penuh!\n";
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

void lihatBarang() {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang tersedia.\n";
    } else {
        system("cls");
        Barang tempBarang[MAX_BARANG];
        for (int i = 0; i < jumlahBarang; i++) {
            tempBarang[i] = barang[i];
        }
        
        cout << "\n========================== PENGURUTAN ==========================\n";
        cout << "Pilih metode pengurutan :\n";
        cout << "---------------------------------------------------------------\n";
        cout << "  1. Urutkan berdasarkan Nama (A-Z)\n";
        cout << "  2. Urutkan berdasarkan Harga (Tertinggi-Terendah)\n";
        cout << "  3. Urutkan berdasarkan Stok (Terbanyak-Tersedikit)\n";
        cout << "  4. Tanpa pengurutan\n";
        cout << "---------------------------------------------------------------\n";
        cout << "Pilihan: ";
        
        int sortpilihan;
        cin >> sortpilihan;
        
        switch(sortpilihan) {
            case 1:
                system("cls");
                SortNamabubble(tempBarang, jumlahBarang);
                cout << "Diurutkan berdasarkan Nama (A-Z)\n";
                break;
            case 2:
                system("cls");
                SortHargaSelection(tempBarang, jumlahBarang);
                cout << "Diurutkan berdasarkan Harga (Tertinggi-Terendah)\n";
                break;
            case 3:
                system("cls");
                SortStokInsertion(tempBarang, jumlahBarang);
                cout << "Diurutkan berdasarkan Stok (Terbanyak-Tersedikit)\n";
                break;
            case 4:
                system("cls");
                cout << "Menampilkan tanpa pengurutan\n";
                break;
                default:
                cout << "Pilihan tidak valid, menampilkan tanpa sorting.\n";
            }
            
        cout << "\n==============================================" << endl;
        cout << "             DAFTAR BARANG SEMBAKO          " << endl;
        cout << "==============================================" << endl;
            
        cout << setw(5) << "No" << setw(20) << "Nama Barang" 
             << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
        for (int i = 0; i < jumlahBarang; i++) {
            cout << setw(5) << i + 1 << setw(20) << tempBarang[i].nama 
                 << setw(10) << tempBarang[i].detail.stok 
                 << setw(10) << tempBarang[i].detail.harga << "\n";
        }
        cout << "==============================================" << endl;
    }
    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void updateBarang() {
    if (jumlahBarang > 0) {
        int index;

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "             DAFTAR BARANG SEMBAKO          " << endl;
        cout << "==============================================" << endl;
        cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
        tampilkanBarang();
        cout << "==============================================" << endl;

        cout << "Masukkan nomor barang yang ingin diupdate: ";
        cin >> index;
        if (index < 1 || index > jumlahBarang) {
            cout << "Nomor barang tidak valid. Kembali ke menu CRUD...\n";
            cout << "Klik Enter...";
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Masukkan Nama Barang Baru: ";
        cin.ignore();
        getline(cin, barang[index - 1].nama);

        int stokBaru;
        cout << "Masukkan Stok Barang Baru: ";
        cin >> stokBaru;
        updateStokBarang(&barang[index - 1], stokBaru);

        int hargaBaru;
        cout << "Masukkan Harga Barang Baru: ";
        cin >> hargaBaru;
        updateHargaBarang(&barang[index - 1], hargaBaru);

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "             BARANG BERHASIL DIUPDATE          " << endl;
        cout << "==============================================" << endl;
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    } else {
        cout << "Tidak ada barang yang tersedia.\n";
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

void hapusBarang() {
    if (jumlahBarang > 0) {
        int index;

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "             DAFTAR BARANG SEMBAKO          " << endl;
        cout << "==============================================" << endl;
        cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
        tampilkanBarang();
        cout << "==============================================" << endl;

        cout << "Masukkan nomor barang yang ingin dihapus: ";
        cin >> index;
        if (index < 1 || index > jumlahBarang) {
            cout << "Nomor barang tidak valid. Kembali ke menu CRUD...\n";
            cout << "Klik Enter...";
            cin.ignore();
            cin.get();
            return;
        }

        Barang *hapusBarang = &barang[index - 1];
        for (int i = index - 1; i < jumlahBarang - 1; i++) {
            barang[i] = barang[i + 1];
        }
        jumlahBarang--;

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "            BARANG BERHASIL DIHAPUS          " << endl;
        cout << "==============================================" << endl;
        cout << "Barang dengan nama " << hapusBarang->nama << "\n";
        cout << "Jumlah barang : " << hapusBarang->detail.stok << "\n";
        cout << "Harga barang : " << hapusBarang->detail.harga << "\n";
        cout << "==============================================" << endl;
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    } else {
        cout << "Tidak ada barang yang tersedia.\n";
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

void beliBarang() {
    if (jumlahBarang > 0) {
        int index, jumlahBeli;

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "             DAFTAR BARANG SEMBAKO          " << endl;
        cout << "==============================================" << endl;
        cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
        tampilkanBarang();
        cout << "==============================================" << endl;

        cout << "Masukkan nomor barang yang ingin dibeli: ";
        cin >> index;
        if (index < 1 || index > jumlahBarang) {
            cout << "Nomor barang tidak valid. Kembali ke menu Pembeli...\n";
            cout << "Klik Enter...";
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Masukkan jumlah yang ingin dibeli: ";
        cin >> jumlahBeli;

        Barang *barangBeli = &barang[index - 1];
        barangBeli->detail.stok -= jumlahBeli;
        int totalHarga = hitungTotalHarga(&barangBeli->detail.harga, &jumlahBeli);

        system("cls");
        cout << "\n==============================================" << endl;
        cout << "             PEMBELIAN BERHASIL          " << endl;
        cout << "==============================================" << endl;
        cout << "Total harga: Rp " << totalHarga << ",-" << endl;
        cout << "Silahkan lakukan pembayaran..." << endl;
        cout << "==============================================" << endl;
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    } else {
        cout << "Tidak ada barang yang tersedia.\n";
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
    }
}

void menuPenjual() {
    bool menucrud = true;
    while (menucrud) {
        system("cls");
        cout << "\n==============================================" << endl;
        cout << "          MENU MANAJEMEN BARANG SEMBAKO          " << endl;
        cout << "==============================================" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Lihat Barang" << endl;
        cout << "3. Update Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "==============================================" << endl;
        cout << "Pilih menu: ";
        int crudPilihan;
        cin >> crudPilihan;

        switch (crudPilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatBarang();
                break;
            case 3:
                updateBarang();
                break;
            case 4:
                hapusBarang();
                break;
            case 5:
                menucrud = false;
                break;
            default:{
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cout << "Klik Enter untuk coba lagi...";
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
}

void menuPembeli() {
    bool pembeliRunning = true;
    while (pembeliRunning) {
        system("cls");
        cout << "\n==============================================" << endl;
        cout << "                 MENU PEMBELI          " << endl;
        cout << "==============================================" << endl;
        cout << "1. Lihat Barang" << endl;
        cout << "2. Beli Barang" << endl;
        cout << "3. Keluar" << endl;
        cout << "==============================================" << endl;
        cout << "Pilih menu: ";
        int pembeliPilihan;
        cin >> pembeliPilihan;

        switch (pembeliPilihan) {
            case 1:
                lihatBarang();
                break;
            case 2:
                beliBarang();
                break;
            case 3:
                pembeliRunning = false;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                cout << "Klik Enter untuk coba lagi...";
                cin.ignore();
                cin.get();
        }
    }
}

void login() {
    string username, password;
    int kesempatan = 0;
    const int max_kesempatan = 3;
    bool loginBerhasil = false;
    string role;

    while (kesempatan < max_kesempatan && !loginBerhasil) {
        cin.ignore();
        system("cls");
        cout << "\n======================================" << endl;
        cout << "             Login Program          " << endl;
        cout << "======================================" << endl;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        if (username == "Muhammad Ridwanansyah Rahman" && password == "2409106073") {
            loginBerhasil = true;
            role = "penjual";
        } else {
            for (int i = 0; i < jumlahUser; i++) {
                if (users[i].username == username && users[i].password == password) {
                    loginBerhasil = true;
                    role = users[i].role;
                    break;
                }
            }
        }
        if (loginBerhasil) {
            system("cls");
            cout << "\n======================================" << endl;
            cout << "             Login Berhasil          " << endl;
            cout << "======================================" << endl;
            cout << "Selamat datang, " << username << "!" << endl;
            cout << "Anda login sebagai " << role << "." << endl;
            cout << "======================================" << endl;
            cout << "Klik Enter untuk melanjutkan...";
            cin.ignore();

            if (role == "penjual") {
                menuPenjual();
            } else if (role == "pembeli") {
                menuPembeli();
            }
        } else {
            kesempatan++;
            cout << "Login gagal. Sisa percobaan: " << max_kesempatan - kesempatan << "\n";
            cout << "Klik Enter...";
            cin.clear();
        }
    }

    if (kesempatan == max_kesempatan) {
        system("cls");
        cout << "\n======================================" << endl;
        cout << "             Login Gagal          " << endl;
        cout << "======================================" << endl;
        cout << "Anda telah mencoba login " << kesempatan  << " kali." << endl;
        cout << "Program berhenti karena batas" << endl; 
        cout << "percobaan telah tercapai." << endl;
        cout << "======================================" << endl;
        running = false;
    }
}

void registrasi() {
    if (jumlahUser < MAX_USER) {
        cin.ignore();
        system("cls");
        cout << "\n======================================" << endl;
        cout << "           REGISTRASI AKUN          " << endl;
        cout << "======================================" << endl; 
        cout << "Username: ";
        getline(cin, users[jumlahUser].username);
        cout << "Password: ";
        getline(cin, users[jumlahUser].password);
        users[jumlahUser].role = "pembeli";
        jumlahUser++;
        system("cls");
        cout << "\n======================================" << endl;
        cout << "          REGISTRASI BERHASIL          " << endl;
        cout << "======================================" << endl;
        cout << "Selamat, Anda telah berhasil mendaftar!" << endl;
        cout << "======================================" << endl;
        cout << "Klik Enter untuk kembali ke menu...";
        cin.ignore();
    } else {
        cout << "Kapasitas user penuh!\n";
        cout << "Klik Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }
}

void tampilkanMenuUtama() {
    while (running) {
        system("cls");
        cout << "\n======================================" << endl;
        cout << "          SELAMAT DATANG          " << endl;
        cout << "======================================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar" << endl;
        cout << "======================================" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                login();
                break;
            case 2:
                registrasi();
                break;
            case 3:
                running = false;
                system("cls");
                cout << "\n==============================================" << endl;
                cout << "         ANDA TELAH KELUAR DARI PROGRAM          " << endl;
                cout << "==============================================" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cout << "Klik Enter untuk coba lagi...";
                cin.ignore();
                cin.clear();
                cin.get();
                break;
        }
    }
}
    
int main() {
    User *admin = &users[jumlahUser++];
    admin->username = "Muhammad Ridwanansyah Rahman";
    admin->password = "2409106073";
    admin->role = "penjual";
    
    Barang *item1 = &barang[jumlahBarang++];
    item1->nama = "Beras";
    item1->detail.stok = 100;
    item1->detail.harga = 5000;
    
    Barang *item2 = &barang[jumlahBarang++];
    item2->nama = "Gula Pasir";
    item2->detail.stok = 50;
    item2->detail.harga = 2000;
    
    Barang *item3 = &barang[jumlahBarang++];
    item3->nama = "Minyak Goreng";
    item3->detail.stok = 20;
    item3->detail.harga = 15000;
    
    tampilkanMenuUtama();
    return 0;
}