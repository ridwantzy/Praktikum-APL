#include <iostream>
#include <string>
// #include <cstdlib>
using namespace std;

int main() {
    // Fungsi login
    const string username = "Muhammad Ridwanansyah Rahman";
    const string password = "2409106073";
    const int max_kesempatan = 3;
    int kesempatan = 0;
    
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
            cin.get();
            break;
            
        } else {
            kesempatan++;
            cout << "Login gagal. Sisa percobaan: " << max_kesempatan - kesempatan << "\n" << endl;
            cout << "Klik Enter...";
            cin.ignore();
            cin.get();
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

    // Menu utama
    while (true) {
        system("cls");
        cout << "\n======================================" << endl;
        cout << "             Menu Utama             " << endl;
        cout << "======================================" << endl;
        cout << "1. Konversi Mata Uang" << endl;
        cout << "2. Konversi Jarak" << endl;
        cout << "3. Konversi Waktu" << endl;
        cout << "4. Konversi Suhu" << endl;
        cout << "5. Logout" << endl;
        cout << "======================================" << endl;
        cout << "Pilih opsi: ";
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
            case 1:
                // Konversi mata uang
                while (true) {
                    system("cls");
                    cout << "\n======================================" << endl;
                    cout << "         Konversi Mata Uang         " << endl;
                    cout << "======================================" << endl;
                    cout << "1. Rupiah ke Dolar AS" << endl;
                    cout << "2. Rupiah ke Euro" << endl;
                    cout << "3. Dolar AS ke Rupiah" << endl;
                    cout << "4. Dolar AS ke Euro" << endl;
                    cout << "5. Euro ke Rupiah" << endl;
                    cout << "6. Euro ke Dolar AS" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "======================================" << endl;
                    cout << "Pilih opsi: ";
                    int pilihan_mata_uang;
                    cin >> pilihan_mata_uang;

                    if (cin.fail()) {
                        cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin.get();
                        continue;
                    }

                    if (pilihan_mata_uang == 7) break;

                    if (pilihan_mata_uang < 1 || pilihan_mata_uang > 6) {
                        cout << "Opsi tidak tersedia!!" << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.ignore();
                        cin.get();
                        continue;
                    }
                    
                    double jumlah;
                    cout << "Masukkan jumlah mata uang : ";
                    cin >> jumlah;
                    
                    switch (pilihan_mata_uang) {
                        case 1:
                            cout << jumlah << " Rupiah = " << jumlah / 16000 << " Dolar AS" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            cout << jumlah << " Rupiah = " << jumlah / 17000 << " Euro" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            cout << jumlah << " Dolar AS = " << jumlah * 16000 << " Rupiah" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            cout << jumlah << " Dolar AS = " << jumlah * 0.92 << " Euro" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            cout << jumlah << " Euro = " << jumlah * 17000 << " Rupiah" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            cout << jumlah << " Euro = " << jumlah * 1.08 << " Dolar AS" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        default:
                            cout << "Input tidak valid! Silakan input ulang." << endl;
                        
                    }
                }
                break;
            case 2:
                // Konversi jarak
                while (true) {
                    system("cls");
                    cout << "\n======================================" << endl;
                    cout << "           Konversi Jarak           " << endl;
                    cout << "======================================" << endl;
                    cout << "1. Kilometer ke Meter" << endl;
                    cout << "2. Kilometer ke Centimeter" << endl;
                    cout << "3. Meter ke Kilometer" << endl;
                    cout << "4. Meter ke Centimeter" << endl;
                    cout << "5. Centimeter ke Kilometer" << endl;
                    cout << "6. Centimeter ke Meter" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "======================================" << endl;
                    cout << "Pilih opsi: ";
                    int pilihan_jarak;
                    cin >> pilihan_jarak;

                    if (cin.fail()) {
                        cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin.get();
                        continue;
                    }
                    if (pilihan_jarak == 7) break;

                    if (pilihan_jarak < 1 || pilihan_jarak > 6) {
                        cout << "Opsi tidak valid!" << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.ignore();
                        cin.get();
                        continue;
                    }

                    double jumlah;
                    cout << "Masukkan jumlah jarak: ";
                    cin >> jumlah;

                    switch (pilihan_jarak) {
                        case 1:
                            cout << jumlah << " Kilometer = " << jumlah * 1000 << " Meter" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            cout << jumlah << " Kilometer = " << jumlah * 100000 << " Centimeter" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            cout << jumlah << " Meter = " << jumlah / 1000 << " Kilometer" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            cout << jumlah << " Meter = " << jumlah * 100 << " Centimeter" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            cout << jumlah << " Centimeter = " << jumlah / 100000 << " Kilometer" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            cout << jumlah << " Centimeter = " << jumlah / 100 << " Meter" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        default:
                            cout << "Opsi tidak valid!" << endl;
                    }
                }
                break;
            case 3:
                // Konversi waktu
                while (true) {
                    system("cls");
                    cout << "\n======================================" << endl;
                    cout << "          Konversi Waktu           " << endl;
                    cout << "======================================" << endl;
                    cout << "1. Jam ke Menit" << endl;
                    cout << "2. Jam ke Detik" << endl;
                    cout << "3. Menit ke Jam" << endl;
                    cout << "4. Menit ke Detik" << endl;
                    cout << "5. Detik ke Jam" << endl;
                    cout << "6. Detik ke Menit" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "======================================" << endl;
                    cout << "Pilih opsi: ";
                    int pilihan_waktu;
                    cin >> pilihan_waktu;

                    if (cin.fail()) {
                        cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin.get();
                        continue;
                    }
                    if (pilihan_waktu == 7) break;

                    if (pilihan_waktu < 1 || pilihan_waktu > 6) {
                        cout << "Opsi tidak valid!" << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.ignore();
                        cin.get();
                        continue;
                    }

                    double jumlah;
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;

                    switch (pilihan_waktu) {
                        case 1:
                            cout << jumlah << " Jam = " << jumlah * 60 << " Menit" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            cout << jumlah << " Jam = " << jumlah * 3600 << " Detik" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            cout << jumlah << " Menit = " << jumlah / 60 << " Jam" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            cout << jumlah << " Menit = " << jumlah * 60 << " Detik" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            cout << jumlah << " Detik = " << jumlah / 3600 << " Jam" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            cout << jumlah << " Detik = " << jumlah / 60 << " Menit" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        default:
                            cout << "Opsi tidak valid!" << endl;
                    }
                }
                break;
            case 4:
                // Konversi suhu
                while (true) {
                    system("cls");
                    cout << "\n======================================" << endl;
                    cout << "          Konversi Suhu           " << endl;
                    cout << "======================================" << endl;
                    cout << "1. Celsius ke Fahrenheit" << endl;
                    cout << "2. Celsius ke Kelvin" << endl;
                    cout << "3. Fahrenheit ke Celsius" << endl;
                    cout << "4. Fahrenheit ke Kelvin" << endl;
                    cout << "5. Kelvin ke Celsius" << endl;
                    cout << "6. Kelvin ke Fahrenheit" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "======================================" << endl;
                    cout << "Pilih opsi: ";
                    int pilihan_suhu;
                    cin >> pilihan_suhu;
    
                    if (cin.fail()) {
                        cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin.get();
                        continue;
                    }
                    if (pilihan_suhu == 7) break;
    
                    if (pilihan_suhu < 1 || pilihan_suhu > 6) {
                        cout << "Opsi tidak valid!" << endl;
                        cout << "Klik Enter untuk coba lagi...";
                        cin.ignore();
                        cin.get();
                        continue;
                    }
    
                    double jumlah;
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
    
                    switch (pilihan_suhu) {
                        case 1:
                            cout << jumlah << " Celsius = " << (jumlah * 9 / 5) + 32 << " Fahrenheit" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            cout << jumlah << " Celsius = " << jumlah + 273.15 << " Kelvin" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            cout << jumlah << " Fahrenheit = " << (jumlah - 32) * 5 / 9 << " Celsius" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            cout << jumlah << " Fahrenheit = " << (jumlah - 32) * 5 / 9 + 273.15 << " Kelvin" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            cout << jumlah << " Kelvin = " << jumlah - 273.15 << " Celsius" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            cout << jumlah << " Kelvin = " << (jumlah - 273.15) * 9 / 5 + 32 << " Fahrenheit" << endl;
                            cout << "Klik Enter untuk coba lagi...";
                            cin.ignore();
                            cin.get();
                            break;
                        default:
                            cout << "Opsi tidak valid!" << endl;
                    }
                }
                break;
            case 5:
                system("cls");
                cout << "\n======================================" << endl;
                cout << "             Logout Berhasil          " << endl;
                cout << "======================================" << endl;
                cout << "Program telah berhenti. Terima kasih!" << endl;
                cout << "======================================" << endl;
                return 0;
            default:
                cout << "Opsi tidak valid!" << endl;
                cout << "Klik Enter untuk coba lagi...";
                cin.ignore();
                cin.get();
        }
    }
}