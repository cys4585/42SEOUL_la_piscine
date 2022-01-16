/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:07:14 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:07:14 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
# define SEARCH_H

# include "checks.h"

struct s_search
{
	int		n;
	char	*cases;
	char	*table;
	char	*cond;
	int		complete;
};

int	try_doing_search(int n, char *cases, char *table, char *cond);
int	search_table(struct s_search *param, int k);
int	check_table(struct s_search *param);
int	check_table_way(struct s_search *param, int way, int i);
int	count_visible(struct s_search *param, int way, int i);

#endif
