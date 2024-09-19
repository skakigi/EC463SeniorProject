//
// Created by sorak on 9/18/2024.
//

#ifndef SENIORDESIGN_MD_HLSCONCEPTUAL_H
#define SENIORDESIGN_MD_HLSCONCEPTUAL_H

//here define the basic building blocks

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

//parameters

#define NUM_PARTICLES_PER_CELL 200
#define NUM_CELLS 100
#define CELL_SIZE_DIMENSION 10
#define GRID_SIZE_DIMENSION 1000
#define CELL_COUNT_ACROSS GRID_SIZE_DIMENSION/CELL_SIZE_DIMENSION
#define TOTAL_PARTICLE_COUNT NUM_PARTICLES_PER_CELL * NUM_CELLS
#define TOTAL_CELL_COUNT (int)(pow(GRID_SIZE_DIMENSION,3)/pow(CELL_SIZE_DIMENSION,3))

//starting with particle
typedef struct{
    //coordinate location
    float x,y,z;

    //cell number
    int cell;

}Particle;

typedef struct{
    //assume each cell has NUM_PARTICLES_PER_CELL particles
    Particle Particles[NUM_PARTICLES_PER_CELL];

    //cell location (has to be integer x,y,z)
    int x,y,z;

    //quick check if the cell is full (mostly for setup)
    bool isFull;
}Cell;

//Helper Functions

int find_neighbors(const Cell *cellList);
int find_distance(const Particle A,const Particle B);
void set_cell_coordinate(Cell *cell,int x,int y,int z){
    cell->x=x;
    cell->y=y;
    cell->z=z;
}
void set_particle_coordinate(Particle *particle,float x, float y, float z){
    particle->x=x;
    particle->y=y;
    particle->z=z;
}
void init(Particle *particleList,Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]);

//Constructors
Particle setup_particle(){
    srand((unsigned int)time(NULL));

    Particle particle;
    particle.x = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;
    particle.y = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;
    particle.z = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;

    particle.cell = -1;

    return particle;
}





#endif //SENIORDESIGN_MD_HLSCONCEPTUAL_H
