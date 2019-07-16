/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:42:45 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_data_conv_id(void)
{
	char	*conv_id;

	conv_id = ft_memalloc(CONV_ID_NB + 1);
	conv_id[0] = 'd';
	conv_id[1] = 'i';
	conv_id[2] = 'o';
	conv_id[3] = 'u';
	conv_id[4] = 'x';
	conv_id[5] = 'X';
	conv_id[6] = 'c';
	conv_id[7] = 's';
	conv_id[8] = 'p';
	conv_id[9] = 'f';
	conv_id[10] = '%';
	conv_id[11] = 'b';
	conv_id[12] = 'D';
	conv_id[CONV_ID_NB] = '\0';
	return (conv_id);
}
