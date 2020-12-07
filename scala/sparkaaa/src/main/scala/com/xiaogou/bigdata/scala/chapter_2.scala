package com.xiaogou.bigdata.scala
import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._
class Counter {
  private var value = 0
  def increment(): Unit = {
    value += 1
  }
  def current() = value
}
class Employee extends Counter {
  var salary = 0.0


}
package com {
  package horsemann {
    package impatient {
      class Employee
    }
  }
}
object chapter_2 {
  var nums1 = ArrayBuffer[Int]()
  var nums2 = ArrayBuffer[Int]()


  private var  lastNumber = 0
  def newQniqueNumber() = {
    lastNumber += 1; lastNumber
  }
  val myCounter = new Counter
  myCounter.increment()
  println(myCounter.current)
  def main(args: Array[String]): Unit = {
    breakable {

    }

    for ( i <- 1 to 3; j <- 1 to 3 if i != j)
      print(( 10 * i + j) + " ")

    for(i <- 1 to 4;
        from = i - 4;
        j <- from to 4) {

    }

    for( i <- 1 to 10) yield i % 3
    for( c<- "Hello" ; i <- 0 to 1) yield (c + i).toChar

    for( i <- 0 to 1; c <- "Hello" ) yield (c + i).toChar

    def abs(x : Double ) = if( x >= 0 ) x else  -x


    def fac(n : Int) : Int = if (n <= 0) 1 else n * fac(n - 1)

    def decorate(str : String, left : String = "[") = left + str

    def sum ( args : Int*) = {
      var result = 0
      for( arg <- args ) result += arg
      result
    }

    def recu(args:Int *):Int = {
      if(args.length == 0) 0
      else  args.head + recu(args.tail: _*)
    }

    def box(s : String): Unit = {
      var border = "-" + s.length + "--\n"
      println(border + "|")
    }

    val nums = new Array[Int](10)
    val a = new Array[String](10)


    ArrayBuffer("Mary", "bad", "a")

    val scores = Map("Alice" -> 10, "Bob" -> 3, "Cindy" -> 8)
    val scs = scala.collection.mutable.Map("Alice"->10)


  }
}
