

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "graph.h"

int main(void) {
  
  plotData calcPlotData;
  // plotData userData;

  printf("Initializing Calculator....\n");
  initializeGraph(&calcPlotData);
  // initializeGraph(&userData);

  setSin(&calcPlotData);

  printf("Displaying Calculator Output....\n");
  printGraph(calcPlotData);

  closeGraph(&calcPlotData);
  printf("Program Completed!\n");
  return 0;
}