#pragma once

#include "Material.h"

/**
 * Calculates material properties corresponding to the Laplace-Young hands-on example.
 */
class LaplaceYoungMaterial : public Material
{
public:
  static InputParameters validParams();

  LaplaceYoungMaterial(const InputParameters & parameters);

protected:
  /// Necessary override. This is where the values of the properties are computed.
  virtual void computeQpProperties() override;

  /// The coupled solution variable
  const ADVariableGradient & _grad_v;

  /// Diffusivity coefficient
  ADMaterialProperty<Real> & _kay;
};
