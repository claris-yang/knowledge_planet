package com.xiaogou.bigdata.scala

import scala.collection.mutable.ArrayBuffer

object Array {
  def restoreString(s: String, indices: Array[Int]): String = {
    val ans  = new  StringBuilder(s.length)
    for(elem <- s) {
      ans += elem
    }
    for(idx <- indices) {
      ans(idx) = s(idx)
    }
    return ans.toString
  }
  def main(args: Array[String]): Unit = {
    val s = "codeleet"
    val indices = (4, 5, 6, 7, 0, 2, 1, 3)
    println()
  }

}
