/*
  ==============================================================================

    FourPointInterpolate.h
    Created: 4 Oct 2015 10:42:03pm
    Author:  Jacob Penn
    this is a four point interpolate function for use in conjunction with the 
    four point delay

  ==============================================================================
*/

#ifndef FOURPOINTINTERPOLATE_H_INCLUDED
#define FOURPOINTINTERPOLATE_H_INCLUDED

float FourPointInterpolate(float t0, float t_minus1, float t_1, float t_2, float fractional);

inline float dLinTerp(float x1, float x2, float y1, float y2, float x)
{
    float denom = x2 - x1;
    if(denom == 0)
        return y1; // should not ever happen
    
    // calculate decimal position of x
    float dx = (x - x1)/(x2 - x1);
    
    // use weighted sum method of interpolating
    float result = dx*y2 + (1-dx)*y1;
    
    return result;
    
}

//inline float Delay_interpolate( float y0, float y1, float y2, float y3, float mu)
//{
//    float c0 = y1;
//    float c1 = 0.5 * ( y2 - y0 );
//    float c2 = y0 - 2.5 * y1 + 2.0 * y2 - 0.5 * y3;
//    float c3 = 0.5 * ( y3 - y0 ) + 1.5 * ( y1 - y2 );
//    
//    return ( (c3 * mu + c2 ) * mu + c1 ) * mu + c0;
//}

#endif  // FOURPOINTINTERPOLATE_H_INCLUDED
