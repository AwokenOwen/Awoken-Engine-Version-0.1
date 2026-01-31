#pragma once
#include <string>
#include <vector>

using namespace std;

class Object;
class Scene
{
public:
	Scene();

	//called once at the start of a scene
	void Awake();
	//called on the first frame if enabled
	void Start();
	//called every frame
	void Update();
	//called every frame after update
	void LateUpdate();
	//returns the name of the Scene
	string getName();

	void Instantiate(Object* obj);

	unsigned int getShaderProgram();

private:
	vector<Object*> inScene;
	vector<Object*> toBeAdded;
	vector<Object*> toBeDeleted;

	string name;

	unsigned int shaderProgram;
};