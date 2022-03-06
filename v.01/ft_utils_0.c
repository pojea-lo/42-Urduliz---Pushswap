#include "push_swap.h"

void    ft_zero (t_st *in, t_opt *mov)
{
   if (in->size_a == 4 || in->size_a == 5)
   {
        ft_pb(in);
        ft_pb(in);    
   }
   ft_printf(in->a, in->size_a);    
   ft_printf(in->b, in->size_b);
   ft_three (in, mov);
   if (in->size_b != 0)
   {
   ft_five (in);//, mov);
   }
}

void    ft_three (t_st *in, t_opt *mov)
{
    ft_minmax(in, mov);
    if (in->size_a < 4)
    {
        if (in->a[0] == mov->ma)
        {
            ft_ra(in->a, in->size_a);
            if (in->a[0] > in->a[1])
                ft_sa(in->a, in->size_a);
        }
        else if (in->a[0] == mov->na)
        {
            ft_rra(in->a, in->size_a);
            ft_sa(in->a, in->size_a);
        }
        else
        {
            if (in->a[1] > in->a[2])
                ft_rra(in->a, in->size_a);
            else
                ft_sa(in->a, in->size_a);
        }
    }
}

void    ft_five (t_st *in)//, t_opt *mov)
{
//    ft_printf(in->a, in->size_a);    
//    ft_printf(in->b, in->size_b);
    int i;
    int j;
    int mr; //movimientos ra o rra
    int cc; //tipo de mov, u si es ra y d si es rra

    i = 0;
    while (i < in->size_b)
    {
        j = 0;
        while (j < in->size_a)
        {
            if (in->b[i] < in->a[j])
            {
                if (j < 2)
                {
                    mr = j;
                    cc = 'u';
                }                    
                else
                {   
                    mr = in->size_a - j;
                    cc = 'd';
                }
            //    break;         
            }
            if (in->b[i] > in->a[j])
            {
                if (j < 2)
                {
                    mr = j;
                    cc = 'u';
                }
                else
                {   
                    mr = in->size_a - j;
                    cc = 'd';
                }                
            }
            j++;
        }
        while (mr != 0)
        {
            if (cc == 'u')
                ft_ra(in->a, in->size_a);
            if (cc == 'd')
                ft_rra(in->a, in->size_a);
            mr--;
        }
        ft_pa(in);
        ft_printf(in->a, in->size_a);    
        ft_printf(in->b, in->size_b);
    //    i++;
    }
}