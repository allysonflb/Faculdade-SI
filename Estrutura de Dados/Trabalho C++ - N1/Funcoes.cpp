#include <iostream>
#include "Auxiliar.h"
#include <stdlib.h>
#include <locale.h>
#include <limits>
using namespace std;

//Funções da Struct

void Aluno::Cadastro(){
	cout << "************************************************************";
	cout << "\nOlá\n";
	cout << "\nDigite o nome do Aluno: \n"; cin.getline(nome, 50);
	cout << "Digite a matricula do Aluno: \n"; cin >> matricula;
		do{
			if(cin.fail()){
			cout << "\nVocê digitou uma letra, digite novamente!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> matricula;		
			}
		}while(cin.fail());
	cout << "Digite a idade do aluno:\n"; cin >> idade;
		do{
			if(cin.fail()){
			cout << "\nVocê digitou uma letra, digite novamente!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> idade;		
			}else if(idade > 99){
				cout << "O número digitado é invalido, digite novamente!\n";
				cin >> idade;
			}else if(idade <=-1){
				cout << "O número digitado é negativo, digite novamente!\n";
				cin >> idade;
			}
		}while(cin.fail() || idade>99 || idade<=-1);	
	cout << "Digite a A1 do aluno:\n"; cin >> A1;
		do{
			if(cin.fail()){
			cout << "\nVocê digitou uma letra, digite novamente!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> A1;		
			}else if(A1 > 10){
				cout << "O número digitado é invalido, digite novamente!\n";
				cin >> A1;
			}else if(A1 <=-1){
				cout << "O número digitado foi negativo, digite novamente!\n";
				cin >> A1;
			}
		}while(cin.fail() || A1>10 || A1<=-1);		
	cout << "Digite a A2 do aluno:\n"; cin >> A2;
		do{
			if(cin.fail()){
			cout << "\nVocê digitou uma letra, digite novamente!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> A2;		
			}else if(A2 > 10){
				cout << "O número digitado é invalido, digite novamente!\n";
				cin >> A2;
			}else if(A1 <=-1){
				cout << "O número digitado foi negativo, digite novamente!\n";
				cin >> A2;
			}
		}while(cin.fail() || A2>10 || A2<=-1);
		MediaCalc();
}

void Aluno::Media(){	
	media = (A1*0.4)+(A2*0.6);
	cout << "A média do Aluno é: " << media;
}

float Aluno::MediaCalc(){
	media = (A1*0.4)+(A2*0.6);
	return media;
}

void Aluno::RevealAll(){
	cout << "\nO nome do aluno é: " << nome;
	cout << "\nA matricula do Aluno é: " << matricula;
	cout << "\nA A1 do aluno é: " << A1;
	cout << "\nA A2 do aluno é: " << A2;
	cout << endl;
	Media();
	cout << endl;
	Ap_Rp();
}

void Aluno::Ap_Rp(){
	if(media >= 6.0){
		cout << "Status Aprovado!";
	}else{
		cout << "Status Reprovado!";
	}
}	

void Aluno::Alt_Nota(){
	char Escolha;
	int Escolha2;
	bool aux=false;
	bool aux2=false;
	do{
	cout << "\nDeseja alterar a nota do aluno? Digite S para *SIM* e N para *NÃO*\n";
	cin >> Escolha;
	Escolha = toupper(Escolha);
	switch (Escolha){
		case 'S':
			do{			
			cout << "\nDeseja alterar a A1 ou A2?\n";
			cout << "\nDigite 1 para escolher A1 ou 2 para escolher A2!\n";
			cin >> Escolha2;
			do{
				if(cin.fail()){
					cout << "\nVocê digitou uma letra, digite novamente!" << endl;
					cout << "\nDigite 1 para escolher A1 ou 2 para escolher A2!\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> Escolha2;		
				}
			}while(cin.fail());
			switch (Escolha2){
				case 1:
					cout << "Digite a A1 do aluno: \n"; cin >> A1;
					do{
						if(cin.fail()){
							cout << "\nVocê digitou uma letra, digite novamente!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							cin >> A1;		
						}else if(A1 > 10){
							cout << "O número digitado é invalido, digite novamente!\n";
							cin >> A1;
						}else if(A1 <=-1){
							cout << "O número digitado foi negativo, digite novamente!\n";
							cin >> A1;
						}
					}while(cin.fail() || A1>10 || A1<=-1);
					aux = true;
					break;
				case 2:
					cout << "Digite a A2 do aluno: \n"; cin >> A2;
					do{
						if(cin.fail()){
							cout << "\nVocê digitou uma letra, digite novamente!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							cin >> A2;		
						}else if(A2 > 10){
							cout << "O número digitado é invalido, digite novamente!\n";
							cin >> A2;
						}else if(A1 <=-1){
							cout << "O número digitado foi negativo, digite novamente!\n";
							cin >> A2;
						}
					}while(cin.fail() || A2>10 || A2<=-1);
					aux = true;
					break;
				default:
					system("cls");
					cout << "Opção invalida!\nRetornando as opções!\n";
					break;							 
			}
			}while(aux==false);
			cout << "\n**********Dados do Aluno Atualizado!****************\n";
			MediaCalc();
			RevealAll();
			aux2 = true;
			break;	
		case 'N':
			cout << "\nVocê optou por não modificar a nota do aluno!\n";
			cout << "\nRetornando ao menu!\n";
			aux2 = true;
			break;
		default:
			system("cls");
			cout << "Opção invalida! Digite novamente!\n";
			fflush(stdin);
			break;
		}
	}while(aux2==false);
}

