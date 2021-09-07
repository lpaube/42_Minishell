/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:16:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/06 14:55:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "phrase.h"
#include "tokenizer.h"
#include <stdlib.h>

t_phrase	*get_next_node(t_list **tokens)
{
	t_phrase	*node;
	char		*str;

	if (get_operator((*tokens)->content) != NONE)
		return (NULL);
	node = ft_calloc(1, sizeof(t_phrase));
	node->name = ft_strdup(ft_str_data((*tokens)->content));
	node->args = ft_calloc(1, sizeof(char *));
	while (*tokens && get_operator((*tokens)->content) == NONE)
	{
		str = ft_strdup(ft_str_data((*tokens)->content));
		node->args = ft_expand_strarr(node->args, str);
		ft_lstnext(tokens);
	}
	if (*tokens)
	{
		node->op = get_operator((*tokens)->content);
		ft_lstnext(tokens);
	}
	else
		node->op = NONE;
	return (node);
}

t_phrase	*get_operator_first_node(t_list **tokens)
{
	t_phrase	*node;

	node = ft_calloc(1, sizeof(t_phrase));
	node->args = ft_calloc(1, sizeof(char *));
	node->op = get_operator((*tokens)->content);
	if (node->op == READ || node->op == APPEND
		|| node->op == INPUT || node->op == READ)
	{
		node->name = ft_strdup("cat");
		node->args = ft_expand_strarr(node->args, ft_strdup("cat"));
	}
	ft_lstnext(tokens);
	return (node);
}

bool	is_valid_syntax(t_phrase *cmds)
{
	t_phrase	*last;

	last = nodelast(cmds);
	if (last->op != NONE)
		return (false);
	return (true);
}

t_phrase	*parse(t_list *tokens)
{
	t_phrase	*cmds;
	t_phrase	*new;

	cmds = NULL;
	if (get_operator(tokens->content) == PIPE)
		return (unexpected_token(tokens->content));
	if (get_operator(tokens->content) != NONE)
		nodeadd_back(&cmds, get_operator_first_node(&tokens));
	while (tokens)
	{
		new = get_next_node(&tokens);
		if (!new)
		{
			nodeclear(&cmds);
			return (unexpected_token(tokens->content));
		}
		nodeadd_back(&cmds, new);
	}
	if (!is_valid_syntax(cmds))
	{
		nodeclear(&cmds);
		return (print_error("syntax error near unexpected token '\\n'"));
	}
	return (cmds);
}