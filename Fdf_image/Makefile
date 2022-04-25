# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 20:10:00 by hkaddour          #+#    #+#              #
#    Updated: 2022/04/25 22:14:34 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
HEADER = fdf.h
CFLAGS = -Wall -Wextra -Werror
FLAG = -lmlx -framework OpenGL -framework AppKit
SRCS =	main.c \
				read.c \
				line.c \
				draw.c \
				utils.c \
				tools.c

SRCS_BONUS = main_bonus.c \
						 read.c \
						 line.c \
						 draw.c \
						 utils.c \
						 tools.c \
						 keystrokes_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIB = libft.a

BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPink=\033[1;38;5;205m
BRed=\033[1;31m

ascii=███████╗██████╗ ███████╗      ██╗    ██╗██╗██████╗ ███████╗███████╗██████╗  █████╗ ███╗   ███╗███████╗\n\
			██╔════╝██╔══██╗██╔════╝      ██║    ██║██║██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗████╗ ████║██╔════╝\n\
			█████╗  ██║  ██║█████╗  █████╗██║ █╗ ██║██║██████╔╝█████╗  █████╗  ██████╔╝███████║██╔████╔██║█████╗  \n\
			██╔══╝  ██║  ██║██╔══╝  ╚════╝██║███╗██║██║██╔══██╗██╔══╝  ██╔══╝  ██╔══██╗██╔══██║██║╚██╔╝██║██╔══╝  \n\
			██║     ██████╔╝██║           ╚███╔███╔╝██║██║  ██║███████╗██║     ██║  ██║██║  ██║██║ ╚═╝ ██║███████╗\n\
			╚═╝     ╚═════╝ ╚═╝            ╚══╝╚══╝ ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n

all: $(NAME)

$(LIB):
	@echo ""
	@echo " $(BPink)$(ascii)"
	@make -C ./../libft
	@mv ./../libft/libft.a ./../Fdf_image

%.o: %.c
	@echo "$(BGreen)$(CC) $(CFLAGS) Compile $^ to $@"
	@$(CC) $(CFLAG) -c $^ -I $(HEADER)

$(NAME): $(LIB) $(OBJS)
	@echo "$(BBlue)Compiling $^ -I $(FLAG) -o $(NAME)"
	@$(CC) $^ $(FLAG) -o $(NAME)

bonus: $(LIB) $(OBJS_BONUS)
	@echo "$(BBlue)Compiling $^ -I $(FLAG) and filter out $(OBJS) -o $(NAME)"
	@$(CC) $^ $(FLAG) $(filter-out main.o read.o draw.o utils.o line.o tools.o, $(OBJS)) -o $(NAME)

clean:
	@echo "$(BRed)clean $(OBJS) $(OBJS_BONUS) $(LIB)"
	@rm -rf $(OBJS) $(OBJS_BONUS) $(LIB)

fclean: clean
	@echo "$(BRed)fclean $(NAME) and fclean libft"
	@rm -rf $(NAME)
	@make fclean -C ./../libft

re: fclean all

.PHONY: all clean fclean bonus re
