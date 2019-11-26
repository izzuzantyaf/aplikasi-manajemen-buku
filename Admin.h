#pragma once
#include <iostream>
#include <string>
#include "Buku.h"
#include "Utility.h"

class Admin : private Utility
{
public:
	void
		hapus_buku(string id_hapus),
		edit_buku(string id_edit),
		tambah_buku(Buku buku, string nama_file),
		filter_buku(string filter_param),
		sorting_buku(string sort_param);

	bool
		login(string username, string password, string nama_file);
};

