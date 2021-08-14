
#include "graph.h"

void initializeGraph(plotData *data) {

  /* Initializing the display resolution */
  setPlotData(data);
  // data->xLength = 120;
  // data->yLength = 80;

  /* Initializing the dynamic array */

  data->coordData = malloc((data->yLength) * sizeof(char*));

  for (uit i = 0; i < data->yLength; i++) {
    for (uit j = 0; j < data->xLength; j++) {
      data->coordData[i] = malloc(data->xLength * sizeof(char));
    }
  }

  /* Initiazling the graph data so the values are expected */
  for (uit i = 0; i < data->yLength; i++) {
    for (uit j = 0; j < data->xLength; j++) {
      data->coordData[i][j] = ' ';
    }
  }
}

void setPlotData(plotData *data) {
  printf("Please type in resolution of graph...\n");

  printf("Length: ");
  scanf("%llu", &data->xLength);

  printf("Height: ");
  scanf("%llu", &data->yLength);
}

void setSin(plotData *data, double omega) {

  /* Creates temporary storage of output of the sin function*/
  double *tempValues;
  tempValues = malloc((data->xLength) * sizeof(double));

  /* Finds where the axis is on the plot data */
  uit axis = ((uit)(data->yLength)/2) +1;

  /* Finds the positive and negative Y halves*/
  uit topHalf = data->yLength - axis;
  // uit bottomHalf = data->yLength - topHalf;

  /* Finds the peak of the sin function */
  double maxValue = 0;

  /* Calculates the output of sin per x position */
  for (uit i = 0; i < data->xLength; i++) {

    /* Cos and Sin have been tested to work*/
    tempValues[i] = sin(omega *i *PI_2);
    // tempValues[i] = cos(0.035*i*PI_2);

    /* Condition to find the maximum value / peak of the sin output */
    if (tempValues[i] > maxValue) {
      maxValue = tempValues[i];
    }
  }
  
  /* Increases the Max Value by 1 */
  maxValue++;

  /* Finds the value per interval for the graph*/
  double valPerPos = maxValue / (topHalf * 2);
  double position = valPerPos;

  /* Optional X Axis*/
  // for (uit k = 0; k < data->xLength; k++) {
  //   data->coordData[axis][k] = 223;
  // }

  for (uit i = 0; i < data->xLength; i++) {

    position = 0;

    int j;
    if (tempValues[i] > position) {

      for (j = topHalf; tempValues[i] > position; j--) {
      position += valPerPos;
      }

    } else {
      for (j = topHalf; tempValues[i] < position; j++) {
      position -= valPerPos;
      }
    }
    data->coordData[j][i] = 219;
  }
  /* frees the dynamically allocated array */
  free(tempValues);
}

void printGraph(plotData data) {
  printf("\n");

  for (uit i = 0; i < data.yLength; i++) {
    for (uit j = 0; j < data.xLength; j++) {
      printf("%c", data.coordData[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

void closeGraph(plotData *data) {

  for (uit i = 0; i < data->yLength; i++) {
      free(data->coordData[i]);
  }

  free(data->coordData);
}


/* BACKUPS */

// void setSin(plotData *data) {

//   /* Creates temporary storage of output of the sin function*/
//   double *tempValues;
//   tempValues = malloc((data->xLength) * sizeof(double));

//   /* Finds where the axis is on the plot data */
//   uit axis = ((uit)(data->yLength)/2) +1;

//   /* Finds the positive and negative Y halves*/
//   uit topHalf = data->yLength - axis;
//   uit bottomHalf = data->yLength - topHalf;

//   /* Finds the peak of the sin function */
//   double maxValue = 0;

//   /* Calculates the output of sin per x position */
//   for (uit i = 0; i < data->xLength; i++) {
//     tempValues[i] = sin(0.1 *i *PI);

//     /* Condition to find the maximum value / peak of the sin output */
//     if (tempValues[i] > maxValue) {
//       maxValue = tempValues[i];
//     }
//   }

//   // /* Rounds the max value for graphical processing */
//   // uit roundedMaxVal = ((uit)maxValue) +1;
  
//   /* TEMP testing maxValue instead of roundedMaxVal*/
//   maxValue++;

//   /* Finds the value per interval for the top half, assuming the bottom half is the same or larger */
//   // double valPerPos = roundedMaxVal/topHalf;
//   double valPerPos = maxValue / topHalf;
//   double position = valPerPos;

//   for (uit i = 0; i < data->xLength; i++) {

//     position = valPerPos;

//     int j = 1;
//     for (j = 1; tempValues[i] > position; j++) {
//       position += valPerPos;
//     }
//     data->coordData[j][i] = 'x';

//     // while(true) {

//     //   if (tempValues[i] > position) {
//     //     data->coordData[][i] = 'x';
//     //     break;

//     //   } else {
//     //     
//     //   }
//     // }
//   }

//   /* frees the dynamically allocated array */
//   free(tempValues);
// }