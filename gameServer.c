// gameServer.c
// CSCI 4511W - Final Project - Dots And Boxes Tournament
// Created: Thursday May 4, 2017
// Contributors:
//		Liam Gonyea - gonye017
//		Seth Eisenbraun - eisen205

/** 
	Description:
		Game Controller/Server will "host" the different game playing agents.
		To do this, it will track the current game state, player scores, whos turn, 
		and current status of the game (whether or not it is finished). 
		Additionally, this program will communicate with other running programs 
		(other game-playing agents) via message passing queues and terminate them if the
		agent takes longer than max allotted time (MAX_TURN_TIME). This program will then
		execute a "random" move for the agent, effectively doubling as a random 
		game-playing agent. 
*/





