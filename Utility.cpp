// memasukkan class Utility ke file ini
#include "Utility.h"

// pendefinisian member function dari class Utility yang bernama validasi yang mengembalikan nilai bertipe data boolean dengan parameter validation_param bertipe char
bool Utility::validasi(char validation_param)
{
	// jika validation_param bernilai Y atau y
	if (validation_param == 'Y' || validation_param == 'y')
	{
		// maka akan mengembalikan nilai true
		return true;
	}

	// jika tidak maka akan mengembalikan nilai false
	return false;
}



// pendefinisian member function dari class Utility yang bernama tampil yang mengembalikan nilai kosong dengan parameter bernama array_buku bertipe array vector yang elemen2 nya bertipe Buku
void Utility::tampil(vector<Buku> array_buku) {

	// menampilkan nama kolom
	cout << setw(12);
	cout << left << "ID";
	cout << setw(35);
	cout << left << "Judul";
	cout << setw(20);
	cout << left << "Kategori";
	cout << setw(4);
	cout << left << "Tahun";
	cout << endl << endl;

	// menampilkan daftar buku
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



// pendefinisian member function dari class Utility yang bernama generate_id yang mengembalikan string tanpa parameter
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



// pendefinisian member function dari class Utility yang bernama pecah yang mengembalikan array vector yang elemen2 nya bertipr string dengan parameter delimiter bertipe char dan buffer bertipe string
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



// pendefinisian member function dari class Utility yang bernama pecah yang mengembalikan array vector yang elemen2 nya bertipe Buku dengan parameter nama_file bertipe string
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



// pendefinisian member function dari class Utility yang bernama sort yang mengembalikan array vector yang elemen2 nya bertipe Buku dengan parameter array buku yang akan disorting dan parameter sorting
vector<Buku> Utility::sort(vector<Buku> array_buku, string sort_param) {

	// objek penampung sementara
	Buku temp;

	// melakukan proses sorting buku berdasarkan parameter sorting
	for (int i = 0; i < array_buku.size() - 1; i++)
	{
		for (int j = 0; j < (array_buku.size() - i - 1); j++)
		{
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

	// mengembalikan daftar buku yang telah terurut
	return array_buku;
}



vector<Buku> Utility::filter(vector<Buku> array_buku, string filter_param) {

	// deklarasi array penampung buku yang sudah difilter
	vector<Buku> array_buku_terfilter;

	// pengulangan sebanyak jumlah buku
	for (Buku b : array_buku) {
		// apabila kategori buku sama dengan parameter filter
		if (b.kategori == filter_param)
		{
			// maka masukkan buku ke array penampung
			array_buku_terfilter.push_back(b);
		}
	}

	// mengembalikan daftar buku yang sudah difilter
	return array_buku_terfilter;
}



// pendefinisian member function dari class Utility yang bernama Buku yang mengembalikan array vector yang elemen2 nya bertipe Buku dengan parameter array buku yang akan disorting dan parameter sorting
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