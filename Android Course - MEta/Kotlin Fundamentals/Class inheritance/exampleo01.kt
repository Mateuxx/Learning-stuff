enum class PizzaSize(val sizeInCm: Int){
    //ENUM VALUES 
    SMALL(15),
    MEDIUM(20),
    LARGE(25),
    EXTRALARGE(30)
}

//a function just to print the pizza size
fun printSize (pizzaSize: PizzaSize) {
    println("$pizzaSize is ${pizzaSize.sizeInCm} cm")
}


fun main() {
    printSize(pizzaSize.MEDIUM); //medius is 20cm
}
