#!/bin/bash 
#SBATCH --job-name=LBExC-debug   
#SBATCH -p debug_queue  
#SBATCH --time=4:00:00  # format days-hh:mm:ss  
#SBATCH --cpus-per-task=3
#SBATCH --ntasks=1
export OMP_NUM_THREADS=3

# echo "Used nodes:" $SLURM_NODELIST
mpirun -n 4 ./LBExC