#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
    
    // Proses Login
    const int MAX_BARANG = 20;
    int jumlahBarang = 0;
    const string username = "Muhammad Ridwanansyah Rahman";
    const string password = "2409106073";
    const int max_kesempatan = 3;
    int kesempatan = 0;
    string barang[MAX_BARANG][3];
    bool running = true;

    // Beberapa data default
    barang[jumlahBarang][0] = "Beras";
    barang[jumlahBarang][1] = "50";
    barang[jumlahBarang][2] = "12000";
    jumlahBarang++;

    barang[jumlahBarang][0] = "Minyak Goreng";
    barang[jumlahBarang][1] = "30";
    barang[jumlahBarang][2] = "25000";
    jumlahBarang++;

    barang[jumlahBarang][0] = "Gula";
    barang[jumlahBarang][1] = "40";
    barang[jumlahBarang][2] = "15000";
    jumlahBarang++;


    while (kesempatan < max_kesempatan) {
        string input_username, input_password;
        system("cls");
        cout << "\n======================================" << endl;
        cout << "             Login Program          " << endl;
        cout << "======================================" << endl;
        cout << "Username: ";
        getline(cin, input_username);
        cout << "Password: ";
        getline(cin, input_password);

        if (input_username == username && input_password == password) {
            system("cls");
            cout << "\n======================================" << endl;
            cout << "             Login Berhasil          " << endl;
            cout << "======================================" << endl;
            cout << "Selamat datang, " << username << "!" << endl;
            cout << "Anda telah berhasil login." << endl;
            cout << "======================================" << endl;
            cout << "Klik Enter untuk melanjutkan...";
            cin.ignore();
            break;
            
        } else {
            kesempatan++;
            cout << "Login gagal. Sisa percobaan: " << max_kesempatan - kesempatan << "\n" << endl;
            cout << "Klik Enter...";
            cin.ignore();
        }
    }

    if (kesempatan == max_kesempatan) {
        system("cls");
        cout << "\n======================================" << endl;
        cout << "             Login Gagal          " << endl;
        cout << "======================================" << endl;
        cout << "Anda telah mencoba login " << max_kesempatan << " kali." << endl;
        cout << "Program berhenti karena batas" << endl;
        cout << "percobaan telah tercapai " << endl;
        cout << "======================================" << endl;
        return 0;
    }

    // CURD
    while (running) {
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
        int pilihan;
        cin >> pilihan;

        if (cin.fail()) {
            cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
            cout << "Klik Enter untuk coba lagi...";
            cin.clear();
            cin.ignore(10000, '\n');
            cin.get();
            continue;
        }

        switch (pilihan) {
            case 1: // Nambah Barang
            if (jumlahBarang < MAX_BARANG) {
                cout << "Masukkan Nama Barang: ";
                cin >> barang[jumlahBarang][0];
        
                int jumlah, harga;
                bool valid = false;
        
                while (!valid) {
                    cout << "Masukkan Stok Barang: ";
                    if (cin >> jumlah) {
                        if (jumlah > 0) {
                            valid = true;
                            barang[jumlahBarang][1] = to_string(jumlah);
                        } else {
                            cout << "Stok barang tidak boleh negatif!!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } else {
                        cout << "Input harus berupa angka!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
        
                valid = false;
        
                while (!valid) {
                    cout << "Masukkan Harga Barang: ";
                    if (cin >> harga) {
                        if (harga > 0) {
                            valid = true;
                            barang[jumlahBarang][2] = to_string(harga);
                        } else {
                            cout << "Harga barang tidak boleh negatif!!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } else {
                        cout << "Input harus berupa angka!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
        
                jumlahBarang++;
                system("cls");
                cout << "\n==============================================" << endl;
                cout << "           BARANG BERHASIL DITAMBAHKAN          " << endl;
                cout << "==============================================" << endl;
                cout << "Barang dengan nama " << barang[jumlahBarang-1][0] << endl;
                cout << "Jumlah barang: " << barang[jumlahBarang-1][1] << endl;
                cout << "Harga barang: " << barang[jumlahBarang-1][2] << endl;
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
            
            case 2: // Liat Barang
            if (jumlahBarang == 0) {
                cout << "Tidak ada barang yang tersedia.\n";
                cout << "Klik Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();
            } else {
                    system("cls");
                    cout << "\n==============================================" << endl;
                    cout << "             DAFTAR BARANG SEMBAKO          " << endl;
                    cout << "==============================================" << endl;
                    cout << setw(5) << "No" << setw(20) << "Nama Barang" << setw(10) << "Stok" << setw(10) << "Harga" << "\n";
                    for (int i = 0; i < jumlahBarang; i++) {
                        cout << setw(5) << i + 1 << setw(20) << barang[i][0] << setw(10) << barang[i][1] << setw(10) << barang[i][2] << "\n";
                    }
                    cout << "==============================================" << endl;
                    cout << "Klik Enter untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                }
                break;
                
                
            case 3: // Update Barang
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
                        cout << setw(5) << i + 1 << setw(20) << barang[i][0] << setw(10) << barang[i][1] << setw(10) << barang[i][2] << "\n";
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
                cin >> barang[index - 1][0];
                
                int jumlahBaru;
                valid = false;
                while (!valid) {
                    cout << "Masukkan Jumlah Barang Baru: ";
                    if (cin >> jumlahBaru) {
                        if (jumlahBaru > 0) {
                            valid = true;
                            barang[index - 1][1] = to_string(jumlahBaru);
                        } else {
                            cout << "Jumlah barang tidak boleh negatif!!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } else {
                        cout << "Input harus berupa angka!\n";
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
                            barang[index - 1][2] = to_string(hargaBaru);
                        } else {
                            cout << "Harga barang tidak boleh negatif!!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } else {
                        cout << "Input harus berupa angka!\n";
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

            case 4: // Apus Barang
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
                        cout << setw(5) << i + 1 << setw(20) << barang[i][0] << setw(10) << barang[i][1] << setw(10) << barang[i][2] << "\n";
                    }
                    cout << "==============================================" << endl;
            
                        cout << "Masukkan nomor barang yang ingin dihapus: ";
                        if (cin >> index) {
                            if (index > 0 && index <= jumlahBarang) {
                                valid = true;
                            } else {
                                cout << "Nomor barang tidak valid. Silakan pilih nomor yang tersedia.\n";
                                cout << "Klik Enter untuk coba lagi...";
                                cin.clear();
                                cin.ignore(10000, '\n');
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
                        barang[i][0] = barang[i + 1][0];
                        barang[i][1] = barang[i + 1][1];
                        barang[i][2] = barang[i + 1][2];
                    }
                    jumlahBarang--;
                    system("cls");
                    cout << "\n==============================================" << endl;
                    cout << "            BARANG BERHASIL DIHAPUS          " << endl;
                    cout << "==============================================" << endl;
                    cout << "Barang dengan nama " << barang[index - 1][0] << "\n";
                    cout << "Jumlah barang : " << barang[index - 1][1] << "\n";
                    cout << "Harga barang : " << barang[index - 1][2] << "\n";
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

            case 5: // Keluar
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
                cin.get();
        }
    }

    return 0;
}