import java.util.*
import java.lang.Math.*
import kotlin.math.max
import kotlin.math.roundToLong

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var n = nextInt()

    for(i in 1..n){
        var a = nextFloat()
        a *= 0.8F * 100
        a = a.roundToLong() / 100f
        print("%")
        println(a)
    }
}