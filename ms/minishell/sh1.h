/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 03:16:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/25 00:59:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

#include <stdio.h>

# include <dirent.h>
# include <signal.h>

# define BUFF_SIZE	1024
# define PTH		path->path_name
# define PROCESS	42
# define TOP		65
# define UNT		66
# define REC		67
# define LIN		68
# define DEL		127
# define TAB		9
# define ISDIR		(!(((sb.st_mode | 4095) - 4095) - S_IFDIR))
# define ISLNK		(!(((sb.st_mode | 4095) - 4095) - S_IFLNK))
# define ISNODOL	(TL[TX] != '$' && TL[TX] != '~')
# define ISNOSPA	(TL[TX - 1] != ' ' && TL[TX - 1] != '\t')
# define ISNOSP		(TL[start + size] != ' ' && TL[start + size] != '\t')
# define CMP		ft_strcmp
# define NCMP		ft_strncmp
# define LEN		ft_strlen
# define RCHR		ft_strrchr
# define WORD		RCHR(word, '/') + 1
# define ISNOTMAIN	(!CMP(*(files[co->i]), ".") || !CMP(*(files[co->i]), ".."))
# define ISNTMAIN	(!CMP(**files, ".") || !CMP(**files, ".."))
# define COMP		!ft_strncmp(co->tmp, *(files[co->i]), k)
# define COOMP		!ft_strncmp(word, **files, k)
# define T			term
# define TBX		T->begin_x
# define TL			T->line
# define TX			T->x
# define TY			T->y
# define TERM		(params->term)
# define KFL		(params->term->kflags)
# define QFLAGS		KFL->zitate | KFL->zitat | KFL->lzitat
# define ALL_FLAGS	KFL->haken | KFL->akkolade | KFL->klammern | QFLAGS
# define KF			term->kflags
# define QFLAG		KF->zitate | KF->zitat | KF->lzitat
# define ALL_FLAG	KF->haken | KF->akkolade | KF->klammern | QFLAG

/*
**	----------------------------------------------------------------------------
*/
typedef enum		e_error
{
	Malloc,
	MissingFile,
	ExtraFlag,
	Access,
	Waitpid,
	TermInit
}					t_error;

/*
**	----------------------------------------------------------------------------
*/
typedef struct		s_log
{
	char			*line;
	char			*log_exec;
	char			*log_args;
	int				log_attempt;
	int				log_number;
	struct s_log	*next;
	struct s_log	*last;
}					t_log;

/*
**	----------------------------------------------------------------------------
*/
typedef struct		s_env
{
	char			*env_name;
	char			*value;
	struct s_env	*next;
}					t_env;

/*
**	----------------------------------------------------------------------------
*/
typedef struct		s_path
{
	char			*path_name;
	int				permission;
	struct s_path	*next;
}					t_path;

/*
**	----------------------------------------------------------------------------
*/
typedef struct		s_ncom
{
	char			**av;
	int				iscom;
	struct s_ncom	*next;
}					t_ncom;

/*
**	----------------------------------------------------------------------------
**	t_dir wird verwendet, Ordner zu schaffen.
*/

typedef struct		s_dir
{
	char			*name;
	char			***files;
	int				total;
	int				nb_files;
	int				nb_sdir;
	DIR				*dirp;
}					t_dir;

typedef struct		s_comp
{
	int				i;
	int				j;
	int				k;
	int				flag;
	int				check;
	char			*tmp;
	t_dir			*dir;
	char			*stock;
}					t_comp;

/*
**	----------------------------------------------------------------------------
**	zitat = '
**	lzitat = `
**	zitate = "
**	klammern = (
**	haken = [
**	akkolade = {
*/
typedef struct		s_kflag
{
	int				zitat;
	int				lzitat;
	int				zitate;
	int				klammern;
	int				haken;
	int				akkolade;
}					t_kflag;

/*
**	----------------------------------------------------------------------------
**	und = &
**	dpund = &&
**	oder = |
**	dpoder = ||
**	recht = >
**	dprecht = >>
**	links = <
**	dplinks = <<
*/
typedef enum		e_lflag
{
	und = 0x01,
	dpund = 0x02,
	oder = 0x04,
	dpoder = 0x08,
	recht = 0x10,
	dprecht = 0x20,
	links = 0x40,
	dplinks = 0x80
}					t_lflag;

/*
**	----------------------------------------------------------------------------
*/
typedef struct		s_term
{
	int				caps;
	int				term_x;
	int				term_y;
	int				curs_x;
	int				curs_y;
	char			*line;
	char			*cutter;
	int				begin_x;
	char			*prompt;
	int				size;
	int				x;
	int				y;
	int				wide;
	t_kflag			*kflags;
	int				lflags;
}					t_term;

/*
**	----------------------------------------------------------------------------
**	struct s_com	**com;
**	struct s_user	**user;
*/
typedef struct		s_par
{
	char			*log_path;
	char			*exec_path;
	char			*check_status;
	struct s_ncom	**ncom;
	struct s_log	**logs;
	struct s_log	**lcpy;
	struct s_env	**env;
	struct s_path	**path;
	struct s_term	*term;
}					t_par;

/*
**	----------------------------------------------------------------------------
*/
void				shell_error(int type, char *prob);
void				shell_warning(int type, char *prob);
void				shell_cure(int type, char *prob);

