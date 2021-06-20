NAME = libftprintf.a

SRCS = base/ft_printf.c \
		libft/ft_putchar_fd.c libft/ft_strchr.c libft/ft_atoi.c libft/ft_strlen.c \
		libft/ft_itoua.c libft/ft_utoa.c libft/ft_padding.c libft/ft_strdup.c \
		libft/ft_putstr_fd.c libft/ft_ui_to_hex.c libft/ft_max_int.c \
		libft/ft_memset.c \
		libft/ft_strlcpy.c \
		parsers/parse_flags.c parsers/parse_precision.c parsers/parse_specifier.c \
		parsers/parse_width.c \
		processors/string_processor.c processors/integer_processor.c \
		processors/unsigned_processor.c processors/char_processor.c \
		processors/hex_processor.c processors/parse_fail_processor.c \
		processors/struct_processor.c processors/percent_processor.c

INCL = includes/ft_printf.h

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -std=c99 -Wextra -Wall -Werror

%.o:%.c $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar crs $(NAME) $?

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
