# 2014-Predator-Prey-Sim-
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
