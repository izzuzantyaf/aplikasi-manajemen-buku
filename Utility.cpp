#include "Utility.h"

bool Utility::validasi(char validation_param)
{
	if (validation_param == 'Y' || validation_param == 'y')
	{
		return true;
	}

	return false;
}

void Utility::tampil(vector<Buku> array_buku) {

	cout << setw(12);
	cout << left << "ID";
	cout << setw(35);
	cout << left << "Judul";
	cout << setw(20);
	cout << left << "Kategori";
	cout << setw(4);
	cout << left << "Tahun";
	cout << endl << endl;

	for (Buku buku : array_buku) {
		cout << setw(12);
		cout << left << buku.id;
		cout << setw(35);
		cout << left << buku.judul;
		cout << setw(20);
		cout << left << buku.kategori;
		cout << setw(4);
		cout << left << buku.tahun;
		cout << endl;
	}
	
}

string Utility::generate_id()
{
	string
		pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		id;

	srand(time(0));

	for (int i = 0; i < 6; i++)
	{
		id += pool[ 0 + rand() % pool.length()];
	}

	return id;
}

vector<string> Utility::pecah(char delimiter, string buffer) {

	vector<string> array_string = {};
	int delimiter_index;

	for (int i = 0; i < buffer.length(); i++)
	{
		if (buffer[i] != delimiter)
		{
			delimiter_index = buffer.find(delimiter, i);
			if (delimiter_index != (-1))
			{
				array_string.push_back(buffer.substr(i, delimiter_index - i));
				i = delimiter_index;
			}
			else {
				array_string.push_back(buffer.substr(i, buffer.length() - i + 1));
				break;
			}
		}
	}
	
	return array_string;
}

vector<Buku> Utility::ambil(string nama_file) {

	ifstream file;
	vector<Buku> array_buku = {};
	vector<string> array_string = {};
	string buffer;
	Buku buku;

	file.open(nama_file);

	while (!file.eof())
	{
		getline(file, buffer);
		if (buffer != "")
		{
			array_string = pecah('/', buffer);

			buku.id = array_string[0];
			buku.judul = array_string[1];
			buku.kategori = array_string[2];
			buku.tahun = stoi(array_string[3]);

			array_buku.push_back(buku);
		}
		else {
			continue;
		}
	}

	file.close();

	return array_buku;
}

vector<Buku> Utility::sort(vector<Buku> array_buku, string sort_param) {

	Buku temp;

	for (int i = 0; i < array_buku.size() - 1; i++)
	{
		for (int j = 0; j < (array_buku.size() - i - 1); j++) {
			if (sort_param == "id")
			{
				if (array_buku[j].id > array_buku[j + 1].id)
				{
					temp = array_buku[j];
					array_buku[j] = array_buku[j + 1];
					array_buku[j + 1] = temp;
				}
			}
			else if (sort_param == "judul") {
				if (array_buku[j].judul > array_buku[j + 1].judul)
				{
					temp = array_buku[j];
					array_buku[j] = array_buku[j + 1];
					array_buku[j + 1] = temp;
				}
			}
			else if (sort_param == "kategori") {
				if (array_buku[j].kategori > array_buku[j + 1].kategori)
				{
					temp = array_buku[j];
					array_buku[j] = array_buku[j + 1];
					array_buku[j + 1] = temp;
				}
			}
			else if (sort_param == "tahun") {
				if (array_buku[j].tahun > array_buku[j + 1].tahun)
				{
					temp = array_buku[j];
					array_buku[j] = array_buku[j + 1];
					array_buku[j + 1] = temp;
				}
			}
			else {

			}
		}
	}

	return array_buku;
}

Buku Utility::buat_buku() {

	Buku buku_baru;
	int pilihan;

	buku_baru.id = generate_id();

	cout << "\nJudul		: ";
	cin.ignore();
	getline(cin, buku_baru.judul);
	cout << "\nKategori\n";
	cout << "1. Kuliah\n2. Novel\n3. Kesehatan\n4. Sejarah\n5. Lainnya";
	cout << "\n\nPilihan kategori : ";
	cin >> pilihan;
	switch (pilihan)
	{
	case 1:
		buku_baru.kategori = "Kuliah";
		break;
	case 2:
		buku_baru.kategori = "Novel";
		break;
	case 3:
		buku_baru.kategori = "Kesehatan";
		break;
	case 4:
		buku_baru.kategori = "Sejarah";
		break;
	case 5:
		buku_baru.kategori = "Lainnya";
		break;
	default:
		buku_baru.kategori = "Lainnya";
		break;
	}
	cout << "\nTahun		: ";
	cin >> buku_baru.tahun;

	return buku_baru;
}