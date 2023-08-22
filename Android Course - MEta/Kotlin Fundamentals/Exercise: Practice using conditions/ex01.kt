//Exericise 01 - COursera tentar fazer  USING WHEN
fun main() {

    val weekday = "Sunday"
    println ("On $weekday, the opening hours are: ")

    when {

        weekday == "Monday" -> println ("8 AM to 12 PM")
        weekday == "Tuesday" -> println ("8 AM to 6 PM")
        weekday == "Wednesday" -> println ("8 AM to 6 PM")
        weekday == "thursday" -> println ("8 AM to 6 PM") 
        weekday == "Friday" -> println ("8 AM to 6 PM")
        weekday == "Saturday" -> println ("9 AM to 4 PM")
        weekday == "Sunday" -> println ("8 AM to 4 PM")
    }


}