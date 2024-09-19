//
// Created by sorak on 9/18/2024.
//

//.h file
#include "MD_HLSConceptual.h"

/*--------------------- functions start below ---------------------*/
//error handler
void handleError(const char *message){
    fprintf(stderr, "Error: %s\n",message);
    exit(EXIT_FAILURE);
}

void init(Particle *particleList, Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]){

    //checking if particle and cell lists exist
    if(particleList == NULL){
        handleError("particleList is NULL : failed to init\n");
    }
    if(cellList == NULL){
        handleError("cellList is NULL : failed to init\n");
    }
    //setup all the particles
    for(int i=0; i<TOTAL_PARTICLE_COUNT; i++){

        //setup particle in MD_HLSConceptual.h
        particleList[i] = setup_particle();
    }

    //setup all the cells
    for(int z=0; z<CELL_COUNT_ACROSS;z++){
        for(int y=0; y<CELL_COUNT_ACROSS;y++){
            for(int x=0; x<CELL_COUNT_ACROSS;x++){
                //for each cell (x,y,z) setup cell
                set_cell_coordinate(&(cellList[x][y][z]),x,y,z);
                cellList[x][y][z].isFull=false;
            }
        }
    }

    //organize particles into cells



}

int main(){
    Particle particleList[TOTAL_PARTICLE_COUNT];
    Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS];
    init(particleList,cellList);



}