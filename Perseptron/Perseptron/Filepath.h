#pragma once
#include "Framework.h"

/*
����� ��� ������ �������� ��������
��������� ������� ����� ��� ������� �������
*/

class Filepath
{
private:
	std::string folder;
	std::string good;
	std::string bad;

	std::vector<std::string> good_files;
	std::vector<std::string> bad_files;

	void LoadFiles();
public:
// �����������
	Filepath();

	void SetFilePaths(int id);
	bool IsEmpty();

	std::vector<std::string> GetGoodFiles();
	std::vector<std::string> GetBadFiles();
};
