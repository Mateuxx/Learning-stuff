class Comment (
    val userId: Int,
    val message: String
)

fun main () {
    //step2
    val comments: List<Comment> = ListOf(
        Comment(5241, "Nice code"),
        Comment(6624, "Like it"),
        Comment(5224, "What’s going on?"),
        Comment(9001, "Check out my website"),
        Comment(8818, "Hello everyone :)")
    )
    val blockUserIds: Set<Int> = setOf(5224, 9001)

    val userIdToRelation: Map<Int, String> mapOf(
        5241 to "friend",
        6624 to "close friend"
    )


    //Step 5
    for (commment in comments) {
        
        //step 6
        if(commment.userId !in blockUserIds){
            val relation = userIdToRelation[commment.userId]?: "unkown"
            
            //step7
            println ("Comment ${comment.message} from $relation")
        
        }
    }
}