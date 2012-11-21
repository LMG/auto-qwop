#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define DELAY 3
#define MAXLINES 100
#define MAXSLEEP 3
#define TIMEOUT 10
#define NB_SCRIPTS 10
enum{QWOP, SLEEP, GOTO};
enum{Q, W, O, P};


void delayed_start(int delay)
{
  printf("Starting in %d\n", DELAY);
  for(int i=delay-1; i>0; i--)
  {
    sleep(1);
    printf("%d..\n", i);
  }
  sleep(1);
  printf("Go !\n");
}

void randInit(FILE* fp)
{
  int nbLines = rand()%MAXLINES;
  int letter;
  for(int i=0; i<nbLines; i++)
  {
    /* Format:
     * nbLines
     * expr
     * ..
     * 
     * With: 
     * expr := ((Q|W|O|P) (UP|DOWN)) |
     * 		SLEEP(N) |
     *		GOTO L
     *
     * With N in 0 MAXSLEEP
     * L in 0 MAXLINES
     */
     switch(rand()%3)
     {
       case QWOP:
        switch(rand()%4)
        {
          case Q:
           letter='Q';
           break;
          case W:
           letter='W';
           break;
          case O:
           letter='O';
           break;
          case P:
           letter='P';
           break;
         }
         fprintf(fp, "%c %s\n", letter, rand()%2?"UP":"DOWN");
         break;
        case SLEEP:
         fprintf(fp, "SLEEP %d\n", rand()%MAXSLEEP);
         break;
        case GOTO:
         fprintf(fp, "GOTO %d\n", rand()%nbLines);
         break;
     }
  }
}

void run(FILE* fp, Display* display)
{
    int nbLines;
    rewind(fp);
    fscanf(fp, "%d\n", &nbLines);
    char line[30];
    char *word, *context;
    int key;
    unsigned int keycode;
    time_t beginTime = time(NULL), currentTime = time(NULL);

    for(int i=0; i<nbLines && difftime((currentTime = time(NULL)),beginTime)<TIMEOUT; i++)
    {
	fgets(line, 30, fp);
	word=strtok_r(line, " ", &context);
	if(strcmp(word, "SLEEP")==0)
	{
	  int sleepTime = atoi(context);
	  printf("Sleep %d\n", sleepTime);
	  sleep(sleepTime);
	}
	else if(strcmp(word, "GOTO")==0)
	{
	  int destLine = atoi(context);
	  printf("Goto %d\n", destLine);
	  rewind(fp);
	  int j;
	  for(j=0; j<destLine-1; j++, fgets(line, 30, fp));
	  i=j;
	}
	else//QWOP
	{
	 if(strcmp(word, "Q")==0)
	   key=XK_Q;
	 else if(strcmp(word, "W")==0)
	   key=XK_W;
	 else if(strcmp(word, "O")==0)
	   key=XK_O;
	 else if(strcmp(word, "P")==0)
	   key=XK_P;
	 else
	   key=XK_A;

	 if(strcmp(context, "UP\n")==0)
	 {
	   printf("%s, UP !\n", word);
  	   keycode = XKeysymToKeycode(display, key);
  	   XTestFakeKeyEvent(display, keycode, False, 0);
  	   XFlush(display);
	 }
	 else if(strcmp(context, "DOWN\n")==0)
	 {
	   printf("%s, DOWN !\n", word);
  	   keycode = XKeysymToKeycode(display, key);
  	   XTestFakeKeyEvent(display, keycode, True, 0);
  	   XFlush(display);
	 }
	 else
	 {
	   printf("Uh?\n");
	 }
	}
    }

    if(difftime(currentTime,beginTime)>=TIMEOUT)
      printf("Timeout\n");
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
  FILE* fp[NB_SCRIPTS];
  for(int i=0; i<NB_SCRIPTS; i++)
  {
    fp[i] = fopen("generation", "w+");
    assert(fp[i] != NULL);
  }
  
  printf("Init done\n");
 
  delayed_start(DELAY); 

  printf("Starting generation\n");
  //first generation

  //for all files
  for(int file=0; file<NB_SCRIPTS; file++)
  {
    randInit(fp[file]);
  }

  //Genetic improvement !
  float mark[NB_SCRIPTS]={0}; //number of meters
  while(1)
  {
    //run generations
    for(int i=0; i<NB_SCRIPTS; i++)
    {
      run(fp[i], display);
    }


    //evolve
  }

  printf("Nettoyage\n");

  for(int i=0; i<NB_SCRIPTS; i++)
  {
    fclose(fp[i]);
  }

  return 0;
}
