#include "complex_numbers.h"

// (a + i * b) + (c + i * d) = (a + c) + (b + d) * i
complex_t c_add(complex_t a, complex_t b)
{
   complex_t c = {
      .real = a.real + b.real,
      .imag = a.imag + b.imag
   };
   return c;
}

// (a + i * b) - (c + i * d) = (a - c) + (b - d) * i
complex_t c_sub(complex_t a, complex_t b)
{
   complex_t c = {
      .real = a.real - b.real,
      .imag = a.imag - b.imag
   };
   return c;
}

// (a + i * b) * (c + i * d) = (a * c - b * d) + (b * c + a * d) * i
complex_t c_mul(complex_t a, complex_t b)
{
   complex_t c = {
      .real = (a.real * b.real) - (a.imag * b.imag),
      .imag = (a.imag * b.real) + (a.real * b.imag)
   };
   return c;
}

// (a + i * b) / (c + i * d) = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i
complex_t c_div(complex_t a, complex_t b)
{

   ((a.real * b.real) + (a.imag * b.imag)) / ()
}

double c_abs(complex_t x)
{
   // TODO: implement
}

complex_t c_conjugate(complex_t x)
{
   // TODO: implement
}

double c_real(complex_t x)
{
   // TODO: implement
}

double c_imag(complex_t x)
{
   // TODO: implement
}

complex_t c_exp(complex_t x)
{
   // TODO: implement
}
