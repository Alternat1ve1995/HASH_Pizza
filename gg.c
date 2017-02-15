#include "pizza_header.h"

static int          ft_amount(int a, int max)
{
    int             i;
    static int      amount = 0;

    i = 0;
    while (++i <= a)
        if (a % i == 0)
            amount++;
    if (a < max)
        amount = ft_amount(a + 1, max);
    return (amount);
}

static t_fig        *ft_find_shapes(t_fig *lst, int nb, int x)
{
    if (nb < x)
        return (lst);
    if (nb % x == 0)
    {
    lst->x = x - 1;
        lst->y = nb / x - 1;
        lst += 1;
    }
    return (ft_find_shapes(lst, nb, x + 1));
}

t_fig               *ft_possible_shapes(int min, int sq, int **inp)
{
    t_fig       *lst;
    t_fig       *list;
    int         amount;

    min = min * 2 - 1;
    amount = ft_amount(min, sq);
    lst = (t_fig *)malloc(sizeof(t_fig) * amount);
    list = lst;
    while (++min <= sq)
        lst = ft_find_shapes(lst, min, 1);
    (*inp)[4] = amount;
    return (list);
}