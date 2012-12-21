#include "util.h"

void openFiles(FILE* fp[][NB_SCRIPTS], int currentGen, int nbScripts)
{
  for(int i=0; i<nbScripts; i++)
  {
    char filename[15];
    sprintf(filename, "generation%d_%d", currentGen, i);
    fp[currentGen][i] = fopen(filename, "w+");
    assert(fp[currentGen][i] != NULL);
  }
}

void delayed_start(int delay)
{
  printf("Starting in %d\n", delay);
  for(int i=delay-1; i>0; i--)
  {
    sleep(1);
    printf("%d..\n", i);
  }
  sleep(1);
  printf("Go !\n");
}
