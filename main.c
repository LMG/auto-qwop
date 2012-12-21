#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "input.h"
#include "util.h"
#include "constants.h"

int sort(const void* x, const void* y)
{
  return (*(int *)x - *(int *)y);
}

int main(int argc, char *argv[])
{
  printf("Init \n");

  //X
  Display *display;
  display = XOpenDisplay(NULL);
  assert(display != NULL);

  //rand
  srand(time(NULL));

  //files
  int currentGen=0;
  FILE* (fp[NB_GENS][NB_SCRIPTS]);
  openFiles(fp, currentGen, NB_SCRIPTS);
  
  printf("Init done\n");
 
  printf("Starting generation\n");
  //first generation

  //for all files (first gen)
  for(int file=0; file<NB_SCRIPTS; file++)
  {
    randInit(fp[0][file]);
  }

  //Genetic improvement !
  float mark[NB_SCRIPTS]={0}; //number of meters
  for(int gen=0; gen<NB_GENS; gen++)
  {
    //run&grade current generation
    for(int i=0; i<NB_SCRIPTS; i++)
    {
      delayed_start(DELAY); 
      run(fp[gen][i], display);
      char answer[10];
      printf("Enter algorithm %d mark: ", i);
      readString(answer, 10);
      mark[i]=atof(answer);
    }

    for(int i=0; i<NB_SCRIPTS; i++)
    {
      printf("%d: %f meters\n", i, mark[i]);
    }

    getchar();

    //evolve
    qsort(mark, NB_SCRIPTS, sizeof(int), sort);
    for(int i=NB_SCRIPTS-1; i>=0; i--)
    {
    	printf("YOUHOU\n");
    }
  }

  printf("Nettoyage\n");

	for(int j=currentGen-1; j>=0; j--)
	{
		for(int i=0; i<NB_SCRIPTS; i++)
		{
		  fclose(fp[j][i]);
		}
	}

  return 0;
}
