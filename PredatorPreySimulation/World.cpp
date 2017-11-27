#include <ctime>
#include <cstdlib>
#include "World.h"
#include "Beetle.h"
#include "Ant.h"


World::World()
{
	srand((unsigned int)time(NULL));

	int row = rand() % SIZE;
	int col = rand() % SIZE;

	// Create first ants and beetls
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			theWorld[i][j] = NULL;

		}
	}
	// Fill empty places with NULL
	for (int i = 0; i < N_ANTS; i++)
	{
		if (i < N_BEETLES)
		{
			while (!(theWorld[row][col] == NULL))
			{
				row = rand() % SIZE;
				col = rand() % SIZE;
			}
			theWorld[row][col] = new Beetle(row, col);
		}
		while (!(theWorld[row][col] == NULL))
		{
			row = rand() % SIZE;
			col = rand() % SIZE;
		}
		theWorld[row][col] = new Ant(row, col);
		
	}
}
World::~World()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] != NULL)
			{
				delete theWorld[i][j];
			}			
		}
	}
}
void World::displayWorld()
{	
	int antCount = getOrganismCount('X');
	int beetleCount = getOrganismCount('O');

	cout << "\n		The World\n";
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] == NULL)
			{
				cout << "|" << " ";
			}
			else
			{
				cout << "|" << theWorld[i][j]->getSymbol();
			}
			if (j == SIZE - 1)
			{
				cout << "|";
			}
		}
		cout << endl;
		
		int counter = 0;
		while (counter < SIZE)
		{
			cout << "--";
			counter++;
		}
		cout << endl;		
	}

	cout << "Living world statistics:\n Ant count: " << antCount << " Beetle count: " << beetleCount << endl;
}
void World::naturalProcess()
{
	bool hasStarved = false;
	
	// Beetle is trying to move
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] != NULL)
			{
				// If this cell contains beetle and it has not yet moved
				if (theWorld[i][j]->getSymbol() == 'O' && !theWorld[i][j]->getHasMoved())
				{
					// Check if beetle is not in starvation state
					hasStarved = theWorld[i][j]->starvation();

					// If beetle has starved then remove it from world
					if (hasStarved)
					{
						removeBeing(i, j);						
					}					
					else
					{						
						theWorld[i][j]->move(*this);
					}
				}
			}
		}
	}
	// Ant is trying to move
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] != NULL )
			{				
				// If this cell contains ant and it has not jet moved
				if (theWorld[i][j]->getSymbol() == 'X' && !theWorld[i][j]->getHasMoved())
				{					
					theWorld[i][j]->move(*this);
				}
			}
		}
	}
	
	/*
	 * When all the organisms have successfully or unsuccesfully tried to move then,
	 * breed them and increase their time lived in this world.
	*/
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] != NULL)
			{
				theWorld[i][j]->breed(*this);
				theWorld[i][j]->setHasMoved(false);				
				theWorld[i][j]->increaseTimeLived();
			}
		}
	}
}
void World::removeBeing(int row, int col)
{
	delete theWorld[row][col];
	theWorld[row][col] = NULL;
}
void World::moveBeing(int row, int col, int newRow, int newCol)
{
	// Move the organism to new position 
	theWorld[newRow][newCol] = theWorld[row][col];

	// Free up the old position
	theWorld[row][col] = NULL; 

	// Let the organism know about its new position
	theWorld[newRow][newCol]->setRow(newRow);
	theWorld[newRow][newCol]->setCol(newCol);
	
}
int World::getOrganismCount(char organismSymbol)
{
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (theWorld[i][j] != NULL)
			{
				if (theWorld[i][j]->getSymbol() == organismSymbol)
				{
					count++;
				}
			}
		}
	}

	return count;
}