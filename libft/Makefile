NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(HEADER_DIR)
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

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
      ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
      ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
      ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
      ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_sqrt.c

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

TOTAL_FILES := $(words $(SRC))
COMPILED := 0

# ========================================== #

define progress_bar
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	$(eval PERCENT=$(shell echo $$(($(COMPILED)*100/$(TOTAL_FILES)))))
	@printf "\r$(CYAN)libft: [$(GREEN)%3d%%$(CYAN)]$(RESET)" $(PERCENT)
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
	@echo "$(RED)Cleaning libft objects...$(RESET)"
	@rm -f $(OBJ) $(DEP)
	@echo "$(GREEN)✔ Clean terminé$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✔ Full clean terminé$(RESET)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
