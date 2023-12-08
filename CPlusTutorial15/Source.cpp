#include <iostream>
using namespace std;


class Object {
public:
	virtual void BeginPlay() {
		cout << "Object BeginPlay() called. \n";
	}
};

class Actor : public Object {
public:
	virtual void BeginPlay() override {
		cout << "Actor BeginPlay() called \n";
	}
};

class Pawn : public Actor {
public:
	virtual void BeginPlay() override {
		cout << "Pawn BeginPlay() called \n";
	}
};



int main()
{
	Object* ptr_to_object = new Object;
	Actor* ptr_to_actor = new Actor;
	Pawn* ptr_to_pawn = new Pawn;

	Object* ObjectArray[] = { ptr_to_object, ptr_to_actor, ptr_to_pawn };

	for (int i = 0; i < 3; i++) {
		ObjectArray[i]->BeginPlay();
	}

	delete ptr_to_actor;
	delete ptr_to_pawn;
	delete ptr_to_object;
	system("pause");
}