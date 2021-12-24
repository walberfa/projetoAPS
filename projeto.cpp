#include<stdio.h>
#include<locale.h>
#include<string.h>

int opcao = 0;

struct pessoa{
    char nome[20],cpf[11],endereco[20],email[20],telefone[11];
    int dia,mes,ano;
};

struct aluno{
    char matricula[10],curso[10];
    int semestre;
};

struct prof{
    char siape[10];
    int status;
};

struct doc{
    char tema[20];
    int status,id_aluno,id_orientador;
};


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
    printf("3) - CADASTRO DE TCC\n\n");    
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    getchar();    

}

/*Criacao dos arquivos*/
    FILE *aluno,*professor,*projeto;

void CadastroAlunos(){

    struct pessoa alunos;
    struct aluno aluno1;

    /*Arquivos onde serÃ£o armazenados os dados*/
    aluno = fopen("aluno.txt", "a+");

    /*Realizar o cadastro do cliente*/

    printf("Entre com o nome: ");
    scanf("%s",alunos.nome);
    
    while (strcmp(alunos.nome,"FIM")){
        
        printf("Entre com o CPF: ");
        scanf("%s",alunos.cpf);
        printf("Entre com o numero de matricula: ");
        scanf("%s",aluno1.matricula);
        printf("Entre com o curso: ");
        scanf("%s",aluno1.curso);
        printf("Entre com o semestre: ");
        scanf("%d",&aluno1.semestre);
        printf("Entre com o dia de nascimento: ");
        scanf("%d",&alunos.dia);
        printf("Entre com o mes de nascimento: ");
        scanf("%d",&alunos.mes);
        printf("Entre com o ano de nascimento: ");
        scanf("%d",&alunos.ano);
        printf("Entre com o endereco: ");
        scanf("%s",alunos.endereco);
        printf("Entre com o email: ");
        scanf("%s",alunos.email);
        printf("Entre com o telefone de contato: ");
        scanf("%s",alunos.telefone);
        

        /*Gravacaoo de dados no arquivo aluno.txt*/
        fprintf(aluno,"Nome: %s  CPF: %s  Data de Nascimento:%d/%d/%d Endereco: %s Email: %s  Telefone: %s Numero de matricula: %s Curso: %s Semestre: %d \r\n",alunos.nome,alunos.cpf,alunos.dia,alunos.mes,alunos.ano,alunos.endereco, alunos.email,alunos.telefone,aluno1.matricula,aluno1.curso,aluno1.semestre);

        /*Realizar um novo cadastro*/
        printf("\nEntre com o novo nome (se não, digite FIM): ");
        scanf("%s",alunos.nome);
    }

    /*Fechar o arquivo*/
    fclose(aluno);

}

void CadastroProfessores(){

    struct pessoa prof;
    struct prof prof1;

    /*Arquivos onde serÃ£o armazenados os dados*/
    professor = fopen("professor.txt", "a+");

    /*Realizar o cadastro do cliente*/

    printf("Entre com o nome: ");
    scanf("%s",prof.nome);
    
    while (strcmp(prof.nome,"FIM")){
        
        printf("Entre com o CPF: ");
        scanf("%s",prof.cpf);
        printf("Entre com o numero do siape: ");
        scanf("%s",prof1.siape);
        printf("Entre com o dia de nascimento: ");
        scanf("%d",&prof.dia);
        printf("Entre com o mes de nascimento: ");
        scanf("%d",&prof.mes);
        printf("Entre com o ano de nascimento: ");
        scanf("%d",&prof.ano);
        printf("Entre com o endereco: ");
        scanf("%s",prof.endereco);
        printf("Entre com o email: ");
        scanf("%s",prof.email);
        printf("Entre com o telefone de contato: ");
        scanf("%s",prof.telefone);
        printf("Entre com o status: ");
        scanf("%d",&prof1.status);        

        /*Gravacaoo de dados no arquivo aluno.txt*/
        fprintf(professor,"Nome: %s  CPF: %s  Data de Nascimento:%d/%d/%d Endereco: %s Email: %s  Telefone: %s Numero do Siape: %s Status: %d \r\n",prof.nome,prof.cpf,prof.dia,prof.mes,prof.ano,prof.endereco, prof.email,prof.telefone,prof1.siape,prof1.status);

        /*Realizar um novo cadastro*/
        printf("\nEntre com o novo nome (se não, digite FIM): ");
        scanf("%s",prof.nome);
    }

    /*Fechar o arquivo*/
    fclose(professor);


}

void CadastroProjetos(){

    struct doc tcc;

    /*Arquivos onde serao armazenados os dados*/
    projeto = fopen("tcc.txt", "a+");

    /*Realizar o cadastro do cliente*/

    printf("Entre com o tema da pesquisa: ");
    scanf("%s",tcc.tema);
    
    while (strcmp(tcc.tema,"FIM")){
        
        printf("Entre com o aluno: ");
        scanf("%d",&tcc.id_aluno);
        printf("Entre com o orientador: ");
        scanf("%d",&tcc.id_orientador);
        printf("Entre com o status: ");
        scanf("%d",&tcc.status);        

        /*Gravacaoo de dados no arquivo aluno.txt*/
        fprintf(projeto,"Tema da pesquisa: %s Aluno: %d  Orientador %d Status: %d \r\n",tcc.tema,tcc.id_aluno,tcc.id_orientador,tcc.status);

        /*Realizar um novo cadastro*/
        printf("\nEntre com o novo tema (se não, digite FIM): ");
        scanf("%s",tcc.tema);
    }

    /*Fechar o arquivo*/
    fclose(projeto);


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
