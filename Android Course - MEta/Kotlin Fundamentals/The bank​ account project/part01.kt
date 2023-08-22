fun main() {
   
    //step 01 -> User interface
    
    //INTRO TO THE USER
    println("Welcome to your banking system. ")
    println("What type of account would you like to create?")
    
    //BANK OPTIOONS
    println("1. Debit account")
    println("2. Credit account")
    println("3. Checking account")
    
    //step 02 -> variables  
   	var accountType = ""
    var userChoice = 0 
    
    //step 03 -> Create a bank account based on user input
    while (accountType == "") {
        println("Choose an option (1, 2 or 3)")
        userChoice = (1..5).random()
        println("The selected choice option is ${userChoice}.")
        
        when (userChoice) {
           1 -> accountType = "debit"
           2 -> accountType = "credit"
           3 -> accountType = "checking"
           else -> continue
       }
    }
    //step 4 
    println("You have created a ${accountType} account.")
}