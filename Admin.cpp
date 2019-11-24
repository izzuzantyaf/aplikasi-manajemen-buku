#include "Admin.h"

void Admin::edit_buku(int id_edit)
{
	fstream file;
	vector<Buku> array_buku;

	array_buku = ambil("buku.txt");



	file.open("buku.txt");



	file.close();
}

bool Admin::hapus_buku(int id_hapus)
{
	fstream files;
	vector<Buku> array_buku;
	array_buku = ambil("buku.txt");

	files.open("buku.txt", ios::app);

	for (Buku buku : array_buku) {
		if (buku.id != id_hapus)
		{
			files << endl;
			files << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
			//if (buku.id != book_arr.size())
			//{
			//	file << endl;
			//	file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
			//	//cout << "aaaaa ";
			//}
			//else {
			//	file << buku.id << "/" << buku.judul << "/" << buku.kategori << "/" << buku.tahun;
			//	//cout << "bbbbb ";
			//}
		}
	}

	files.close();

	/*array_buku = ambil("buku.txt");
	int jumlah_buku_setelah = array_buku.size();

	if (jumlah_buku_setelah < jumlah_buku_sebelum)

		return true;
	}*/

	return true;
}

bool Admin::tambah_buku(Buku buku, string nama_file)
{
	fstream file;
	vector<Buku> array_buku;

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