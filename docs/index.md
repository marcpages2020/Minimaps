I am [Marc Pagès Francesch](https://www.linkedin.com/in/marc-pagès-7206b3186/), student of the [Bachelor's Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/ing/estudis/graus-videojocs/). This content is generated for the second year's subject Project 2, under supervision of lecturer [Marc Garrigó](https://www.linkedin.com/in/mgarrigo/).
The purpose of this website is to have a look at what Minimaps are, how different games have approached them, which caharacteristics they have and give a little example on how to implement one. So now, let's get into it!

## What's a minimap?
A minimap is a miniature map representation located in a part of the screen. It often displays the different points of interest or elements the player might be interested in locating in the game and depending on the game. It can also display the position of allies and enemies.  
In order for the player to be oriented it normally has an N or an arrow indicating where the north is. 

|![far cry 3 minimap](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/Far_Cry_3_Minimap.jpg?raw=true)|![the witcher 3 minimap](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/The_Witcher_3_Minimap.jpg?raw=true)|
|:---:|:---:|
|Far Cry 3|The Witcher 3: Wild Hunt|


## Why to use a minimap?
A minimap can help the user to get oriented in the game world but its use has created a lot of controversy:
### Inmersion
Minimaps have been accused of breaking the inmersion of the player in the game because of being a static UI element which unless you get to do a diegetic minimap it won't be a part of the game so you take the risk of breaking the player's inmersion into the game. 

![BotW HUD](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/BotW_HUD.gif?raw=true)

### Position
Later we will talk about where a minimap can be displayed, but in general people who are against the use of minimaps argument that along with other UI elements it is placed in a screen position which is not natural for human perception.
To make this point clear we have to take a deeper look at how human vision works. 

![foveal vision](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/foveal_and_peripheral_vision.jpg?raw=true)

This is more or less how our brain sees the world even we don't consciouscly see it this way. In the middle of our field of vision stands the foveal vision and the rest is composed by the peripheral vision. The foveal vision is made by our cone cells located mainly in the middle of our retina and they send clear colored images to our brain while the peripheral vision is made by our rod cells which send uncolored and less clear images to our brain. This is why our eyes always move: to try to keep the important elements of our environment in the center of the vision. 
So, if important information should be in the middle of our vision it's quite ironic that important UI elements are in the corners of the screen where the player won't see them clearly or will have to change the focusing point quite often to be aware of this information. 

## Characteristics of a minimap
Minimaps can be very different depending on the game genre and the specific characteristics of the game. Nevertheless, there are certain elements all game minimaps have in common and good practices to be taken in account when implementing one:
* Marking north in the minimap helps the players locate themselves in the game world and eases navigation in it. 
* The map can either be fixed to north or fixed to the player. If the minimap is fixed to the player, when he rotates, the minimap will do it too. But if it is fixed to the north, when the player rotates, it will be it's representation in the minimap which will rotate. 
* If in the game allies and enemies positions are important and they don't neet to be secret, it is useful for the player that their position is displayed in the minimap. 
* Information in the minimap should be simplified for two reasons. 
  * The minimap is small so if the icons are too complex the player will have to look at the minimap for too long. 
  * If they are too big they will take too much minimap space and it will be more difficult to display more icons in it or see clearly the setoff of the map. 
* Important icons which are not in the minimap area can be placed in the edge of the minimap for the player to know the direction where they are and be able to follow them until he reaches the area where the icon is. 
* In strategy games if the game is made for PC it is useful to make the map interactable so the player can move easily through the map using the minimap.
* To help people with color blindness the minimap icons should have a well contrasted color or at least there should be the possibility to change the icons colors to high contrasted ones. 
* Depending on the size of the map the minimap can show all the map extension or just a part of it. For example, in racing games the circuit is small enough to be displayed entirely in the minimap while in most RPGs the map is too big and not even an eleventh part of it can be shown in the minimap. 

## Implementation in RTS 
In RTS games, in order to make the minimap as functional as possible, it normally has these characteristics:
 * It is static.
 * It displays the totallity of the map extension keeping the zoom at its minimum. 
 * It shows all allies position and enemies in the allies field of view. 
 * It can be orthogonal or isometric. 
 * It can show the path some entities are following.
 * It may have icons represetnting temporary alerts or notifications. 

|![StarCraft](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/Starcraft%20Minimap.png?raw=true)|![Age of Empires](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/AoE2_Minimap.jpg?raw=true)|![they are billions image](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/TheyAreBillionsMinimap.jpg?raw=true)|
|:---:|:---:|:---:|
|StarCraft|Age of Empires II|They Are Billions|

## The future of minimaps
Minimaps have been present in video games for more than thirty or fourty years, depending on if you count Defender's minimap as one or you count Civilization I as the first. Now it seems that the industry is starting to take them out of the HUD. It can either be for the tendency to reduce the HUD as much as possible in order not to break the inmersion into the game or to replace it with an element which is becoming more popular, the compass.

|![Defender's minimap](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/defender.png?raw=true)|![Civilization minimap](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/Civilization.jpg?raw=true)|
|:---:|:---:|
|Defender|Civlization I|

The compass hasn't been invented recently. It has been an important part of some franchises such as The Elder Scrolls or Fallout, but it has started appearing in genres that had always used minimaps such as third person games like Assassin's Creed or Horizon: Zero Dawn. This change has been made mainly because compasses are more discrete and important points now aren't displayed as exact positions but directions, what aims the player to explore a little bit more and if he wants to know the exact position he can always use the map. 
 
|![Skyrim](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/Skyrim%20compass.jpg?raw=true)|![AC compass](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/ACO_Compass.jpg?raw=true)|
|:---: |:---:|
|Skyrim|Assassin's Creed Origins|

## Implementation in code

In [my repository](https://github.com/marcpages2020/Minimaps) you can find a project with which you can practice a simple implementation of minimaps in C language. 

### TODO 1: Calculate the dimensions of the minimap
You should determine the scale calculating the map size and relating it to the target map width given in config.

### TODO 2: Create a texture for the minimap
Create a base texture using the function [SDL_CreateTexture](https://wiki.libsdl.org/SDL_CreateTexture) and the data from the previous TODO. 

### TODO 3: Set this texture as a rendering target and create the minimap

Check [SDL_SetRenderTarget](https://wiki.libsdl.org/SDL_SetRenderTarget) and try setting the target to create thet make and blit it. Don't forget to untarget the renderer when you hav finished drawing the map!

By now you should have something like this:

![](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/TODOs/TODO%203.PNG?raw=true)

### TODO 4.1: Fill the function WorldToMinimap to make the representation of the rect in the minimap be in the position it should 
When done, you should see something like this on screen: 

![](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/TODOs/TODO%204.gif?raw=true)

### TODO 4.2: Using WorldToMinimap create a white rect which represents the area that the camera records of the world onto the minimap 
Don't forget to make it a not filled rect!

### TODO 5: Convert a position from the screen to the Minimap and directly to world
Fill the function which can convert a screen position into world coordinates knowing the minimap position and the scale

### TODO 6: Transform the position of the mouse into Minimap coordinates and then to the world
Now that you have your conversion function use it ot convert the mouse position

### TODO 7: Move the camera when the player clicks on the minimap or scrolls the mouse on it while holding the left button
If the player clicks or holds the left mouse button while the mouse is on the minimap the camera should change it's position properly. 
And this should be the final result!

![](https://github.com/marcpages2020/Minimaps/blob/master/docs/images/TODOs/TODO%207.gif?raw=true)

### Homework
Now that you have all the basic material to implement a minimap imagination is the limit! Here are some examples of things you could try:
* Add more icons onto the minimap.
* Try replacing the squares by textures. 
* Using the config file try changing the corner in which the minimap, the margin and the width.
* Try replacing the black background by a colored one.  

## Sources
* [My personal crusade against mini-maps and other corner based HUD elements in immersive games by Andrii Honcharuk on Gamasutra](https://www.gamasutra.com/blogs/AndriiHoncharuk/20170714/301733/My_personal_crusade_against_minimaps_and_other_corner_based_HUD_elements_in_immersive_games.php)
* [Game UI PAtterns: Mini Map](https://gameuipatterns.com/gameui/mini-map/)
* [Video Game Mini-Maps Might Finally Be Going Away](https://www.kotaku.com.au/2017/11/video-game-mini-maps-might-finally-be-going-away/)

