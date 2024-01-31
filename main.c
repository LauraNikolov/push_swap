
#include "test.h"

static void ft_free_tab(t_list *a)
{
    t_list *tmp;

    while(a)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
}



int main(int ac, char **av)
{
    t_list *a;
    t_list *b;
    ft_parse(av, ac, &a);
    ft_arg_is_ok(a);
    ft_pb(&a, &b);
    ft_pb(&a, &b);

   /*  printf("a\n");
    ft_print_list(a);
    printf("b\n");
    ft_print_list(b);
 */
    ft_push_swap(&a, &b);
    
  /*   printf("a\n");
    ft_print_list(a);
    printf("b\n");
    ft_print_list(b); */
    //ft_free_tab(a);
    //ft_free_tab(b);


}