//Funçoes do programa

Aluno* Criar(int TAM){
	Aluno *A1, *Aux;
	A1 = (Aluno*)malloc(TAM*sizeof(Aluno));
	if(A1 == NULL){
		cout << "Error na alocação!";
		exit(0);
	}
	
	Aux = A1;
	
	for (int i=0; i<TAM; i++){
		fflush(stdin);
		Aux->Cadastro();
		Aux++;
	}
	system("CLS");
	cout << "\nAlocação Completa! " << TAM << " Alunos inseridos!\n";
	return A1;
}

Aluno* Aumentar_Vet(Aluno *Vetor, int *TAM){
	system("CLS");
	int TAux;
	int TAM2;
	Aluno *VAux;
	cout << "Digite quantos alunos serão inseridos: \n";
	cin >> TAM2;
	TAux = TAM2;
	TAM2 = *TAM+TAM2;
	VAux = (Aluno*)realloc(Vetor, TAM2*sizeof(struct Aluno));
	if(VAux != NULL){
		Vetor = VAux;
		cout << "Realocação bem sucedida!\nNOVO TAMANHO DO BANCO DE DADOS: " << TAM2 << " ALUNOS"<< endl;
	}else{
		cout << "\nRealocação FALHOU!!!";
		return Vetor; 
	}
	for(int i=0; i<*TAM;i++){
		Vetor++;
	}
	for(int i=*TAM; i<TAM2; i++){
		cout << "\n******Adicione o novo aluno: " << i+1 << "******" << "\n\n" << endl;
		fflush(stdin);
		Vetor->Cadastro();
		Vetor++;
	}
	cout << "\nAlocação Completa! " << TAux << " Alunos inseridos!\n";
	*TAM = TAM2;
	return VAux;	
}

void ImprimirVetor(Aluno *Vetor, int TAM){
	for (int i=0; i<TAM; i++){
		cout << "\n***********************Dados do Aluno: " << i+1 <<  " ***********************";
		Vetor->RevealAll();
		cout << endl;
		Vetor++;
	}	
}

void Create(Aluno *Vetor, int TAM){
	for (int i=0; i<TAM; i++){
		Vetor->Cadastro();
		Vetor++;
	}
	cout << "Alocação Completa!\n";
}
void Acessar_Aluno(Aluno *Vetor, Aluno *VetorPos, int Posicao){
	int Pos;
	for (int i=0; i<Posicao; i++){
		Pos++;
		VetorPos = Vetor;
		Vetor++;
		if(Pos == Posicao){
			cout << "\n***********************Dados do Aluno: " << Pos <<  " ***********************";
			VetorPos->RevealAll();
			VetorPos->Alt_Nota();
		}
	}	
}

void CalcMediaTotal(Aluno *Vetor, int TAM){
	float MediaT;
	for (int i=0; i<TAM; i++){
		MediaT = MediaT + Vetor->MediaCalc();
		Vetor++;
	}
	cout << MediaT/TAM;	
}

void LimparVetor(Aluno *Vetor){
	cout << "\nLimpando o Vetor...\n";
	cout << "\nVetor limpo com sucesso!\n";
	free(Vetor);
}

