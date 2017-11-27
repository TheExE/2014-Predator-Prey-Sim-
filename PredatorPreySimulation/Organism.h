#ifndef ORGANISMS_H_INCLUDED
#define ORGANISMS_H_INCLUDED

#include <iostream>
#include "World.h"

using namespace std;

class Organism
{
protected:
	int row, col;
	char symbol;
	bool hasMoved;
	int time_lived;

public:
	Organism();
	Organism(int row, int col, char symbol);

	int getRow();
	int getCol();
	void setRow(int row);
	void setCol(int col);
	char getSymbol();

	bool getHasMoved();
	void setHasMoved(bool moved);

	virtual void move(World& livingWorld) {}
	virtual void breed(World& livingWorld) {}
	virtual bool starvation() { return 0; }
	virtual void increaseTimeLived(){}
};
#endif