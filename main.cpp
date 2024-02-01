#include <iostream>

using namespace std;

int main()
{
    int n, di, menu, tf, vtf, vez;
    
    cout << "Digite a Quantidade de Jogadores: ";
    cin >> n;
    cout << "Digite o dinheiro inicial para cada jogador: ";
    cin >> di;
    cout << endl;
    
    //vetor para dinheiro e nomes
    string nome[n];
    int dinheiro[n];

    //preenchendo dados
    for(int i = 0; i < n; i++){
        cout << endl;
        cout << "Digite o Nome do Jogador " << i + 1 << " : ";
        cin >> nome[i];
        dinheiro[i] = di;
        cout << "Operacao Realizada." << endl;
    }
    cout << endl;
    system ("cls");
    
    //imprimindo dinheiro de cada Jogador
    for(int i = 0; i < n; i++){
        cout << "Nome  : " << nome[i] << endl;
        cout << "Saldo : " << dinheiro[i] << endl;
        cout << " - - - - - - - - - " << endl;
    }
    
    //vez
    vez = 0;//jogador 1
    
    //menu
    cout << "O que deseja fazer?" << endl;
    cout << "(1) Consultar Saldo" << endl;
    cout << "(2) Tranferir Dinheiro." << endl;
    cin >> menu;
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
    }
    
    //imprimindo dinheiro de cada Jogador
    for(int i = 0; i < n; i++){
        cout << "Nome  : " << nome[i] << endl;
        cout << "Saldo : " << dinheiro[i] << endl;
        cout << " - - - - - - - - - " << endl;
    }
    
    return 0;
}