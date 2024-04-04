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
    type = LaplaceYoungDiffusion
    variable = u
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

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
