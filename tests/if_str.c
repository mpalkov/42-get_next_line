#include <stdio.h>

int main()
{
  char *ptr = NULL;
  char *nnn = "";
  
  printf("ptr = %s\nnnn = %s.\n", ptr, nnn);
  
  // TRUE
  if (!ptr)
    printf("!ptr\n");

  //FALSE
  if (!nnn)
    printf("!nnn\n");

  //TRUE
  if (!nnn[0])
    printf("!nnn[0]\n");
  return 0;
}
