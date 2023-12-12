NAME = libftprintf.a

SRC = ft_printf.c\
		ft_base.c\
		ft_basedecimal.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "⚙️ successfully compiled $< ⚙️"

$(NAME): $(OBJ)
	$(info $(OBJ) successfully created ✅)
	@ar rc $(NAME) $(OBJ)
	$(info $(NAME) successfully created ✅)

all: $(NAME)

clean:
	@$(info $(OBJ) successfully deleted ✅)
	@rm -rf $(OBJ)

fclean:
	@$(info $(OBJ) and $(NAME) successfully deleted ✅)
	@rm -rf $(OBJ) $(NAME)

re:fclean all

.PHONY: all clean fclean