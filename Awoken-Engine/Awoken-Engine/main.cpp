#include "GameManager.h"
#include "nlohmann/json.hpp"
#include <vector>
#include "iostream"

using namespace std;

using json = nlohmann::json;

struct test
{
	vector<int> apples;
};

void to_json(json& j, const test& p)
{
	j = json{ {"Apple:", p.apples} };
}

void from_json(const json& j, test& p)
{
	j.at("Apple:").get_to(p.apples);
}

int main() 
{
	test a;

	a.apples.push_back(5);
	a.apples.push_back(4);
	a.apples.push_back(7);

	json j = a;

	cout << j << endl;

	test p;

	j.get_to(p);

	for (size_t i = 0; i < p.apples.size(); i++)
	{
		cout << p.apples[i] << " ";
	}

	//GM.Start();

	//GM.Run();

	//GM.Stop();
}