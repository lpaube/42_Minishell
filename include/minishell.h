/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:16:25 by mleblanc          #+#    #+#             */
/*   Updated: 2021/08/19 15:15:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

# define WHITESPACE (" \t\n\v\f\r")

typedef enum e_builtin
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
}	t_builtin;

typedef struct s_parse
{
	char		*name;
	bool		is_prg;
	t_builtin	cmd;
	char		**args;
	char		**opts;
}	t_parse;

#endif