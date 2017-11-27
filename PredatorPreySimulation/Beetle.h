#ifndef VABOLE_H_INCLUDED
#define VABOLE_H_INCLUDED

#include "Organism.h"

class Beetle :public Organism
{
private:
	const int MAX_TIME_NOT_EATEN = 3;
	const int TIME_STEPS_TO_BREED = 8;
	bool haveEaten;
	int timeStarved;

public:
	Beetle();
	Beetle(int row, int col);

	virtual void move(World& livingWorld);
	virtual void breed(World& livingWorld);
	virtual bool starvation();
	virtual void increaseTimeLived();
};
#endif