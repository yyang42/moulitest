#ifndef		PROJECT_H
# define	PROJECT_H
# include	<testframework.h>

char	*get_cmd_out(const char *cmd);
char	*sandbox_cmd(const char *cmd);
void	reset_sandbox();
char	*ls(const char *options);
char	*ft_ls(const char *options);
char	*ls_err(const char *options);
char	*ft_ls_err(const char *options);

#endif