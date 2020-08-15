package com.xiaogou.bigdata.scala

import scala.collection.mutable.ArrayBuffer
class Counter {
  private var value = 0
  def increment(): Unit = {
    value += 1
  }
  def current() = value

  val timeStamp = new java.util.Date

  def v() : Int = {
    return Int(timeStamp)
  }
}
object huangxiaoyan {

  private var lastNumber  = 0
  def newUniqueNumber () = {
    lastNumber += 1; lastNumber
  }
  def main(args: Array[String]): Unit = {
    val nums  = new Array[Int](10)
    val strs  = new Array[String](10)
    val s = Array("Hello", "World")
    s(0) = "Goodbyte"


    val b = ArrayBuffer[Int]()

    b+=1
    b+=1

    b+=(1, 2, 3, 4)
    b ++= Array(8, 13, 21)

    b.trimEnd(5)

    b.insert(2, 6)
    b.insert(2, 7, 8, 9)
    b.remove(2)
    b.remove(2, 3)

    b.toArray

    val result = for(elem <- b) yield 2 * elem
    println(result)

    val myCounter = new Counter
    myCounter.increment()
    println(myCounter.current())
    println(myCounter.v())
  }

  def maxSubArray(nums : Array[Int]) : Int = {
    var  ans : Int = 0
    var  sum : Int = 0
    var  mmax: Int = nums(0)

    for ( i <- 0 until nums.length) {
      mmax = if (mmax < nums(i)) nums(i) else mmax
      if( nums(i) + ans < 0) {
        sum = 0
      } else {
        sum += nums(i)
        ans = if(ans < sum)  sum else ans
      }
    }

    return if( ans == 0 ) nums.Max else ans

  }
}
