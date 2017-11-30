#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///função que verifica se um caracter pertece a uma string
int verificaseexiste (char a,int i, char *b){
	int j=0;
	for(;j<i;j++){
		if(a == b[i]) return 1;
	}
	return 0;
}


int main(int argc, char *argv[ ])
{
    char c, caminholeitura[100];
    char caminhosaida[500];
    char aminoacidos[500] = {"ARNDCEQGHILKMFPSTWYVUOXBZJ"};
    caminholeitura[0] = caminhosaida[0] = aminoacidos[26] = '\0';
    int qtaminoacidos = strlen(aminoacidos);

    strcpy(caminholeitura, argv[1]);
    strcpy(caminhosaida, argv[1]);
    printf("sai");
    if(caminholeitura[0] == '\0' || caminhosaida[0] == '\0'){
        printf("Não foram passados os parâmetros de entrada e saida. Necessario passar o diretorio do arquivo a ser lido e o diretorio do arquivo de saida\n");
        system("pause");
    }
    if(caminholeitura[0] == caminhosaida[0]){
        printf("O arquivo de entrada não pode ser o mesmo de saida.\n");
        system("pause");
    }

    FILE *fileleitura, *fileescrita;
    int i = 0, j=0;
    fileescrita = fopen(caminhosaida, "w");
    fileleitura = fopen(caminholeitura, "r");
    if(fileleitura == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }
    while( (c=fgetc(fileleitura))!= EOF ){
        if(verificaseexiste(c, qtaminoacidos, aminoacidos)){
            fprintf(fileescrita, "%c", c);
        }
    }

    fclose(fileleitura);
    fclose(fileescrita);
    return 0;
}
