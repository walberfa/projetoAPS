#include<stdio.h>
#include<locale.h>
#include<string.h>

int opcao = 0;

void FazerLogin(){

    char login[15] = "wbr42";
    char login1[15];
    char senha[15] = "123";
    char senha1[15];   
	int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro     

    while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\nDADOS INVALIDOS!\n\n");    
    }

}

void MostrarMenu(){

    printf("*************************************\n\n");
    printf("******SEJA BEM VINDO AO TCCZANDO******\n\n");
    printf("*************************************\n\n");

    printf("1) - CADASTRO DE ALUNO\n");
    printf("2) - CADASTRO DE PROFESSOR\n");
    printf("3) - CADASTRAR TCC\n\n");    
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    getchar();    

}

void CadastroAlunos(){

    printf("\n\nAdicione os dados do Aluno\n");

}

void CadastroProfessores(){

    printf("\n\nAdicione os dados do Professor\n");

}

void CadastroProjeto(){

    printf("\n\nAdicione os dados do TCC\n");

}

int main(){

    setlocale(LC_ALL, "");

    FazerLogin();

    MostrarMenu();

        switch (opcao)

        {

            case 1 : // Gravar Clientes

                CadastroAlunos();

            break;

            case 2 : // Gravar Corretores

                CadastroProfessores();

            break;
            
            case 3 : // Gravar TCC
		
		CadastroProjetos();
			
            break;

            default :

                printf("Opção Invalida!");

            break;    
        }

        getchar();



    return 0;
}
