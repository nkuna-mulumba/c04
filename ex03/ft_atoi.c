/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:45:15 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 17:20:00 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_atoi - Converte uma string em valor inteiro.
    Parâmetros:
        str → ponteiro para string a ser convertida
    Comportamento:
        - Ignora espaços em branco no início
        - Processa múltiplos sinais '+' e '-' (paridade de '-' define sinal final)
        - Constrói valor decimal até encontrar caractere não numérico
    Observações:
        - Não trata overflow/underflow
        - Retorna 0 se não houver dígitos após sinais/espaços
*/

int ft_atoi(char *str)
{
    int i;
    int sig;
    int nbr;
    
    //Ignorar espaços
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
    {
        i++;
    }
    //Processar sinais múltiplos
    sig = 1;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sig *= -1;//
        }
        i++;
    }
    //Construir o número
    nbr = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = (nbr * 10) + (str[i] - '0');
        i++;
    }
    return(sig * nbr);
}

/*
    #include <stdio.h>
    int main(int argc, char **argv)
    {
        (void)argc;
        printf("%d\n", ft_atoi(argv[1]));
        return(0);
    }
*/