

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "graph.h"

int main(void) {
  
  plotData calcPlotData;
  double omega = 0.0f;
  // plotData userData;

  printf("Initializing Calculator....\n");
  initializeGraph(&calcPlotData);
  // initializeGraph(&userData);
  printf("Please specify the omega coefficient: ");
  scanf("%lf", &omega);
  
  setSin(&calcPlotData, omega);

  printf("Displaying Calculator Output....\n");
  printGraph(calcPlotData);

  closeGraph(&calcPlotData);
  printf("Program Completed!\nPress [Enter] to exit");

  while ((getchar()) != '\n'); 
  getchar(); 
  return 0;
}