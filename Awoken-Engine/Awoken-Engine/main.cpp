#include "GameManager.h"
#include "Cube.h"
#include "MeshRenderer.h"

void loadObjects() {
	
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}