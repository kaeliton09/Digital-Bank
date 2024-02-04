#include <iostream>

using namespace std;

//Numeros de Jogadores
int jogadores(){
    int n;
    cout << "Digite a Quantidade de Jogadores: ";
    cin >> n;
    return n;
}

//Saldo Inicial
int saldo_inicial(){
    int di;
    cout << "Digite o dinheiro inicial para cada jogador: ";
    cin >> di;
    cout << endl;
    return di;
}

//Preenchendo dados
void preenchendo(string *nome, int *dinheiro, int n, int di){
    for(int i = 0; i < n; i++){
        cout << endl;
        cout << "Digite o Nome do Jogador " << i + 1 << " : ";
        cin >> nome[i];
        dinheiro[i] = di;
        cout << "Operacao Realizada." << endl;
    }
    cout << endl;
    system ("cls");
}

//imprimindo dinheiro de cada Jogador
void saldo_geral(string *nome, int *dinheiro, int n){
    for(int i = 0; i < n; i++){
        cout << "Nome  : " << nome[i] << endl;
        cout << "Saldo : " << dinheiro[i] << endl;
        cout << " - - - - - - - - - " << endl;
    }
}

//Selecao de Jogador
int selecao(string nome[], int n){
    int vez;
    cout << "- - - - - - - - - - -" << endl;
    cout << "De quem e a vez? " << endl;
    for(int i = 0; i < n; i++){
        cout << "(" << i + 1 << ")" << nome[i] << endl;
    }
    cout << "- - - - - - - - - - -" << endl;
    cin >> vez;
    return vez - 1;
}

//Pagamento e saldo
void pagamento_saldo(int menu, string *nome, int *dinheiro, int n, int vez){
    int tf, vtf;
    if(menu == 1){
        cout << "Nome  : " << nome[vez] << endl;
        cout << "Saldo : " << dinheiro[vez] << endl;
        cout << " - - - - - - - - - " << endl;
    }
    else{//tranferencia
        cout << "Deseja Tranferir para qual jogador? " << endl;
        for(int i = 0; i < n; i++){
            if(i != vez){
                cout << "(" << i + 1 << ")" << nome[i] << endl;
            }
        }
        cin >> tf;
        cout << "Digite o Valor: ";
        cin >> vtf;
        dinheiro[vez] -= vtf;//tirando de quem vai pagar
        dinheiro[tf -1] += vtf;//pagando
        cout << "Tranferencia Concluida" << endl;
    }
}

//Menu
void Menu(string* nome, int* dinheiro, int n, int vez){
    int menu;
    cout << "O que deseja fazer?" << endl;
    cout << "(1) Consultar Saldo" << endl;
    cout << "(2) Tranferir Dinheiro." << endl;
    cin >> menu;
    pagamento_saldo(menu, nome, dinheiro, n, vez);
}



//Passar vez
int passar_vez(string *nome, int *dinheiro, int n, int vez){
    int s;
    cout << endl;
    cout << "Deseja Passar a Vez? (1)Sim - (2)Nao";
    cin >> s;
    if(s == 1){
        return 0;
    }
    else{
        Menu(nome, dinheiro, n, vez);
        return passar_vez(nome, dinheiro, n, vez);
    }
}


int main()
{
    int n, di, menu, vez, passar, vitoria = 1;
    
    n = jogadores();
    di = saldo_inicial();
    
    //vetor para dinheiro e nomes
    string nome[n];
    int dinheiro[n];

    preenchendo(nome, dinheiro, n, di);
    saldo_geral(nome, dinheiro, n);
    while(vitoria){
        vez = selecao(nome, n);
    
        Menu(nome, dinheiro, n, vez);
        passar = passar_vez(nome, dinheiro, n, vez);
    }
    

    
    return 0;
}