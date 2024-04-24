/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:29:02 by muoz              #+#    #+#             */
/*   Updated: 2024/04/24 19:34:53 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_message(int flag)
{
	if (flag == 1)
		printf("Not interpret unclosed quotes\n");
	if (flag == 2)
		printf("syntax error near unexpected token `newline'\n");
	if (flag == 3)
		printf(" syntax error near unexpected token `|'\n");
}

#include <stdio.h>

void ft_pass_quote(char *command_line, int *i) {
    int quote_flag = 0;

    if (command_line[*i] == '\"') // Determine flag based on the type of quote
        quote_flag = 1;
    else if (command_line[*i] == '\'')
        quote_flag = 2;

    // Move forward until the corresponding closing quote is found
    while (command_line[++*i]) {
        if ((quote_flag == 1 && command_line[*i] == '\"') ||
            (quote_flag == 2 && command_line[*i] == '\'')) {
            (*i)++;  // Move past the closing quote
            break;
        }
    }
}

int ft_layer_cal(char *command_line) {
    int i = 0;
    int ret = 0;

    while (command_line[i]) {
        // Skip spaces to find the start of a segment
        while (command_line[i] == ' ') i++;

        // If we reach the end of the string after skipping spaces, break
        if (command_line[i] == '\0') break;

        // Start a new segment
        ret++;

        // Move to the end of the current segment
        while (command_line[i] && command_line[i] != ' ' && command_line[i] != '|' && command_line[i] != '>' && command_line[i] != '<') {
            if (command_line[i] == '\"' || command_line[i] == '\'') {
                ft_pass_quote(command_line, &i);
            } else {
                i++;
            }
        }

        // Skip the separator and handle case where separator is at the end
        if (command_line[i] && (command_line[i] == '|' || command_line[i] == '>' || command_line[i] == '<')) {
            i++;
            if (command_line[i] == '\0') { // Check if the separator is at the end
                break;
            }
        }
    }

    return ret;
}

int	ft_pre_pars(char *command_line)
{
	int error;

	error = 0;
	error += ft_check_quote(command_line); //burada " ve ' için kapanmama durumu kontrol ediliyor
	error += ft_pipe_loc(command_line); //pipe başta olup olmadığını 
	error += ft_orientation_loc(command_line); //burada ">>" , "<<" ve ">" , "<" operatörlerinin en sonda bulunma durumu kontrol ediliyor
	return (error);
}

void	parse_command(char *command_line)
{
	int		i;
	t_data	*data;
	int 	error;

	error = ft_pre_pars(command_line); //tokenlerle ilgili yanlış kullanımları önceden pars ettiğimiz kısım
	if (!error)
	{
	data = malloc(sizeof(t_data)); //data ya yer ayırdık
	data->layer = ft_layer_cal(command_line); //datanın içerisinde bulunana int'e vewrdiğimiz komut satırını kaç katmanlı çift pointer'a ekliyeceğimizi belirliyoruz
	printf("->>>>%d\n", data->layer);
	data->command = malloc((data->layer + 1) * sizeof(char *)); //sondaki NULL pointerı da hesaba katıp yer açıyoruz
	}
	//Sevgili acar kodun şuanlık sonuna geldik malesef yarın mazın hayatın sert rüzgaralrının estiği zor koşulların diz boyu yükseldiği inşaat sektöründe çalışmaya gideceğimden saat 3:15 sularında uyuyacağım
	//anlayamadığın bir kısım olursa ----> 05423621593 <----- ban bu nbumaradan ulaşabilirsin en aşşağıda genel çözülmesi gereken sorunları yazdım 
}

int main() 
{
    char *command_line;

    while (1)
	{
		command_line = readline("my shell: "); //dışarıdan veri alımı
        if (command_line == NULL) {
            printf("An error occurred.\n");
            continue;
        }
        if (strcmp(command_line, "exit") == 0)
            break; // 'exit' komutu girildiyse çık
        parse_command(command_line); //pars başlangıç
		add_history(command_line); //geçmişe ekleme
    }
    return 0;
}

// error messageları döndürdükten sonra exit vermeden işlemi kesmemiz lazım nasıl yapacağımız hakkında hiçbir fikrim yok
// bişi daha vardıda şuan hatırlayamadım
// eğer bir hata yakalayamadıysan kodu devam ettirmek istersen datanın commandına yer açtım doldurmaya başlayabilirsin
// her > her < her | her kelime tek bir pointer tarafından tutulacak "" veya '' içerisinde olmaması taktirinde 
// yanlış olmasın >> veya << her bir karakteri bir pointer tutmalı yani >> bitişik değil data[0] = > ve data [1] = > gibi 