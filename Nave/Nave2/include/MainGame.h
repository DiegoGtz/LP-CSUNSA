#ifndef MAINGAME_H
#define MAINGAME_H

#include <allegro.h>
class MainGame
{
    public:
        MainGame()
        {
            siguiente = 0;
            anterior = 0;
        }
        virtual ~MainGame();
        virtual void draw(){}
        virtual void update(){}
        void set_x(int pos_x){ x = pos_x;}
        void set_y(int pos_y){ y = pos_y;}
        int get_x(){return x;}
        int get_y(){return y;}
        void setImg(const char *c){ this->img = load_bitmap(c,NULL);}
        friend class Controller;
        bool estado=true;
    protected:
        int x;
        int y;
        MainGame* siguiente;
        MainGame* anterior;
        BITMAP* bmp;
        BITMAP* img;

};

#endif // MAINGAME_H
