#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <MainGame.h>

class Controller
{
    public:
        Controller(){
            inicio = 0;
            actual = 0;
        }
        bool vacio(){

        if (this->inicio==0){
                return true;
            }
            return false;
        }

        void insertar(MainGame* as ){
            if(vacio())
            {
                inicio = as;
            }
            else
            {
                actual->siguiente = as;
                as->anterior = actual;
            }
            actual = as;


        }
        void display(){

            MainGame* temporal = inicio;
            while (temporal)
            {
                if(temporal->estado)
                    temporal->draw();
                temporal=temporal->siguiente;

            }

        }
        void borrar(MainGame* as){
            as->anterior->siguiente=as->siguiente;
            as->siguiente->anterior=as->anterior;
            delete(as);
        }

    private:
        MainGame* inicio;
        MainGame* actual;
};

#endif // CONTROLLER_H
