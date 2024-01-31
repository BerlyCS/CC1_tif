#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

float width = 1366.0f;
float height = 768.0f;
int max_speed=10;
int max_size = 40;
int objects = 50;

class Bola : public CircleShape {
private:
    float velY;
    float velX;
    int size;
    int X;
    int Y;
    Color color;

public:
    Bola(): 
      velX(rand() % max_speed),
      velY(rand() % max_speed),
      size(rand() % max_size+10) 
   {
        color = Color(rand() % 256, rand() % 256, rand() % 256);

        X = rand() % (int(width)-size*2);
        Y = rand() % (int(height)-size*2);

        Vector2f posicion(X, Y);
        setRadius(size);
        setPosition(posicion);
        setFillColor(color);
    }

    void setVelY(float vel) { velY = vel; }
    void setVelX(float vel) { velX = vel; }
    float getVelY() {return velY;}
    float getVelX() {return velX;}
    void setPosX(float X) { this->X=X;}
    void setPosY(float Y) { this->Y=Y;}
    int getPosX(){return X;}
    int getPosY(){return Y;}
    virtual void fun() {
        X=X + velX;
        if (X < 0 || X > width - size*2) {
            velX *=-1;
        }
        Y=Y + velY;
        if (Y < 0 || Y > height - size*2) {
            velY *=-1;
        }
        Vector2f posicion(X,Y);
        setPosition(posicion);
    }

    void print() {
        cout << "velY: " << velY << " velX: " << velX << endl;
    }
};

class MultiColor : public Bola {
   Color color;
   public:
      virtual void fun() {
         int r=rand()%256;
         int g=rand()%256;
         int b=rand()%256;
         color = Color(r,g,b);
         setFillColor(color);
      }
};

int main() {
    RenderWindow window(VideoMode(width, height), "Bouncing balls");
    window.setFramerateLimit(60);

    vector<Bola> bolas;
    vector<MultiColor> ballsGroup2;

    for (int i = 0; i < objects; i++) {
        Bola objeto;
        bolas.push_back(objeto);

        MultiColor objeto2;
        ballsGroup2.push_back(objeto2);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        for (int i=0;i<objects;i++) {
           bolas[i].fun();
           ballsGroup2[i].fun();
        }

        window.clear();

        for (int i=0;i<objects;i++) {
            window.draw(bolas[i]);
            window.draw(ballsGroup2[i]);
        }

        window.display();
    }

    return 0;
}

