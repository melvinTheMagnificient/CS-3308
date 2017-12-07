//Melissa Coblentz
#include "./Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "./Circle.h"
#include "./Triangle.h"

using namespace std;

Game::Game() {
  srand(clock());
  _x = 1.33; _y = 1.0;
  //make asteroids
  for (int i = 0; i < 15; ++i) {
    float x = (rand() / (float)RAND_MAX)*2 - 1;
    float y = (rand() / (float)RAND_MAX)*2 - 1;
    float vx = (rand() / (float)RAND_MAX)*0.0004 - 0.0002;
    float vy = (rand() / (float)RAND_MAX)*0.0004 - 0.0002;
    float size = 0.03 + (rand() / (float)RAND_MAX)*0.05;
    //asteroids won't initialize too close to rocket in center
    while((x > -.5 & x < .5)||(y > -.5 & y < .5)){
      x = (rand() / (float)RAND_MAX)*2 - 1;
      y = (rand() / (float)RAND_MAX)*2 - 1;
    }
    Asteroid a(float2(x, y), float2(vx, vy), size, Color::random());
    _asteroids.push_back(a);
  }

  //make rocket
  float theta = 0.0;
  const float size = 0.6;
  Color color = Color::BLACK;
  _rocket = new Rocket(size, color);
}

void Game::frame(RenderContext& context, const float elapsed) {
  Circle* c = Circle::instance();
  Triangle* t = Triangle::instance();  
  t->render(context, float2(0, 0), (*_rocket).getTheta(), 
    (*_rocket).getSize(), (*_rocket).getColor(), true);

  //render each asteroid and change positions based on velocity
  for (list<Asteroid>::iterator it = _asteroids.begin();
       it != _asteroids.end(); it++) {
    Asteroid& a = *it;
    c->render(context, a.getPos(), a.getSize(), a.getColor(), true);    
    a.move();
  } 

  //Modifiy asteroids positions
  for (list<Asteroid>::iterator it = _asteroids.begin();
       it != _asteroids.end(); it++) {
    Asteroid& a = *it;
    WallBounce(a); 
    AsteroidCollisions(a);
    RocketCollisions(a);
    if(BulletAsteroidCollisions(a)){
      it = _asteroids.erase(it);
      if(_asteroids.size() == 0) GameOver();
    }
  }    
  
  //Render and modify bullets in list
  if(_bullets.size() > 0){
    //render each bullet and change positions based on velocity
    for(list<Bullet>::iterator it = _bullets.begin();
        it != _bullets.end(); it++) {
      Bullet& b = *it;
      c->render(context, b.getPos(), b.getSize(), b.getColor(), true);
      b.move();    
    }
    //remove bullet from list if out of screen bounds
    for(list<Bullet>::iterator it = _bullets.begin();
       it != _bullets.end(); it++) {
      Bullet& b = *it;
      if(OffScreen(b.getPos())){
        it= _bullets.erase(it);
      }
    }
  }  
}

//True if two asteroids are touching
bool Game::AreTouching(Asteroid& a, Asteroid& b){
  float d = dist(a.getPos(),b.getPos());
  if(d<(a.getSize()+b.getSize())) return true;
  return false;   
}

//True if an asteroid and a bullet are touching
bool Game::AreTouching(Asteroid& a, Bullet& b){
  float d = dist(a.getPos(),b.getPos());
  if(d<(a.getSize()+b.getSize())) return true;
  return false;
}

//True if an asteroid and the rocket are touching
bool Game::IsTouchingRocket(Asteroid& a){
  Asteroid b(float2(0,0), float2(0,0), ((*_rocket).getSize())/10, Color::BLACK);
  float d = dist(a.getPos(),b.getPos());
  if(d<(a.getSize()+b.getSize())) return true;
  return false;
}

//True if a point is out of bounds
bool Game::OffScreen(float2 f){
  if(f.x > _x || f.x < -_x || f.y > _y || f.y < -_y)
    return true;
  return false;
}

//Bounces asteroids off the bounds of the screen
void Game::WallBounce(Asteroid& a){
   if(OffScreen(a.getPos()))
     a.setVel(a.getVel()*-1);   
}

//Reverses velocities of two touching asteroids
void Game::AsteroidCollisions(Asteroid& a){
  for(list<Asteroid>::iterator it = _asteroids.begin();
       it != _asteroids.end(); it++){
  Asteroid& b = *it;
  if(AreTouching(a, b)){   
     a.setVel(a.getVel()*-1);
     b.setVel(b.getVel()*-1);
     a.move();
     b.move();
    }
  }
}

//True if any bullet is touching the asteroid
bool Game::BulletAsteroidCollisions(Asteroid& a){
  for(list<Bullet>::iterator it = _bullets.begin();
        it != _bullets.end(); it++){
    Bullet& b = *it;
    if(AreTouching(a,b)){
      return true;
    }
  }
  return false;
}

//Game over if asteroid touches rocket
void Game::RocketCollisions(Asteroid& a){
  if(IsTouchingRocket(a)){ 
    GameOver();
  }
}

//Adds new bullet to bullet vector with velocity 
//based on rocket
void Game::MakeBullet(){
  float theta = (*_rocket).getTheta();
  float thetaX = cos(theta + (M_PI/2));
  float thetaY = sin(theta + (M_PI/2));
  float2 thetaVel = float2(thetaX, thetaY)/1300;
  Bullet b(float2(0,0), thetaVel);
  _bullets.push_back(b);
}

//Ends game and program
void Game::GameOver(){
  cout<<endl<<"Game Over"<<endl;
  if(_asteroids.size()==0){
    cout<<"You won!"<<endl;
  }else{
    cout<<"You lose!"<<endl;
  }
  cout<<endl;
  exit(EXIT_FAILURE);
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
  else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)   
    (*_rocket).SpinRocketRight();
  else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    (*_rocket).SpinRocketLeft();
  else if(key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    MakeBullet();
}

void Game::mouseButtonCallback(int button, int action, int mods,
                               double x, double y) {
  // using namespace std;
  // if (button == 0 && action == GLFW_PRESS) {
  //   cout << "Left button pressed at " << x << ", " << y << endl;
  // } else if (action == GLFW_RELEASE) {
  //   cout << "Button released at " << x << ", " << y << endl;
  // }
}

void Game::cursorPositionCallback(double x, double y) {
  // cout << "Mouse cursor at " << x << ", " << y << endl;
}
