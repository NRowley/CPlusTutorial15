#include <iostream>
#include "Object.h"
#include "Actor.h"
#include "Pawn.h"
using namespace std;

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

	delete ptr_to_actor;
	delete ptr_to_pawn;
	delete ptr_to_object;
	system("pause");
}