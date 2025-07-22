/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:07:37 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 19:52:57 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_is_valid_base - Verifica se base personalizada é válida
    Parâmetro:
        base → string contendo os símbolos da base (ex: "0123456789ABCDEF")
    Comportamento:
        - Retorna 0 se:
            - A base for nula ou tiver menos de dois caracteres
            - Contiver símbolos '+' ou '-'
            - Contiver caracteres repetidos
        - Retorna 1 se a base for válida
    Utilização:
        - Usada por ft_putnbr_base para garantir que a conversão ocorra corretamente
*/

#include <unistd.h>

int ft_is_valid_base(char *base)
{
    int i;
    int j;

    //Base vazia ou de tamanho 1
    i = 0;
    if (!base || !base[i] || !base[i + 1])
    {
        return(0);
    }

    //Verifica + ou -
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
        {
            return(0);
        }
        i++;
    }

    //Verifica duplicatas
    i = 0;
    while(base[i])
    {
        j = i + 1;
        while (base[j])
        {
            if (base[j] == base[i])
            {
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);
}

/*
    ft_putnbr_base - Imprime um número inteiro no terminal utilizando uma base personalizada.
    Parâmetros:
        nbr  → número inteiro a ser convertido e impresso
        base → string que representa os símbolos da base (ex: "0123456789ABCDEF")
    Comportamento:
        - Valida a base:
            - Deve conter pelo menos dois caracteres
            - Não pode conter os símbolos '+' ou '-'
            - Não pode conter caracteres duplicados
        - Se base for inválida, nada será impresso
        - Se número for negativo, o sinal '-' será impresso antes da conversão
        - Utiliza recursão para imprimir os dígitos da esquerda para a direita
        - Cada dígito é determinado pelo índice da base correspondente ao resto da divisão
    Observações:
        - Apenas a função write é utilizada
        - Compatível com bases personalizadas de qualquer tamanho válido (ex: binário, decimal, hexadecimal, poneyvif, etc.)
*/

void    ft_putnbr_base(int nbr, char *base)
{
    int     base_len;
    long    num;
    char    c;
    //Validar base
    if (!ft_is_valid_base(base))
    {
        return;
    }

    //Calcular tamanho da base
    base_len = 0;
    while (base[base_len])
    {
        base_len++;
    }

    num = nbr;
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
        
    //Recursão
    if (num >= base_len)
    {
        ft_putnbr_base(num / base_len, base);
    }

    c = base[num % base_len];
    write(1, &c, 1);
}

/*
int main(void)
{
    ft_putnbr_base(42, "0123456789");       //decimal == 42
    write(1, "\n", 1);

    ft_putnbr_base(42, "01");               //binário == 101010
    write(1, "\n", 1);

    ft_putnbr_base(255, "0123456789ABCDEF");//hexadecimal == FF
    write(1, "\n", 1);

    ft_putnbr_base(-42, "poneyvif");        //base octal estilizada == -vn
    write(1, "\n", 1);

    ft_putnbr_base(123456, "abcdef");       //base 6 personalizada == cdfbdca
    write(1, "\n", 1);

    ft_putnbr_base(1, "0");                 //base inválida == nada impresso
    write(1, "\n", 1);

    ft_putnbr_base(-2147483648, "0123456789"); //INT_MIN == -2147483648
    write(1, "\n", 1);

    return 0;
}
*/
