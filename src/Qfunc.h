/******************************************************************************
* FILE: Qnorm.h
* ots@ac.uma.es
* LAST REVISED: 23/02/09
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXLIN   1000
#define MAXnP    4
#define NGEN     15
#define NEXP     2
#define max(a,b)    (((a)>(b)) ? (a):(b))
#define min(x,y)    (((x) < (y)) ? (x) : (y))


struct Files { // LIst of files
   char *fname;
   int nG;
   char fType;
   int pos;
};

struct Average { // Average array
   double Av;
   int num;
};


struct params {// Parameters struct-----------------
  int  nP;                  // number of nodes
  char fListName[MAXLIN];   // file with a list of files
  char fOutName[MAXLIN];    // Output file name
  int  Traspose;            // Traspose file to file final results (0:NOT 1:Yes)
  int  MemIndex;            // store Index in (1) memory or (0) in disk
  int  nG;                  // Number of Genes (rows)
  int  nE;                  // Number of Experiments or samples(cols)
  int  Verbose;             // Not(0) (default) / yes (1)
};

// Function protorypes------------------------------------------

// general functions
struct params *CommandLine(int, char **);
struct Files* LoadListOfFiles(struct params *);
void LoadFile(struct Files*, int, double *);
void terror(char *);
void Alerta(char *,char *);

void DebugPrint(char *, int, double*, int); 
int  TransposeBin2Txt(struct params*, char**);
void QsortC(double *array,int l,int r,int *index);
int partition( double* a, int l, int r, int *indexes);

// related to Qnorm
void QNormMain(struct params*, struct Files*);
void AccumulateRow(struct Average *, double *, int);
int Qnorm1(double *, int *, int);

char ** LoadprobeID(struct Files*, struct params *);

// ===============================================================================
