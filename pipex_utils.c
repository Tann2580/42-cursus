/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:06:33 by yanshen           #+#    #+#             */
/*   Updated: 2025/01/09 18:49:06 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, " ");
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(127);
	}
	ft_free_tab(s_cmd);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
char	*get_env(char *name, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(name);
	printf("len is %d", len);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd0, char **env)
{
	int	i;
	char	**entirepath;
	char	*each_path;
	char	*exec_path;

	i = -1;
	entirepath = ft_split(get_env("PATH", env), ":");
	while (entirepath[++i])
	{
		each_path = ft_strjoin(entirepath[i], "/");
		exec_path = ft_strjoin(each_path, cmd0);
		free(each_path);
		if (access(exec_path, F_OK | X_OK) == 0)
			return (exec_path);
		free(exec_path);
		ft_free_tab(entirepath);
	}
	return (cmd0);
}
