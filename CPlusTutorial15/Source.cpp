#include <iostream>
using namespace std;


class Object {
public:
	virtual void BeginPlay() {
		cout << "Object BeginPlay() called. \n";
	}

	void ObjectFunction() {
		cout << "ObjectFunction() called.\n";
	}
};

class Actor : public Object {
public:
	virtual void BeginPlay() override {
		cout << "Actor BeginPlay() called \n";
	}

	void ActorFunction() {
		cout << "ActorFunction() called.\n";
	}
};

class Pawn : public Actor {
public:
	virtual void BeginPlay() override {
		cout << "Pawn BeginPlay() called \n";
	}

	void PawnFunction() {
		cout << "PawnFunction() called.\n";
	}
};

//CASTING





int main()
{
	//POLYMORPHISM//////////////////////////

	Object* ptr_to_object = new Object;
	Actor* ptr_to_actor = new Actor;
	Pawn* ptr_to_pawn = new Pawn;

	Object* ObjectArray[] = { ptr_to_object, ptr_to_actor, ptr_to_pawn };

	for (int i = 0; i < 3; i++) {
		//ObjectArray[i]->BeginPlay();
		
		Object* obj = ObjectArray[i];

		Actor* act = dynamic_cast<Actor*>(obj);
		cout << i << endl;
		if (act) {
			act->ActorFunction();
		}

		Pawn* pwn = dynamic_cast<Pawn*>(obj);
		cout << i << endl;
		if (pwn) {
			pwn->PawnFunction();
		}
	}


	//CASTING///////////////////////////////////////////




	delete ptr_to_actor;
	delete ptr_to_pawn;
	delete ptr_to_object;
	system("pause");
}