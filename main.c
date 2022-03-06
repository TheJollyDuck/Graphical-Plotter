

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "graph.h"

int main(void) {
  
  graph_plotData calcPlotData;
  // double omega = 0.0f;
  // graph_plotData userData;

  printf("Initializing Calculator....\n");
  graph_initialize(&calcPlotData);
  // initializeGraph(&userData);
  //printf("Please specify the omega coefficient: ");
  //scanf("%lf", &omega);
  
  // graph_setSin(&calcPlotData, omega);
  graph_sin2Coords(&calcPlotData);

  printf("Displaying Calculator Output....\n");
  graph_printGraph(calcPlotData);

  graph_closeGraph(&calcPlotData);
  printf("Program Completed!\nPress [Enter] to exit");

  while ((getchar()) != '\n'); 
  getchar(); 
  return EXIT_SUCCESS;
}