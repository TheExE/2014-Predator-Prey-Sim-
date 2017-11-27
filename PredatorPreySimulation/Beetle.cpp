#include "Beetle.h"
#include "Direction.h"


Beetle::Beetle() :Organism()
{
	symbol = 'O';
	haveEaten = false;
	timeStarved = 1;
}
Beetle::Beetle(int row, int col) : Organism(row, col, 'O')
{
	haveEaten = false;
	timeStarved = 1;
}
void Beetle::move(World& livingWorld)
{	
	// Beetle tries to eat ant
	if (row - 1 >= 0 && livingWorld.theWorld[row - 1][col] != NULL &&
		livingWorld.theWorld[row - 1][col]->getSymbol() == 'X')
	{
		// Free the space for beetle (eat the ant)
		livingWorld.removeBeing(row - 1, col);
			
		// Move to the new position
		livingWorld.moveBeing(row, col, row - 1, col);
		haveEaten = true;
	}	
	else if (row + 1 < livingWorld.SIZE && 
		livingWorld.theWorld[row + 1][col] != NULL &&
		livingWorld.theWorld[row + 1][col]->getSymbol() == 'X')
	{		
		livingWorld.removeBeing(row + 1, col);
		livingWorld.moveBeing(row, col, row + 1, col);
		haveEaten = true;		
	}
	else if (col - 1 >= 0 && livingWorld.theWorld[row][col - 1] != NULL &&
		livingWorld.theWorld[row][col - 1]->getSymbol() == 'X')
	{				
		livingWorld.removeBeing(row, col - 1);
		livingWorld.moveBeing(row, col, row, col - 1);			
		haveEaten = true;		
	}
	else if (col + 1 < livingWorld.SIZE && 
		livingWorld.theWorld[row][col + 1] != NULL &&
		livingWorld.theWorld[row][col + 1]->getSymbol() == 'X')
	{		
		livingWorld.removeBeing(row, col + 1);
		livingWorld.moveBeing(row, col, row, col + 1);			
		haveEaten = true;		
	}

	// No ants nearby, failed to eat ant
	if (!haveEaten)
	{		
		int direction = rand() % LAST;
		
		// Try to move in randomly chosen direction 
		switch (direction)
		{
		case DOWN:
				// If place is free and not out of bounds then move to it
				if (livingWorld.theWorld[row - 1][col] == NULL && row - 1 >= 0)
				{					
					livingWorld.moveBeing(row, col, row - 1, col);
				}
			break;

		case UP:
				if (livingWorld.theWorld[row + 1][col] == NULL &&
					row + 1 < livingWorld.SIZE)
				{
					livingWorld.moveBeing(row, col, row + 1, col);
				}
			break;

		case LEFT:
				if (livingWorld.theWorld[row][col - 1] == NULL && col - 1 >= 0)
				{
					livingWorld.moveBeing(row, col, row, col - 1);
				}
			break;

		case RIGHT:
				if (livingWorld.theWorld[row][col + 1] == NULL &&
					col + 1 < livingWorld.SIZE)
				{
					livingWorld.moveBeing(row, col, row, col + 1);
				}
			break;
		}
	}

	// Make a note that even if bettle failed to move, it did try
	hasMoved = true;
}
void Beetle::breed(World& livingWorld)
{	
	if (time_lived == TIME_STEPS_TO_BREED)
	{
		// Start counting to next breeding time
		time_lived = 0; 

		// Breed if possible
		if (row - 1 >= 0 && livingWorld.theWorld[row - 1][col] == NULL)
		{
			livingWorld.theWorld[row - 1][col] = new Beetle(row - 1, col);						
		}		
		else if (row + 1 < livingWorld.SIZE &&
			livingWorld.theWorld[row + 1][col] == NULL)
		{
			livingWorld.theWorld[row + 1][col] = new Beetle(row + 1, col);						
		}
		else if (col - 1 >= 0 && livingWorld.theWorld[row][col - 1] == NULL)
		{
			livingWorld.theWorld[row][col - 1] = new Beetle(row, col - 1);						
		}
		else if (col + 1< livingWorld.SIZE &&
			livingWorld.theWorld[row][col + 1] == NULL)
		{
			livingWorld.theWorld[row][col + 1] = new Beetle(row, col + 1);			
		}		
	}
}

bool Beetle::starvation()
{
	bool starved = false;

	// If beetle has not eaten for 3 time steps then it starves
	if (timeStarved == MAX_TIME_NOT_EATEN && !haveEaten)
	{
		starved = true;
	}
	else if (timeStarved == MAX_TIME_NOT_EATEN && haveEaten)
	{		
		timeStarved = 0;
		haveEaten = false;
	}

	return starved;
}

void Beetle::increaseTimeLived()
{
	time_lived++;
	timeStarved++;
}

