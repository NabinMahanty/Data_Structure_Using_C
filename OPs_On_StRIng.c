#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*PROTOTYPE*/
int strLen(char *charptr);
void strcopy(char *dest, char *source);
char *strConcatenate(char *dest, char *source);
int strCompare(char *str1, char *str2);
void strReveres(char *str1);
char *substrLeft(char *str1, int n);
char *substrRight(char *str1, int n);
char *substrMid(char *str1, int n, int m);
void toUpperCase(char *str1);
void tolowerCase(char *str1);
/*MAIN FUN*/
void main()
{
  char str1[] = "Structured";
  char str2[30] = "Programing";
  char temp[50] ;
  char *k;
  int m;
  printf("\nString length of str1 = %d\n",strLen(str1));
  strcopy(temp,str1);
  printf("\nCopied string = %s\n",temp);
  k = strConcatenate(temp,str2);
  printf("\nConcatenated String = %s\n",k);
  m = strCompare(str1, str2);
  if (m==0)
  printf("\nString are identical\n");
  else if (m>0)
  printf("\nString %s comes later than %s\n",str1,str2);
  else
    printf("\nString %s comes earlier than %s\n",str1,str2);
  printf("\nOriginal string = %s\n",str2);
  strReveres(str2);
  printf("\nReveres String = %s\n",str2);
  k = substrLeft(str1,5);
  printf("\nLeft substring = %s\n",k);
  k = substrRight(str1,5);
  printf("\nRight substring = %s\n",k);
  k = substrMid(str1, 8, 3);
  printf("\nMiddle substring = %s\n",k);
  toUpperCase(str1);
  printf("\nUpperCase string = %s\n",str1);
  tolowerCase(str1);
  printf("\nLowerCase string = %s\n",str1);
}

/*other fun*/
int strLen(char *charptr)
{
  int len = 0;
  while(*charptr++)
  len++;
  return len;
}

void strcopy(char *dest, char *source)
{
  char *ptr1, *ptr2;
  ptr1 = source;
  ptr2 = dest;
  while(*ptr1)
  {
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
  }
  *ptr2 = NULL;
}
char *strConcatenate(char *dest, char *source)
{
  char *ptr1, *ptr2;
  ptr1 = source;
  ptr2 = dest;
  while(*ptr1)
  {
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
  }
  *ptr2 = NULL;
  return dest;
}
int strCompare(char *str1, char *str2)
{
  char *ptr1, *ptr2;
  ptr1 = str1;
  ptr2 = str2;
  while((*ptr1 == *ptr2) && (*ptr1 && *ptr2))
  {
    ptr1++;
    ptr2++;
  }
  if(*ptr1 == NULL && *ptr2 == NULL)
  return 0;
  else if (*ptr1 == NULL)
  return -1;
  else if (ptr2 == NULL)
  return 1;
  else
    return (*ptr1 - *ptr2);
}
void strReveres(char *str1)
{
  char *ptr1, *ptr2, temp;
  ptr1 = str1;
  ptr2 = str1;
  while(*ptr2 != NULL)
    ptr2++;
    ptr2--;
    while(ptr1 < ptr2)
    {
      temp = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = temp;
      ptr1++;
      ptr2--;
    }
}
char *substrLeft(char *str1, int n)
{
  char *ptr1;
  char *temp, *ptr2 = NULL;
  ptr1 = str1;
  if(n == 0)
    return ptr2;
  temp = ptr2 = (char *)malloc((n+1)*sizeof(char));
  while((*ptr1) && (n>0))
  {
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
    n--;
  }
  *ptr2 = NULL;
  return temp;
}
char *substrRight(char *str1, int n)
{
  char *ptr1;
  char *temp, *ptr2 = NULL;
  ptr1 = str1;
  if(n == 0)
    return ptr2;
  temp = ptr2 = (char *)malloc((n+1)*sizeof(char));
  while(*ptr1++)
    ;
    ptr1 -=n+1;
  while(*ptr1)
  {
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
  }
  *ptr2 = NULL;
  return temp;
}
char *substrMid(char *str1, int n, int m)
{
  char *ptr1;
  char *temp, *ptr2 = NULL;
  ptr1 = str1;
  if(n == 0)
    return ptr2;
  temp = ptr2 = (char *)malloc((n+1)*sizeof(char));
  ptr1 +=m;
  while((*ptr1) && (n>0))
  {
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
    n--;
  }
  *ptr2 = NULL;
  return temp;
}
void toUpperCase(char *str1)
{
  char *ptr1;
  ptr1 = str1;
  while(*ptr1)
    {
      if((*ptr1 >= 'a') && (*ptr1 <= 'z'));
      *ptr1 -=32;
      ptr1++;
    }
}
void tolowerCase(char *str1)
{
  char *ptr1;
  ptr1 = str1;
  while(*ptr1)
    {
      if((*ptr1 >= 'A') && (*ptr1 <= 'Z'));
      *ptr1 +=32;
      ptr1++;
    }
}
