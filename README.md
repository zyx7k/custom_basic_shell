# Custom Shell

This is a simple custom shell program implemented in C. The shell supports basic commands like `cd`, `pwd`, `echo`, and `history`. The code is modularized, with each command implemented in a separate `.c` file.

## Features

- **cd**: Change the current directory.
- **pwd**: Display the current working directory.
- **echo**: Print the given string.
- **history**: Show the last 10 commands executed.
- Command history is saved in a `history.txt` file in the user's home directory.

## Project Structure

.
├── main.c          # Main shell loop
├── cd.c            # cd command implementation
├── pwd.c           # pwd command implementation
├── echo.c          # echo command implementation
├── history.c       # history management (show and update history)
├── display.c       # display shell prompt
├── Makefile        # Makefile for compiling and running the shell
└── include/*.h     # Header files for each command


## Instructions to Run

1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Compile and run the program by executing the following command:
    ```bash
    make shell
    ```

## Commands Supported

- **cd [directory]**: Change the current directory to the specified one. If no directory is provided, it goes to the home directory.
- **pwd**: Print the current working directory.
- **echo [text]**: Print the specified text.
- **history**: Display the most recent commands executed.

## Cleaning Up

To remove the compiled shell, run:


```bash
    make clean
```