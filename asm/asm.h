/*
** asm.h for asm in /home/Vatoth/Epitech/CPE_2016_corewar/ASM
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Wed Mar 22 13:57:41 2017 Quentin Sonnefraud
** Last update Mon Apr  3 09:16:32 2017 Quentin Sonnefraud
*/

#ifndef ASM_H_
# define ASM_H_

#include <stdlib.h>
#include "op.h"

typedef struct          s_parser
{
  char			*line;
  int			num_line;
  char                  *label;
  int                   addr_label;
  char                  *instruction;
  char                  **param;
  struct s_parser       *next;
  struct s_parser       *prev;
}                       t_parser;

typedef struct          s_list
{
  int			prog_size;
  struct s_parser       *first;
  struct s_parser       *last;
}                       t_list;

void    *my_memset(void *str, const int c, size_t n);
int	my_strlen(const char *);
int     my_compare(const char *s1, const char *s2, int i);
int     my_printf(const char *flag, ...);
int	init_header(t_header , int fd_output, int);
void    epur_str(char *str);
int	parser(char **tab, t_list *list);
int     my_strcmp(const char *s1, const char *s2);
void	write_instructions(int, t_list *);
int	my_getnbr(char *);
char	*my_strstr(char *s, char *);
void	get_addr(t_list *);
int	my_strlen(const char *);
void	help(void);
int	lend_to_bend(int);
int     redirect(const char *file);
void    epur_str(char *str);
char	count_tab(char **tab);
int     parser(char **tab, t_list *list);
char    *my_strdup(const char *src);
char    *get_name(const char *path);
char    **parse_instruction(const char *s);
char    **parse_param(const char *to_parse, const char *instruct,
		      t_list *list);
int     label_exist(t_list *list, const char *name);
int     label_call(t_list *list);
int	get_param_value(int fd, t_list *cont, char *param,
				t_parser *instruction);
int	get_lbl(t_parser *list, char *label, t_parser *instruction);
char	get_coding_byte(t_parser *instruction);
char	get_opcode(char *instruction);
void    my_puterror(char *s);
int     my_puterror_nbr(int nb);
int     take_name(const char *arg,
                  char header_name[PROG_NAME_LENGTH + 1]);
int     take_comment(const char *arg,
                     char header_comment[COMMENT_LENGTH + 1]);

#endif /* !ASM_H_ */
