#include "Admin.h"

void Admin::edit_buku(string id_edit)
{
	// deklarasi variabel
	fstream file;
	Buku buku_baru, buku_target;
	bool buku_ada = false;
	char validation_param;
	vector<Buku> array_buku;

	// mengambil seluruh daftar buku
	array_buku = ambil("buku.txt");

	// cek apakah buku yang akan diedit ada ?
	for (int i = 0; i < array_buku.size(); i++)
	{
		if (array_buku[i].id == id_edit)
		{
			buku_ada = true;
			buku_target = array_buku[i];
		}
	}

	// jika ada
	if (buku_ada)
	{
		// buat buku dengan identitas yang baru
		buku_baru = buat_buku();
		buku_baru.id = buku_target.id;

		// menampilkan pesan untuk meyakinkan user
		cout << "\nApakah anda yakin mengganti buku\n";
		cout << "\nJudul    : " << buku_target.judul;
		cout << "\nKategori : " << buku_target.kategori;
		cout << "\nTahun    : " << buku_target.tahun;
		cout << "\n\ndengan\n";
		cout << "\nJudul    : " << buku_baru.judul;
		cout << "\nKategori : " << buku_baru.kategori;
		cout << "\nTahun    : " << buku_baru.tahun;
		cout << "\n\n(Y/T) ? : ";
		cin >> validation_param;

		// jika iya
		if (validasi(validation_param))
		{
			// lakukan proses edit buku
			for (int i = 0; i < array_buku.size(); i++)
			{
				if (array_buku[i].id == id_edit)
				{
					array_buku[i] = buku_baru;

					// tulis kembali daftar buku setelah proses edit
					file.open("buku.txt", ios::out);

					for (int i = 0; i < array_buku.size(); i++)
					{
						if (i == array_buku.size() - 1)
						{
							file << array_buku[i].id << "/" << array_buku[i].judul << "/" << array_buku[i].kategori << "/" << array_buku[i].tahun;
						}
						else
						{
							file << array_buku[i].id << "/" << array_buku[i].judul << "/" << array_buku[i].kategori << "/" << array_buku[i].tahun;
							file << endl;
						}
					}

					cout << "\nBuku berhasil diedit\n";

					file.close();
				}
			}
		}
		else {
			cout << "\nUpdate buku dibatalkan\n";
		}
	}
	else {
		cout << "\nBuku tidak ada\n";
	}
}

void Admin::filter_buku(string filter_param)
{
	tampil(filter(ambil("buku.txt"),filter_param));
}

void Admin::hapus_buku(string id_hapus)
{
	// deklarasi variabel
	fstream file;
	Buku buku_target;
	bool buku_ada = false;
	char validation_param;
	vector<Buku> array_buku;

	// mengambil semua data buku yang ada di file
	array_buku = ambil("buku.txt");
	// menghitung jumlah buku sebelum proses hapus
	int jumlah_buku_sebelum = array_buku.size();

	for (int i = 0; i < array_buku.size(); i++)
	{
		// cek apakah buku yang akan dihapus ada ?
		if (array_buku[i].id == id_hapus)
		{
			buku_ada = true;
			buku_target = array_buku[i];
		}
	}

	// jika bukunya ada
	if (buku_ada)
	{
		// tampilkan pesan kepada user apakah proses hapus dilanjutkan apa tidak ?
		cout << "\nApakah anda yakin akan menghapus buku\n";
		cout << "\nJudul    : " << buku_target.judul;
		cout << "\nKategori : " << buku_target.kategori;
		cout << "\nTahun    : " << buku_target.tahun;
		cout << "\n\n(Y/T) ? : ";
		cin >> validation_param;

		// jika iya
		if (validasi(validation_param))
		{
			// lakukan proses penghapusan buku yang diinginkan
			for (int i = 0; i < array_buku.size(); i++)
			{
				if (array_buku[i].id == id_hapus)
				{
					array_buku.erase(array_buku.begin() + i);
				}
			}

			// lalu menulis kembali daftar buku setelah proses hapus ke dalam file
			file.open("buku.txt", ios::out);

			for (int i = 0; i < array_buku.size(); i++)
			{
				if (i == array_buku.size() - 1)
				{
					file << array_buku[i].id << "/" << array_buku[i].judul << "/" << array_buku[i].kategori << "/" << array_buku[i].tahun;
				}
				else
				{
					file << array_buku[i].id << "/" << array_buku[i].judul << "/" << array_buku[i].kategori << "/" << array_buku[i].tahun;
					file << endl;
				}
			}

			file.close();

			// mengambil semua data buku yang ada di file
			array_buku = ambil("buku.txt");
			// menghitung jumlah buku setelah proses hapus
			int jumlah_buku_setelah = array_buku.size();

			// jika jumlah buku setelah proses hapus lebih kecil daripada jumlah buku sebelumnya maka proses hapus berhasil
			if (jumlah_buku_setelah < jumlah_buku_sebelum) {
				cout << "\nBuku berhasil dihapus\n";
			}

		}
		else {
			cout << "\nPenghapusan buku dibatalkan\n";
		}
	}
	else {
		cout << "\nBuku tidak ada\n";
	}
}

