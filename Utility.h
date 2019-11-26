#pragma once
// memasukkan daftar library yang diperlukan ke file ini
#include <iostream> // library input dan output
#include <string>	// library string
#include <fstream>	// library file
#include <vector>	// library vector
#include <iomanip>	// library untuk manipulasi input dan output

// memasukkan class Buku ke file ini
#include "Buku.h"

using namespace std;

// deklarasi class Utility
class Utility
{
public:

	// deklarasi prototype member function validasi yang mengembalikan tipe data boolean dengan parameter validation_param bertipe char
	bool
		validasi(char validation_param);

	// deklarasi prototype member function bernama tampil bertipe void dengan parameter bernama buku yang bertipe data array vector yang elemen2 nya bertipe data Buku
	void
		tampil(vector<Buku> buku);

	// deklarasi prototype member function bernama generate_id yang mengembalikan tipe data string
	string
		generate_id();

	// deklarasi prototype member function pecah yang mengembalikan tipe data array vector yang elemen2 nya bertipe string
	vector<string>
		pecah(char delimiter, string buffer);

	vector<Buku>
		filter(vector<Buku> array_buku, string filter_param),
		ambil(string nama_file), // deklarasi prototype member function bernama ambil yang mengembalikan tipe data array vector yang elemen2 nya bertipe Buku, dengan parameter nama_file bertipe string
		sort(vector<Buku> array_data, string sort_param); // deklarasi prototype fungsi sort yang mengembalikan tipe data array vector yang elemen2 nya bertipe Buku, dengan parameter array_buku bertipe array vector Buku dan sort_param bertipe string
	
	// deklarasi prototype member function bernama buat_buku yang mengembalikan tipe data Buku
	Buku buat_buku();
};

