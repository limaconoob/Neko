MAKE = make
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -lft -lls
LDFLAGS = -Llibft/ -Lls/

LIB = libsh.a
NAME = 21sh

SRC = main.c \
	  add_char.c \
	  auto_comp.c \
	  begin_space.c \
	  check_sub.c \
	  check_nsub.c \
	  clear_afterline.c \
	  clear_afterslash.c \
	  clear_afterword.c \
	  command_line.c \
	  command_exec.c \
	  del_char.c \
	  del_dir.c \
	  del_size.c \
	  do_exec.c \
	  do_exit.c \
	  do_protect.c \
	  env_check.c \
	  env_exec.c \
	  env_parse.c \
	  flcpy.c \
	  ftab.c \
	  ft_cat.c \
	  ft_concat.c \
	  ft_del_quote.c \
	  ft_echo.c \
	  ft_getbrack.c \
	  ft_grep.c \
	  ft_help.c \
	  ft_isbrack.c \
	  ft_isbrack2.c \
	  ft_isdir.c \
	  ft_isdir2.c \
	  ft_isspace.c \
	  ft_list_reverse.c \
	  ft_list_reverse2.c \
	  ft_putescstr.c \
	  ft_replacedol.c \
	  ft_replacetild.c \
	  ft_signal.c \
	  ft_space.c \
	  ft_splitspaces.c \
	  ft_strisnum.c \
	  ft_strsplit2.c \
	  ft_wait.c \
	  get_av.c \
	  get_dir.c \
	  get_dirpart.c \
	  get_history.c \
	  get_next_line.c \
	  get_next_line2.c \
	  get_size.c \
	  idir2.c \
	  ienv.c \
	  ilog.c \
	  incom.c \
	  ins_char.c \
	  iparams.c \
	  ipath.c \
	  iscom.c \
	  isdir.c \
	  kick_env.c \
	  kick_ncom.c \
	  last_char.c \
	  log_cpy.c \
	  log_dup.c \
	  move_down.c \
	  move_it.c \
	  move_left.c \
	  move_right.c \
	  move_to.c \
	  move_up.c \
	  ncommands.c \
	  outc.c \
	  penv.c \
	  pmanp.c \
	  plog.c \
	  push_env.c \
	  push_log.c \
	  put_comp.c \
	  put_dol.c \
	  put_prline.c \
	  put_prompt.c \
	  put_newprompt.c \
	  put_solo.c \
	  put_termstr.c \
	  regprocess.c \
	  renv.c \
	  reset_cd.c \
	  rlogs.c \
	  rpath.c \
	  schdir.c \
	  senv.c \
	  set_path.c \
	  set_shlvl.c \
	  set_termkappa.c \
	  shell_cure.c \
	  shell_error.c \
	  shell_warning.c \
	  spath.c \
	  tab_realloc.c \
	  tab_size.c \
	  tabenv.c \
	  term_coord.c \
	  term_init.c \
	  uenv.c \
	  write_comp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@make -C ./ls
	@$(CC) $(CPPFLAGS) $(SRC) -c
	@$(CC) $(CPPFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	@$(CC) $(CPPFLAGS) $(SRC) -c
	@ar rc $(LIB) $(OBJ)

clean:
	@make clean -C ./libft
	@make clean -C ./ls
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./ls
	@$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
