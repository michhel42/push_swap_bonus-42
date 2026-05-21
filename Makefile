NAME        = push_swap
NAME_BONUS	= checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g

ALGOS_DIR   = algos
FUNC_DIR    = functions
PARSER_DIR  = parser
LIBFT_DIR   = libft
PRINTF_DIR  = printf
HEADER_DIR  = headers
GNL_DIR  	= gnl
LIBFT_A     = $(LIBFT_DIR)/libft.a
PRINTF_A    = $(PRINTF_DIR)/libftprintf.a
INCLUDES    = -I$(HEADER_DIR)

MAKEFLAGS += --no-print-directory

# ================= COLORS ================= #

RESET   = \033[0m
BOLD    = \033[1m
DIM     = \033[2m

RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m

# ========================================== #

ALGOS_SRC   = $(addprefix $(ALGOS_DIR)/,\
					complex.c \
					medium.c \
					simple.c \
					utils.c)

FUNC_SRC    = $(addprefix $(FUNC_DIR)/,\
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c)

PARSER_SRC  = $(addprefix $(PARSER_DIR)/,\
					cleaner.c \
					parser_utils.c \
					parser.c \
					stack_parser.c \
					stack_struct_utils.c \
					strategy_parser.c \
					bench.c)

GNL_SRC    = $(addprefix $(GNL_DIR)/, get_next_line.c)

SRC = main.c $(FUNC_SRC) $(PARSER_SRC) $(ALGOS_SRC)
SRC_BONUS = bonus.c $(FUNC_SRC) $(PARSER_SRC) $(ALGOS_SRC) $(GNL_SRC)

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEP_BONUS = $(OBJ_BONUS:.o=.d)

TOTAL_FILES := $(words $(SRC))
COMPILED := 0

# ========================================== #

define progress_bar
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	$(eval PERCENT=$(shell echo $$(($(COMPILED)*100/$(TOTAL_FILES)))))
	@printf "\r$(CYAN)Compiling: [$(GREEN)%3d%%$(CYAN)] $(RESET)" $(PERCENT)
endef

# ========================================== #

all: banner $(NAME)

banner:
	@echo "$(MAGENTA)"
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗     ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║     ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║     ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║     ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║     ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝     ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "                                                                                                         
	@echo "by sloubiat and vihardy"
	@echo "$(RESET)"
	@echo "$(DIM)Compilation en cours...$(RESET)"

banner-bonus:
	@echo "$(YELLOW)"
	@echo " ▗▄▄▖▗▖ ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▖     ▗▄▄▖  ▗▄▖ ▗▖  ▗▖▗▖ ▗▖ ▗▄▄▖"
	@echo "▐▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌▗▞▘▐▌   ▐▌ ▐▌    ▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌▐▌   "
	@echo "▐▌   ▐▛▀▜▌▐▛▀▀▘▐▌   ▐▛▚▖ ▐▛▀▀▘▐▛▀▚▖    ▐▛▀▚▖▐▌ ▐▌▐▌ ▝▜▌▐▌ ▐▌ ▝▀▚▖"
	@echo "▝▚▄▄▖▐▌ ▐▌▐▙▄▄▖▝▚▄▄▖▐▌ ▐▌▐▙▄▄▖▐▌ ▐▌    ▐▙▄▞▘▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘▗▄▄▞▘\n"

$(NAME): $(OBJ)
	@echo "\n$(BLUE)Compilation des librairies...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) -o $(NAME)
	@echo "\n$(GREEN)✔ $(NAME) compilé avec succès !$(RESET)"

bonus: banner-bonus ${OBJ_BONUS}
	@echo "\n$(BLUE)Compilation des librairies...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@echo "\n$(BLUE)Compilation du checker...$(RESET)"
	@$(CC) $(CFLAGS)  ${OBJ_BONUS} $(LIBFT_A) $(PRINTF_A) -o ${NAME_BONUS}
	@echo "$(GREEN)✔ $(NAME_BONUS) compilé avec succès !$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@rm -f $(OBJ) $(DEP) $(OBJ_BONUS) $(DEP_BONUS)
	@echo "$(GREEN)✔ Clean terminé$(RESET)"

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)✔ Full clean terminé$(RESET)"

re: fclean all

only: all clean
only_bonus: bonus clean

-include $(DEP)

.PHONY: all clean fclean re only banner bonus only_bonus banner-bonus
