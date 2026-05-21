NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(HEADER_DIR) -g
AR = ar rcs

HEADER_DIR = ../headers

MAKEFLAGS += --no-print-directory

# ================= COLORS ================= #

RESET   = \033[0m
DIM     = \033[2m

RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m

# ========================================== #

SRC =	ft_applyflags.c \
		ft_handle_int.c \
		ft_handle_str.c \
		ft_lenflags.c \
		ft_lst.c \
		ft_options.c \
		ft_printf.c \
		ft_utils.c \
		ft_utils2.c \
		itoa.c

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

TOTAL_FILES := $(words $(SRC))
COMPILED := 0

# ========================================== #

define progress_bar
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	$(eval PERCENT=$(shell echo $$(($(COMPILED)*100/$(TOTAL_FILES)))))
	@printf "\r$(MAGENTA)printf: [$(GREEN)%3d%%$(MAGENTA)]$(RESET)" $(PERCENT)
endef

# ========================================== #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(BLUE)Building $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)✔ $(NAME) ready$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress_bar)

clean:
	@echo "$(RED)Cleaning printf objects...$(RESET)"
	@rm -f $(OBJ) $(DEP)
	@echo "$(GREEN)✔ Clean terminé$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✔ Full clean terminé$(RESET)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
