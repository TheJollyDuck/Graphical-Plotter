/*
 * TheJollyDuck
 *
 * Graph Plotter Header
 *
 * This header file contains all the necessary constants, type and function
 * declarations for the code regarding the plotting of the functions.
 *
 *
 *
 *
 *
 *
 *
 *
 */



#ifndef GRAPH_INCLUDED
#define GRAPH_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

#define PI 3.1415f
#define PI_2 355.0f/113.0f

typedef unsigned int uit;

typedef struct graph_plotData {
  size_t xLength;
  size_t yLength;

  short amplitude;
  short frequency;

  char lineChar;
  char graphBackground;
  char **coordData;
} graph_plotData;

void graph_initialize(graph_plotData *);
void graph_setPlotData(graph_plotData *);

//void graph_setSin(graph_plotData *, double);
void graph_setWave(graph_plotData *);
void graph_sin2Coords(graph_plotData *);
void graph_printGraph(graph_plotData);
void graph_closeGraph(graph_plotData *);


#endif