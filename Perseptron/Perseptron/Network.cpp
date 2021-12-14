#include "Network.h"

Network::Network() : perceptron_storage(0)
{
	/*map<Symbol, Perceptron> m;
	perceptron_storage = m;*/
}

bool Network::IsEmpty()
{
	if (perceptron_storage.size() == 0)
		return true;
	else
		return false;
}

int Network::GetSize()
{
	return perceptron_storage.size();
}

void Network::CreatePerceptron(const Symbol& symbol, int x, int y)
{
	auto perceptron_ptr = make_shared<Perceptron>(symbol, x, y);

	//perceptron_ptr->SetParams(symbol, x, y);

	perceptron_storage.push_back(perceptron_ptr);
}

void Network::TeachNetwork()
{
	if (!IsEmpty())
	{
		int i = 0;
		for (auto& perceptron : perceptron_storage)
		{
			perceptron->TeachPerceptron();
			cout << "id " << i << " Обучение прошло" << endl;
			++i;
		}
	}
	else throw exception("Error! Network is empty!");
}




//void Network::AddPerceptron(const Symbol& symbol,const Perceptron& perceptron)
//{
//	//v.push_back(perceptron);
//	perceptron_storage.insert(make_pair(symbol,perceptron));
//}
//
//void Network::TeachNetwork()
//{
//	for (auto elem : perceptron_storage)
//	{
//		elem.second.TeachPerceptron();
//	}
//	/*for (auto it = perceptron_storage.begin(); it != perceptron_storage.end(); it++)
//	{
//		it->second.TeachPerceptron();
//	}*/
//}
