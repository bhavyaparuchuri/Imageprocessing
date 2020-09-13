#include<stdio.h>
#include<stdlib.h>
#include"handler.h"

int vdrawimage(char *filename)
{
    if(canHandle(filename))
    {
 		printf("how is this image %s\n",filename);
                return TRUE;
    else
		return FAlse;
    }

}

int vsavefile(char *newfile)
{
   printf("the  file is changed by ");
   TRUE;
}

int findhandler(char *file)
{

 
