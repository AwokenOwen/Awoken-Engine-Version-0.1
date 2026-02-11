#include "GameManager.h"
#include "Object.h"

int main() 
{
	GM.Initialize();

	Object* o = new Object();



	GM.Run();

	GM.Terminate();
}