#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Game.hpp"
//File

int main(int, char const**)
{
 try{
     Game g;
     g.exec();
 } catch(...)
 {
 /* future operations */
 }
    return EXIT_SUCCESS;
}
