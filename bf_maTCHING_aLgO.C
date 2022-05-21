/*pattern_matching_Using_Brute_Fource_Algorithm */
#include <stdio.h>
#include <String.h>
int BfMatching(char *t, char *p);
void main()
{
    char t[50],p[50];
    int index;
    printf("\nEnter some text \n\n");
    gets(t);
    printf("\nEnter some pattern\n\n");
    gets(p);
    index = BfMatching(t, p);
    if (index == -1)
    printf("\nGiven pattern is not present in text\n");
    else
      printf("\nFirst occurrence of pattern is present at index %d\n",index);
}
int BfMatching(char *t, char *p)
{
  int i,j,m,n;
  n = strlen(t);
  m = strlen(p);
  for(i = 0;i<=n-m;i++)
  {
    j = 0;
     while((j<m) && (t[i+j] == p[j]))
     {
       j++;
     }
      if(j==m)
      return i;
  }
  return -1;
}
