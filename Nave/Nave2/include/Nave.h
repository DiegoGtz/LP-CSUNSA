#ifndef NAVE_H
#define NAVE_H

#include <MainGame.h>
#include <allegro.h>
#include <iostream>
#include <vector>

using namespace std;

class Nave : public MainGame
{
    public:
        Nave(){
            x = 250;
            y = 300;
            setImg("recursos/nave1.bmp");
        }
        void actualizar(){
           if(key[KEY_UP])   {this->y -= 1;}
           if(key[KEY_DOWN]) {this->y += 1;}
           if(key[KEY_RIGHT]){this->x += 1;}
           if(key[KEY_LEFT]) {this->x -= 1;}
           if(x<0){this->x=0;}
           if(y<0){this->y=0;}
           if(x>460){this->x=460;}
           if(y>400){this->y=400;}
        }
        void draw(){

             draw_sprite(buffer,img,x,y);
            (*m_vec)[0]=x;
            (*m_vec)[1]=y;
        }
        void set_image(BITMAP*);
        int x;
        int y;
        BITMAP* buffer;
        vector<int> *m_vec;
        void set_v_col(vector<int> *vec){m_vec=vec;}

        virtual ~Nave();


};

#endif // NAVE_H
