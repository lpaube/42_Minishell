/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:15:00 by laube             #+#    #+#             */
/*   Updated: 2021/09/11 18:19:31 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/*	Executes the binary entered as cmd */
int	ft_binary(t_phrase *phrase)
{
	char	*bin_path;
	pid_t	pid;

	bin_path = get_bin_path(g_minishell.env, phrase->name);
	if (bin_path == NULL)
		return (-1);
	g_minishell.allow_signal = 0;
	pid = fork();
	if (pid == -1)
		print_error("Invalid process id after fork.");
	if (pid == 0)
	{
		if (execve(bin_path, phrase->args, g_minishell.env) == -1)
			print_error("Invalid execution of binary.");
	}
	wait(0);
	g_minishell.allow_signal = 1;
	return (0);
}

void	ft_echo(t_phrase *phrase)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if ((phrase->args)[i] && ft_strnstr((phrase->args)[i], "-n", 2))
	{
		nl = 0;
		i++;
	}
	while ((phrase->args)[i])
	{
		printf("%s", (phrase->args[i]));
		i++;
		if ((phrase->args)[i])
			printf(" ");
	}
	if (nl)
		printf("\n");
}

void	ft_exit(t_phrase *phrase)
{
	(void)phrase;
	exit(0);
}
