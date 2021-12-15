#include "Filepath.h"

void Filepath::LoadFiles()
{
	if (!IsEmpty())
	{
		for (int i = 1; i <= 45; i++)
		{
			good_files.push_back(good + std::to_string(i) + ".txt");
			bad_files.push_back(bad + std::to_string(i) + ".txt");
		}
	}
}

Filepath::Filepath(): folder("Symbols/"), good(""), bad(""), good_files(0), bad_files(0)
{
}

std::string Filepath::GetFolder()
{
	return folder;
}

void Filepath::SetFilePaths(int id)
{
	switch (id)
	{
	case 0:
	{
		good = folder + "0/Good/";
		bad = folder + "0/Bad/";
		LoadFiles();
	}
	break;

	case 1:
	{
		good = folder + "1/Good/";
		bad = folder + "1/Bad/";
		LoadFiles();
	}
	break;

	case 2:
	{
		good = folder + "2/Good/";
		bad = folder + "2/Bad/";
		LoadFiles();
	}
	break;

	case 3:
	{
		good = folder + "3/Good/";
		bad = folder + "3/Bad/";
		LoadFiles();
	}
	break;

	case 4:
	{
		good = folder + "4/Good/";
		bad = folder + "4/Bad/";
		LoadFiles();
	}
	break;

	case 5:
	{
		good = folder + "5/Good/";
		bad = folder + "5/Bad/";
		LoadFiles();
	}
	break;

	case 6:
	{
		good = folder + "6/Good/";
		bad = folder + "6/Bad/";
		LoadFiles();
	}
	break;

	case 7:
	{
		good = folder + "7/Good/";
		bad = folder + "7/Bad/";
		LoadFiles();
	}
	break;

	case 8:
	{
		good = folder + "8/Good/";
		bad = folder + "8/Bad/";
		LoadFiles();
	}
	break;

	case 9:
	{
		good = folder + "9/Good/";
		bad = folder + "9/Bad/";
		LoadFiles();
	}
	break;

	case 10:
	{
		good = folder + "x/Good/";
		bad = folder + "x/Bad/";
		LoadFiles();
	}
	break;

	case 11:
	{
		good = folder + "plus/Good/";
		bad = folder + "plus/Bad/";
		LoadFiles();
	}
	break;

	case 12:
	{
		good = folder + "minus/Good/";
		bad = folder + "minus/Bad/";
		LoadFiles();
	}
	break;

	case 13:
	{
		good = folder + "multiply/Good/";
		bad = folder + "multiply/Bad/";
		LoadFiles();
	}
	break;

	case 14:
	{
		good = folder + "divide/Good/";
		bad = folder + "divide/Bad/";
		LoadFiles();
	}
	break;

	case 15:
	{
		good = folder + "equal/Good/";
		bad = folder + "equal/Bad/";
		LoadFiles();
	}
	break;

	default:
		throw std::invalid_argument("received negative value");
	}
}

bool Filepath::IsEmpty()
{
	return (good == "" || bad == "");
}

std::vector<std::string> Filepath::GetGoodFiles()
{
	return good_files;
}

std::vector<std::string> Filepath::GetBadFiles()
{
	return bad_files;
}

