#pragma once

#include "ADDiffusion.h"

class LaplaceYoungDiffusion : public ADDiffusion
{
public:
  static InputParameters validParams();

  LaplaceYoungDiffusion(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
};
