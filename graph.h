
#ifndef GRAPH_INCLUDED
#define GRAPH_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

#define PI 3.1415f
#define PI_2 355.0f/113.0f

typedef unsigned int uit;

typedef struct plotData {
  size_t xLength;
  size_t yLength;
  char **coordData;
} plotData;

void initializeGraph(plotData *data);
void setPlotData(plotData *data);

void setSin(plotData *data, double omega);
void printGraph(plotData data);
void closeGraph(plotData *data);


#endif