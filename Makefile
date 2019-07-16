#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 18:38:00 by tmaze             #+#    #+#              #
#    Updated: 2019/07/16 19:25:03 by tmaze            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

VM_DIR		=	./vm
ASM_DIR		=	./asm

LIB_DIR		=	./libft
PRT_DIR		=	./printf

all		:
		$(MAKE) -C $(LIB_DIR)
		$(MAKE) -C $(PRT_DIR)
		$(MAKE) -C $(VM_DIR)
		$(MAKE) -C $(ASM_DIR)	

clean	:
		$(MAKE) -C $(LIB_DIR) clean
		$(MAKE) -C $(PRT_DIR) clean
		$(MAKE) -C $(VM_DIR) clean
		$(MAKE) -C $(ASM_DIR) clean

fclean	:
		$(MAKE) -C $(LIB_DIR) fclean
		$(MAKE) -C $(PRT_DIR) fclean
		$(MAKE) -C $(VM_DIR) fclean
		$(MAKE) -C $(ASM_DIR) fclean

re		:	fclean all

.PHONY	=	default all re clean fclean

