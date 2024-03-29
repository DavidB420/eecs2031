/* Linear search header files. */
/* We define the two struct's for linear search */
/* David Badiei, Mar. 2024 */

#define MAXELMS 100
#define MAXCHARS 30

typedef struct linstruct *linptr;
typedef struct elmstruct *elmp;

struct linstruct {
  elmp data;
  int elmn;
};

struct elmstruct {
  char name[MAXCHARS];
  double val;
};

extern int lininsert(linptr lin, char *s, double v);
extern int linsrch(linptr lin, char *s, double *vp);
