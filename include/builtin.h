/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:45:01 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/17 19:10:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "node.h"

# define PWD "pwd"
# define CD "cd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"

void	ft_echo(t_node *node);
void	ft_cd(t_node *node);
void	ft_unset(t_node *node);
void	ft_export(t_node *node);
void	ft_pwd(t_node *node);
void	ft_env(t_node *node);
void	ft_exit(t_node *node);

#endif