#include "pizza.h"

static int	min_slice_max_pos(t_fig *el, int ing, int m_sl, int size_l)
{
	int k;
	int slice;

	slice = 0;
	k = 0;
	while (k < size_l)
	{
		i = 0;
		while (i <= el->y)
		{
			j = -1;
			while (j <= el->x)
				slice++;
		}
		if (slice - 1 > ing * 2)
			return (k);
	}
}

static void		fill_pice(int ***ar, int i, int j, t_fig *el, int num)
{
	int z;
	int k;

	z = i;
	while (z <= el->y + i)
	{
		k = j;
		while (k <= el->x + i)
		{
			(*ar)[z][k] = num;
			k++;
		}
		z++;
	}
}

static int			fit_to_border(int i, int j, t_fig *el, int *inp, int **ar) 
{
	int k;
	int z;

	z = i;
	if ((i + y) < inp[0] && (j + x) < inp[1])
	{
		while (z <= el->y + i)
		{
			k = j;
			while (k <= el-x + j)
			{
				if (ar[i][k] != 0 || ar[i][k] != 1)
					return (0);
				k++;
			}
			z++;
		}
		return (1);
	}
	return (0);
}

static void		push_min_sq(t_fig *el, int ***ar, int *inp)
{
	int i;
	int j;
	int m_sl;
	int num;

	num = 2;
	m_sl = min_slice_max_pos(el, inp[2], inp[3], inp[4]);
	i = -1;
	while (++i < inp[0])
	{
		j = -1;
		while (++j < inp[1])
		{
			k = -1;
			while (++k < m_sl)
				if (check(i, j, el[k], inp, *ar) == 1)
				{
					fill_pice(ar, i, j, el[k], num);
					num++;
				}
		}
	}
}