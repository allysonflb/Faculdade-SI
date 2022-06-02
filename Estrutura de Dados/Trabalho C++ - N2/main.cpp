#include <iostream>
#include <locale.h>
#include "Auxiliar.h"
#include <stdlib.h>
#include <limits>
using namespace std;


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int menu, Pos;
	bool aux=false;
	char Menu1;
	Aluno* Inicio = NULL;
	do{
	cout << "\n\n***Digite***\n\n I - Inserir alunos na lista (op��es)\n\n M - Mostrar Lista!\n\n B - Buscar aluno (op��es)";
	cout << "\n\n D - Deletar um aluno (op��es)\n\n C - Calcular a m�dia da turma\n\n";
	cout << "\n***Digite qualquer tecla para encerrar o programa e limpar a lista***\n";
	cin >> Menu1;
	Menu1 = toupper(Menu1);	
	switch(Menu1){
		case 'I':{
			int Escolha1;
			system("CLS");
			cout << "As op��es de inserir aluno na lista s�o:\n";
			cout << "1 - Inserir no in�cio\n\n2 - Inserir no final\n\n3 - Inserir no meio(requer pelo menos 3 elementos na lista)";
			cout << "\n\n4 - Inserir ordenado por matr�cula\n\n";
			cout << "***Digite qualquer outra tecla para retornar ao menu principal\n";
			cin >> Escolha1;
			switch(Escolha1){
				case 1:
					system("CLS");
					inserirInicio(&Inicio);
					cout << "\n\n\n";
					break;
				case 2:
					system("CLS");
					cout << "Inserir alunos no final da lista!\n";
					inserirFinal(&Inicio);
					cout << "\n\n\n";
					break;
				case 3:
					system("CLS");
					cout << "Inserir alunos no meio da lista!\n";
					inserirMeio(Inicio->next);
					cout << "\n\n\n";
					break;
				case 4:
					system("cls");
					cout << "Inserir de forma ordenada por matr�cula!\n";
					Inicio = inserirOrd(Inicio);
					break;
				default:
					system("CLS");
					cout << "\nOp��o invalida retornando ao menu!\n";
					break;			
			}
			break;
		}
		case 'M':{
			system("cls");
			if(lista_vazia(Inicio)){
				cout << "\nLista Vazia!!!\n"; 
			}else{
				cout << "\nMostrando os alunos inseridos!\n";	
				mostrarLista(Inicio);
				cout << "\n\n\n";
			}
			break;
		}
		case 'B':{
			system("CLS");
			int escolha2;
			cout << "\n\nAs op��es de escolha de aluno s�o:";
			cout << "\n\n1 - Buscar aluno por matricula\n\n2 - Buscar aluno por posi��o\n\n";
			cout << "***Digite qualquer outra tecla para retornar ao menu principal\n";
			cin >> escolha2;
			switch(escolha2){
				case 1:
					system("CLS");
					if(lista_vazia(Inicio)){
						cout << "\nLista Vazia!!!\n"; 
					}else{
						buscarMatricula(Inicio);	
					}
					break;
				case 2:
					system("CLS");
					if(lista_vazia(Inicio)){
						cout << "\nLista Vazia!!!\n"; 
					}else{
						cout << "\nDigite a posi��o do aluno a ser buscado!\n";
						cin >> Pos;
						buscarAluno(Inicio, Pos);
					}
					break;
				default:
				 	system("CLS");
					cout << "\nOp��o invalida retornando ao menu!\n";
					break;			
			}
			break;
		}
		case 'D':{
			system("CLS");
			int escolha3;
			cout << "\n\nAs op��es para deletar aluno s�o:";
			cout << "\n\n1 - Remover por posi��o na lista\n\n2 - Remover por matricula";
			cout << "\n\n3 - Remover o primeiro aluno\n\n4 - Remover o �ltimo aluno\n";
			cout << "\n***Digite qualquer outra tecla para retornar ao menu principal\n";
			cin >> escolha3;
			switch(escolha3){
				case 1:
					system("cls");
					cout << "\nDigite a posi��o do aluno a ser buscado!\n";
					cin >> Pos;
					removerAluno(&Inicio, Inicio, Pos);
					break;
				case 2:
					system("cls");
					if(lista_vazia(Inicio)){
						cout << "\nLista vazia!!!\n";
					}else{
						cout << "\nDeletar aluno por matricula\n";
						deleteOrd(&Inicio);
					}
					break;
				case 3:
					system("CLS");
					cout << "\nRemovendo o primeiro aluno...\n";
					if(lista_vazia(Inicio)){
						cout << "\nLista Vazia!!!\n"; 
					}else{
						removerInicio(&Inicio);	
					}
					break;
				case 4:
					system("CLS");
					cout << "\nRemovendo o �ltimo aluno...\n";
					if(lista_vazia(Inicio)){
						cout << "\nLista Vazia!!!\n"; 
					}else{
					removerFinal(&Inicio);
					}
					break;
				default:
					system("CLS");
					cout << "\nOp��o invalida retornando ao menu!\n";
					break;			
			}
			break;
		}
		case 'C':{
			system("cls");
			if(lista_vazia(Inicio)){
				cout << "\nLista Vazia!!!\n"; 
			}else{
				calcMediaTurma(Inicio);	
			}
			break;
		}
		default:
			system("cls");
			cout << "\n\nLimpando a lista!!!\n\n";
			deletarLista(&Inicio);	
			aux = true;
			break;			
	}
	}while(aux==false);
	system("pause");
	return 0;
}