void Admin::tambah_buku(Buku buku, string nama_file)
{
	// deklarasi varaiabel
	fstream file;
	char validation_param;
	vector<Buku> array_buku;

	// ambil seluruh daftar buku yang tersimpan di file
	array_buku = ambil("buku.txt");
	int jumlah_buku_sebelum = array_buku.size();

	// tampilkan pesan untuk meyakinkan user apakah ingin menambahkan buku ?
	cout << "\nApakah anda yakin akan menambahkan buku\n";
	cout << "\nJudul    : " << buku.judul;
	cout << "\nKategori : " << buku.kategori;
	cout << "\nTahun    : " << buku.tahun;
	cout << "\n\n(Y/T) ? : ";
	cin >> validation_param;

	// jika iya
	if (validasi(validation_param))
	{
		// lakukan proses penambahan buku
		file.open(nama_file, ios::app);

		if (array_buku.empty())
		{
			file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
		}
		else {
			file << endl;
			file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
		}

		file.close();

		// mengambil kembali semua daftar buku yang tersimpan di file
		array_buku = ambil("buku.txt");

		// menghitung jumlah buku setelah proses tambah buku
		int jumlah_buku_setelah = array_buku.size();

		// jika jumlah buku setelah proses tambah lebih besar daripada jumlah buku sebelumnya maka proses tambah buku berhasil
		if (jumlah_buku_setelah > jumlah_buku_sebelum)
		{
			cout << "\nBuku berhasil ditambahkan\n";
		}
		else {
			cout << "\nBuku gagal ditambahkan\n";
		}
	}
	else {
		cout << "\nPenambahan buku dibatalkan\n";
	}
}

void Admin::sorting_buku(string sort_param) {
	tampil(sort(ambil("buku.txt"), sort_param));
}

bool Admin::login(string username, string password, string nama_file) {

	// deklarasi variabel
	fstream file;
	vector<string> array_string = {}; // array penampung string diinisialisasi dengan array vector kosong
	string
		username_in_file,
		password_in_file,
		buffer;

	// buka file
	file.open(nama_file);

	// selama pembacaan file belum selesai
	while (!file.eof())
	{
		// ambil isi file baris per baris dan dimasukkan ke variabel buffer
		getline(file, buffer);
		// pecah variabel buffer berdasarkan tanda "/" dan masukkan ke variabel array_string
		array_string = pecah('/', buffer);
		// array_string index ke-0 sebagai username
		username_in_file = array_string[0];
		// array_string index ke-1 sebagai password
		password_in_file = array_string[1];

		// jika username dan password yang ada di file cocok dengan username dan password yang diinputkan user maka login berhasil
		if (username_in_file == username && password_in_file == password)
		{
			return true;
		}
	}

	file.close();

	return false;
}