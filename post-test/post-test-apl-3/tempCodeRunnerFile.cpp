        if (cin.fail()) {
            cout << "Input tidak valid! Silakan Masukkan ANGKA!!!." << endl;
            cout << "Klik Enter untuk coba lagi...";
            cin.clear();
            cin.ignore(10000, '\n');
            cin.get();
            continue;
        }