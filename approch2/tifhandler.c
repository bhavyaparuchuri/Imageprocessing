/*This module takes care of tif files*/

#include<stdio.h>
#include<string.h>
#include "handlers.h"

int tif_canHandle(char *filename)
{
	int len;
	char *end;
	printf("Checking whether we can handle %s\n",filename);
	len = strlen(filename);
	end = filename + (len - 3);
	printf("end = %s\n",end);
	if(strcmp(end,"tif")==0)
		return TRUE;
	else
		return FALSE;

}

int tif_drawImage(char *filename)
{
			printf(" How is this image %s \n", filename);
			return TRUE;
}

int tif_savefile(char *newfilename)
{
	printf("file saved by tif handler \n");
        return TRUE;
}
 imageHandler tifhandler ={
  	 tif_canHandle,
   	 tif_drawImage,
         tif_savefile
};
 
