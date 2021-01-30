#include<stdio.h>

#define NUM_PESSOAS 2

typedef struct{
	char nome[50];
	unsigned long cpf;
	unsigned char idade;
}pessoa;

char validaCPF(unsigned long cpf){
	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpf%10;
	cpf = cpf/10;
	int penultimo = cpf%10;
	cpf = cpf/10;
	
	somatorioValidaUltimo = penultimo*2;
	for(int i=2; i <= 11; i++){
		modulo = cpf%10;
		cpf = cpf/10;
		somatorioValidaPenultimo += modulo*i;
		somatorioValidaUltimo += modulo*(i+1);
	}
	modulo = somatorioValidaPenultimo%11;
	if(modulo < 2){
		if(!penultimo)
			return 0;//cpf invalido
	}else{
		if(penultimo != 11 - modulo)
			return 0;//cpf invalido
	}
	modulo = somatorioValidaUltimo%11;
	if(modulo < 2){
		if(!ultimo)
			return 0;//cpf invalido
	}else{
		if(ultimo != 11-modulo)
			return 0;//cpf invalido
	}
	return 1;//cpf valido
}

int main(){
	pessoa pessoas[NUM_PESSOAS];
	
	for(int i=0; i < NUM_PESSOAS; i++){
		printf("Digite o nome: ");
		scanf("%s", pessoas[i].nome);
		printf("Digite o cpf: ");
		scanf("%lu", &pessoas[i].cpf);
		while(!validaCPF(pessoas[i].cpf)){
			printf("CPF invalido. Digite outro: ");
			scanf("%lu", &pessoas[i].cpf);
		}
		printf("CPF Valido\n");
		printf("Digite a idade: ");
		scanf("%hhu", &pessoas[i].idade);

		printf("Usuario Cadastrado: %s\t%lu\t%hhu\n", pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade);
	}

	printf("Fim!\n");

	return 0;
}
