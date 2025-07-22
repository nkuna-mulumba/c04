/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:59:10 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 15:40:36 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_putnbr - Imprime um número inteiro no terminal.
    Parâmetros:
        nb → número inteiro (positivo ou negativo) a ser impresso
    Comportamento:
        - Imprime os dígitos um por um usando write
        - Se nb for negativo, imprime o sinal '-'
        - Trata o caso especial de INT_MIN para evitar overflow
        - Utiliza recursão para imprimir dígitos da esquerda para a direita
    Observações:
        - Não imprime espaços nem quebra de linha automaticamente
        - Não usa nenhuma função da biblioteca padrão
*/

#include <unistd.h>

void    ft_putnbr(int nb)
{
    long    num;
    char    c;

    num = nb;
    if (num == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }

    if (num >= 10)
    {
        ft_putnbr(num / 10);
    }    

    c = (num % 10) + '0';
    write(1, &c, 1);
}

/*
    int main(void)
    {
        int nb = 42;
        ft_putnbr(nb);
        write(1, "\n", 1);
        return(0);
    }
*/
