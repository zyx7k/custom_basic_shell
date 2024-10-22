shell: main.c cd.c pwd.c history.c echo.c display.c
	gcc main.c cd.c pwd.c history.c echo.c display.c -o shell
	./shell

clean:
	rm shell
