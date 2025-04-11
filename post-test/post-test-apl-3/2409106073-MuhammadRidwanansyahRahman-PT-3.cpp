// kalo mau login penjual masukkan usn "Muhammad Ridwanansyah Rahman" dan pw "2409106073". 
// klo pembeli regis dlu trus login dgn usn & pw regis sebelumnya 🙌😁

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

int main() {
    // Data penjual default
    users[jumlahUser].username = "Muhammad Ridwanansyah Rahman";
    users[jumlahUser].password = "2409106073";
    users[jumlahUser].role = "penjual";
    jumlahUser++;

    // Data barang default
    barang[0].nama = "Beras";
    barang[0].detail.stok = 100;
    barang[0].detail.harga = 5000;
    jumlahBarang++;

    barang[1].nama = "Gula Pasir";
    barang[1].detail.stok = 50;
    barang[1].detail.harga = 2000;
    jumlahBarang++;

    barang[2].nama = "Minyak Goreng";
    barang[2].detail.stok = 20;
    barang[2].detail.harga = 15000;
    jumlahBarang++;

    bool running = true;
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

        if (cin.fail()) {
            cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
            cout << "Klik Enter untuk coba lagi...";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: { // Login
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

                                if (cin.fail()) {
                                    cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                                    cout << "Klik Enter untuk coba lagi...";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                    cin.get();
                                    continue;
                                }

                                switch (crudPilihan) {
                                    case 1: { // Tambah Barang
                                        if (jumlahBarang < MAX_BARANG) {
                                            cin.ignore();
                                            cout << "Masukkan Nama Barang: ";
                                            getline(cin, barang[jumlahBarang].nama);

                                            int stok, harga;
                                            bool valid = false;

                                            while (!valid)  {
                                                cout << "Masukkan Stok Barang: ";
                                                if (cin >> stok) {
                                                    if (stok > 0) {
                                                        valid = true;
                                                        barang[jumlahBarang].detail.stok = stok;
                                                    } else{
                                                        cout << "Stok tidak boleh 0 atau kurang!\n";
                                                        cin.clear();
                                                        cin.ignore(10000, '\n');
                                                    }
                                                }else {
                                                    cout << "Input harus berupa ANGKA!!!\n";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                }
                                            }

                                            valid = false;
                                            while (!valid){
                                                cout << "Masukkan Harga Barang: ";
                                                if (cin >> harga) {
                                                    if (harga > 0) {
                                                        valid = true;
                                                        barang[jumlahBarang].detail.harga = harga;
                                                    } else {
                                                        cout << "Harga tidak boleh 0 atau kurang!\n";
                                                        cin.clear();
                                                        cin.ignore(10000, '\n');
                                                        }
                                                } else {
                                                    cout << "Input harus berupa ANGKA!!!\n";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                }
                                            }
                                            jumlahBarang++;
                                            system("cls");
                                            cout << "\n==============================================" << endl;
                                            cout << "           BARANG BERHASIL DITAMBAHKAN          " << endl;
                                            cout << "==============================================" << endl;
                                            cout << "Barang dengan nama " << barang[jumlahBarang-1].nama << endl;
                                            cout << "Jumlah barang: " << barang[jumlahBarang-1].detail.stok << endl;
                                            cout << "Harga barang: " << barang[jumlahBarang-1].detail.harga << endl;
                                            cout << "==============================================" << endl;
                                            cout << "Klik Enter untuk kembali ke menu utama..." ;
                                            cin.ignore();
                                            cin.get();
                                        } else {
                                            cout << "Kapasitas barang penuh!\n";
                                            cout << "Klik Enter untuk kembali ke menu...";
                                            cin.ignore();
                                            cin.get();
                                         }
                                        break;
                                    }

                                    case 2: { // Lihat Barang
                                        if (jumlahBarang == 0) {
                                            cout << "Tidak ada barang yang tersedia.\n";
                                        } else {
                                            system("cls");
                                            cout << "\n==============================================" << endl;
                                            cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                                            cout << "==============================================" << endl;
                                            cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                                            for (int i = 0; i < jumlahBarang; i++) {
                                                cout << setw(5) << i + 1 << setw(20) << barang[i].nama << setw(10) << barang[i].detail.stok << setw(10) << barang[i].detail.harga << "\n";
                                            }
                                            cout << "==============================================" << endl;
                                        }
                                        cout << "Klik Enter untuk kembali ke menu...";
                                        cin.ignore();
                                        cin.get();
                                        break;
                                    }

                                    case 3: { // Update Barang
                                        if (jumlahBarang > 0) {
                                            int index;
                                            bool valid = false;
                                            while (!valid) {
                                                system("cls");
                                                cout << "\n==============================================" << endl;
                                                cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                                                cout << "==============================================" << endl;
                                                cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                                                for (int i = 0; i < jumlahBarang; i++) {
                                                    cout << setw(5) << i + 1 << setw(20) << barang[i].nama << setw(10) << barang[i].detail.stok << setw(10) << barang[i].detail.harga << "\n";
                                                }
                                                cout << "==============================================" << endl;

                                                cout << "Masukkan nomor barang yang ingin diupdate: ";
                                                if (cin >> index) {
                                                    if (index > 0 && index <= jumlahBarang) {
                                                        valid = true;
                                                    } else {
                                                        cout << "Nomor barang tidak valid. Silakan pilih nomor yang tersedia.\n";
                                                        cout << "Klik Enter untuk coba lagi...";
                                                        cin.ignore();
                                                        cin.get();
                                                    }
                                                } else {
                                                    cout << "Input harus berupa angka. Silakan pilih nomor yang tersedia.\n";
                                                    cout << "Klik Enter untuk coba lagi...";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                    cin.get();
                                                }
                                            }

                                            cout << "Masukkan Nama Barang Baru: ";
                                            cin.ignore();
                                            getline(cin, barang[index - 1].nama);

                                            int stokBaru;
                                            valid = false;
                                            while (!valid) {
                                                cout << "Masukkan Stok Barang Baru: ";
                                                if (cin >> stokBaru) {
                                                    if (stokBaru > 0) {
                                                        valid = true;
                                                        barang[index - 1].detail.stok = stokBaru;
                                                    } else {
                                                        cout << "Stok barang tidak boleh 0 atau kurang!!\n";
                                                        cin.clear();
                                                        cin.ignore(10000, '\n');
                                                    }
                                                } else {
                                                    cout << "Input harus berupa angka!!\n";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                }
                                            }

                                            int hargaBaru;
                                            valid = false;
                                            while (!valid) {
                                                cout << "Masukkan Harga Barang Baru: ";
                                                if (cin >> hargaBaru) {
                                                    if (hargaBaru > 0) {
                                                        valid = true;
                                                        barang[index - 1].detail.harga = hargaBaru;
                                                    } else {
                                                        cout << "Harga barang tidak boleh 0 atau kurang!!\n";
                                                        cin.clear();
                                                        cin.ignore(10000, '\n');
                                                    }
                                                } else {
                                                    cout << "Input harus berupa angka!!\n";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                }
                                            }
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
                                        break;
                                    }

                                    case 4: { // Hapus Barang
                                        if (jumlahBarang > 0) {
                                            int index;
                                            bool valid = false;
                                            while (!valid) {
                                                system("cls");
                                                cout << "\n==============================================" << endl;
                                                cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                                                cout << "==============================================" << endl;
                                                cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                                                for (int i = 0; i < jumlahBarang; i++) {
                                                    cout << setw(5) << i + 1 << setw(20) << barang[i].nama << setw(10) << barang[i].detail.stok << setw(10) << barang[i].detail.harga << "\n";
                                                }
                                                cout << "==============================================" << endl;

                                                cout << "Masukkan nomor barang yang ingin dihapus: ";
                                                if (cin >> index) {
                                                    if (index > 0 && index <= jumlahBarang) {
                                                        valid = true;
                                                    } else {
                                                        cout << "Nomor barang tidak valid. Silakan pilih nomor yang tersedia.\n";
                                                        cout << "Klik Enter untuk coba lagi...";
                                                        cin.ignore();
                                                        cin.get();
                                                    }
                                                } else {
                                                    cout << "Input harus berupa angka. Silakan pilih nomor yang tersedia.\n";
                                                    cout << "Klik Enter untuk coba lagi...";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                    cin.get();
                                                }
                                            }

                                            for (int i = index - 1; i < jumlahBarang - 1; i++) {
                                                barang[i] = barang[i + 1];
                                            }
                                            jumlahBarang--;
                                            system("cls");
                                            cout << "\n==============================================" << endl;
                                            cout << "            BARANG BERHASIL DIHAPUS          " << endl;
                                            cout << "==============================================" << endl;
                                            cout << "Barang dengan nama " << barang[index - 1].nama << "\n";
                                            cout << "Jumlah barang : " << barang[index - 1].detail.stok << "\n";
                                            cout << "Harga barang : " << barang[index - 1].detail.harga << "\n";
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
                                        break;
                                    }

                                    case 5: { // Keluar
                                        menucrud = false;
                                        system("cls");
                                        cout << "\n==============================================" << endl;
                                        cout << "         ANDA TELAH KELUAR DARI PROGRAM          " << endl;
                                        cout << "==============================================" << endl;
                                        break;
                                    }

                                    default: {
                                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                        cout << "Klik Enter untuk coba lagi...";
                                        cin.ignore();
                                        cin.get();
                                        break;
                                    }
                                }
                            }
                        } else if (role == "pembeli") {
                            // Menu untuk pembeli
                            bool pembeliRunning = true;
                            while (pembeliRunning) {
                                system("cls");
                                cout << "\n==============================================" << endl;
                                cout << "          MENU PEMBELI          " << endl;
                                cout << "==============================================" << endl;
                                cout << "1. Lihat Barang" << endl;
                                cout << "2. Beli Barang" << endl;
                                cout << "3. Keluar" << endl;
                                cout << "==============================================" << endl;
                                cout << "Pilih menu: ";
                                int pembeliPilihan;
                                cin >> pembeliPilihan;

                                if (cin.fail()) {
                                    cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                                    cout << "Klik Enter untuk coba lagi...";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                    cin.get();
                                    continue;
                                }

                                switch (pembeliPilihan) {
                                    case 1: {
                                        if (jumlahBarang == 0) {
                                            cout << "Tidak ada barang yang tersedia.\n";
                                        } else {
                                            system("cls");
                                            cout << "\n==============================================" << endl;
                                            cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                                            cout << "==============================================" << endl;
                                            cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                                            for (int i = 0; i < jumlahBarang; i++) {
                                                cout << setw(5) << i + 1 << setw(20) << barang[i].nama << setw(10) << barang[i].detail.stok << setw(10) << barang[i].detail.harga << "\n";
                                            }
                                            cout << "==============================================" << endl;
                                        }
                                        cout << "Klik Enter untuk kembali ke menu...";
                                        cin.ignore();
                                        cin.get();
                                        break;
                                            break;
                                    }
                                    //beli barang
                                    case 2: { 
                                        if (jumlahBarang > 0) {
                                            int index, jumlahBeli;
                                            bool valid = false;
                                            while (!valid) {
                                                system("cls");
                                                cout << "\n==============================================" << endl;
                                                cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                                                cout << "==============================================" << endl;
                                                cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                                                for (int i = 0; i < jumlahBarang; i++) {
                                                    cout << setw(5) << i + 1 << setw(20) << barang[i].nama << setw(10) << barang[i].detail.stok << setw(10) << barang[i].detail.harga << "\n";
                                                }
                                                cout << "==============================================" << endl;

                                                cout << "Masukkan nomor barang yang ingin dibeli: ";
                                                if (cin >> index) {
                                                    if (index > 0 && index <= jumlahBarang) {
                                                        cout << "Masukkan jumlah yang ingin dibeli: ";
                                                        if (cin >> jumlahBeli) {
                                                            if (jumlahBeli > 0 && jumlahBeli <= barang[index - 1].detail.stok) {
                                                                valid = true;
                                                                barang[index - 1].detail.stok -= jumlahBeli;
                                                                int totalHarga = jumlahBeli * barang[index - 1].detail.harga;
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
                                                                if (jumlahBeli > barang[index - 1].detail.stok) {
                                                                    cout << "Maaf, jumlah stok tidak mencukupi.\n";
                                                                    cout << "Klik Enter...";
                                                                    cin.ignore();
                                                                    cin.get();
                                                                } else {
                                                                    cout << "Jumlah yang dibeli tidak boleh 0 atau negatif!!.\n";
                                                                    cout << "Klik Enter...";
                                                                    cin.ignore();
                                                                    cin.get();
                                                                } 
                                                            }
                                                        } else {
                                                            cout << "Input harus berupa angka.\n";
                                                            cout << "Klik Enter...";
                                                            cin.clear();
                                                            cin.ignore(10000, '\n');
                                                            cin.get();
                                                        }                                                         
                                                    } else {
                                                        cout << "Nomor barang tidak valid. Silakan pilih nomor yang tersedia.\n";
                                                        cout << "Klik Enter untuk coba lagi...";
                                                        cin.ignore();
                                                        cin.get();
                                                    }
                                                } else {
                                                    cout << "Input harus berupa angka. Silakan pilih nomor yang tersedia.\n";
                                                    cout << "Klik Enter untuk coba lagi...";
                                                    cin.clear();
                                                    cin.ignore(10000, '\n');
                                                    cin.get();
                                                }
                                            }
                                        } else {
                                            cout << "Tidak ada barang yang tersedia.\n";         
                                            cout << "Klik Enter untuk kembali ke menu...";
                                            cin.ignore();
                                            cin.get();
                                        }
                                        break;
                                    }

                                    case 3: { // Keluar
                                        pembeliRunning = false;
                                        break;
                                    }

                                    default: {
                                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                        cout << "Klik Enter untuk coba lagi...";
                                        cin.ignore();
                                        cin.get();
                                        break;
                                    }
                                }
                            }
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
                    cout << "Anda telah mencoba login " << max_kesempatan << " kali." << endl;
                    cout << "Program berhenti karena batas" << endl; 
                    cout << "percobaan telah tercapai." << endl;
                    cout << "======================================" << endl;
                    return 0;
                }
                break;
            }

            case 2: {
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
                break;
            }

            case 3: { // Keluar
                running = false;
                system("cls");
                cout << "\n==============================================" << endl;
                cout << "         ANDA TELAH KELUAR DARI PROGRAM          " << endl;
                cout << "==============================================" << endl;
                break;
            }

            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cout << "Klik Enter untuk coba lagi...";
                cin.ignore();
                cin.get();
                break;
            }
        }
    }

    return 0;
}