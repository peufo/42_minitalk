NAME = libftprintf.a
DIR_SRC = ./
DIR_BUILD = build
FLAGS = -Wall -Wextra -Werror -I ./

SOURCES		=	ft_atoi_ptr.c ft_format.c ft_format_c.c ft_format_di.c ft_format_p.c ft_format_percent.c ft_format_s.c ft_format_u.c ft_format_x.c ft_itoa_base.c ft_printf.c ft_put.c ft_run.c ft_string.c 
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@ $^

bonus: $(OBJECTS)
	@ar -cr $(NAME) $^

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	@mkdir $(DIR_BUILD)

so: $(OBJECTS)
	@cc -nostartfiles -shared -o libft.so $(OBJECTS)

test: all ./.test.c
	@cc $(FLAGS) -L ./ -lftprintf ./.test.c -o test

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
