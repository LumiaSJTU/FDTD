//
// Created by LoveStu on 2016/12/24.
//

#include <stdio.h>
#include <math.h>

#define SIZE 200

int main()
{
    double ez[SIZE] = {0.}, hy[SIZE] = {0.}, imp0 = 377.0;
    int qTime, maxTime = 200, mm;

    char basename[80] = "sim", filename[100];
    int frame = 0;
    FILE *snapshot;

    for (qTime = 0; qTime < maxTime; qTime++)
    {
        for (mm = 0; mm < SIZE - 1; mm++)
            hy[mm] = hy[mm] + (ez[mm + 1] -ez[mm]) / imp0;

        for (mm = 1; mm < SIZE; mm++)
            ez[mm] = ez[mm] + (hy[mm] - hy[mm - 1]) * imp0;

        ez[50] += exp(-(qTime - 30.) * (qTime - 30.) / 100.);

        if (qTime % 10 == 0)
        {
            sprintf(filename, "%s%d.txt", basename, frame++);
            snapshot = fopen(filename, "w");
            for (mm = 0; mm < SIZE; mm++)
                fprintf(snapshot, "%g\n", ez[mm]);
            fclose(snapshot);
        }
    }

    return 0;
}