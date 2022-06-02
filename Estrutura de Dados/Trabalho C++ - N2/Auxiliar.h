#include <iostream>
#include <string>
using namespace std;

//Aluno:
//Allyson Freire de Lima Barbosa, RA: 201902982


struct Aluno{
	private:
		char nome[50];
		int matricula;
		int idade;
		float A1,A2;
		float media;
	public:
		int count;
		int getMatricula();
		float MediaCalc();
		void Cadastro();
		void RevealAll();
		void Ap_Rp();	
		void Media();
		void Alt_Nota();
		struct Aluno *next;	
};

//Funções da lista
void inserirInicio(Aluno** Inicio);
void inserirMeio(Aluno* node_Anterior);
struct Aluno* inserirOrd(struct Aluno* Inicio); 
void deleteOrd(struct Aluno** Inicio); 
int lista_vazia(Aluno* Lista); 
void inserirFinal(Aluno** Inicio); 
void mostrarLista(struct Aluno *node); 
void buscarAluno(struct Aluno *node, int Pos); 
void removerAluno(Aluno** Inicio, Aluno *Busca, int Pos); 
void removerInicio(Aluno** Inicio);
void removerFinal(Aluno** Inicio);
void buscarMatricula(struct Aluno* Lista);
void deletarLista(struct Aluno** Lista);
void calcMediaTurma(struct Aluno* Lista);



