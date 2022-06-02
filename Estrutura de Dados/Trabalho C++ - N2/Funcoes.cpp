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
	fflush(stdin);
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
	A1 = 0;
	A2 = 0;
	count = 1;
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
	if(media == 0){
		cout << "Status cursando!";
	}else if(media >= 6.0){
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
			cout << "\nDeseja alterar a A1 ou A2 ou Ambas?\n";
			cout << "\nDigite 1 para escolher A1 ou 2 para escolher A2 ou 3 para Ambas!\n";
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
				case 3:
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

int Aluno::getMatricula(){
	return matricula;	
}



//Funções da lista

//inserir na frente da lista
void inserirInicio(Aluno** Inicio){
	struct Aluno* novoNode = new Aluno;
	novoNode->Cadastro();
	novoNode->next = (*Inicio);
	(*Inicio) = novoNode;
}

//Inserir ordenado por matricula
struct Aluno* inserirOrd(struct Aluno* Inicio){
	struct Aluno* temp;
	struct Aluno* newP = new Aluno;
	newP->Cadastro();
	newP->next = NULL;
	int key = newP->getMatricula();
	//Caso seja o fim do nó
	if (Inicio == NULL || key < Inicio->getMatricula()){
		newP->next = Inicio;
		Inicio = newP;
	}else{
	//Localizar o no antes do ponto de inserção
		temp = Inicio;
		while(temp->next!=NULL && temp->next->getMatricula()< key){
			temp = temp->next;
		}
		newP->next = temp->next;
		temp->next = newP;
		}
	return Inicio;	
}

//Verifica se a lista está vazia
int lista_vazia(struct Aluno* Lista){
	if(Lista == NULL){
		return 1;
	}else{
		return 0;
	}
}

//Remover da lista ordenado por matricula!
void deleteOrd(struct Aluno** Inicio){
	char Aux, Aux2;
	struct Aluno* temp = *Inicio;
	struct Aluno* anterior = new Aluno;
	anterior->next = NULL;
	int key;
	cout << "\nDigite a matricula do aluno a ser deletado!\n";
	cin >> key;
	//Caso seja o primeiro aluno da lista! 
	if (temp == NULL || temp->getMatricula() == key){
		cout << "\nDeseja remover o primeiro aluno da lista?\n";
		temp->RevealAll();
		cout << "\nDigite S para sim e N para não!\n";
		cin >> Aux;
		Aux = toupper(Aux);
		switch(Aux){
			case 'S':
			{
				*Inicio = temp->next;
				delete temp;
				cout << "\nAluno removido com sucesso\n";
				break;
			}
			case 'N':
			{
				cout << "\nRetornando ao menu\n";
				break;		
			}
			default:
				cout << "\nOpção invalida retornando ao menu!\n";
				break;
		}
		return;
	//Caso não seja o primeiro aluno, busque!	
	}else{
		while(temp != NULL && temp->getMatricula() != key){
			anterior = temp;
			temp = temp->next;
		}
		if(temp == NULL){
			cout << "\nMatrícula inexistente!\n";
			return;
		}
		cout << "\nRealmente deseja remover o seguinte aluno da lista?\n";
		temp->RevealAll();
		cout << "\n\nDigite S para sim ou N para não\n";
		cin >> Aux2;
		Aux2 = toupper(Aux2);
		switch(Aux2){
			case 'S':
			{
				anterior->next = temp->next;
				delete temp;
				cout << "\nAluno removido com sucesso\n";
				break;
			}
			case 'N':
			{
				cout << "\nRetornando ao menu\n";
				break;		
			}
			default:
				cout << "\nOpção invalida! retornando ao menu!\n";
				break;
		}
	}
}		

//Inserir no meio da lista
void inserirMeio(Aluno* node_Anterior){
	if(node_Anterior == NULL){
		cout << "E necessário ao menos um ínicio e um fim para inserir no meio!";
		return;
	}
	struct Aluno* novoNode = new Aluno;
	novoNode->Cadastro();
	novoNode->next = node_Anterior->next;
	node_Anterior->next = novoNode;
}

//Inserir no final da lista
void inserirFinal(Aluno** Inicio){
	struct Aluno* novoNode = new Aluno;
	struct Aluno *Final = *Inicio;
	novoNode->Cadastro();
	novoNode->next = NULL;
	if(*Inicio == NULL){
		*Inicio = novoNode;
		return;
	}
	while(Final->next != NULL){
		Final = Final->next;	
	}
	Final->next = novoNode;
	return;
}

//Visualizar toda a lista
void mostrarLista(struct Aluno *node){
	while(node != NULL){
		node->RevealAll();
		node = node->next;
	}
	if(node == NULL){
		cout << "\n\n**********FIM DA LISTA**********\n\n";
	}
}

//Função de buscar alunos da lista por posição!
void buscarAluno(struct Aluno *node, int Pos){
	int Count;
	do{
		Count++;
		if(Count == (Pos)){
			node->RevealAll();
			node->Alt_Nota();
		}
		node = node->next;
	}while(node!=NULL);
}

//Função de remover o aluno da lista por posição!
void removerAluno(Aluno** Inicio, Aluno *Busca, int Pos){
	int Count;
	do{
		Count++;
		if(Count == (Pos)){
			Busca->RevealAll();
		}
		Busca = Busca->next;
	}while(Busca!=NULL);
	char Aux;
	bool Aux2 = false;
	do{
		cout << "\n\n\n\nDeseja remover o aluno?\n\nDigite S para SIM e N para não!\n\n";
		cin >> Aux;
		Aux = toupper(Aux);
		switch (Aux){
			case 'S':
				{
				if(Inicio == NULL){
					cout << "\n\n\nA lista está vazia!\n\n\n";
					Aux2 = true;
					break;
				}
				Aluno* temp = *Inicio;
				if (Pos == 1){
					*Inicio = temp->next;
					free(temp);
					Aux2 = true;
					break;
				}
				for (int i = 2; temp!= NULL && i<=Pos-1; i++){
					temp = temp->next;	
				}
				if(temp == NULL || temp->next == NULL){
						Aux2 = true;
						break;
				}
				Aluno* next = temp->next->next;
				free(temp->next);
				temp->next = next;
				cout << "\n\nAluno Deletado com SUCESSO!\n\n";
				Aux2 = true;
				break;
			}
			case 'N':
				{
				cout << "\n\nVocê escolheu não deletar! Retornando ao menu!\n\n";
				Aux2 = true;
				break;
				}
			default:
				{
				cout << "\n\nVocê digitou uma opção inexistente!\nDigite novamente!\n";
				Aux2 = false;
				break;
				}
		}
	}while(Aux2 == false);
}

//Função de remover o primeiro integrante da lista!
void removerInicio(struct Aluno** Lista){
	char Aux;
	struct Aluno* temp = *Lista;
	cout << "\nDeseja remover o primeiro aluno da lista?\n";
	temp->RevealAll();
	cout << "\n\nDigite S para sim e N para não!\n\n";
	cin >> Aux;
	Aux = toupper(Aux);
	switch(Aux){
		case 'S':
		{
			*Lista = temp->next;
			delete temp;
			cout << "\nAluno removido com sucesso\n";
			break;
		}
		case 'N':
		{
			cout << "\nRetornando ao menu\n";
			break;		
		}
		default:
			cout << "\nOpção invalida retornando ao menu!\n";
			break;
		}
		return;
}

//Função de remover o último integrante da lista!
void removerFinal(struct Aluno** Lista){
	struct Aluno* anterior, *no = *Lista;
	while(no->next != NULL){
		anterior = no;
		no = no->next;
	}
	if(no == (*Lista)){
		*Lista = no->next;
	}else{
		anterior->next = no->next;
	}
	delete no;
	return;
}

//Função de buscar matricula na lista!
void buscarMatricula(struct Aluno* Lista){
	int matricula;
	cout << "\nDigite a matricula do aluno a ser buscado!\n";
	cin >> matricula;
	do{
		if(matricula == Lista->getMatricula()){
			Lista->RevealAll();
			Lista->Alt_Nota();
		}
		Lista = Lista->next;
	}while(Lista!=NULL);
}

//Deletar toda a lista!
void deletarLista(struct Aluno** Lista){
	Aluno* atual = *Lista;
	Aluno* proximo = NULL;
	while(atual != NULL){
		proximo = atual->next;
		delete atual;
		atual = proximo;
	}
	*Lista = NULL;
}

//Calcular a média da turma!
void calcMediaTurma(struct Aluno* Lista){
	float media = 0;
	int count = 0;
	while(Lista != NULL){
		media = media + Lista->MediaCalc();
		count = count + Lista->count;
		Lista = Lista->next;
	}
	if(Lista == NULL){
		cout << "\n\n******A média da turma é: " << media/count << "******\n\n";
	}
}

//-------------------------------------------------------------------------




