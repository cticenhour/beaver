#include "LaplaceYoungMaterial.h"
#include <cmath>

registerMooseObject("BeaverApp", LaplaceYoungMaterial);

InputParameters
LaplaceYoungMaterial::validParams()
{
  InputParameters params = Material::validParams();
  params.addRequiredCoupledVar("coupled", "The coupled solution variable.");
  return params;
}

LaplaceYoungMaterial::LaplaceYoungMaterial(const InputParameters & parameters)
  : Material(parameters),
    _grad_v(adCoupledGradient("coupled")),
    _kay(declareADProperty<Real>("kay"))
{
}

void
LaplaceYoungMaterial::computeQpProperties()
{
  _kay[_qp] =
      1 / std::sqrt(1 + (_grad_v[_qp](0) * _grad_v[_qp](0) + _grad_v[_qp](1) * _grad_v[_qp](1) +
                         _grad_v[_qp](2) * _grad_v[_qp](2)));
}
