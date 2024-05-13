NAME			=		libft.a

CC				=		gcc
CCFLAGS			=		-Wall -Wextra -Werror 

FILES			=		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
							ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
							ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
							ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
							ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
							ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
							ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
							ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
							ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
							get_next_line.c ft_strcmp.c ft_abs.c ft_replace.c \
							ft_strstr.c ft_power.c

BONUS_FILES		=		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
							ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
							ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_FILES	=		 ft_formating.c ft_ft_strchr.c ft_initflagdata.c \
							ft_printf.c ft_printhex.c ft_printpad.c ft_ptf_percent.c\
							ft_printstr.c ft_ptf_char.c ft_ptf_str.c ft_ptf_ptr.c \
							ft_ptf_int.c ft_ptf_uint.c ft_ptf_hex.c 

OBJS_DIR		=		objs/
OBJ				=		$(FILES:.c=.o) $(PRINTF_FILES:.c=.o)
OBJ_PREFIX		=		$(addprefix $(OBJS_DIR), $(OBJ))

BONUS_OBJ		=		$(BONUS_FILES:.c=.o)
BNS_PREFIX		=		$(addprefix $(OBJS_DIR), $(BONUS_OBJ))

$(OBJS_DIR)%.o:			%.c libft.h
							@mkdir -p $(OBJS_DIR)
							@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): 				$(OBJ_PREFIX)
							@ar r $(NAME) $(OBJ_PREFIX)
							@echo "Libft Completed"

all:					$(NAME)

clean:
						rm -rf $(OBJS_DIR)

fclean:					clean
						rm -f $(NAME)

re:						fclean all bonus

bonus:					$(BNS_PREFIX)
							@ar r $(NAME) $(BNS_PREFIX)
							@echo "Libft Bonus Completed"

.PHONY:					all, clean, fclean, re