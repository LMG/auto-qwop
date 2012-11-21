#include "input.h"

void readString(char *chaine, int nbChar)
{
	char *retourChariot = NULL;
	
	fgets(chaine, nbChar, stdin);
	
	retourChariot=strchr(chaine, '\n');
	if(retourChariot==NULL)//si on ne trouve pas la fin de chaine, il faut vider le buffer
	{
		flushBuffer();
	}
	else//sinon il faut le retirer
	{
		*retourChariot='\0';
	}
}

int readNumber(int nbDigits)
{
	char *retourChariot = NULL;
	char chaine[nbDigits+1];
	
	fgets(chaine, nbDigits+1, stdin);
	
	printf("%s, %d\n", chaine, atoi(chaine));
	
	retourChariot=strchr(chaine, '\n');
	if(retourChariot==NULL)//si on ne trouve pas la fin de chaine, il faut vider le buffer
	{
		flushBuffer();
	}
	
	return atoi(chaine);
}

void flushBuffer()
{
	char c=0;
	
	while(c != EOF && c != '\n')//tant qu'on n'a pas rencontré un caractere indiquant la fin d'une saisie clavier ou la fin du fichier stdin on lit le caractere suivant
	{
		c = getchar();
	}
}
