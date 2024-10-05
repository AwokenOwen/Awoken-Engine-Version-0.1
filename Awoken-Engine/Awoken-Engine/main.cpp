#include "GameManager.h"
#include "nlohmann/json.hpp"
#include <vector>
#include "iostream"

using namespace std;

using json = nlohmann::json;

int main() 
{
	GM.Start();

	GM.Run();

	GM.Stop();
}