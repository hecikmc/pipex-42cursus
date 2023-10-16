# Pipex - 42cursus

## Description 

This is my implementation of the pipex project for the Cursus 42 program. Pipex is a **program** that simulates the functionality of the shell command | (pipe).

<p align="center">
<img width="450" alt="Screen Shot 2023-03-20 at 5 30 45 PM" src="https://github.com/hecikmc/pipex-42cursus/assets/121127625/8805c737-3166-4558-b1ab-5ca66546c4be">
</p>

<img width="1187" alt="Screen Shot 2023-03-20 at 5 30 45 PM" src="https://user-images.githubusercontent.com/121127625/226406390-c0e7b4cd-12cd-43ce-b80e-6ca389cb48f9.png">

* Project developed in C language.
* The project compiles with the 'norma' (Norminette).
* The makefile compiles the program with the name: pipex

## Mandatory part

<p align="center">
  <img width="615" alt="Screen Shot 2023-03-20 at 5 46 21 PM" src="https://user-images.githubusercontent.com/121127625/226410310-f15b1691-c9b2-4783-8349-0a80d73d4653.png">
</p>

The program works with 4 arguments with the following structure:
<p align=center>
  <i>./pipex file1(source) comand1 comand2 file2(destination)</i>
</p>
The behavior of the program is the same as when running in the shell: 
<p align=center>
  <i>$> < file1 comand1 | comand2 > file2</i>
 </p>
 
Pipex reads the input file and sends the output to the first command as standard input. The first command's output is sent as standard input to the second command. The result of applying both commands in the specified order is written at the output file.
  
**Requirements**:

* If the number of arguments is other than 4, the program will output an error to standard output.
* It includes the use of [libft-extended](https://github.com/hecikmc/libft-extended) like submodule. 
