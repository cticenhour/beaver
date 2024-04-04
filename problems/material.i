[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diff]
    type = ADMatDiffusion
    variable = u
    diffusivity = kay
  []
  [rxn]
    type = ADReaction
    variable = u
    rate = 1
  []
[]

[BCs]
  [all]
    type = ADNeumannBC
    variable = u
    boundary = 'left right top bottom'
    value = 0.2
  []
[]

[Materials]
  [ly]
    type = LaplaceYoungMaterial
    coupled = u
  []
[]

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
