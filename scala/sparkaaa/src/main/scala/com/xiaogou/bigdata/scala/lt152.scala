package com.xiaogou.bigdata.scala

object lt152 {
  val P = 1000000007
  def main(args: Array[String]): Unit = {
    var res = waysToStep(61)
    println(res)
  }
  def waysToStep(n : Int) : Int = {
    var a , b, c, ans: Long = 1
    b = 2
    c = 4
    if (n == 1 ) return 1
    else if (n == 2) return 2
    else if (n == 3) return 4

    for(i <- 4 until n + 1 ){
      ans = (a + b + c) % P
      a = b
      b = c
      c = ans
    }
    return ans.toInt
  }
}
