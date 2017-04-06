#include "remove_pbc.h"

/**
 * This function unwraps periodic boundary conditions
 **/

void remove_pbc(float& boxlength, double& coord, double& prevcoord)
{
  double stepdiff = coord - prevcoord;
  double halfbox = boxlength / 2.0;
  while (stepdiff >= halfbox)
    {
      if (stepdiff > halfbox)
        {
          coord = coord - boxlength;
        }
      else if (stepdiff < -halfbox)
        {
          coord = coord + boxlength;
        }
      stepdiff = coord - prevcoord;
    }
}

double separation(double& val1, double& val2, float& boxlength)
/**
 * This calculates the difference between two values then modifies based on pbc
 **/
{
  double dr = 0.0;
  dr = val1 - val2;
  // handle pbc
  if (dr > boxlength/2.0)
    {
      dr = boxlength - dr;
    }
  else if (dr < -boxlength/2.0)
    {
      dr = boxlength + dr;
    }
  return dr;
}

int distance(double& dx, double& dy, double& dz, float dd)
/**
 * Calculates the absolute distance between coordinates
 **/
{
  double d = 0;
  int d_bin = 0;
  d = sqrt(pow(dx,2) + pow(dy,2) + pow(dz,2));
  d_bin = floor(d/dd);
  return d_bin;
}

