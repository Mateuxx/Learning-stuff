data class Student (val id: Int, val name:String ,val grade: Double, ) 

    val students = listOf<Student>(
        Student(1, "Mateus", 86.0),
        Student(2, "Luan", 89.0),
        Student(3, "Bob", 92.0),
        Student(4, "Mark", 140.0)
    )


 fun main() { 
//    step 4 
    println("Please, Enter the student's ID") 
    val id = readln().toInt() 
    println( getStudentById(id)) 
    println("Please, Enter the student's name") 
    val name= readln() 
    println(searchInStudents(name)?:"the student is not found") 
}    
 
fun getStudentById (id:Int):Student {
    return students.find { it.id==id }!!
}

fun searchInStudents(name:String):Student?{ 
    return students.find { it.name.lowercase()==name.lowercase()} 
   
}



