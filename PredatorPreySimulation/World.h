#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

class World
{
	friend class Organism;
	friend class Beetle;
	friend class Ant;

private:
	static const int SIZE = 20;
	static const int N_ANTS = 100;
	static const int N_BEETLES = 5;
	Organism* theWorld[SIZE][SIZE];

public:
	World();
	~World();
	void displayWorld();
	void naturalProcess();
	void removeBeing(int row, int col);
	int getOrganismCount(char beingSymbol);
	void moveBeing(int row, int col, int newRow, int newCol);
};

#endif