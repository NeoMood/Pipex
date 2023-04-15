# Pipex - (42Network) 1337 Project
Welcome to Pipex, a program that mimics the pipe (|) operator in shell scripts. This project focuses on file manipulation and process management.
# Installation
To get started with Pipex, simply clone the repository and compile the program using the Makefile:
```sh
git clone https://github.com/NeoMood/Pipex
cd Pipex
make
```
# Usage

Usage
To use Pipex, run the executable file with the appropriate command-line arguments:

```sh
./pipex infile "cmd1" "cmd2" outfile
```

This will execute **cmd1 < infile | cmd2 > outfile**, effectively copying the contents of **'infile'** to **'outfile'** through the two commands. For example, to copy the contents of a file **'input.txt'** to another file **'output.txt'** after passing it through the **cat** and **grep** commands, you would run:
```sh
./pipex input.txt "cat" "grep word" output.txt
```

# Features
Pipex includes a number of advanced features, such as:

- Support for multiple pipes (**IN THE BONUS PART**)
- Error handling for invalid command-line arguments
- Input and output redirection
