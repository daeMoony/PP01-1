#include "MObject.hpp"

class Player : public MObject
{
public:
	int x, y;
	Player()
	{
		x = 20;
		y = 7;
	}
	~Player()
	{

	}

	void isKeyPressed()
	{
		y = 5;
	}

	void isKeyUnpressed()
	{
		y = 7;
	}

};
class Trap
{
public:
	int x, y;
	Trap() {
		x = 60;
		y = 7;
	}
	~Trap() {

	}


};
