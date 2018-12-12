/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mask.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 11:14:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 14:32:33 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long    ft_mask(int c)
{
    long    l;

    l = c & 0xff;
    l |= (l << 8);
    l |= (l << 16);
    l |= (l << 16) << 16;
    return (l);
}
