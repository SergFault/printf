#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define NULL_SPEC	0b00000000
# define I_SPEC		0b00000001
# define U_SPEC		0b00000010
# define C_SPEC		0b00000100
# define S_SPEC		0b00001000
# define P_SPEC		0b00010000
# define X_SPEC		0b00100000
# define UPX_SPEC	0b01000000
# define D_SPEC		0b10000000
# define UPPER		1
# define LOWER		0

typedef struct s_specs
{
	int				flag_dot;
	int				flag_zero;
	int				flag_minus;
	int				negative_signed;
	int				width;
	int				precision;
	unsigned int	specifier;
}	t_specs;

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
void	parse_flags(t_specs *specs, const char **fstr);
void	parse_precision(t_specs *specs, const char **fstrptr, va_list ap);
int		parse_specifier(t_specs *specs, const char **fstrptr);
void	parse_width(t_specs *specs, const char **fstr, va_list ap);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_max_int(int i1, int i2);
int		ft_padding(int width, char c);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_itoua(int n);
char	*ft_utoa(unsigned int num);
char	*ft_ui_to_hex(unsigned long ui, int up_lo_pref_flag, int prefix);
char	*ft_strdup(const char *s);
int		string_processor(t_specs *specs, va_list va);
int		integer_processor(t_specs *specs, va_list va);
int		unsigned_processor(t_specs *specs, va_list va);
int		char_processor(t_specs *specs, va_list va);
int		hex_processor(t_specs *specs, va_list va);
int		parse_fail_processor(const char **str_ptr);
void	struct_processor(t_specs *specs);
#endif
