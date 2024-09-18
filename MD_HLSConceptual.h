//
// Created by sorak on 9/18/2024.
//

#ifndef SENIORDESIGN_MD_HLSCONCEPTUAL_H
#define SENIORDESIGN_MD_HLSCONCEPTUAL_H

//here define the basic building blocks

#include <stdbool.h>
#include <stdlib.h>

//parameters

#define NUM_PARTICLES_PER_CELL 200


//starting with particle
typedef struct{
    //coordinate location
    int x,y,z;

    //cell number
    int cell;

}Particle;

typedef struct{
    //assume each cell has NUM_PARTICLES_PER_CELL particles
    Particle Particles[NUM_PARTICLES_PER_CELL];

    //quick check if the cell is full (mostly for setup)
    bool isFull;
}Cell;

int find_neighbors(const Cell *cellList);
int find_distance(const Particle A,const Particle B);
int setup_particles();





#endif //SENIORDESIGN_MD_HLSCONCEPTUAL_H
