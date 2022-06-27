#include<stdio.h>
#include<string.h>
#include<dirent.h>

void ls(char *dirpath);

int main(int argc, char *argv[])
{
   int i;

  if(argc < 2){
    ls(".");
    exit(0);
  }
  for(i=1; i<argc; i++)
    ls(argv[i]);
  exit(0);
}

void ls(char *dirpath)
{
    DIR *pDir;
    struct dirent *pdirent;

    if((pDir=opendir(dirpath)) == NULL)
    {
        fprintf(stderr,"ls1:cannot open %s\n",dirpath);
    }
    else
    {
        while((pdirent=readdir(pDir)) != NULL)
        {
            if (strcmp(pdirent->d_name, ".") == 0 || strcmp(pdirent->d_name, "..") == 0)
            {
                continue;
            }
            printf("%s\n", pdirent->d_name);
        }
        closedir(pDir);
    }
}