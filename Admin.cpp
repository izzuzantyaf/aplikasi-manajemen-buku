#include "Admin.h"

void Admin::edit_buku(string id_edit)
{
	fstream file;
	Buku buku_baru, buku_target;
	bool buku_ada = false;
	char validation_param;
	vector<Buku> array_buku;

	array_buku = ambil("buku.txt");

	for (int i = 0; i < array_buku.size(); i++)
	{
		if (array_buku[i].id == id_edit)
		{
			buku_ada = true;
			buku_target = array_buku[i];
		}
	}

	if (buku_ada)
	{
		buku_baru = buat_buku();
		buku_baru.id = buku_target.id;

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

		if (validasi(validation_param))
		{
			for (int i = 0; i < array_buku.size(); i++)
			{
				if (array_buku[i].id == id_edit)
				{
					array_buku[i] = buku_baru;

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

void Admin::hapus_buku(string id_hapus)
{
	fstream file;
	Buku buku_target;
	bool buku_ada = false;
	char validation_param;
	vector<Buku> array_buku;

	array_buku = ambil("buku.txt");
	int jumlah_buku_sebelum = array_buku.size();

	for (int i = 0; i < array_buku.size(); i++)
	{
		if (array_buku[i].id == id_hapus)
		{
			buku_ada = true;
			buku_target = array_buku[i];
		}
	}

	if (buku_ada)
	{
		cout << "\nApakah anda yakin akan menghapus buku\n";
		cout << "\nJudul    : " << buku_target.judul;
		cout << "\nKategori : " << buku_target.kategori;
		cout << "\nTahun    : " << buku_target.tahun;
		cout << "\n\n(Y/T) ? : ";
		cin >> validation_param;

		if (validasi(validation_param))
		{
			for (int i = 0; i < array_buku.size(); i++)
			{
				if (array_buku[i].id == id_hapus)
				{
					array_buku.erase(array_buku.begin() + i);
				}
			}

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

			array_buku = ambil("buku.txt");
			int jumlah_buku_setelah = array_buku.size();

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
	fstream file;
	char validation_param;
	vector<Buku> array_buku;

	array_buku = ambil("buku.txt");
	int jumlah_buku_sebelum = array_buku.size();

	cout << "\nApakah anda yakin akan menambhakan buku\n";
	cout << "\nJudul    : " << buku.judul;
	cout << "\nKategori : " << buku.kategori;
	cout << "\nTahun    : " << buku.tahun;
	cout << "\n\n(Y/T) ? : ";
	cin >> validation_param;

	if (validasi(validation_param))
	{
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

		array_buku = ambil("buku.txt");

		int jumlah_buku_setelah = array_buku.size();

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

vector<Buku> Admin::filter(vector<Buku> array_buku, string filter_param) {

	vector<Buku> array_buku_filter;

	for (Buku b : array_buku) {
		if (b.kategori == filter_param)
		{
			array_buku_filter.push_back(b);
		}
	}

	return array_buku_filter;
}

bool Admin::login(string username, string password, string nama_file) {
	fstream file;
	vector<string> array_string = {};
	string
		username_in_file,
		password_in_file,
		buffer;

	file.open(nama_file);

	while (!file.eof())
	{
		getline(file, buffer);
		array_string = pecah('/', buffer);
		username_in_file = array_string[0];
		password_in_file = array_string[1];

		if (username_in_file == username && password_in_file == password)
		{
			return true;
		}
	}

	file.close();

	return false;
}