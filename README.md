<div align="center">
  <img src="https://github.com/duc14102/LBExC/blob/main/LBExC.ico" alt="LBExC Logo">
  <p>A Lattice-Boltzmann-based Block-Structured Adaptive Mesh Refinement Framework.</p>

  [Overview](#Overview) -
  [Features](#Features) 
</div>

## Overview
LBExC solver is developed by [Van-Duc Nguyen](https://orcid.org/0000-0001-5864-5555)

## Features
- C++ language
- Parallelization via hybrid MPI/OpenMP
- Plotfile format supported by ParaView
  
- Support Single/Multiple relaxation time model
- Support Large eddy simulation
- Support Stationary adaptive mesh refinement
 <!-- Dynamic adaptive mesh refinement -->

Quantities:
| Quantity      | Formula (lattice) | Normalization     |
| :---       |    :----:   |    :---: |
| Speed of sound  | $c_s=1/\sqrt{3}$ | 
| Grid spacing   | $\Delta x=\Delta y=\Delta z=1$ |  |$U_\infty$ |
| Time step   | $\Delta t=1$ |  |
| Density   | $\rho$ | $C_\rho$ |
| Freestream velocity   | $\textcolor{red}{U_\infty}(\leq0.15, standard=0.1)$ | $U_\infty$ |
| Mach number   | $Ma=U_\infty/c_s$ |  |
| Characteristic length | $\textcolor{red}{D}$ | $D$ |
| Length   | $l$ | $D$ |
| Time   | $t$ | $D/U_\infty$ |
| Kinematic viscosity   | $\nu$ | $U_\infty D$ |
| Reynolds number   | $Re=U_\infty D/\nu$ |  |
| Gravity | $g$ | $U_\infty^2/D$ |
| Pressure   | $p=c_s^2\rho$ | - |
| Pressure coefficient  | $C_p=2(p-p_0)/(\rho U_\infty^2)$ |  |
| Velocity   | $\boldsymbol{u}$ | $U_\infty$ |
| Mean velocity | $\overline{\boldsymbol{u}}=\sum \boldsymbol{u}/N$ | $U_{\infty}$ |
| Root-mean-square Velocity   | $\boldsymbol{u}^\prime=\sqrt{\sum\left(\boldsymbol{u}-\overline{\boldsymbol{u}}\right)^2/N}$ | $U_{\infty}$ |
| Vorticity | $\boldsymbol{\omega}=\nabla\times\boldsymbol{u}$ | $U_{\infty}/D$ |
| Mean vorticity   | $\overline{\boldsymbol{\omega}}=\sum \boldsymbol{\omega}/N$ | $U_{\infty}/D$ |
| Q-criterion | $Q=0.5(\|\Omega\|^2-\|S\|^2)$ | $U_{\infty}^2/D^2$ |
| Enstrophy | $\mathcal{E}=0.5\lvert\boldsymbol{\omega}\rvert^2$ | $U_{\infty}^2/D^2$ |
| Kinetic energy   | $\mathcal{K}=0.5\lvert\boldsymbol{u}\rvert^2$ | $U_{\infty}^2$ |
| Energy dissipation rate | $\varepsilon=\partial\mathcal{K}/\partial t=2\nu\overline{s_{ij}s_{ij}}$ | $U_{\infty}^3/D$ |
| Helicity | $\mathcal{H}=\boldsymbol{u}\cdot(\nabla\times\boldsymbol{u})$  | $U_{\infty}^2/D$ |
| Helicity dissipation density | $\partial\mathcal{H}/\partial t=-2\nu\boldsymbol{\omega}\cdot(\nabla\times\boldsymbol{\omega})$ | $U_{\infty}^3/D^2$ |
| Volume of cell | $\mathcal{V}_{cell}=\Delta x\Delta y\Delta z=1$ | $D^3$ |
| Kolmogorov length scale | $\eta=(\nu^3/\varepsilon)^{1/4}$ | $D$ |
| Ratio of grid size to Kolmogorov length scale | $\sqrt[3]{\mathcal{V}_{cell}}/\eta$ |  |
| Reference area | $A$ | $D^2$ |
| Force | $\boldsymbol{F}(F_x,F_y,F_z)$ | $C_\rho U_{\infty}^2 D^2$ |
| Force density | - | $C_\rho U_{\infty}^2/D$ |
| Force coefficient | $\boldsymbol{C}(C_{drag},C_{lift},C_z)=2\boldsymbol{F}/(\rho U_\infty^2 A)$ |  |
| Strouhal number | $St=fD^{\star}/U_{\infty}^{\star}$ |  |
Note: subscript $^\star$ denotes normalized parameter