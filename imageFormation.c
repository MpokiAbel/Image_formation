#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "imageFormationUtils.h"

struct point2d
{
    float x; // If you want to access x, you need to do p.x, suppose you decleared p as "struct point3d p;"
    float y; // Similar to above
    int r;
    int g;
    int b;
};

struct point2d *pinhole_projection(struct point3d *points, float f, int N_v)
{
    struct point2d *dpoints;

    dpoints = (struct point2d *)malloc(N_v * sizeof(struct point2d));

    for (int i = 0; i < N_v; i++)
    {
        dpoints[i].x = points[i].x / (1 + points[i].z / f);
        dpoints[i].y = points[i].y / (1 + points[i].z / f);
        dpoints[i].r = points[i].r;
        dpoints[i].g = points[i].g;
        dpoints[i].b = points[i].b;
    }

    return dpoints;
}

int main(int argc, char *argv[])
{
    struct point3d *points;
    struct point2d *dpoints;
    {
        /* data */
    };

    int N_v = 8073;

    if (argc != 2)
    {
        fprintf(stderr, "usage : %s filename\n", argv[0]);
        exit(-1);
    }

    points = readOff(argv[1], &N_v);

    dpoints = pinhole_projection(points, 1.0, N_v);


    //  centerThePCL(points, N_v);
}