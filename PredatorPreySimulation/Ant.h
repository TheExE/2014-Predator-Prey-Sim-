#ifndef SKUDRA_H_INCLUDED
#define SKUDRA_H_INCLUDED

#include "Organism.h"

class Ant :public Organism
{
private:
	const int TIME_STEPS_TO_BREED = 3;

public:
	Ant();
	Ant(int row, int col);

	virtual void move(World& livingWorld);
	virtual void breed(World& livingWorld);
	virtual bool starvation(){ return false; }
	virtual void increaseTimeLived();
};
#endif