/*
**	----------------------------------------------------------------------------
**	t_com			**rcomm(t_par *params);
*/
int					soptions(int argc, char **argv, int *options);
t_env				**renv(t_env **env, char **envp);
t_log				**rlogs(t_par *params, char *path);
t_path				**rpath(t_par *params);

/*
**	----------------------------------------------------------------------------
**	t_com			*icom(char *name);
**	t_user			*iuser(char *name, char *pwd);
*/
t_par				*iparams(char **envp);
t_log				*ilog(char *line, int log_number);
t_path				*ipath(char *name);
t_env				*ienv(char *line);
t_ncom				*incom(char *multi);

/*
**	----------------------------------------------------------------------------
*/
void				ft_signal(pid_t mutter);
void				ft_wait(t_par *params, pid_t father);
void				regprocess(t_par *params, int *first_log);
char				**command_line(t_par *params);
void				do_exec(char **env, char **av, t_par *params);
void				do_protect(t_par *params);

/*
**	----------------------------------------------------------------------------
*/
void				env_check(t_par *params, t_env **env, char **av);
void				penv(t_env **env);
void				senv(t_par *params, t_env **env, char **av);
void				uenv(t_env **env, char **av, t_par *params);
int					kick_env(t_env **env, char *av);
void				push_env(t_env **env, char *line);
void				env_exec(t_par *params, t_env **env, char **av);
void				schdir(t_env **env, char **av);
void				reset_cd(t_env **env);
void				spath(t_path **paths, char *value);
void				set_path(t_par *params, char *av);
void				set_shlvl(t_env **env);
void				command_exec(t_par *params, t_env **env, char **av);
void				plog(t_log **logs, char **av);
void				ft_ls(int argc, char **argv);
void				ft_cat(char **av);
void				ft_grep(char **av);
t_ncom				*ncommands(t_ncom **ncom, char **multi);
t_ncom				*kick_ncom(t_ncom **ncom);
void				pmanp(char **av, char *exec_path);
void				ft_help(char **av, char *exec_path);
void				ft_echo(char **av);
char				*ft_replacedol(char *line, t_env **env, t_par *params);
char				*ft_replacetild(char *line, t_env **env, t_par *params);
void				do_exit(char **av);

/*
**	----------------------------------------------------------------------------
*/
int					term_init(void);
int					term_coord(void);
int					outc(int c);
void				put_prompt(char *prompt, t_par *params);
void				ins_char(t_term *term, char push);
void				del_char(t_term *term);
char				*tab_tline(t_par *params);
int					ft_getbrack(t_par *params);
void				ft_isbrack(char c, t_term *term);
int					ft_isbrack2(char c);
void				term_infos(t_term *term);
void				put_newprompt(t_par *params, int flag);
void				get_size(int x, int y, t_par *params);
void				clear_afterword(t_term *term);
void				clear_afterline(t_term *term);
void				clear_afterslash(t_term *term);
void				set_termkappa(void);
void				del_size(t_term *term, int size);

void				get_history(t_log **glogs, t_term *term, int way);
t_log				**log_cpy(t_log **logs, t_term *term);
t_log				*log_dup(t_log *log);
void				put_termstr(t_term *term, char *str);
void				flcpy(t_log **logs);

void				move_it(int way, t_term *term);
void				move_up(t_term *term);
void				move_right(t_term *term);
void				move_down(t_term *term);
void				move_left(t_term *term);
void				move_to(t_term *term, int get);

void				auto_comp(t_term *term, int flag, t_par *params);
int					write_comp(char *word, t_dir *dir, t_comp *co, t_term *te);
void				put_dol(t_term *term, t_par *params, char *word);
int					put_comp(t_dir *dir, char *word, t_term *term);
int					put_solo(char ***files, char *word, int k, t_term *term);
void				gdir(t_dir *dir, int *options);
t_dir				*get_dir(char *word, t_dir *dir);
t_dir				*del_dir(t_dir *dir);
t_dir				*isdir(char *word);
int					ft_isdir(char *str);
int					ft_isdir2(char *str);
t_dir				*idir2(char *name);
void				ffiles(char ****files);
char				***ft_dtri(t_dir *dir, int *options);
void				put_prline(t_term *term);
char				*get_dirpart(char *word);
t_env				*check_sub(char *line, t_env **env);
t_env				*check_nsub(char *line, t_env **env);

/*
**	----------------------------------------------------------------------------
*/
char				*add_char(char *str, char c);
int					begin_space(char *line, int x);
int					env_parse(char *av);
void				ftab(char **tab);
char				*ft_concat(char *s1, char *s2, int pot);
char				*ft_del_quote(char *str);
int					ft_isspace(char c);
char				*ft_join(char *s1, char *s2);
t_env				*ft_list_reverse(t_env **get);
t_log				*ft_list_reverse2(t_log **get);
t_ncom				*ft_list_reverse3(t_ncom **get);
void				ft_putescstr(char const *s);
int					ft_space(char c);
char				**ft_splitspaces(char *str);
int					ft_strisnum(char *get);
char				**ft_strsplit2(char *str, char c);
int					get_next_line(int fd, char **line);
int					get_next_line2(int fd, char **line);
char				**get_av(t_par *params, int first_log);
char				*iscom(char *av);
int					last_char(char *str, char c);
void				push_log(t_par *params, char *line);
char				**tab_realloc(char **tab, int new_size, int range);
int					tab_size(char **tab);
char				**tabenv(t_env **env);

#endif
