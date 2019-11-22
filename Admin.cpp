#include "Admin.h"

void Admin::edit_buku()
{
}

bool Admin::hapus_buku(int id_hapus)
{
	array_buku = ambil("buku.txt");
	int jumlah_buku_sebelum = array_buku.size();

	/*cout << "\nMasukkan ID buku yang ingin diahpus : ";
	cin>>id*/

	file.open("buku.txt",ios::out);

	for (Buku buku : array_buku) {
		if (buku.id != id_hapus)
		{
			if (buku.id != array_buku.size())
			{
				file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
				file << endl;
				cout << "aaaaa ";
			}
			else {
				file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
				cout << "bbbbb ";
			}
		}
	}

	file.close();

	/*array_buku = ambil("buku.txt");
	int jumlah_buku_setelah = array_buku.size();

	if (jumlah_buku_setelah < jumlah_buku_sebelum)
	{
		return true;
	}*/

	return true;
}

bool Admin::tambah_buku(Buku buku, string nama_file)
{
	fstream file;

	array_buku = ambil("buku.txt");
	int jumlah_buku_sebelum = array_buku.size();

	file.open(nama_file, ios::app);

	file << endl;
	file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;

	file.close();

	array_buku = ambil("buku.txt");

	int jumlah_buku_setelah = array_buku.size();

	if (jumlah_buku_setelah > jumlah_buku_sebelum)
	{
		return true;
	}

	return false;
}

bool Admin::login(string username, string password, string nama_file) {

	array_string = {};

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
