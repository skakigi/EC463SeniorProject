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

//basic building block parameters
#define NUM_PARTICLES_PER_CELL 200
#define NUM_CELLS 100
#define CELL_SIZE_DIMENSION 10
#define GRID_SIZE_DIMENSION 1000
#define CELL_COUNT_ACROSS GRID_SIZE_DIMENSION/CELL_SIZE_DIMENSION
#define TOTAL_PARTICLE_COUNT NUM_PARTICLES_PER_CELL * NUM_CELLS
#define TOTAL_CELL_COUNT (int)(pow(GRID_SIZE_DIMENSION,3)/pow(CELL_SIZE_DIMENSION,3))

//properties of particles
#define EXCLUSION_RADIUS 1

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

    int nextIndex;

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
int convert_cellX_to_coordinate(Cell *cell){
    return cell->x*CELL_SIZE_DIMENSION;
}
void init(Particle *particleList,Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]);
void initCellList(Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]);
//Constructors

/* ---------------------------------  Random Creation  --------------------------------- */
/* This is a randomly generated particle method but will fail to use exclusion principle */
Particle setup_particle_random(){


    srand((unsigned int)time(NULL));

    Particle particle;
    particle.x = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;
    particle.y = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;
    particle.z = ((float)rand()/(float)(RAND_MAX)) * GRID_SIZE_DIMENSION;

    particle.cell = -1;


    return particle;
}

/* ---------------------------------  Ordered Creation  --------------------------------- */
/* This is an ordered creation that will start with exclusion principle in mind | will run the same if parameters are not changed */

void setup_particle_ordered(int cellNum,Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS],Cell *currCell){
    /* we need to initialize all particles in currCell */
    float currX = 0;
    float currY = 0;
    float currZ = 0;
    for(int i = 0; i<NUM_PARTICLES_PER_CELL; i++){
        Particle currParticle;
        if(currX!=CELL_SIZE_DIMENSION){

            float xConvert = currX + currCell->x*CELL_SIZE_DIMENSION;
            float yConvert = currY + currCell->y*CELL_SIZE_DIMENSION;
            float zConvert = currZ + currCell->z*CELL_SIZE_DIMENSION;

            set_particle_coordinate(&currParticle,xConvert,yConvert,zConvert);
            currCell->Particles[currCell->nextIndex] = currParticle;
            currCell->nextIndex++;

            currX+=EXCLUSION_RADIUS;
        }
        else if(currY!=CELL_SIZE_DIMENSION){
            currX=0;
            currY+=EXCLUSION_RADIUS;

            float xConvert = currX + currCell->x*CELL_SIZE_DIMENSION;
            float yConvert = currY + currCell->y*CELL_SIZE_DIMENSION;
            float zConvert = currZ + currCell->z*CELL_SIZE_DIMENSION;

            set_particle_coordinate(&currParticle,xConvert,yConvert,zConvert);
            currCell->Particles[currCell->nextIndex] = currParticle;
            currCell->nextIndex++;

            currX+=EXCLUSION_RADIUS;
        }
        else{
            currX = 0;
            currY = 0;
            currZ +=EXCLUSION_RADIUS;

            float xConvert = currX + currCell->x*CELL_SIZE_DIMENSION;
            float yConvert = currY + currCell->y*CELL_SIZE_DIMENSION;
            float zConvert = currZ + currCell->z*CELL_SIZE_DIMENSION;


            set_particle_coordinate(&currParticle,xConvert,yConvert,zConvert);
            currCell->Particles[currCell->nextIndex] = currParticle;
            currCell->nextIndex++;

            currX+=EXCLUSION_RADIUS;
        }
    }
}





#endif //SENIORDESIGN_MD_HLSCONCEPTUAL_H
