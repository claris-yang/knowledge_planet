package com.xiaogou.bigdata.scala

import scala.io.StdIn
import scala.math.{BigInt, pow, sqrt}
import scala.math.{max, min}

object StTable {

  val N = 1005
  var lg = new Array[Int](N)
  var st = Array.ofDim[Int](N, N)
  var n , m  = 0
  def main(args: Array[String]) : Unit = {

    n = StdIn.readInt()
    m = StdIn.readInt()
    for( i <- 1 to n  ) {
      st(i)(0) = StdIn.readInt()
    }

    for( i <- 1 to n) {
      lg(i) = lg( i - 1 ) + (1 << (i - 1)) == i)
    }

    for( j <- 1 to n
  }

  def query(l : Int, r : Int) : Int = {
    val k : Int = lg( (r - l + 1) >> 1)
    return max(st(l)(k), st(r - (1 << k) + 1)(k))
  }

  def fac(n : Int) : Int = if(n < 0) 1 else 0
}
