/*
 * lagrange.hpp - Lagrange's Interpolation Polynomial
 *
 * Copyright (C) 2019 Lucas V. Araujo <lucas.vieira.ar@disroot.org> .
 *
 * This is free software: you are free to change and redistribute it under the
 * terms of GNU GPL license version 3 or, at your choice, any later version.
 * You should have received a copy of the license along with this software. If
 * not, you can read the full text at https://gnu.org/licenses/gpl.html.
 * This software is offered AS IT IS, in hope that it will be usefull, but there
 * is NO WARRANTY, to the extent permitted by law.
 */

#include <cmath>
#include <cstdio>
#include <vector>

#include "exception.hpp"

#ifndef  _LAGRANGE_H
#define  _LAGRANGE_H

#define valueType long double

using std::vector;

class Lagrange
{
private:

    /* The struct point will hold the coordinates of known points */
    struct point
    {
        valueType x;
        valueType y;
    };
    
    vector<point> pastData;
    
public:
    
    Lagrange()
    {
        
    }
    
    ~Lagrange()
    {
        
    }
    
    void
    loadData(const char *filename)
    {
        /* Given the name of a file, this function will load the data on it. */
        
        /* Open the file on read-only mode */
        FILE *file = fopen(filename, "r");

        /* Checks for errors opening the file */
        if (!file)
        {
            char error[100];
            sprintf(error, "Failed to open file %s", filename);
            throw GeneralException(error, __FILE__, __LINE__ - 5);
        }
        
        /* Keeps loading until the end of file is reached */
        while (!feof(file))
        {
            point p;
            /* The file must contain only numerical data, indicating the x and y
            coordinates of each known point, separated by spaces. So, each pair
            is stored on a struct point and then added to the pastData vector */
            fscanf(file, "%LF %LF", &p.x, &p.y);
            pastData.push_back(p);
        }
    }
    
    void
    interpolate(valueType x, valueType &result)
    {
        /*
            Interpolates a future value based on known previous points, by using
         Lagrange's Interpolation Polynomial. You should have received a file
         named maths.pdf along with this software, where the mathematical method
         is described. If not, search for the original source code on GitHub
         <https://github.com/lvmalware/>
         */
        
        result = 0;
        for (unsigned i = 0; i < pastData.size(); i++)
        {
            valueType L = 1;
            for (unsigned j = 0; j < pastData.size(); j++)
            {
                if (j != i)
                {
                    L *= (x - pastData[j].x) / (pastData[i].x - pastData[j].x);
                }
            }
            L *= pastData[i].y;
            result += L;
        }
    }
    
    valueType
    interpolate(valueType xCoord)
    {
        valueType y;
        interpolate(xCoord, y);
        return y;
    }
};

#endif /*_LAGRANGE_H*/