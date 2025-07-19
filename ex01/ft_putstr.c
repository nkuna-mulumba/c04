/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:50:03 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 13:57:18 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_putstr - Imprime uma string de caracteres no terminal.
    Parâmetros:
        str → ponteiro para string NUL-terminada a ser exibida
    Comportamento:
        - Itera cada caractere da string
        - Usa write para imprimir cada caractere individualmente
    Observações:
        - Não adiciona espaços nem quebra de linha automaticamente
        - Não trata ponteiro nulo (é esperado que str seja válido)
*/

#include <unistd.h>
void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

/*
    int main(void)
    {
        char    *str = "ABCD";
        
        ft_putstr(str);
        
        write(1, "\n", 1);
        
        return(0);
    }
*/