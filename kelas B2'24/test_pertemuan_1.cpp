#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai > 10) {
        cout << "Nilai lebih besar dari 10" << endl;
    } else if (nilai == 10) {
        cout << "Nilai sama dengan 10" << endl;
    } else {
        cout << "Nilai kurang dari 10" << endl;
    }


    int i = 1;
    while (i <= 5) {
        cout << "Perulangan ke-" << i << endl;
        i++;
    }

    int main() {
        for (int i = 1; i <= 5; i++) {
            cout << "Perulangan ke-" << i << endl;
        }
    return 0;}
}