
#include "libft.h"

void	*insert_mem(char *src, size_t src_size, char *rep,
			size_t rep_size, unsigned int pos)
{
	char	*new_mem;
	char	*before;
	char	*after;
	size_t	mem_len;

	if (!src)
		return (NULL);
	else if (!rep || pos >= src_size)
		return (src);
	mem_len = src_size + rep_size;
	new_mem = malloc(sizeof(char) * mem_len);
	before = memsub(src, 0, pos);
	after = memsub(src, pos, src_size - pos);
	memcat(new_mem, 0, before, pos);
	memcat(new_mem, pos, rep, rep_size);
	memcat(new_mem, pos + rep_size, after, src_size - pos);
	free(before);
	free(after);
	return (new_mem);
}
