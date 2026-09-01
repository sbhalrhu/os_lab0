all: fork_loop who_runs_first

fork_loop: fork_loop.c
	gcc -Wall -Werror -g -o fork_loop fork_loop.c

who_runs_first: who_runs_first.c
	gcc -Wall -Werror -g -o who_runs_first who_runs_first.c

clean:
	rm -rf fork_loop who_runs_first