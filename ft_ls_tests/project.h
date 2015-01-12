#ifndef	PROJECT_H
# define PROJECT_H
# include <fw.h>
# include <regex.h>

char	*get_cmd_out(const char *cmd);
char	*sandbox_cmd(const char *cmd);
void	reset_sandbox();
char	*ls(const char *options);
char	*ft_ls(const char *options);
char	*ls_err(const char *options);
char	*ft_ls_err(const char *options);
char	*strip_illegal_opt_err(char *str);
char	*strip_no_such_file_or_dir(char *str);
void	print_ls_debug(const char *cmd);

#endif