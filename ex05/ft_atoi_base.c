/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:52:35 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/19 20:58:07 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_is_valid_base - Verifica se uma base personalizada é válida para conversão
    Parâmetro:
        base → string contendo os símbolos da base (ex: "0123456789ABCDEF")
    Comportamento:
        - Retorna 0 se:
            - A base for nula ou tiver menos de dois caracteres
            - Contiver símbolos '+' ou '-'
            - Contiver espaços ou caracteres invisíveis (ASCII 9 a 13)
            - Contiver caracteres duplicados
        - Retorna 1 se a base for válida
    Utilização:
        - Usada por ft_atoi_base para garantir que a conversão numérica ocorra corretamente
*/

int ft_is_valid_base(char *base)
{
    int i;
    int j;

    //Verificar se base tem pelo menos dois símbolos válidos
    i = 0;
    if (!base || !base[i] || !base[i + 1])
    {
        return(0);
    }

    //Se base tiver sinais de '+' e '-', retona 0
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
        {
            return(0);
        }
        i++;
    }

    // Verificar duplicatas na base
    i = 0;
    while(base[i])
    {
        j = i + 1;
        while(base[j])
        {
            if(base[j] == base[i])
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
    ft_get_index - Retorna o índice de um caractere dentro de uma base fornecida.
    Parâmetros:
        c     → caractere a ser procurado
        base  → string representando os símbolos da base (ex: "0123456789ABCDEF")
    Comportamento:
        - Percorre a string base do início ao fim
        - Se o caractere c for encontrado na base, retorna seu índice (posição)
        - Se c não existir na base, retorna -1
        - Usado para determinar o valor numérico de um símbolo da base durante conversão
    Exemplo:
        ft_get_index('A', "0123456789ABCDEF") → retorna 10
        ft_get_index('9', "0123456789")       → retorna 9
        ft_get_index('Z', "0123456789ABCDEF") → retorna -1 (caractere não encontrado)
*/
int ft_get_index(char *base, char c)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (base[i] == c)
        {
            return(i);
        }
        i++;
    }
    return(-1);
}

/*
    ft_prepare_number_start - Analisa o início de uma string numérica
    Parâmetros:
        str → string contendo o número
        sig → ponteiro para sinal (positivo ou negativo)
    Comportamento:
        - Ignora espaços e caracteres invisíveis no início da string
        - Interpreta os sinais '+' e '-' acumulados (como em ft_atoi)
        - Atualiza o sinal via ponteiro (1 ou -1)
        - Retorna o índice onde começa a parte numérica válida da string
*/
int ft_prepare_number_start(char *str, int *sig)
{
    int i;

    i = 0;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
    {
        i++;
    }

    *sig = 1;
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            *sig *= -1;
        }
        i++;
    }
    return(i);
}

/*
    ft_atoi_base - Converte uma string para inteiro com base personalizada.
    Parâmetros:
        str  → string que representa o número (pode conter espaços e sinais)
        base → string com os símbolos válidos da base (ex: "0123456789ABCDEF")
    Comportamento:
        - Ignora espaços iniciais da string
        - Interpreta sinais '+' e '-' no início
        - Valida a base:
            - Deve conter pelo menos dois caracteres distintos
            - Não pode conter '+' ou '-' ou espaços/brancos invisíveis
            - Não pode conter caracteres duplicados
        - Constrói o número acumulando os valores conforme os índices na base
        - Para quando encontra um caractere que não existe na base
        - Retorna 0 se a base for inválida ou não houver dígitos válidos
    Funções autorizadas:
        - Nenhuma
*/

int ft_atoi_base(char *str, char *base)
{
    int base_len;
    int i;
    int sig;
    int nbr;
    int dig;

    // Validar a base fornecida
    if (!ft_is_valid_base(base))
    {
        return(0);
    }
    
    // Calcular o tamanho da base
    base_len = 0;
    while (base[base_len])
    {
        base_len++;
    }
    
    // Retornar numero valido
    i = ft_prepare_number_start(str, &sig);
        
    //Construir número com base nos caracteres válidos
    nbr = 0;
    while (str[i] && ft_get_index(base, str[i]) != -1)
    {
        dig = ft_get_index(base, str[i]);
        nbr = nbr * base_len + dig; //Acumula valor do número
        i++;
    }
    return(sig * nbr);
}

/*
    #include <stdio.h>
    int main(void)
    {
        // Teste com base decimal
        printf("Decimal: %d\n", ft_atoi_base("   -42", "0123456789"));

        // Teste com binário
        printf("Decimal: %d\n", ft_atoi_base("ab", "ba")); //2
        printf("Binário: %d\n", ft_atoi_base("101010", "01")); // → 42

        // Teste com hexadecimal
        printf("Hexa:    %d\n", ft_atoi_base("1A", "0123456789ABCDEF")); // → 26

        // Teste com base personalizada ("poneyvif")
        printf("Poney:   %d\n", ft_atoi_base("vif", "poneyvif")); // → 75

        // Teste com sinais misturados
        printf("Sinais:  %d\n", ft_atoi_base(" --+-2F", "0123456789ABCDEF")); // → -47

        // Base inválida
        printf("Inválido: %d\n", ft_atoi_base("123", "0")); // → 0

        return 0;
    }
*/