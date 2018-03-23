/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:19:36 by mipham            #+#    #+#             */
/*   Updated: 2018/03/23 15:08:31 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/libft/libft.h"

int		main(void)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	printf("ret1 : %d\tline: %p\n", ret, line);
	while(1);
	return (0);
}
