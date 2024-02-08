#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <cmath>
#include <cstdlib>
#include <sys/types.h>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

float width = 1366.0f;
float height = 768.0f;
int max_speed = 10;
int max_size = 5;
int objects=100;

//Clase Ball, Rebota por la pantalla
class Ball : public CircleShape {
private:
    float velY;
    float velX;
    int size;
    int X;
    int Y;
    Color color;

public:
    Ball(): 
    //Se define la velocidad y el tamaño de forma aleatoria

      velX(rand() % max_speed+1),
      velY(rand() % max_speed+1),
      size(rand() % max_size+10) 
    {
        //Color aleatorio
        color = Color(rand() % 256, rand() % 256, rand() % 256);

        //Posicion inicial
        X = rand() % (int(width)-size*2);
        Y = rand() % (int(height)-size*2);
        Vector2f posicion(X, Y);

        setRadius(size);
        setPosition(posicion);
        setFillColor(color);
    }

    void setVelY(float vel) { 
        velY = vel; 
    }

    void setVelX(float vel) {
        velX = vel; 
        }

    float getVelY() {
        return velY;
        }

    float getVelX() {
        return velX;
    }
    void setPosX(float X) {
        this->X=X;
    }
    void setPosY(float Y) {
        this->Y=Y;
    }
    int getPosX(){
        return X;
    }
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

    double distance(int Mx, int My) {
      int dx= pow((Mx-X),2);
      int dy = pow((My-Y),2);
      if ((sqrt(dx*dx + dy*dy)) < size) {
        return true;
      }
      return false;
    }
};

class MultiColor : public Ball {
    private:
        Color color;
        int r;
        int g;
        int b;
    public:
      MultiColor() : r(rand()%256),
                     g(rand()%256),
                     b(rand()%256)                     
      {
         color=Color(r,g,b);
         setFillColor(color);
      }
      void fun() {
         r=(r+getVelX());
         g=(g+getVelX());
         b=(b+getVelX());
         color = Color(r,g,b);
         setFillColor(color);
      }
};

int main() {
    RenderWindow window(VideoMode(width, height), "Bouncing balls");
    window.setFramerateLimit(60);

    vector<Ball> Balls;

    for (int i = 0; i < objects; i++) {
        Ball objeto;
        Balls.push_back(objeto);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        for (int i=0;i<objects;i++) {
           Balls[i].fun();
        }

        window.clear();

        for (int i=0;i<objects;i++) {
            window.draw(Balls[i]);
        }

        window.display();
    }

    return 0;
}

