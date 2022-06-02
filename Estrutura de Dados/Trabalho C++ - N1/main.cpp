#include <iostream>
#include <locale.h>
#include "Auxiliar.h"
#include <stdlib.h>
#include <limits>
using namespace std;


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int TAM, menu, Pos, TAM2;
	bool aux=false;
	cout << "Digite quantos alunos serão inseridos: \n";
	cin >> TAM;
	do{
		if(cin.fail()){
			cout << "\nVocê digitou uma letra, digite novamente!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> TAM;		
		}else if(TAM <=0){
				cout << "O número digitado é invalido, digite novamente!\n";
				cin >> TAM;
		}
	}while(cin.fail() || TAM<=0);
	TAM2=TAM;
	Aluno *VetorPos = new Aluno;
	Aluno *Vetor = new Aluno; 
	Vetor = Criar(TAM); 
	do{	
	cout << "\nDigite 1 para inserir mais alunos\n\nDigite 2 para imprimir o total de alunos\n";
	cout << "\nDigite 3 para calcular a média da turma\n\nDigite 4 buscar aluno\n";
	cout << "\nDigite qualquer tecla para encerrar o programa\n";
	cin >> menu;
	switch (menu){
		case 1:
			Vetor = Aumentar_Vet(Vetor,&TAM);
			cout << "\n\n\n";
			break;
		case 2: 
			system("CLS");
			cout << "\nMostrando os alunos inseridos!\n";	
			ImprimirVetor(Vetor, TAM);
			cout << "\n\n\n";
			break;
		case 3:
			system("CLS");
			cout << "\nCálculo de média de toda a turma!";
			cout << "\nCalculando..";
			cout << "\n\nA média total da turma é: ";
			CalcMediaTotal(Vetor,TAM);
			cout << "\n\n\n";
			break;
		case 4:
			system("CLS");
			cout << "\nDigite a posição do aluno na lista!\n";
			cin >> Pos;
			do{
				if(cin.fail()){
					cout << "\nVocê digitou uma letra, digite novamente!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> Pos;		
				}else if(Pos > TAM){
					cout << "O número digitado é invalido, digite novamente!\n";
					cin >> Pos;
				}else if(Pos<=0){
					cout << "O número digitado foi negativo, digite novamente!\n";
					cin >> Pos;
				}
		}while(cin.fail() || Pos>TAM || Pos<=0);
			Acessar_Aluno(Vetor,VetorPos,Pos);
			cout << "\n\n\n";
			break;
		default:
			system("CLS");
			cout << "\nEncerrando o programa!\n";
			LimparVetor(Vetor);
			aux = true;				
	}
	}while(aux==false);
	system("pause");
	return 0;
}
