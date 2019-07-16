/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:08:18 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/16 16:23:43 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_check_fd(int fd, char **argv)
{
	if (fd == -1)
	{
		ft_printf("error: no such file or directory: '%s'\n", argv[1]);
		close(fd);
		exit(0);
	}
}

static void		ft_check_arg(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc == 1)
	{
		ft_printf("usage: ./asm <file.s>\n");
		exit(0);
	}
	if (argc > 2)
	{
		ft_printf("error: too many files / "
		"only one file accepted\n");
		exit(0);
	}
	i = ft_strlen(argv[1]);
	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd, argv);
	close(fd);
	if (i >= 3 && argv[1][i - 1] == 's' && argv[1][i - 2] == '.')
		return ;
	else
	{
		ft_printf("error: invalid file\n");
		exit(0);
	}
}

t_header		*init_header(void)
{
	t_header	*head;
	int			i;

	if (!(head = (t_header *)ft_memalloc(sizeof(t_header))))
		return (NULL);
	head->magic = 15369203;
	head->prog_size = 0;
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		head->prog_name[i] = 0;
	head->prog_name[i] = '\0';
	i = -1;
	while (++i < COMMENT_LENGTH)
		head->comment[i] = 0;
	head->comment[i] = '\0';
	return (head);
}

static int		ft_lexer_parser(t_header *head, t_label *list_label,
								t_lst_tk *lst_tk, char **argv)
{
	if (!(ft_lexer(&lst_tk, &list_label, argv)))
	{
		ft_free_all(lst_tk, list_label, head);
		return (0);
	}
	if (lst_tk == NULL)
	{
		ft_free_all(lst_tk, list_label, head);
		ft_printf("error: empty file / directory file\n");
		return (0);
	}
	if (!(ft_parser(lst_tk, list_label, head)))
	{
		ft_free_all(lst_tk, list_label, head);
		return (0);
	}
	ft_convert(lst_tk, head, argv, list_label);
	ft_free_all(lst_tk, list_label, head);
	return (1);
}

int				main(int argc, char **argv)
{
	t_header	*head;
	t_label		*list_label;
	t_lst_tk	*lst_tk;

	ft_check_arg(argc, argv);
	if (!(head = init_header()))
		return (0);
	list_label = NULL;
	lst_tk = NULL;
	if (!(ft_lexer_parser(head, list_label, lst_tk, argv)))
		return (0);
	return (0);
}
