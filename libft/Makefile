# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rporcon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 15:14:43 by rporcon           #+#    #+#              #
#    Updated: 2017/09/04 18:14:33 by rporcon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c char_count.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c itoa.c itoa_base.c \
	ft_ll_new.c ft_ll_append.c ft_ll_prepend.c ft_ll_print.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c next_powerchr.c ft_printf.c \
	putaddr.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	strsplit.c ft_strstr.c strsub.c strtrim.c ft_tolower.c \
	ft_toupper.c hexdump.c ft_putnbr_max.c putaddr_fd.c syscmd_tostr.c \
	putaddr_byte.c putaddr_byte_fd.c puts_leading_zero.c \
	itoa_ulong.c itoa_base_ulong.c leading_char_before.c \
	dynarray_add.c dynarray_print.c words_alpha_sort.c \
	swap_str.c dynarray_init.c ft_intarr_includes.c xxd.c \
	swap_u64b.c swap_u32b.c swap_u16b.c perr_exit.c err_exit.c \
	swap_u8b.c ft_pow.c ft_putnbr_u.c ft_putnbr_llu.c \
	ft_isupper.c ft_islower.c atoi_base.c atoi_base_max.c \
	atoi_max.c words_baseunum_sort.c rev_words.c ft_insert_char.c \
	ft_insert_str.c natoi.c syscmd_tostr.c charnpos.c read_fd.c \
	ulong_size.c ft_putnbr_max_fd.c ft_fprintf.c ft_basename.c \
	charlastpos.c memmemchr.c memsub.c strreplace.c charpos.c strisdigit.c \
	natoi_base.c memcat.c strisalnum.c strisalpha.c sstrlen.c \
	sstrfree.c sstrchr.c

OBJ = $(SRC:%.c=%.o)

all: libft.h $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
