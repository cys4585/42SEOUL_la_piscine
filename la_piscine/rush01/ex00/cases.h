/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:02:51 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:02:51 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASES_H
# define CASES_H

void	make_cases(int n, char **cases_ptr);
int		case_permutation(char **cases_ptr, char *arr, int k, int n);
char	*store_found_case(char *cases, char *arr, int n);
int		factorial(int n);
void	swap_char(char *a, char *b);

#endif
