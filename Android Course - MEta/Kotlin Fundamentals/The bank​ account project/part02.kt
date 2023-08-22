fun main () {
	
    //step 01 
    var accountBalance = (0..100).random()
    println("The current balance is ${accountBalance} dollars.")
	
    val money = (0..100).random()
    println("The amount you transferred is ${money} dollars.")
	
    //step 02 
    var output = 0;
    
    //step 03 -> Implement the withdrawal operation for generic and credit bank accounts 
   
    fun withdraw (amount: Int ): Int {
		accountBalance -= amount
        println("You succesfully withdraw ${amount} The current balance is ${accountBalance} dollars.")
    	return amount
       }
    
   	output = withdraw (money)
    //print(output)-. retorna apenas o valor do amount -> que eh oq a função retorna
    
    //step 05 -> Implement the withdrawal operation for debit accounts
    fun debitWithdraw(amount:Int): Int {
		if (accountBalance == 0){
            println("Cant withdraw, no money in this account!")
        	return accountBalance
        }
        else if (amount > accountBalance) {
            println("Not enough money on this account! The current balance is ${accountBalance} dollars.")
        	return 0
        }
        else {
         	return withdraw(amount)   
        }
    }	
    	
     output = debitWithdraw(money)
     println("The amount you withdrew is ${output} dollars.")

    
    //step 06 -> : Implement the deposit operation for generic and debit accounts
	fun deposit(amount: Int): Int {
        accountBalance += amount
        println("You successfully deposited ${amount} dollars. The current balance is ${accountBalance} dollars.")
        return amount
    }
    
    //step 07 -> Test functions
    output = deposit(money)
    println("The amount you deposited is ${output} dollars.")
	
    //step 08 -> Implement the deposit operation for credit accounts
	fun creditDeposit(amount: Int): Int {
        if (accountBalance == 0) {
            println("This account is completely paid off! Do not deposit money!")
            return accountBalance
        } else if (accountBalance + amount > 0) {
            println("Deposit failed, you tried to pay off an amount greater than the credit balance. The current balance is ${accountBalance} dollars.")
        	return 0
        } else if (amount == -accountBalance) {
            accountBalance = 0
            println("You have paid off this account!")
            return amount
        } else {
            return deposit(amount)
        }
    }
    
    output = creditDeposit(money)
    println("The amount you deposited is ${output} dollars.")
}