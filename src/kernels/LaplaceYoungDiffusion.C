#include "LaplaceYoungDiffusion.h"

registerMooseObject("BeaverApp", LaplaceYoungDiffusion);

InputParameters
LaplaceYoungDiffusion::validParams()
{
  auto params = ADDiffusion::validParams();
  params.addClassDescription("Diffusion kernel for the Laplace-Young example.");
  return params;
}

LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters)
  : ADDiffusion(parameters)
{
}

ADRealVectorValue
LaplaceYoungDiffusion::precomputeQpResidual()
{
  return (1 / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp])) * ADDiffusion::precomputeQpResidual();
}
