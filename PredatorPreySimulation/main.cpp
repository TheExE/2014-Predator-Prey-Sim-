/***********************************************************
Task description:

Create predator-prey model simulation.
In this simulation beetles are predators, but ants are prey.
These organisms live in a world that is represented by 20x20 element array.
"World" is locked, that means, that organisms cannot cross its boundaries.
Time is simulated with time step, in each time step every organism does some actions.

Behaviour model of ants is as follows:
1. Move. Every time step ant can move to nearby cell in any direction.
	Move direction is determined with random number generator.
	If nearby cell in chosen direction is occupied or it is out of bounds,
	then ant stays at its current position.
2. Breeding. If ant has lived for 3 time steps, then at the end of third time step after moving it breeds.
	It is simulated by creating new ant in nearby cell that is empty.
	If there is no empty cells nearby, the breeding process stops.
	If breeding happens successfully then next breeding can successfully happen
	only after 3 time steps.

Behavior model of beetles is as follows:
1. Move. Every time step if ant is nearby beetle moves to ant position and eats it.
	If there is no ants nearby, then beetle moves according to same rules as ant.
	Note that beetle can't eat other beetles.
2. Breed. If beetle has lived for 8 time steps, 
	then at the end of eight step it breeds, creating new
	beetle according to same rules as ant.
3. Starvation. If beetle has not eaten for 3 time steps then,
	it dies and leaves the world.
************************************************************/

#include <iostream>
#include "World.h"
#include <vector>
#include <fstream>

using namespace std;

struct Graph
{
	int timePassed;
	int antCount;
	int beetleCount;
};

int main()
{
	World theLivingWorld;
	vector<Graph> dataForExcel;
	ofstream dataFile;
	Graph tmp;

	int world_time;
	char atbilde;
	
	cout << "\n				THE WORLD SIMULATION\n\n";
	cout << "Please insert count of time steps you want to see.\n=>";
	cin >> world_time;

	cout << "This is the beggining of time !" << endl;
	theLivingWorld.displayWorld();
	
	// Save all data in vector
	tmp.timePassed = 0;
	tmp.antCount = theLivingWorld.getOrganismCount('X');
	tmp.beetleCount = theLivingWorld.getOrganismCount('O');
	dataForExcel.push_back(tmp);

	for (int i = 0; i < world_time; i++)
	{
		cout << "\nPress y - to continue, n-to end session.\n=>";
		cin >> atbilde;

		if (atbilde == 'n')
		{
			break;
		}
		
		cout << "This is time step  " << i + 1 << "." << endl;

		theLivingWorld.naturalProcess();

		// View after first time step 
		theLivingWorld.displayWorld();
		
		// Save data in vector
		tmp.timePassed = i + 1;
		tmp.antCount = theLivingWorld.getOrganismCount('X');
		tmp.beetleCount = theLivingWorld.getOrganismCount('O');
		dataForExcel.push_back(tmp);
	}

	// Save data to .csv file
	dataFile.open("living_processData.csv");
	
	// Write all lines
	dataFile << "Time Passed" << "," <<"Ant Count" << "," << "Beetle Count" << endl;

	for (int i = 0; i < (int)dataForExcel.size(); i++)
	{
		dataFile << dataForExcel.at(i).timePassed << "," 
			<< dataForExcel.at(i).antCount << "," 
			<< dataForExcel.at(i).beetleCount << endl;
	}

	dataFile.close();

	return 0;
}
