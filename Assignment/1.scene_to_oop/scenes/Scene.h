// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once

class Game; //Forward declaration for not include Game.h
            //If we don't need to make Game Instance we don't need to include game.h just using pointer is fine

class Scene
{
    //we use Game class pointer as memeber function we should initialize this as constructor 
    Game* gameInstance; 

protected:
    //return GamePointer
    Game&       game() { return *gameInstance; }

    //we overload two version for because const class only use const member function 
    const Game& game() const { return *gameInstance; }

public:
    Scene(Game& the_game) : gameInstance(&the_game) {}
    //here we made our own constructor our compiler will delete other "Compiler Generate constructor and operator"

    //made two virtual function for implement PolyMorpsysm  our based class should override ethis two functions 

    virtual void Update()     = 0; //pure virtual function 
    virtual void Draw() const = 0; //pure virtual function 

    //virtual destructor for  prevent memoryleak 
    //If we not make virtual destructor our program will have 100 percent memory leak because our compiler naver invoke our derived class destructor 
    virtual ~Scene()                         = default;



    
    Scene(const Scene& other)                = default; //copy constructpr
    Scene(Scene&& other) noexcept            = default; //move constructor
    Scene& operator=(const Scene& other)     = default; //copy assignment operator
    Scene& operator=(Scene&& other) noexcept = default; //move assignment operator 
};
