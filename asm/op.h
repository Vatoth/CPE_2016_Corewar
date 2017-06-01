/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sat Apr  1 20:30:04 2017 Quentin Sonnefraud
*/

#ifndef OP_H_
# define OP_H_

# define MAX_ARGS_NUMBER         4

# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define REGISTER_CHAR		 'r'
# define SEPARATOR_CHAR          ','

# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"

# define REG_NUMBER      16

typedef char    args_type_t;

# define T_REG           1
# define T_DIR           2
# define T_IND           4

# define T_LAB           8

typedef struct	s_op
{
  char         *mnemonique;
  char         nbr_args;
  args_type_t  type[MAX_ARGS_NUMBER];
  char         code;
  int          nbr_cycles;
  char         *comment;
}		t_op;

# define REG_SIZE        4
# define IND_SIZE        2
# define DIR_SIZE        REG_SIZE

/*
** header
*/

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
# define COREWAR_EXEC_MAGIC      0xea83f3

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

#endif /* !OP_H_ */
