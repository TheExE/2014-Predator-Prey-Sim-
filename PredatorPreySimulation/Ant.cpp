#include "Ant.h"
#include "Direction.h"


Ant::Ant() : Organism()
{
	symbol = 'X';
}

Ant::Ant(int row, int col) 
	: 
Organism(row, col, 'X')
{
	
}

void Ant::move(World& livingWorld)
{
	int direction = rand() % LAST;

	// Try to move in randomly chosen direction
	switch (direction)
	{
	case DOWN:		
		if (livingWorld.theWorld[row - 1][col] == NULL && row - 1 >= 0)
		{			
			livingWorld.moveBeing(row, col, row - 1, col);
		}
		break;

	case UP:
		if (livingWorld.theWorld[row + 1][col] == NULL && row + 1 < livingWorld.SIZE)
		{
			livingWorld.moveBeing(row, col, row + 1, col);
		}
		break;

	case LEFT:
		if (livingWorld.theWorld[row][col - 1] == NULL && col - 1 >= 0)
		{
			livingWorld.moveBeing(row, col, row, col - 1);
			hasMoved = true;
		}
		break;

	case RIGHT:
		if (livingWorld.theWorld[row][col + 1] == NULL && col + 1 < livingWorld.SIZE)
		{			
			livingWorld.moveBeing(row, col, row, col + 1);
		}
		break;
	}
	
	// Make note that ant tried to move
	hasMoved = true;
}
void Ant::breed(World& livingWorld)
{
	// If ant has lived for TIME_STEPS_TO_BREED time steps and it has hasMoved, then try to breed
	if (time_lived == TIME_STEPS_TO_BREED)
	{
		if (row - 1 >= 0 && livingWorld.theWorld[row - 1][col] == NULL)
		{
			livingWorld.theWorld[row - 1][col] = new Ant(row - 1, col);						
		}
		else if (row + 1 < livingWorld.SIZE && livingWorld.theWorld[row + 1][col] == NULL)
		{
			livingWorld.theWorld[row + 1][col] = new Ant(row + 1, col);
		}
		else if (col - 1 >= 0 && livingWorld.theWorld[row][col - 1] == NULL)
		{	
			livingWorld.theWorld[row][col - 1] = new Ant(row, col - 1);			
		}
		else if (col < livingWorld.SIZE && livingWorld.theWorld[row][col + 1] == NULL)
		{
			livingWorld.theWorld[row][col + 1] = new Ant(row, col + 1);			
		}

		/* After successful or unsuccessful atempt to breed,
		 * the time is reset to cout till next breeding event.
		 */
		time_lived = 0;
	}	
}

void Ant::increaseTimeLived()
{
	time_lived++;
}