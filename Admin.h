#pragma once
#include <iostream>
#include <string>
#include "Buku.h"
#include "Utility.h"

class Admin:public Utility
{
public:
	void
		hapus_buku(string id_hapus),
		edit_buku(string id_edit),
		tambah_buku(Buku buku, string nama_file);

	vector<Buku>
		filter(vector<Buku> array_buku, string filter_param);

	bool
		login(string username, string password, string nama_file);
};

