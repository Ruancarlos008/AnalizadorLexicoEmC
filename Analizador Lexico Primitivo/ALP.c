#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{

	int reiniciar = 1;
	do
	{

	char alfa[23] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
					'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', '\0'}; // tokens alfabeticos, sem as letras reservadas.
	char num[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}; // tokens num�rico.
	char var[6] = {'x', 'y', 'z', 't', 'w', '\0'}; // tokens reservados pelo sistema.
	char opm[8] = {'+', '-', '*', '/', '@', '#', '!', '\0'}; // tokens de operadores matem�ticos.
	char paa[6] = {'x(', 'y(', 'z(', 't(', 'w(', '\0'}; // tokens com parenteses abrindo
	char paf[6] = {'x)', 'y)', 'z)', 't)', 'w)', '\0'}; // tokens com parenteses fechando
	char cha[6] = {'x[', 'y[', 'z[', 't[', 'w[', '\0'}; // tokens com chaves abrindo
	char chf[6] = {'x]', 'y]', 'z]', 't]', 'w]', '\0'}; // tokens com cheves fechando
	char coa[6] = {'x{', 'y{', 'z{', 't{', 'w{', '\0'}; // tokens com coxetes abrindo
	char cof[6] = {'x}', 'y}', 'z}', 't}', 'w}', '\0'}; // tokens com coxetes fechando
	char cnaf[19] = {'x', 'y', 'z', 't', 'w', '+', '-', '*', '/', '@', '#', '!', '(', ')',
					'[', ']', '{', '}','\0'}; // Compilado de todos os tokens com exce��o dos alfab�ticos.
	char comp[51] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
				'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', '0', '1', '2', '3', '4', '5', '6', '7', '8',
				'9', 'x', 'y', 'z', 't', 'w', '+', '-', '*', '/', '@',
				'#', '!', '(',')', '{','}', '[',']', '\0'}; // Compilado de todos os tokens v�lidos da gram�tica.



	// 1� ENTRADA DE TOKENS LIMITADA A 10.

	char entrada[11];

	printf("insira os dados para an�lise: ");
	fflush(stdout);

	scanf("%10s", entrada);

	printf("\nVoc� inseriu esses caracteres: %s\n", entrada);
	fflush(stdout);

	//2�  COMPARA��O DOS TOKENS DIGITADOS COM A GRAM�TICA.

	char invalidos[11] = ""; // string para empilhar caracteres inv�lidos
	int n = 0;
	while (entrada[n] != '\0')
	{
		int m = 0;
	    while (comp[m] != '\0')
	    	{
	        	if (entrada[n] == comp[m])
	        	{
	        		break;
	        	}
	            m++;
	        }
	        if (comp[m] == '\0') // caractere n�o encontrado em comp
	        {
	            char str[2] = {entrada[n], '\0'}; // transforma o caractere em uma string.
	            strcat(invalidos, str); // desenpilhar o(s) caractere(s) inv�lido(s) � string.
	        }
	        n++;
	}

	    if (strlen(invalidos) > 0)
	    {
	        printf("\nO(s) caractere(s) %s nao pertence(m) a gramatica.\n", invalidos);
	        break;
	    }
	    else
	    {
	        printf("\nO(s) token(s) digitado(s) esta(�o) dentro da gram�tica.\n");
	    }

	    // ANALIZA SE A STRING � UMA PALAVRA RESERVADA DO SISTEMA.

	    if (entrada[0] >= '0' && entrada[0] <= '9')
	    {
	    	printf("\nPalavras iniciadas com n�meros s�o palavras "
	    			"reservadas do sistema.\n");
	    	break;
	    }



	    // 3� VERIFICA SE OS TOKENS ALFABETICOS E SE EST�O NA MESMA ENTRADA.

	    int i, j, alfa_encontrado, num_encontrado, cnaf_encontrado;
	    alfa_encontrado = 0; // supondo que inicialmente n�o h� caracteres alfab�ticos
	    num_encontrado = 0; // supondo que inicialmente n�o h� n�meros
	    cnaf_encontrado = 0; // supondo que inicialmente n�o h� caracteres da vari�vel cnaf

	    	for (i = 0; i < strlen(entrada); i++) // verifica se o caractere atual � alfab�tico
	    	{

	    		for (j = 0; j < 26; j++)
	    	    {
	    			if (entrada[i] == alfa[j])
	    	        {
	    				alfa_encontrado = 1;
	    	            	break;
	    	        }
	    	    }
	    			// verifica se o caractere atual � num�rico
	    	         	 for (j = 0; j < 10; j++)
	    	             {
	    	         		 if (entrada[i] == num[j])
	    	                 {
	    	                     num_encontrado = 1;
	    	                     break;
	    	                 }
	    	             }
	    	         	// verifica se o caractere atual � da vari�vel cnaf
	    	                for (j = 0; j < 19; j++)
	    	                {
	    	                    if (entrada[i] == cnaf[j])
	    	                    {
	    	                        cnaf_encontrado = 1;
	    	                        break;
	    	                    }
	    	                }
	    	}

	    	if (alfa_encontrado)
	    	{
	    		if (!cnaf_encontrado)
	    		{
	    			printf("\nEntrada v�lida.\n");
	    			return 0;
	    	    }
	    	    else if (cnaf_encontrado)
	    	    {
	    	    	printf("\nEntrada inv�lida: tokens alfab�ticos e tokens de express�es \n"
	    	               "matem�ticas n�o podem vir juntos.\n");
	    	        return 0;
	    	    }

	    	}
	    	else;




	    //LEITURA DE PARENTESES

	    int len_paa = strlen(paa);
	    int len_paf = strlen(paf);
	    int paa_found = 0;
	    int paf_found = 0;
	    int len = strlen(entrada);

	        for (int i = 0; i < len; i++)
	        {
	            for (int j = 0; j < len_paa; j++)
	            {
	                if (entrada[i] == paa[j])
	                {
	                    paa_found = 1;
	                    break;
	                }
	            }
	            if (paa_found)
	            {
	                for (int k = i + 1; k < len; k++)
	                {
	                    for (int l = 0; l < len_paf; l++)
	                    {
	                        if (entrada[k] == paf[l])
	                        {
	                            paf_found = 1;
	                            break;
	                        }
	                    }
	                    if (paf_found)
	                    {
	                        printf("A entrada � v�lida!\n");
	                        break;
	                    }
	                }
	                printf("A entrada � inv�lida!, parenteses devem ser fechados.\n");
	                break;
	            }
	        }














	} while (reiniciar == 1);

return 0;

}



