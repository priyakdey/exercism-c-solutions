#include "complex_numbers.h"

#include <math.h>
#include <stdio.h>

#define PI acos(-1)
#define E exp(1)


complex_t c_add(complex_t a, complex_t b)
{
   // (a + i * b) + (c + i * d) = (a + c) + (b + d) * i
   double p = a.real, q = a.imag;
   double r = b.real, s = b.imag;

   complex_t c = {
      .real = p + r,
      .imag = q + s
   };
   return c;
}

complex_t c_sub(complex_t a, complex_t b)
{
   // (a + i * b) - (c + i * d) = (a - c) + (b - d) * i
   double p = a.real, q = a.imag;
   double r = b.real, s = b.imag;

   complex_t c = {
      .real = p - r,
      .imag = q - s
   };
   return c;
}

complex_t c_mul(complex_t a, complex_t b)
{
   // (a + i * b) * (c + i * d) = (a * c - b * d) + (b * c + a * d) * i
   double p = a.real, q = a.imag;
   double r = b.real, s = b.imag;

   complex_t c = {
      .real = (p * r) - (q * s),
      .imag = (q * r) + (p * s)
   };

   return c;
}

complex_t c_div(complex_t a, complex_t b)
{
   // (a + i * b) / (c + i * d) = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i
   double p = a.real, q = a.imag;
   double r = b.real, s = b.imag;

   double denom = (r * r) + (s * s);

   complex_t c = {
      .real = ((p * r) + (q * s)) / denom,
      .imag = ((q * r) - (p * s)) / denom
   };

   return c;
}

double c_abs(complex_t x)
{
   return sqrt((x.real * x.real) + (x.imag * x.imag));
}

complex_t c_conjugate(complex_t x)
{
   complex_t c = {
      .real = x.real,
      .imag = -x.imag
   };

   return c;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t c = { 0 };
   c.real = pow(E, x.real) * cos(x.imag);
   c.imag = pow(E, x.real) * sin(x.imag);
   return c;
}
