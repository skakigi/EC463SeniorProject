//
// Created by sorak on 9/18/2024.
//

//.h file
#include "MD_HLSConceptual.h"
#define RANDOM_PARTICLE_GEN true

/*--------------------- functions start below ---------------------*/
//error handler
void handleError(const char *message){
    fprintf(stderr, "Error: %s\n",message);
    exit(EXIT_FAILURE);
}
void initCellList(Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]){
    /* Setup Cell Blocks in Grid */
    for (int z = 0; z < CELL_COUNT_ACROSS; z++) {
        for (int y = 0; y < CELL_COUNT_ACROSS; y++) {
            for (int x = 0; x < CELL_COUNT_ACROSS; x++) {
                //for each cell (x,y,z) setup cell
                set_cell_coordinate(&(cellList[x][y][z]), x, y, z);
                cellList[x][y][z].isFull = false;
                cellList[x][y][z].nextIndex = 0;
            }
        }
    }
}
void init(Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS]){

    //checking if particle and cell lists exist
    if(cellList == NULL){
        handleError("cellList is NULL : failed to init\n");
    }


    /* initialize cell list */
    initCellList(cellList);

    /* This section uses random particles */
    if(RANDOM_PARTICLE_GEN) {
        /* iterate through the cell list */
        for(int x=0;x<CELL_COUNT_ACROSS;x++){
            for(int y=0;y<CELL_COUNT_ACROSS;y++){
                for(int z=0;z<CELL_COUNT_ACROSS;z++){
                    Cell currCell = cellList[x][y][z];
                    for(int p=0;p<NUM_PARTICLES_PER_CELL;p++){
                        Particle currParticle = setup_particle_random(&currCell);
                        int nextIndex = currCell.nextIndex;
                        currCell.Particles[nextIndex] = currParticle;
                    }
                }
            }
        }


        /* Generate all particles randomly */
        /* -----out of order----- probably will scrap this method
        for (int i = 0; i < TOTAL_PARTICLE_COUNT; i++) {
            particleList[i] = setup_particle_random();
            float currPartX = particleList->x;
            float currPartY = particleList->y;
            float currPartZ = particleList->z;

            int cellX = (int)(currPartX/CELL_SIZE_DIMENSION);
            int cellY = (int)(currPartY/CELL_SIZE_DIMENSION);
            int cellZ = (int)(currPartZ/CELL_SIZE_DIMENSION);

            int nextIndex = cellList[cellX][cellY][cellZ].nextIndex;

            //there are probably out of bounds issues with this atm
            if(nextIndex!=199) {
                cellList[cellX][cellY][cellZ].Particles[nextIndex] = particleList[i];
                cellList[cellX][cellY][cellZ].nextIndex++;
            }
        }
        */
    }
    /* this section uses ordered particle start */
    else{
        for (int z = 0; z < CELL_COUNT_ACROSS; z++) {
            for (int y = 0; y < CELL_COUNT_ACROSS; y++) {
                for (int x = 0; x < CELL_COUNT_ACROSS; x++) {
                    setup_particle_ordered(&cellList[x][y][z]);
                }
            }
        }
    }




}

int main(){
    //instantiate cellList and setup particles
    Cell cellList[CELL_COUNT_ACROSS][CELL_COUNT_ACROSS][CELL_COUNT_ACROSS];
    init(cellList);





}