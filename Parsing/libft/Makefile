CFLAGS	= -Wall -Wextra -Werror -g3
RM = rm -f
CC = cc

NAME	= libft.a

SOURCES =	ft_isascii.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_itoa.c \
			ft_split.c

BONUS_SOURCES =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJECTS	= ${SOURCES:.c=.o}
BONUS_OBJECTS = ${BONUS_SOURCES:.c=.o}

%.o : %.c libft.h
	$(CC) ${CFLAGS} -c $< -o $@

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}
	echo "$(COLOUR_GREEN)Libft compiled successfully!$(COLOUR_END)"

all: ${NAME}

bonus: ${OBJECTS} ${BONUS_OBJECTS}
	ar rcs ${NAME} ${BONUS_OBJECTS}
	echo "$(COLOUR_GREEN)Libft bonus compiled successfully!$(COLOUR_END)"

clean:
	${RM} ${OBJECTS} ${BONUS_OBJECTS}
	echo "$(COLOUR_RED)Objects cleaned successfully!$(COLOUR_END)"

fclean: clean
	${RM} ${NAME}
	echo "$(COLOUR_RED)Libft cleaned successfully!$(COLOUR_END)"

re: fclean all

debug: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o debug
