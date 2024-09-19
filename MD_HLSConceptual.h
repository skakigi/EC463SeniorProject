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

//parameters

#define NUM_PARTICLES_PER_CELL 200
#define NUM_CELLS 100
#define TOTAL_GRID_SIZE_DIMENSION 1000

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

    //quick check if the cell is full (mostly for setup)
    bool isFull;
}Cell;

//Helper Functions

int find_neighbors(const Cell *cellList);
int find_distance(const Particle A,const Particle B);

//Constructors
Particle setup_particles(){
    srand((unsigned int)time(NULL));

    Particle particle;
    particle.x = ((float)rand()/(float)(RAND_MAX)) * TOTAL_GRID_SIZE_DIMENSION;
    particle.y = ((float)rand()/(float)(RAND_MAX)) * TOTAL_GRID_SIZE_DIMENSION;
    particle.z = ((float)rand()/(float)(RAND_MAX)) * TOTAL_GRID_SIZE_DIMENSION;

    particle.cell = -1;

}





#endif //SENIORDESIGN_MD_HLSCONCEPTUAL_H
