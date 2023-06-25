//Nama : Avi Oktaviani
//NPM : 21081010227
//Kelas : C081


#include <iostream>
#include <string>

using namespace std;

class Node {		
public:
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};
//linkedlist
class LinkedList {		
protected:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void tambahNode(string data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void tampilkanList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    Node* getHead() {
        return head;
    }
};

class User {
private:
    string username;
    string password;

public:
    User(string username, string password) : username(username), password(password) {}

    bool authenticate(string inputUsername, string inputPassword) {
        return (username == inputUsername && password == inputPassword);
    }
};

class ProfilMahasiswa {
private:
    string nama;
    string nim;
    string fakultas;
    string jurusan;
    int semester;

public:
    ProfilMahasiswa(string nama, string nim, string fakultas, string jurusan, int semester)
        : nama(nama), nim(nim), fakultas(fakultas), jurusan(jurusan), semester(semester) {}

    void tampilkanProfil() {
        cout << "=== Profil Mahasiswa ===" << endl;
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "Fakultas :" << fakultas <<endl;
        cout << "Jurusan: " << jurusan << endl;
        cout << "Semester: " << semester << endl;
        cout << "========================" << endl;
    }
};

//inhertence
class DaftarMataKuliah : public LinkedList {
public:
    void tambahMataKuliah(string namaMataKuliah) {	
        tambahNode(namaMataKuliah);
    }

    void tampilkanDaftarMataKuliah() {				
        cout << "=== Daftar Mata Kuliah ===" << endl;
        tampilkanList();
        cout << "=========================" << endl;
    }

    bool isMataKuliahAda(string namaMataKuliah) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == namaMataKuliah) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

//inhertence
class MataKuliahDipilih : public LinkedList {
public:
    void tambahMataKuliah(string namaMataKuliah) {
        tambahNode(namaMataKuliah);
    }

    void tampilkanMataKuliahDipilih() {
        cout << "=== Mata Kuliah Dipilih ===" << endl;
        tampilkanList();
        cout << "===========================" << endl;
    }

    void hapusMataKuliahDipilih(string namaMataKuliah) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == namaMataKuliah) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Mata kuliah berhasil dihapus!" << endl;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Mata kuliah tidak ditemukan." << endl;
    }

    int totalSKS() {
        int sks = 0;
        Node* current = head;
        while (current != nullptr) {
        	// overloading
            sks += 3; 										
            current = current->next;
        }
        return sks;
    }
};

class TambahMataKuliah {
private:
    MataKuliahDipilih& mataKuliahDipilih;
    DaftarMataKuliah& daftarMataKuliah;

public:
    TambahMataKuliah(MataKuliahDipilih& mkDipilih, DaftarMataKuliah& daftarMk)
        : mataKuliahDipilih(mkDipilih), daftarMataKuliah(daftarMk) {}

    void tambahMataKuliahDipilih(string namaMataKuliah) {
        if (daftarMataKuliah.isMataKuliahAda(namaMataKuliah)) {
            mataKuliahDipilih.tambahMataKuliah(namaMataKuliah);
            cout << "Mata kuliah berhasil ditambahkan!" << endl;
        } else {
            cout << "Mata kuliah tidak tersedia." << endl;
        }
    }
};

void tampilkanMenu() {
    cout << "=== Menu SIAKAD ===" << endl;
    cout << "1. Lihat Profil" << endl;
    cout << "2. Daftar Mata Kuliah" << endl;
    cout << "3. Tambah Mata Kuliah" << endl;
    cout << "4. Hapus Mata Kuliah" << endl;
    cout << "5. Lihat Mata Kuliah Dipilih" << endl;
    cout << "6. Hitung Total SKS" << endl;
    cout << "7. Keluar" << endl;
    cout << "===================" << endl;
}

int main() {
    User user("admin", "password");

    string inputUsername, inputPassword;

    cout << "Masukkan username: ";
    cin >> inputUsername;

    cout << "Masukkan password: ";
    cin >> inputPassword;

    if (user.authenticate(inputUsername, inputPassword)) {
        cout << "Login berhasil!" << endl;

        bool selesai = false;
        int pilihan;

        ProfilMahasiswa profil("Avi Oktaviani", "21081010227", "Ilmu Komputer", "Informatika", 4);

        DaftarMataKuliah daftarMataKuliah;
        daftarMataKuliah.tambahMataKuliah("Pemrograman Berbasis Orientasi A");
        daftarMataKuliah.tambahMataKuliah("Pemrograman Berbasis Orientasi B");
        daftarMataKuliah.tambahMataKuliah("Pemrograman Berbasis Orientasi C");
		daftarMataKuliah.tambahMataKuliah("Pemrograman Website A");
		daftarMataKuliah.tambahMataKuliah("Pemrograman Website B");
		daftarMataKuliah.tambahMataKuliah("Pemrograman Website C");
        daftarMataKuliah.tambahMataKuliah("Kecerdasan Buatan A");
        daftarMataKuliah.tambahMataKuliah("Kecerdasan Buatan B");
       	daftarMataKuliah.tambahMataKuliah("Kecerdasan Buatan C");
        daftarMataKuliah.tambahMataKuliah("Jaringan Komputer A");
        daftarMataKuliah.tambahMataKuliah("Jaringan Komputer B");
        daftarMataKuliah.tambahMataKuliah("Jaringan Komputer C");
		daftarMataKuliah.tambahMataKuliah("Rekayasa Perangkat Lunak A");
		daftarMataKuliah.tambahMataKuliah("Rekayasa Perangkat Lunak B");
		daftarMataKuliah.tambahMataKuliah("Rekayasa Perangkat Lunak C");
        daftarMataKuliah.tambahMataKuliah("Desain Antarmuka A");
		daftarMataKuliah.tambahMataKuliah("Desain Antarmuka B");
		daftarMataKuliah.tambahMataKuliah("Desain Antarmuka C");
		
        MataKuliahDipilih mataKuliahDipilih;
        TambahMataKuliah tambahMk(mataKuliahDipilih, daftarMataKuliah);

        while (!selesai) {
            tampilkanMenu();

            cout << "Masukkan pilihan: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    profil.tampilkanProfil();
                    break;
                case 2:
                    daftarMataKuliah.tampilkanDaftarMataKuliah();
                    break;
                case 3: {
                    string namaMataKuliah;
                    cout << "Masukkan nama mata kuliah: ";
                    cin.ignore();
                    getline(cin, namaMataKuliah);
                    tambahMk.tambahMataKuliahDipilih(namaMataKuliah);
                    break;
                }
                case 4: {
                    string namaMataKuliah;
                    cout << "Masukkan nama mata kuliah yang akan dihapus: ";
                    cin.ignore();
                    getline(cin, namaMataKuliah);
                    mataKuliahDipilih.hapusMataKuliahDipilih(namaMataKuliah);
                    break;
                }
                case 5:
                    mataKuliahDipilih.tampilkanMataKuliahDipilih();
                    break;
                case 6:
                    cout << "Total SKS: " << mataKuliahDipilih.totalSKS() << endl;
                    break;
                case 7:
                    selesai = true;
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
            }

            cout << endl;
        }
    } else {
        cout << "Login gagal. Username atau password salah." << endl;
    }

    return 0;
}
