/* 
Scenario
Function parameters and returning values are important parts of programming. Let’s say you are developing a game and you need to keep track of the score.
As someone plays the game, you need to add points to their score.
The score might be boosted if the player picked up a special item.
In this exercise, you’ll create a simple function that calculates the total points to be added to the score. 
The function will have two parameters, one for the base number of points and another for the boost value. The boost value will be multiplied by the base amount.
*/


fun getPoints(basePoints: Int, boost: Int): Int { 
    return basePoints * boost 
} 
 
fun main() { 
    var score = 0; 
    println(score) 
    score += getPoints(10, 1) 
    println(score) 
    score += getPoints(20, 2) 
    println(score) 
    score += getPoints(-10, 1) 
    println(score) 
    score += getPoints(5, 3) 
    println(score) 
    score += getPoints(-15, 2) 
}