# Cub3D
A raycasting game engine programmed in C from scratch, inspired by the world's first 3D game

![](images/record.gif)

### The project covers:

- The parsing of a map file
- The use of a basic graphic library
- Coding a program which allows us to save a screen shot of the image on screen in a "bmp" format
- The raycasting physics engine allowing us to see 2D calculations as a 3D world around us
- A HUD containing a minimap
- Healthbar and traps
- Enemies and an animated weapon
- Distance related shadow effect
- Secret corridors
- The skybox and a floor texture
- Collisions with walls and some objects 
- Background music and sounds
- A game over level

### Amazing links that helped me to create this project:
- [**A great C++ Raycasting tutorial**](https://lodev.org/cgtutor/raycasting.html)
- [**A walkthrough tutorial for the minilibx graphic library**](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [**BMP format in detail**](https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html)
- [**BMP format C code example**](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries)
- [**A great free online tool to draw pixel art sprites**](https://www.piskelapp.com)
- [**PNG to XPM online converter (❗ has a daily limit of conversions)**](https://convertio.co/fr/png-xpm/)
- [**Free music and sound effects website**](https://www.zapsplat.com)

### Try it:
❗ This project was optimized for a local use and may not work properly in other environments.

If you wish to try it, here are the Makefile commands you need to use in the terminal while in project's repo directory:
- `make` will compile the basic project (without the enemies / shadows etc.) and create the "cub3D" executable
- `make bonus` will do the same but will include the bonus part
- With "cub3D" executable created, you can launch the game with any of the .cub map files in "maps" folder. 

  Example: `./cub3D maps/map9.cub`
- `make fclean` is used to clean up all of the files created using the compilation
- `make run` will launch  the project without any bonuses
- `make brun` will launch the project with the bonuses
- `make save` will launch the project and save the first image on screen in a "bmp" format, then it will close the project window
- WASD or Up/Down arrow keys to move, QE or Left/Right arrow keys to look left/right, SPACEBAR to attack using the weapon
- Escape key to quit the game

### Licensing Notes:
- All music and sounds were free ressourses downloaded from [**zapsplat.com**](https://www.zapsplat.com/)
- The hand with the knife is a modified image from the Wolfenstein 3D, all rights belong to id Software
- The rest of the used sprites and textures were drawn by myself using Pixaki on iPadOS
