SRCDIR	= ./srcs/
SRCNAME	= 	main.c\
			add_stack.c\
			clear_stack.c\
			error.c\
			error_check.c\
			pa.c\
			pb.c\
			ra.c\
			rr.c\
			rra.c\
			rrr.c\
			sa.c\
			set_stack.c\
			sort_2.c\
			sort_3.c\
			sort_6.c\
			sort_100.c\
			ss.c\
			stacklen.c\
			stackmeidian.c\
			stackmin.c\
			finish_program.c\
			put_stack.c\
			info_init.c\
			is_sorted.c\
			is_dup.c\
			is_dup_util.c\
			half_set.c\
			quick_sort.c\
			command_set.c\
			quick_sort2.c\
			quick_sort3.c\
			command_set2.c\
			command_opt.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./includes
NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBDIR	= ./libft/
LIBFT	= libft.a

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBDIR)$(LIBFT) -o $(NAME)

$(LIBFT):
			make -C $(LIBDIR)

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBDIR)

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBDIR)

re		:	fclean all

sani	:	$(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LIBDIR)$(LIBFT) -o $(NAME)

.PHONY	:	all clean fclean re $(LIBFT)