# Minimaps

## What's a minimap?
A minimap is a miniature map representation located in a part of the screen. It often displays the different points of interest or elements the player might be interested in locating in the game and depending on the game it can also display the position of allies and enemies.  
In order for the player to be oriented it normally has an N indicating where the north is. 

## Why to use a minimap?
The minimap is a game element that has created a lot of controversy for various reasons:
### Inmersion
Minimaps have been accused of breaking the inmersion of the player in the game because of being a static UI element which is not actually a part of the game, in other words, unless you get to do a diegetic minimap it won't be a part of the game so you take the risk of breaking the player's inmersion into the game. 
### Position
Later we will talk about where a minimap can be displayed and where it should to be optimal but in general people who are against the use of minimaps argument that it along with other UI elements is placed in a screen position which is not natural for human perception.
To make this point clear we have to take a deeper look at how human vision works. 
This is more or less how our brain sees the world even we don't consciouscly see it this way. In the middle of our field of vision stands the foveal vision and the rest is composed by the peripheral vision. The foveal vision is made by our cone cells located mainly in the middle of our retina and they send clear colored images to our brain while the peripheral vision is made by our rod cells which send uncolored and less clear images to our brain. This is why our eyes always move to try to keep the important elements of our environment in the center of the vision. 
So, if important information should be in the middle of our vision it's quite ironic that important UI elements are in the corners of the screen where the player won't see them clearly or will have to change the focusing point quite often to be aware of this information. 
## Characteristics of a minimap
Minimaps can be very different dependng on the game genre and the specific characteristics of the game but there are certain elements all game minimaps have in common and good practices to be taken in account when implementing one:
- Marking north in the minimap helps the players locate themselves in the game world and eases navigation in it. 
- The map can either be fixed to north or fixed to the player. If the minimap is fixed to the player when he rotates the minimap will do it too if it is fixed to the north when the player rotates it will be it's representation in the minimap which will rotate. 
- If in the game allies and enemies positions are important and they don't neet to be secret, it is useful for the player that their position is displayed in the minimap. 
- Information in the minimap should be simplified for two reasons. First, the minimap is small so if the icons are too complex the player will have to look at the minimap for too long. Secondly, if they are too big they will take too much minimap space and it will be more difficult to display more icons in it. 
-Important icons which are not in the minimap area can be placed in the edge of the minimap for the player to know the direction where they are and be able to follo it until he reaches the area where the icon is. 
- In strategy games if the game is made for PC it is useful to make the map interactable so the player can move eaily through the map using the minimap.
- To help people with color blindness the minimap icons should have a well contrasted color or at least there should be the possibility to change the icons colors to high contrasted ones. 
- Depending on the size of the map the minimap can show all the map extension or just a part of it. For example in racing games the circuit is small enough to be displayed entirely in the minimap while in most RPGs the map is too big and not even an eleventh part of it can be shown in the minimap. 
## Implementation

## Sources
https://www.gamasutra.com/blogs/AndriiHoncharuk/20170714/301733/My_personal_crusade_against_minimaps_and_other_corner_based_HUD_elements_in_immersive_games.php
https://gameuipatterns.com/gameui/mini-map/
