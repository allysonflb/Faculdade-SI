#include <iostream>
#include <string>
using namespace std;

//Alunos:
//Allyson Freire de Lima Barbosa, RA: 201902982


struct Aluno{
	private:
		char nome[50];
		int matricula;
		int idade;
		float A1,A2;
		float media;
	public:
		float MediaCalc();
		void Cadastro();
		void RevealAll();
		void Ap_Rp();	
		void Media();
		void Alt_Nota();		
};
Aluno* Criar(int TAM);
Aluno* Aumentar_Vet(Aluno *Vetor, int *TAM);
void ImprimirVetor(Aluno *Vetor, int TAM);
void Create(Aluno *Vetor, int TAM);
void Acessar_Aluno(Aluno *Vetor, Aluno *VetorPos, int Posicao);
void CalcMediaTotal(Aluno *Vetor, int TAM);
void LimparVetor(Aluno *Vetor);
