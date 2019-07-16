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

#	Prefixes

all		:
		$(MAKE) -C $(VM_DIR)
		$(MAKE) -C $(ASM_DIR)	

#	Cleaner rules
clean	:
		$(MAKE) -C $(VM_DIR) clean
		$(MAKE) -C $(ASM_DIR) clean

fclean	:	clean
		$(MAKE) -C $(VM_DIR) fclean
		$(MAKE) -C $(ASM_DIR) fclean

re		:	fclean all

#	Phony
.PHONY	=	default all re clean fclean

