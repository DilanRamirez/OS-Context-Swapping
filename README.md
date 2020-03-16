# Lab 1 - Context Swapping (CS 4375 - OS)

## Description

The main purpose of Lab 1 – Context Swapping is to measure the cost, in this case, the time it takes for the operative system to swap processes. According to tutorialspoint.com, context swap process means, “It involves storing the context or state of a process so that it can be reloaded when required and execution can be resumed from the same point as earlier.” The steps to do it are the next:

 * 1.	Save the context of the process which is running on the CPU.
 * 2.	Change the process state to blocked and store it in the queue.
 * 3.	Select a new process from the ready list to execute.
 * 4.	Update the process state to running.
 * 5.	Update memory as required.
 * 6.	Restore the context of the process which was previously running after it is loaded again on the CPU.
 * 7.	Repeat.

A process runs on the CPU until it is swapped to start another process. Swapping can occur for many reasons. Among these reasons are the process has used its timeslice, the process needs to use some other resource not available, the process state has changed, etc. 

## Instructions

The folder contains seven files. The Makefile includes only the file read_input.c and write_input.c to execute.
File Lab1_DilanRamirez.c contains the context swapping demostration in which measures the time it takes to OS
to swap process.

## Author

Dilan Ramirez

