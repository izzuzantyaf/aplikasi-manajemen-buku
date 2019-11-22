#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Buku.h"

using namespace std;

class Utility
{
public:

	vector<Buku> array_buku;
	vector<string> array_string;
	fstream file;

	void
		tampil(vector<Buku> buku);

	vector<string>
		pecah(char delimiter, string buffer);

	vector<Buku>
		ambil(string nama_file),
		sort(vector<Buku> array_data, string sort_param);
		
	Buku input_data_buku();
};

