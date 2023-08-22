/*** 
 Scenario
 
Imagine you have secured a job with a game development company. Your first assignment is to create a small piece of code to hold the Player data for one of their games.
The requirements of your program are:
Store and display the Player’s full name 
Store, manipulate and display the Player’s score data 
Store and display a personal best score (Players get a score for each level played) 
Display the winning Player’s name and their total score and their best level score
When all your code is completed you will have a final console output that simulates an end-of-game score. 
You will have two lines each with text and a Player score.  (This is just an example of the output, you will input level sores later to produce a final result).
 ***/

 class Player (val name:String, val surName: String){

    //properties
    var totalScore = 0
    var personalBestScore = 0
    
    //method -> jus a normal function inside a class!!!!
    fun fullName () : String { // Specify what you want to get for return!!!
        return "$name $surName"
    }

}

class Scores () {
        fun checkScore (best:Int, current:Int) : Int {
            if (best < current ){
                return  current;
            }
            return best;
        }
}


fun main () {
    
    val P1 = Player("Nicolas", "Tesla")
    val P2 = Player ("Thomas", "Edison")

    //create working variables 
    val scoring = Scores() // Instance of the Score class to acess the checkScore function (Actually is a Method)
    var lvlScore = 0

    //LEVEL 1

    //P1
    lvlScore = 12
    P1.totalScore += lvlScore
    P1.personalBestScore = scoring.checkScore(P1.personalBestScore, lvlScore)

    //P2
    lvlScore = 78
    P2.totalScore += lvlScore
    P2.personalBestScore = scoring.checkScore(P2.personalBestScore, lvlScore)

    
    //Getting the Names of the players -> just beacause im not sure if i can use $P1.fullName() in println 
    val nameP1 = P1.fullName() 
    val nameP2 = P2.fullName()

    //Getting the score
    val scoreP1 = P1.totalScore
    val scoreP2 = P2.totalScore
   	val personalP2 = P2.personalBestScore
    //Determine a winner 
    if(P1.totalScore>P2.totalScore) {
        println("The winner is $nameP1 with a Score of $scoreP1 ")
        println("Personal Best Score is = $P1.personalBestScore")
    }
    else {
        println("The winner is "+ P2.fullName() + " with a Score of "+P2.totalScore); 
        println("Personal Best Score is = $personalP2" ); 

    }
    
}