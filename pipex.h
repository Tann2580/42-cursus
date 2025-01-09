#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h> //fork pipe
# include <stdlib.h> //exit
# include <sched.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

char	**ft_split(const char *str, const char *charset);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_strncpy(char *dest, const char *src, int size);
void	ft_exec(char *cmd, char **env);
void	ft_free_tab(char **tab);
void	create_pipe(int *pipefd, int input_fd);
void	child1_process(int *pipefd, int input_fd, char **argv, char **env);
void	child2_process(int *pipefd, char **argv, char **env);
char	*get_path(char *cmd0, char **env);
char	*get_env(char *name, char **env);

#endif