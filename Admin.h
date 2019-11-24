#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Buku.h"
#include "Utility.h"

class Admin:public Utility
{
public:
	void
		edit_buku(int id_edit);
	bool
		hapus_buku(int id_hapus),
		tambah_buku(Buku buku, string nama_file),
		login(string username, string password, string nama_file);
};

