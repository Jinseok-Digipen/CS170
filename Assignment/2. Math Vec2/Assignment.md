# CS170 Math Assignment

For this assignment you will be implementing your own objects to represent mathematical Vectors in two dimensions. There will be two versions where one version represents it's numbers with `double` called `vec2` and the other with `int` called `ivec2`.

One must be able to:

* construct a vector with no arguments which defaults to `[0,0]`
* construct a vector with one argument which is used for both x and y to `[value, value]`
    + should be marked `explicit`
* construct a vector with two arguments like `[x_value, y_value]`
* add one vector into another --> `v += v2;`
* add two vectors to create another --> `v = v1 + v2;`
* subtract one vector from another --> `v -= v2;`
* subtract two vectors to create another --> `v = v1 - v2;`
* negate a vector --> `v = -v1;` _(note `v1` won't have it's values changed)_
* scale a vector by a --> `v *= 2.0; v = v2 * 2.0; v = 2.0 * v2;`
* divide a vector by a --> `v /= 2.0; v = v2 / 2.0;`
* check if two vectors are equal  --> `if(v == v2) {...} if(v != v2){...}`
    - should use `std::numeric_limits<double>::epsilon()` for the `double` version
* `double` version can be normalized and has a way to get the length squared --> `v.LengthSquared(), v.Normalize()`
* `int` version can be converted to the `double` version --> `static_cast<vec2>(ivec2{10,25});`

## Requirements

Your objects must be marked as **`[[nodiscard]]`**, so that functions that return it will automatically become `nodiscard`.

Any function or method that returns a basic type must be marked `[[nodiscard]]`.

Must make use of delegating a constructor.

Must make use of a **'`= default`'** constructor.

Every function, constructor and object method must be **`constexpr`** and **`noexcept`**.

Because you will be creating `constexpr` objects, that means you will have to create header only code. Instead of putting your implementations into a `*.cpp` file put them in a `*.inl` file instead. **'*.inl'** is short for **`inline`**. At the bottom of your header file **`#include`** the corresponding inline file. Any implementation that is more than one line of code must be defined in the inline file. If the implementation is a small one liner then you may implement it with it's declaration.

You will create a `double` based vector called **`vec2`** and an `int` based vector called **`ivec2`**.
In order for your types to work with the test drivers you will need to within the **`math`** namespace.


Create a **`ReadMe.txt`** file that defines the following

1. your name, assignment name/number, course name, term
2. Section describing anything incomplete about the assignment
3. File and Line numbers for objects & functions marked `[[nodiscard]]`
4. File and Line numbers where delegating constructors were used
5. File and Line numbers where a `= default` constructor were used
6. Section describing something you're proud of about the assignment

## Submission

You will be submitting your work on GitHub with the provided class assignment repository. You will also create a copy of your project as a zip file on the course site. 

The name of the ZIP file must follow this naming convention: `[class_name]_[login]_math.zip`

For example, if a student had the login name fun.frank then the appropriate filename would be `cs170_fun.frank_math.zip`. Note: The .zip file names are case-sensitive and must be in all lowercase, exactly as described above.

Note that we will be grading from the GitHub repo and we are using the zip copy as a way to backup your work.

## Rubric


- [ ] [**core**] Implementation of the concept of 2d vectors and points as C++ objects with `double` and `int` representations
- [ ] [**core**] Satisfied all of the Requirements listed above
- [ ] Used `std::numeric_limits<double>::epsilon()` for `double` equality checks.
- [ ] Reused functions as much as possible.
- [ ] All source files compile without warnings and without errors.
- [ ] Correct files submitted. No unnecessary files submitted.
- [ ] All source files have a proper header comment with your name, assignment name/number, course name, term.
- [ ] Followed the appropriate Code Quality Guidelines and Code Style Guidelines.
- [ ] Properly named zip file.
- [ ] Zip file has all the required files.



Scores for Assignments will be given as the following:

Score        | Assessment
------------ | ----------
F | Nothing turned in at all
D | Close to meeting core requirements
C | Meets all of the core requirements
B | Close to meeting all requirements
A | Clearly meets all requirements 
S | High quality, well beyond the requirements
