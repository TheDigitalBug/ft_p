HEADER = ft_printf.h

FlAG = -Wall -Werror -Wextra

OBJECT = ft_toupper.o ft_puts_count.o ft_putstr_w.o ft_printf.o ft_atoi.o ft_converter_float.o ft_converter_dec.o ft_converter_oct.o ft_converter_hex.o ft_converter_un.o ft_converter_p.o ft_read_format.o ft_flagsetlong.o ft_flagbezero.o ft_flagcheck.o ft_putchar_count.o ft_putchar_flag.o ft_putchar_w.o ft_recursive_power.o ft_read_type.o ft_strrchr.o

SRC = ft_toupper.c ft_puts_count.c ft_putstr_w.c ft_printf.c ft_atoi.c ft_converter_float.c ft_converter_dec.c ft_converter_oct.c ft_converter_hex.c ft_converter_un.c ft_converter_p.c ft_read_format.c ft_flagsetlong.c ft_flagbezero.c ft_flagcheck.c ft_putchar_count.c ft_putchar_flag.c ft_putchar_w.c ft_recursive_power.c ft_read_type.c ft_strrchr.c

NAME = libftprintf.a

all: $(NAME)

%.o: %.c 
	gcc -o $@ -c $< $(FLAGS)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT) $(HEADER)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
