#pragma once
#include <string>
#include <vector>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

using namespace std;

class Object;
class Scene
{
public:
	Scene();

	//called once at the start of a scene
	void Awake();
	//called once at the start of the frame it is enabled on
	void OnEnable();
	//called on the first frame if enabled
	void Start();
	//called every frame
	void Update();
	//called every frame after update
	void LateUpdate();
	//called on the last frame it is enabled
	void OnDisable();
	//returns the name of the Scene
	string getName();

	virtual void to_json(json& j, const Scene& p);

	virtual void from_json(const json& j, Scene& p);

	void Instantiate(Object* obj);

private:
	vector<Object*> inScene;
	vector<Object*> toBeAdded;
	vector<Object*> toBeDeleted;

	string name;
};