#include "./Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./Circle.h"
#include "./Triangle.h"

using namespace std;

inline float dist(const float2& p, const float2& q){
  return length(p-q);
}

Game::Game() {
  for (int i = 0; i < 13; ++i) {
    float x = (rand() / (float)RAND_MAX)*2 - 1;
    float y = (rand() / (float)RAND_MAX)*2 - 1;
    float vx = (rand() / (float)RAND_MAX)*0.0004 - 0.0002;
    float vy = (rand() / (float)RAND_MAX)*0.0004 - 0.0002;
    float size = 0.03 + (rand() / (float)RAND_MAX)*0.05;
    float r = (rand() / (float)RAND_MAX);
    float g = (rand() / (float)RAND_MAX);
    float b = (rand() / (float)RAND_MAX);
    Asteroid a(float2(x, y), float2(vx, vy), size, Color(r, g, b));
    _asteroids.push_back(a);
  }
}

void Game::frame(RenderContext& context, const float elapsed) {
  Circle* c = Circle::instance();

  Triangle* t = Triangle::instance();
  float theta = 0.0;
  t->render(context, float2(0, 0), theta, 0.25, Color::RED, true);

  for (list<Asteroid>::iterator it = _asteroids.begin();
       it != _asteroids.end();
       it++) {
    Asteroid& a = *it;
    WallBounce(a);    
    AsteroidCollisions(a);
    c->render(context, a.getPos(), a.getSize(), a.getColor(), true);    
    a.move();
  }    
}

void Game::WallBounce(Asteroid& a){
  float2 pos = a.getPos();
   if(pos.x > 1 || pos.x < -1 || pos.y > 1 || pos.y < -1){
     a.setVel(a.getVel()*-1);
   }  
}

void Game::AsteroidCollisions(Asteroid& a){
  for(list<Asteroid>::iterator it = _asteroids.end();
       it != _asteroids.begin();
       it--){
    Asteroid& b = *it;

    if(a.getVel()==b.getVel() 
      // & a.getSize()==b.getSize() &
      // a.getColor()==b.getColor()& 
      // a.getPos()==b.getPos()
      ){
      break;
    }

    Asteroid bigger = a;
    if(b.getSize()>a.getSize()){
      bigger = b;
    } 

    if(dist(a.getPos(),b.getPos())<=bigger.getSize()*2){
       a.setVel(a.getVel()*-1);
       b.setVel(b.getVel()*-1);
    }

  }
}

//----------------------------------------------------------------------------
// The following functions are called when the user presses
// a key, holds a key, presses the mouse or moves the mouse
// cursor. They will be useful when allowing user interaction.
//----------------------------------------------------------------------------

void Game::keyCallback(int key, int action, int mods) {
  // See http://www.glfw.org/docs/latest/group__keys.html for key
  // values.
  //
  // Possible values for action are GLFW_PRESS, GLFW_REPEAT and GLFW_RELEASE.
  //
  // Possible modifiers are GLFW_MOD_SHIFT, GLFW_MOD_CONTROL and GLFW_MOD_ALT.

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    cout << "Escape pressed" << endl;
  else if (key == GLFW_KEY_A && action == GLFW_PRESS)
    cout << "\'a\' pressed" << endl;
  else if (key == GLFW_KEY_B && action == GLFW_PRESS &&
           (mods & GLFW_MOD_SHIFT) != 0)
    cout << "\'B\' pressed while holding shift" << endl;
  else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
    cout << "Right arrow pressed" << endl;
  }
  else if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT)
    cout << "Right arrow repeated" << endl;
}

void Game::mouseButtonCallback(int button, int action, int mods,
                               double x, double y) {
  using namespace std;
  if (button == 0 && action == GLFW_PRESS) {
    cout << "Left button pressed at " << x << ", " << y << endl;
  } else if (action == GLFW_RELEASE) {
    cout << "Button released at " << x << ", " << y << endl;
  }
}

void Game::cursorPositionCallback(double x, double y) {
  // cout << "Mouse cursor at " << x << ", " << y << endl;
}
