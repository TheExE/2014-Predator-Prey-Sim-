#include "Organism.h"

Organism::Organism()
{
	row = 0;
	col = 0;
	symbol = ' ';
	hasMoved = false;
	time_lived = 0;
}

Organism::Organism(int row, int col, char symbol)
{
	this->row = row;
	this->col = col;
	this->symbol = symbol;
	this->time_lived = 1;
	this->hasMoved = false;
}

int Organism::getRow()
{
	return row;
}

int Organism::getCol()
{
	return col;
}

char Organism::getSymbol()
{
	return symbol;
}

bool Organism::getHasMoved()
{
	return hasMoved;
}

void Organism::setHasMoved(bool moved)
{
	this->hasMoved = moved;
}

void Organism::setRow(int row)
{
	this->row = row;
}

void Organism::setCol(int col)
{
	this->col = col;
}