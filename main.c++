#include <iostream>


int main(){
    int opcao;
    while (1){
        std::cout << "\n========= BEM VINDO AO FLUXO FINACEIRO =========\n";
        std::cout << "1. Cadastrar Usuario\n";
        std::cout << "2. Login\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        
        if (opcao == 3){
            std::cout << "Saindo...\n";
            break;
        }
        else if(opcao == 1){
            std::cout << "Cadastrar Usuario não implementado ainda.\n";
           
        }
        else if(opcao == 2){
            std::cout << "Login não implementado ainda.\n";
           
        }
        else{
            std::cout << "Opção inválida. Tente novamente.\n";
        }

           
        
    }
    


    return 0;
}