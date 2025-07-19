/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:41:16 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 13:47:36 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strlen - Conta o número de caracteres de uma string.
    Parâmetros:
        str → ponteiro para string NUL-terminada
    Retorno:
        Número de caracteres antes do '\0'
    Observações:
        - Não usa funções de biblioteca
        - Não conta o caractere nulo
*/
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}

/*
    #include <stdio.h>
    int main(void)
    {
        char    *str = "abcd";

        int len_str = ft_strlen(str);
        
        printf("[%d]\n", len_str);
        
        return(0);
    }
*/
