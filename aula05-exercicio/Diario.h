#ifndef DIARIO_H
#define DIARIO_H

#include <string>
#include "Message.h"

using namespace std;

struct Diario{
    Message* mensagens;

    void adicionarMensagem(Message mensagem);
    void listarMensagem(Message* mensagens);
    void apagarMensagem(Message mensagem);

};

#endif