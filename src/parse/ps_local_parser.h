/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_local_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:33:47 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 10:17:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LOCAL_PARSER_H
# define PS_LOCAL_PARSER_H

int	ps_intoverflow(char *str, int sign);
int	ps_isint(char *str);
int	ps_islistofint(int size, char **strv);
int	ps_hasduplicates(int size, int *list);
int	ps_haserrors(int size, char **strv);

#endif
