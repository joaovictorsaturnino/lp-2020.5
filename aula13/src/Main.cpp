#include "../include/Conta.h"

#include <iostream>
#include <string>

using namespace std;



int main(int argc, char const *argv[]){
    
    Conta c;
    c.saldo = 0;
    c.titular = "João Victor";
    c.numero = 1234;

    Conta d;

    d.saldo = 0;
    d.titular = "José Victor";
    d.numero = 12345;
    int opc = 3;
    while(opc != 0){
    
        cout << "| Bem vindo ao seu banco, "<< c.titular << ". Seu saldo atual é R$: " << c.saldo << endl;
        cout << "| Que operação deseja realizar?" << endl;
        cout << "| 1 - Saque" << endl;
        cout << "| 2 - Depósito" << endl;
        cout << "| 3 - Transferência" << endl;
        cout << "| 0 - encerrar" << endl;
        cout << "| Opção: ";
        
        cin >> opc;

        switch (opc){
            case 1:
                if (c.saldo > 0){
                    cout << "Qual valor deseja sacar?" << endl;
                    cout << "Valor: ";
                    int valorSaque;
                    cin >> valorSaque;
                    c.saca(valorSaque);
                    cout << "saque realizado!" << endl;
                } else {
                    cout << "voce nao possui saldo suficiente!" << endl;
                }
                break;
            
            case 2:
                cout << "Qual valor deseja depositar na sua conta?" << endl;
                cout << "Valor: ";
                int valorDeposito;
                cin >> valorDeposito;
                c.deposita(valorDeposito);
                cout << "Deposito realizado!" << endl;
                break;
            
            case 3:
                if(c.saldo > 0){
                    cout << "Transferindo para a conta '12345'... " << endl;
                    cout << "Digite o valor a ser transferido: ";
                    int valorTransferencia;
                    cin >> valorTransferencia;
                    if(c.saldo > valorTransferencia){
                        c.transfere(valorTransferencia,d);
                        cout << "Transferencia realizada!" << endl;
                        cout << "Saldo na outra conta: " << d.saldo << endl;
                    }else{
                        cout << "voce nao possui saldo suficiente" << endl;
                    }
                }else{
                    cout << "voce nao possui saldo suficiente" << endl;
                }
            default:
                break;
        }
    }
    return 0;
}

