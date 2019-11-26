// memasukkan daftar library yang diperlukan
#include <iostream> // library input dan output
#include <string>	// library string
#include <fstream>	// library file
#include <vector>	// library vector
#include <iomanip>	// library untuk manipulasi input dan output

// memasukkan class Admin, Buku, dan Utility
#include "Admin.h"
#include "Buku.h"
#include "Utility.h"

using namespace std;

int main() {

	// deklarasi variabel
	int pilihan;
	string
		username,
		password,
		id_edit,
		id_hapus;

	// instansiasi objek admin dan utility
	Admin admin;
	Utility utility;

	start:
	system("cls");

	// menampilkan menu
	cout << "APLIKASI MANAJEMEN BUKU\n\n";
	cout << "Menu\n1. Login\n2. Exit\n\n";
	cout << "Masukkan pilihan anda : ";
	cin >> pilihan; // input pilihan

	switch (pilihan)
	{
		// jika pilihan user adalah 1
	case 1:

	admin_login_page:
		system("cls");

		cout << "ADMIN LOGIN PAGE\n\n";
		cout << "Username : ";
		cin >> username; // input username
		cout << "Password : ";
		cin >> password; // input password

		// jika login berhasil
		if (admin.login(username, password, "admin.txt"))
		{
		main_page:
			system("cls");
			cout << "DAFTAR BUKU\n\n";

			// menampilkan daftar buku
			utility.tampil(utility.ambil("buku.txt"));

			// menampilkan menu kelola buku
			cout << "\nMENU KELOLA BUKU\n";
			cout << "\n1. Tambah\n2. Update\n3. Hapus\n4. Filter\n5. Sorting\n6. Log out\n\nMasukkan pilihan : ";
			cin >> pilihan; // input pilihan kelola buku

			switch (pilihan) {
				// jika pilihan user adalah tambah buku
			case 1:
				system("cls");
				cout << "TAMBAH BUKU BARU\n";

				// fungsi untuk menambahkan buku
				admin.tambah_buku(utility.buat_buku(), "buku.txt");

				cout << "\n";
				system("pause");
				goto main_page; // kembali ke halaman setelah login

				break;

				// jika pilihan user adalah hapus buku
			case 2:
				system("cls");

				cout << "DAFTAR BUKU\n\n";
				// fungsi untuk menampilkan daftar buku
				utility.tampil(utility.ambil("buku.txt"));

				cout << "\nEDIT BUKU\n\n";
				cout << "Masukkan ID buku yang ingin diedit : ";
				cin >> id_edit; // input id buku yang akan diedit

				system("cls");

				cout << "EDIT BUKU\n";
				// fungsi untuk mengedit buku
				admin.edit_buku(id_edit);

				cout << "\n";
				system("pause");
				goto main_page; // kembali ke halaman setelah login

				break;

				// jika pilihan user adalah hapus buku
			case 3:
				system("cls");

				cout << "DAFTAR BUKU\n\n";
				// fungsi untuk menampilkan daftar buku
				utility.tampil(utility.ambil("buku.txt"));

				cout << "\nHAPUS BUKU\n\n";
				cout << "Masukkan ID buku yang ingin dihapus : ";
				cin >> id_hapus; // input ID buku yang akan dihapus

				// fungsi untuk menghapus buku
				admin.hapus_buku(id_hapus);

				cout << "\n";
				system("pause");
				goto main_page; // kembali ke halaman setelah login

				break;

				// jika pilihan user adalah filter buku
			case 4:
			filter_buku:
				system("cls");

				cout << "DAFTAR BUKU\n\n";
				// fungsi untuk menampilkan daftar buku
				utility.tampil(utility.ambil("buku.txt"));

				// menampilkan menu filter
			menu_filter:
				cout << "\nFILTER BUKU\n\n";
				cout << "Filter berdasarkan kategori\n";
				cout << "1. Kuliah\n2. Novel\n3. Kesehatan\n4. Sejarah\n5. Lainnya\n6. Kembali\n";
				cout << "\nPilihan filter : ";
				cin >> pilihan; // input pilihan filter

				switch (pilihan)
				{
					// jika user memilih kategori kuliah
				case 1:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk menampilkan buku yang berkategori Kuliah
					admin.filter_buku("Kuliah");

					goto menu_filter; // kembali ke halaman menu filter

					break;

					// jika user memilih kategori Novel
				case 2:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk menampilkan buku yang berkategori Novel
					admin.filter_buku("Novel");

					goto menu_filter; // kembali ke halaman menu filter

					break;

					// jika user memilih kategori Novel
				case 3:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk menampilkan buku yang berkategori Kesehatan
					admin.filter_buku("Kesehatan");

					goto menu_filter; // kembali ke halaman menu filter

					break;

					// jika user memilih kategori Sejarah
				case 4:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk menampilkan buku yang berkategori Sejarah
					admin.filter_buku("Sejarah");

					goto menu_filter; // kembali ke halaman menu filter

					break;

					// jika user memilih kategori Lainnya
				case 5:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk menampilkan buku yang berkategori Lainnya
					admin.filter_buku("Lainnya");

					goto menu_filter; // kembali ke halaman menu filter

					break;

					// jika user memilih kembali
				case 6:
					goto main_page; // kembali ke halaman setelah login

					break;

					// jika user selain pilihan yang disediakan
				default:
					system("cls");
					goto filter_buku; // kembali ke halaman menu filter

					break;
				}
				break;

				// jika user memilih menu Sorting
			case 5:
			sorting_buku:
				system("cls");
				cout << "DAFTAR BUKU\n\n";

				// fungsi untuk menampilkan daftar buku
				utility.tampil(utility.ambil("buku.txt"));

				// menampilkan menu kelola buku
			menu_sorting:
				cout << "\nMENU KELOLA BUKU\n";
				cout << "\nSorting berdasarkan\n1. ID\n2. Judul\n3. Kategori\n4. Tahun\n5. Kembali";
				cout << "\n\nMasukkan pilihan : ";
				cin >> pilihan; // input pilihan sorting

				switch (pilihan)
				{
					// jika user memilih sorting berdasarkan ID
				case 1:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk mengurutkan dan menampilkan daftar buku berdasarkan ID
					admin.sorting_buku("id");

					goto menu_sorting; // menampilkan menu sorting

					break;

					// jika user memilih sorting berdasarkan Judul
				case 2:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk mengurutkan dan menampilkan daftar buku berdasarkan Judul
					admin.sorting_buku("judul");

					goto menu_sorting; // menampilkan menu sorting

					break;

					// jika user memilih sorting berdasarkan Kategori
				case 3:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk mengurutkan dan menampilkan daftar buku berdasarkan Kategori
					admin.sorting_buku("kategori");

					goto menu_sorting; // menampilkan menu sorting

					break;

					// jika user memilih sorting berdasarkan Tahun
				case 4:
					system("cls");
					cout << "DAFTAR BUKU\n\n";

					// fungsi untuk mengurutkan dan menampilkan daftar buku berdasarkan Tahun
					admin.sorting_buku("tahun");

					goto menu_sorting; // menampilkan menu sorting

					break;

					// jika user memilih untuk kembali
				case 5:
					system("cls");
					goto main_page; // kembali ke halaman setelah login

					break;

					// jika user memilih pilihan yang tidak tersedia
				default:
					goto sorting_buku; // kembali ke menu sorting

					break;
				}

				break;

				// jika user memilih Log out
			case 6:
				system("cls");
				goto start; // kembali ke halaman utama

				break;

				// jika user memilih pilihan yang tidak tersedia
			default:
				goto main_page; // kembali ke halaman setelah login
				break;
			}
		}

		// jika login gagal
		else {
			goto admin_login_page; // kembali ke halaman login
		}

		break;

		// jika user memilih Exit
	case 2:
		system("cls");
		cout << "Terima kasih :)";
		break;

		// jika user memilih diluar pilihan yang tersedia
	default:
		system("cls");
		goto start; // kembali ke halaman utama
		break;
	}

	cout << endl;

	return 0;
}