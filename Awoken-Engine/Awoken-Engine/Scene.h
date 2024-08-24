#pragma once
#include <string>

#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/serialization/vector.hpp"

using namespace std;
using namespace boost;
using namespace serialization;

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

	string getName();

private:
	vector<Object*> inScene;
	vector<Object*> toBeAdded;
	vector<Object*> toBeDeleted;

	string name;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& name;
		ar& inScene;
		ar& toBeAdded;
		ar& toBeDeleted;
	}
};