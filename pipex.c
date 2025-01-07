/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:29:20 by yanshen           #+#    #+#             */
/*   Updated: 2025/01/07 17:30:01 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h> //fork
#include <stdlib.h> //exit

int	main(int argc, char **argv)
{
	const char	*file1;
	int	file1, file2;
	int	pipefd;
	int	pid1, pid2;


	if(argc != 5)
		perror("Wrong number input");
	if (access(file1, F_OK) == -1) //CHECK IF EXIST
		perror("File not exist");
	if (access(file1, R_OK) == -1)
		perror("File no access");
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		perror("Error opening file.");
		exit(EXIT_FAILURE);
	}

	if (pipe(pipefd) ==-1)
	{
		perror("Error creating pipe");
		close(file1);
		exit(EXIT_FAILURE);
	}
	
	pid1 = fork();
	if (pid1 == 0)
	dup2(file1, STDIN_FILENO);
	close(file1);
	

	return(0);
}
	
