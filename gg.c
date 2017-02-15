static int             ft_amount(int a, int max)
{
    int     i;
    static int     amount = 0;

    i = 0;
    while (++i <= a)
        if (a % i == 0)
            amount++;
    if (a < max)
        amount = ft_amount(a + 1, max);
    return (amount);
}

static shapes_lst     *ft_find_shapes(shapes_lst *lst, int nb, int x)
{
    shapes_lst  *adr;

    adr = lst;
    if (nb < x)
        return (adr);
    if (nb % x == 0)
    {
        lst->x = x - 1;
        lst->y = nb / x - 1;
        adr = ft_find_shapes(lst + 1, nb, x + 1);
    }
    else
        adr = ft_find_shapes(lst, nb, x + 1);
    return (adr);
}

shapes_lst      *ft_possible_shapes(int min, int sq, int **inp)
{
    shapes_lst  *lst;
    shapes_lst  *list;
    int         amount;
    int         len;
    int         i;

    len = 0;
    i = 0;
    min = min * 2;
    amount = ft_amount(min, sq);
    lst = (shapes_lst *)malloc(sizeof(shapes_lst) * amount);
    list = lst;
    while (min <= sq)
    {
        lst = ft_find_shapes(lst, min, 1);
        min++;
    }

    *inp[4] = amount;
    return (list);
}