//Melissa Coblentz
#include "./Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./Circle.h"
#include "./PrintSpooler.h"
#include "./float2.h"

using namespace std;

//returns a random number between 0 and 1 (from Dr. Edwards)
float myrand(){
  return (random()/(float)RAND_MAX);
}

//returns a random number between -1 and 1 (from Dr. Edwards)
float myrand2(){
  return myrand() * 2 - 1;
}

Game::Game() {
  _astroidPosition = float2(0,0);
  _astroidSize = 0.05;
  _astroidColor = Color::BLUE;
  _astroidVelocity = float2(-.0005, 0.0003);  
}


void Game::frame(RenderContext& context, const float elapsed) {  
    Circle* c = Circle::instance();
    if(_astroidPosition.x > (float)(4/3) || _astroidPosition.x < (float)(-4/3) || _astroidPosition.y > 1 || _astroidPosition.y < -1){
      _astroidVelocity = _astroidVelocity * -1;
      _astroidVelocity.x = _astroidVelocity.x * (.75+myrand2());
      _astroidVelocity.y = _astroidVelocity.y * (.5+myrand2());
      // _astroidColor = Color(rand()%255,rand()%255,rand()%255);
    }
    _astroidPosition = _astroidPosition + _astroidVelocity;     
    c->render(context, _astroidPosition, _astroidSize, _astroidColor, true);  
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
  else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    cout << "Right arrow pressed" << endl;
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
  cout << "Mouse cursor at " << x << ", " << y << endl;
}
