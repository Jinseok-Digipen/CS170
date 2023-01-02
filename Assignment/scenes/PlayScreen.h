//Author : Jinseok Son
#include"Scene.h"
#include"Button.h"
class Game;
class PlayScreen : public Scene
{

private:
    Button test;
   
    void Update() override;
    void Draw() const override;

public:
    PlayScreen(Game& the_game);
	~PlayScreen()=default;
};