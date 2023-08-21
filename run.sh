#!/bin/bash
export OMP_NUM_THREADS=1
mpiexec -n 6 --bind-to core ./LBExC