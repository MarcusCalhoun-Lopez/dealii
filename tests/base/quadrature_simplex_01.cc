// ---------------------------------------------------------------------
//
// Copyright (C) 1998 - 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------

// construct a simplex quadrature, and check that we can get an affine
// transformation out of it.

#include "../tests.h"
#include <deal.II/base/quadrature_lib.h>
#include <numeric>
#include "simplex.h"

template<int dim>
void test(int n)
{
  QSimplex<dim> quad(QIterated<dim>(QTrapez<1>(), n));

  deallog << "# dim = " << dim << std::endl;

  for (auto p:quad.get_points())
    deallog << p << std::endl;

  deallog << std::endl << "# Area: " << std::accumulate(quad.get_weights().begin(),
                                                        quad.get_weights().end(),
                                                        0.0) << std::endl << std::endl;

  auto quad2 = quad.compute_affine_transformation(get_simplex<dim>());

  for (auto p:quad2.get_points())
    deallog << p << std::endl;


  deallog << std::endl << "# Area 2: " << std::accumulate(quad2.get_weights().begin(),
                                                          quad2.get_weights().end(),
                                                          0.0) << std::endl << std::endl;

}


int main()
{
  initlog();

  test<1>(10);
  test<2>(10);
  test<3>(10);
}