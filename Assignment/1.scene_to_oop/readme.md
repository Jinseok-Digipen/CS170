# CS170 Assignment - Scenes to OOP

For this assignment you will be practicing inheritance and polymorphism with C++.

The Assignment starts off with project that has a few scenes : Main Menu, Play, Options and Credits.

The project is currently suffering from an issue related to "if else disease" caused by multiple switch statements. 
As we have learned, it is not extensible to have conditional logic that checks an instances type. It is too easy to forget to add a new case / else if when a new derived class is created, which will likely lead to bugs that won't be detected until run-time.

The solution is to use virtual functions and an interface designed for generic use. By moving the logic that is unique to each type or in other words logic that is unique to each case / else if, we can never forget to add the needed logic since it is required by the interface. 

For this assignment you are to fix the code to prevent this issue.

## Task 1 Use Scene base class

Re-implement the project with using the following `Scene` base class:

```c++
// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once


class Game;

class Scene
{
    Game* gameInstance;

protected:
    Game&       game() { return *gameInstance; }
    const Game& game() const { return *gameInstance; }

public:
    Scene(Game& the_game) : gameInstance(&the_game) {}

    virtual void Update()     = 0;
    virtual void Draw() const = 0;

    virtual ~Scene()              = default;
    Scene(const Scene& other)     = default;
    Scene(Scene&& other) noexcept = default;
    Scene& operator=(const Scene& other) = default;
    Scene& operator=(Scene&& other) noexcept = default;
};

```

The `Scene` base class provides a simple interface for derived classes to access the `Game`.

The game uses the scenes to update logic and draw, so the `Scene` base class declares this interface in an abstract way.

The virtual destructor, the copy operations and move operations enable us to not leak memory. We will study the details of these later in the course.

You are to update all the current scenes to use this as their base class.

## Task 2 Update Game Class

Update the game class to be the following:

```c++
// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once
#include <doodle/color.hpp>

#include "Scene.h"
#include <map>
#include <memory>

enum class GameScenes
{
    MAIN_MENU,
    CREDITS,
    OPTIONS,
    PLAY
};

class Game
{
    Scene*                                       currentScene{ nullptr };
    Scene*                                       queuedScene{ nullptr };
    std::map<GameScenes, std::unique_ptr<Scene>> scenes{};

public:
    Game() = default;

    void          Setup();
    void          Update();
    void          Draw() const;
    doodle::Color BackgroundColor{ 120.0 };
    void          QueueNextScene(GameScenes scene);
};

```

Now that we have the `Scene` base class, the Game's interface no longer needs to know about all possible scene types. 

We can store the derived instances of `Scene` generically by storing them inside of a `std::unique_ptr<Scene>` instance.

To create a `std::unique_ptr<Scene>`, you can use [`std::make_unique`](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique). The trick is to remember that you pass constructor arguments as the parameters for `std::make_unique`.

Here is an example of how you could populate the scenes map:

```c++
    scenes[GameScenes::MAIN_MENU] = std::make_unique<MainMenu>(*this);
    scenes[GameScenes::CREDITS]   = std::make_unique<CreditsScreen>(*this);
    scenes[GameScenes::OPTIONS]   = std::make_unique<OptionsScreen>(*this);
    scenes[GameScenes::PLAY]      = std::make_unique<PlayScreen>(*this);
```

Now you are to remove all the `switch` statements and replaces them with simple function calls from the `Scene` interface.

## Task 3 Create a New PlayScreen

After you have updated the project to use the `Scene` interface, it is now time to take advantage of it's benefits by creating your own `PlayScreen` class that implements the `Scene` interface.  

Create an experience of your own design that allows the user to do something to trigger going back to the main menu.

The provided sample does this by creating circle that follows the mouse. When that circle overlaps with another circle then it will switch to the Main Menu.

After writing your class, note that the only change needed to be done to your Game class is to simply create one instance of it. The Update and Draw logic will work with your new class without having to modify them.

## Submission

You will be submitting your work on GitHub with the provided class assignment repository. You will also create a copy of your project as a zip file on the course site. 

The name of the ZIP file must follow this naming convention: `[class_name]_[login]_scenes.zip`

For example, if a student had the login name fun.frank then the appropriate filename would be `cs099_fun.frank_scenes.zip`. Note: The .zip file names are case-sensitive and must be in all lowercase, exactly as described above.

Note that we will be grading from the GitHub repo and we are using the zip copy as a way to backup your work.

## Grading Rubric


- [ ] [**core**] Reorganized the project to use the provided `Scene` base class
- [ ] [**core**] Updated the `Game` class to use the provided declaration and implemented it's interface
- [ ] [**core**] Created own implementation of the `Scene` interface to provide a `PlayScreen` that has a way to go back to the Main Menu
- [ ] Used `virtual` only in base class declarations
- [ ] Used `override` when implementing a base class method
- [ ] All source files compile without warnings and without errors.
- [ ] Correct files submitted. No unnecessary files submitted.
- [ ] All source files have a proper header comment with your name, assignment name/number, course name, term.
- [ ] Followed the appropriate Code Quality Guidelines and Code Style Guidelines.
- [ ] Zip file has all the required files.



Scores for Assignments will be given as the following:

Score        | Assessment
------------ | ----------
Zero         | Nothing turned in at all
Failing      | Close to meeting core requirements
Rudimentary  | Meets all of the core requirements
Satisfactory | Close to meeting all requirements
Good         | Clearly meets all requirements 
Excellent    | High quality, well beyond the requirements
