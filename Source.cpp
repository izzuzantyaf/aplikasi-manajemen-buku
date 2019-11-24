#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Admin.h"
#include "Buku.h"
#include "Utility.h"

using namespace std;

int main() {

	int pilihan;
	string
		username,
		password;
	Admin admin;
	Utility utility;

	system("cls");

	cout << "APLIKASI MANAJEMEN BUKU\n\n";
	cout << "Menu\n1. Login\n2. Exit\n\n";
	cout << "Masukkan pilihan anda : ";
	cin >> pilihan;

	switch (pilihan)
	{
	case 1:

		admin_login_page:
		system("cls");

		cout << "ADMIN LOGIN PAGE\n\n";
		cout << "Username : ";
		cin >> username;
		cout << "Password : ";
		cin >> password;

		if (admin.login(username, password, "admin.txt"))
		{
			main_page:
			system("cls");
			cout << "DAFTAR BUKU\n\n";

			utility.tampil(utility.ambil("buku.txt"));

			cout << "\nMENU KELOLA BUKU\n";
			cout << "\n1. Tambah\n2. Update\n3. Hapus\n4. Filter\n5. Sorting\n\nMasukkan pilihan : ";
			cin >> pilihan;

			switch (pilihan) {
			case 1:
				system("cls");
				cout << "TAMBAH BUKU BARU\n\n";

				// fungsi tambah
				if (admin.tambah_buku(utility.input_data_buku(), "buku.txt"))
				{
					cout << "\nBuku berhasil ditambahkan\n";
				}
				else {
					cout << "\nBuku gagal ditambahkan\n";
				}
				cout << "\n";

				system("pause");
				goto main_page;

				break;
			case 2:
				system("cls");
				cout << "Update Buku\n\n";
				// fungsi update

				break;
			case 3:
				system("cls");
				int id_hapus;

				cout << "DAFTAR BUKU\n\n";
				utility.tampil(utility.ambil("buku.txt"));

				cout << "\nHAPUS BUKU\n\n";
				cout << "Masukkan ID buku yang ingin dihapus : ";
				cin >> id_hapus;

				//fungsi hapus
				if (admin.hapus_buku(id_hapus))
				{
					cout << "\nBuku berhasil dihapus\n";
				}
				else {
					cout << "\nBuku gagal dihapus\n";
				}
				cout << "\n";
				system("pause");
				goto main_page;

				break;
			case 4:
				system("cls");
				cout << "Filter Buku\n\n";
				// fungsi filter

				break;
			case 5:
			sorting_buku:
				system("cls");
				cout << "DAFTAR BUKU\n\n";
				utility.tampil(utility.ambil("buku.txt"));

			menu_sorting:
				cout << "\nMENU KELOLA BUKU\n";
				cout << "\nSorting berdasarkan\n1. ID\n2. Judul\n3. Kategori\n4. Tahun\n5. Kembali";
				cout << "\n\nMasukkan pilihan : ";
				cin >> pilihan;

				switch (pilihan)
				{
				case 1:
					system("cls");
					utility.tampil(utility.sort(utility.ambil("buku.txt"), "ID"));
					goto menu_sorting;

					break;
				case 2:
					system("cls");
					utility.tampil(utility.sort(utility.ambil("buku.txt"), "judul"));
					goto menu_sorting;

					break;
				case 3:
					system("cls");
					utility.tampil(utility.sort(utility.ambil("buku.txt"), "kategori"));
					goto menu_sorting;

					break;
				case 4:
					system("cls");
					utility.tampil(utility.sort(utility.ambil("buku.txt"), "tahun"));
					goto menu_sorting;

					break;
				case 5:
					system("cls");
					goto main_page;

					break;
				default:
					goto sorting_buku;

					break;
				}

				break;
			default:
				goto main_page;
				break;
			}
		}
		else {
			goto admin_login_page;
		}

		break;

	case 2:
		system("cls");
		cout << "Terima kasih :)";
		break;

	default:
		system("cls");
		main();
		break;
	}

	cout << endl;

	return 0;
}