/* Linear search */
/* David Badiei, Mar. 2024 */

#define _CRT_SECURE_NO_WARNINGS //remove if not using msvc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <BaseTsd.h>

#include "linsrch.h"
#include "getline.h"

int main(int argc, char *argv[]) {
  int c;

  SSIZE_T nread;                /* Minor variant of the example          */
  size_t len = 0;               /* in the manual                         */
  char *line = NULL;            /* line is (or will be) a vector of char */
  char *name, *value;
  double numvalue;
  int lineno=0;
  struct linstruct DB;
  linptr DBp;
  struct elmstruct DBdata[MAXELMS];
  
  DBp = &DB;
  DBp->data = DBdata;
  DBp->elmn = 0;
  

  while ((nread = getline(&line, &len, stdin)) != -1) {
    lineno++;
    switch (*line){
    case 'I':
      c = line[1];
      if (c!=' ') {
	fprintf(stderr, "%s: expected space after 'I', not '%c'\n",
		argv[0], c);
	break;
      }
      name = line+1;
      while (*name==' ') name++;
      value = strchr(name, ' ');
      while (value!=NULL && value[-1]=='\\')
	value = strchr(value+1, ' ');
      if (value == NULL) {
	fprintf(stderr, "%s: expected space after name'\n", argv[0]);
	break;
      }
      *value++ = '\0';
      numvalue = atof(value);
      printf("Insert %s and %f\n", name, numvalue);
      lininsert(DBp, name, numvalue);
      break;
    case 'S':
      c = line[1];
      if (c!=' ') {
	fprintf(stderr, "%s: expected space after 'D', not '%c'\n",
		argv[0], c);
	break;
      }
      name = line+2;
      strchr(name+1,'\n')[0]='\0';
      printf("Search %s\n", name);
      if (linsrch(DBp, name, &numvalue)==-1){
	fprintf(stderr, "%s: name %s not found\n",
		argv[0], name);
	break;
      }
      printf("%s: %f\n", name, numvalue);
      break;
    default:
      fprintf(stderr, "%s: Unexpected command '%c'\n", argv[0], *line);
      break;
    }
  }
  return 0;
}
