MAKE = make
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -lft
LDFLAGS = -L../libft/

NAME = libls.a

SRC = main.c \
	  idir.c \
	  ifile.c \
	  files_malloc.c \
	  ft_concat.c \
	  ft_sort_time.c \
	  ft_sort_time2.c \
	  ft_swap_str.c \
	  ft_swap_str2.c \
	  ft_tri.c \
	  ft_dtri.c \
	  gdir.c \
	  garg.c \
	  goptr.c \
	  gstat.c \
	  gtime.c \
	  gtype.c \
	  ls_error.c \
	  ls_warning.c \
	  soptions.c \
	  ffiles.c \
	  put_name.c \
	  pfiles.c \
	  ptotal.c \
	  pperm.c \
	  pmiss.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CPPFLAGS) $(SRC) -c
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
