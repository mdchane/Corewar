/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:56:22 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/16 12:45:37 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_create_file(char **argv, unsigned char *buffer, int len)
{
	char	*str;
	int		len_argv;
	int		fd;
	int		i;

	len_argv = ft_strlen(argv[1]);
	if (!(str = malloc(sizeof(char) * len_argv - 1)))
		return (0);
	str[len_argv - 2] = 0;
	i = 0;
	while (argv[1][i] != '.')
	{
		str[i] = argv[1][i];
		i++;
	}
	str = ft_strextend(str, ".cor");
	ft_printf("Writing output program to %s\n", str);
	fd = open(str, O_CREAT, S_IRWXU, O_RDWR);
	close(fd);
	fd = open(str, O_RDWR);
	free(str);
	write(fd, buffer, len);
	close(fd);
	return (0);
}

unsigned char	*ft_convert_head(t_header *head)
{
	unsigned char	*buffer;
	unsigned char	*conv_progsize;

	if (!(buffer = (unsigned char *)ft_strnew(sizeof(*buffer) * 2192)))
		return (NULL);
	buffer[0] = 0;
	buffer[1] = 234;
	buffer[2] = 131;
	buffer[3] = 243;
	ft_strcpy_n(buffer, (unsigned char *)head->prog_name, 4, 128);
	conv_progsize = ft_conv_hexa(head->prog_size, 4);
	ft_strcpy_n(buffer, conv_progsize, 136, 4);
	ft_strcpy_n(buffer, (unsigned char *)head->comment, 140, 2048);
	ft_strdel((char **)&conv_progsize);
	return (buffer);
}

void			init_convert(unsigned char **buffer, t_header *head, int *pos)
{
	unsigned char	*conv_head;

	*buffer = (unsigned char *)ft_strnew(2192 + head->prog_size);
	conv_head = ft_convert_head(head);
	*buffer = ft_strcpy_n(*buffer, conv_head, 0, 2192);
	*pos = 2192;
	ft_strdel((char **)&conv_head);
}

void			ft_convert(t_lst_tk *lst, t_header *head, char **argv,
							t_label *lab)
{
	unsigned char	*buffer;
	int				pos;
	int				size_instru;
	t_pos_lab		pos_lab;

	init_convert(&buffer, head, &pos);
	pos_lab.lab = lab;
	while (lst)
	{
		pos_lab.pos = pos - 2192;
		size_instru = 0;
		if (lst->token->type == INSTRUCTION)
			buffer = ft_strextend_nm(buffer, ft_conv_instru(lst->token,
				&size_instru, pos_lab), pos, size_instru);
		else if (lst->token->type == LABEL)
		{
			if (lst->token->next && lst->token->next->type != COMMENT)
				buffer = ft_strextend_nm(buffer, ft_conv_instru(
				lst->token->next, &size_instru, pos_lab), pos, size_instru);
		}
		lst = lst->next;
		pos += size_instru;
	}
	ft_create_file(argv, buffer, 2192 + head->prog_size);
	ft_strdel((char **)&buffer);
}
