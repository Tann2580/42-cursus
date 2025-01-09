/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:29:20 by yanshen           #+#    #+#             */
/*   Updated: 2025/01/09 18:32:38 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	input_fd;
	int	pipefd[2];

	if(argc != 5)//argument nb
		perror("Wrong number input");
	if (access(argv[1], F_OK | R_OK) == -1) //CHECK IF EXIST
		perror("File not exist");
	printf("sofarsogood1\n");
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
	{
		perror("Error opening file.");
		exit(EXIT_FAILURE);
	}
	create_pipe(pipefd, input_fd);
	printf("pipeok\n");
	child1_process(pipefd, input_fd, argv, env);
	printf("child1\n");
	child2_process(pipefd, argv, env);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	
	return(0);
}

void	create_pipe(int *pipefd, int input_fd)
{
	if (pipe(pipefd) == -1)
	{
		perror("Error creating pipe");
		close(input_fd);
	}
}
void	child1_process(int *pipefd, int input_fd, char **argv, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(input_fd);
		close(pipefd[0]);
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	//create the child process 0 sucess -1failure
	if (pid == 0)//create ok
	{
		close(pipefd[0]);//the child1 do not need pipe read
		dup2(input_fd, STDIN_FILENO);//set the file1 as standard input
		close(input_fd);
		dup2(pipefd[1], STDOUT_FILENO);//set the pipe write point as standard output
		close(pipefd[1]);//finish pipe write
		ft_exec(argv[2], env);
	}
}
void	child2_process(int *pipefd, char **argv, char **env)
{
	pid_t	pid;
	int	output_fd;

	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipefd[1]); // child2 no need for pipe write
		dup2(pipefd[0], STDIN_FILENO);//redirect the pipe read as standard input
		close(pipefd[0]);
		output_fd = open(argv[4], O_WRONLY);
		if (output_fd < 0)
		{
			perror("Error open file 2");
			exit(EXIT_FAILURE);
		}
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
		ft_exec(argv[3], env);
	}
}
