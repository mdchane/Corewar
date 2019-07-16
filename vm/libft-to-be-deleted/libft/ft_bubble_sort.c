/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:37:01 by jfleury           #+#    #+#             */
/*   Updated: 2019/02/28 13:41:41 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_bubble_sort(int *tab, int size)
{
	int		temp;
	int		c;
	int		check;

	c = 0;
	check = 0;
	while (check == 0)
	{
		check = 1;
		while (c < size - 1)
		{
			if (tab[c] > tab[c + 1])
			{
				temp = tab[c];
				tab[c] = tab[c + 1];
				tab[c + 1] = temp;
				check = 0;
			}
			c++;
		}
		c = 0;
	}
	return (tab);
}
