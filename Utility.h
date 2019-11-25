#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>

#include "Buku.h"

using namespace std;

// deklarasi class Utility
class Utility
{
public:

	// deklarasi prototype fungsi validasi bertipe boolean dengan parameter validation_param bertipe char
	bool
		validasi(char validation_param);

	// deklarasi prototype fungsi tampil bertipe void dengan parameter bernama buku bertipe array vector yang elemen2 nya bertipe data Buku
	void
		tampil(vector<Buku> buku);

	// deklarasi prototype fungsi generate_id bertipe string
	string
		generate_id();

	// deklarasi prototype fungsi pecah bertipe array vector yang elemen2 nya bertipe string
	vector<string>
		pecah(char delimiter, string buffer);

	vector<Buku>
		ambil(string nama_file), // deklarasi prototype fungsi ambil bertipe array vector yang elemen2 nya bertipe Buku, dengan parameter nama_file bertipe string
		sort(vector<Buku> array_data, string sort_param); // deklarasi prototype fungsi sort bertipe array vector yang elemen2 nya bertipe Buku, dengan parameter array_buku bertipe array vector Buku dan sort_param bertipe string
	
	// deklarasi prototype fungsi buat_buku bertipe Buku
	Buku buat_buku();
};

