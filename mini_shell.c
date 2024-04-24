/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:29:02 by muoz              #+#    #+#             */
/*   Updated: 2024/04/21 03:35:10 by muoz             ###   ########.fr       */
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

void	ft_pass_quote(char *command_line, int *i)
{
	int	quote_flag;

	if (command_line[*i] == '\"') //tırnak türüne göre flag belirleme
		quote_flag = 1;
	if (command_line[*i] == '\'') //tırnak türüne göre flag belirleme
		quote_flag = 2;
	while (command_line[++*i]) //flage göre gerekli tırnağı bulana kadar yani tırnak kapanana kadar ilerleme
	{
		if ((quote_flag == 1 && command_line[*i] == '\"') 
			|| (quote_flag == 2 && command_line[*i] == '\''))
		{
			quote_flag = 0; //flag sıfırlama ölesine :p
			break ;
		}
	}
}

int	ft_layer_cal(char *command_line)
{
	int	i;
	int	quote_flag;
	int	ret; //katman değeri dömüş değeri

	ret = 0;
	i = -1;
	while (command_line[++i])
	{
		if (i == 0 && command_line[i] == ' ') //dışarıdan gelen verilerimiz boşluk ile başlıyorsan katman değerimizi artırmadan sadece boşlukları geçiyoruz
			while (command_line && command_line[i] == ' ')
				i++;
		if (command_line[i] == '\"' || command_line[i] == '\'') //pre_parstan geçen doğru tırnak kullanımı ile tırnak içeriğini tüm seperatörlerden muaf tutmak için geçiyoruz
			ft_pass_quote(command_line, &i);
		if (command_line[i] == ' ' || command_line[i] == '|'
			|| command_line[i] == '>' || command_line[i] == '<') //seperatörlerimizi belirledik ve her biri için fazla fazlada olsa yer açıyoruz
		{
			while (command_line[i] && command_line[i] == ' ') // boşluk karakteri  diğer seplerden ziyade kendisi için yer açmamalı o yüzden geçiyoruz
				i++;
			if (command_line[i] != '\0') // boşluk karakteri en sonda ise katman değeri artmamalı bunun kontrolünü yapıyoruz
				ret++;
		}
	}
	return (ret + 1); //burayı çok sorgulama burayı bende tam anlamadım ama böle olmalı bu
}

void	ft_pre_pars(char *command_line)
{
	ft_check_quote(command_line); //burada " ve ' için kapanmama durumu kontrol ediliyor
	ft_pipe_loc(command_line); //burada ">>" , "<<" ve ">" , "<" operatörlerinin en sonda bulunma durumu kontrol ediliyor
	ft_orientation_loc(command_line); //burada ">>" , "<<" ve ">" , "<" operatörlerinin en sonda bulunma durumu kontrol ediliyor
}

void	parse_command(char *command_line)
{
	int		i;
	t_data	*data;

	ft_pre_pars(command_line); //tokenlerle ilgili yanlış kullanımları önceden pars ettiğimiz kısım
	data = malloc(sizeof(t_data)); //data ya yer ayırdık
	data->layer = ft_layer_cal(command_line); //datanın içerisinde bulunana int'e vewrdiğimiz komut satırını kaç katmanlı çift pointer'a ekliyeceğimizi belirliyoruz
	data->command = malloc((data->layer + 1) * sizeof(char *)); //sondaki NULL pointerı da hesaba katıp yer açıyoruz

	//Sevgili acar kodun şuanlık sonuna geldik malesef yarın mazın hayatın sert rüzgaralrının estiği zor koşulların diz boyu yükseldiği inşaat sektöründe çalışmaya gideceğimden saat 3:15 sularında uyuyacağım
	//anlayamadığın bir kısım olursa ----> 05423621593 <----- ban bu nbumaradan ulaşabilirsin en aşşağıda genel çözülmesi gereken sorunları yazdım 
}

int main() 
{
    char *command_line;

    while (1)
	{
		command_line = readline("Bir sey gir yarram: "); //dışarıdan veri alımı
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