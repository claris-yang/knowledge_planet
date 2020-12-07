package com.xiaogou.bigdata.scala

object C44 {

  def main(args: Array[String]): Unit = {
    // 不可变映射
    val scores = Map("Alice" -> 10, "Bob" -> 3)

    // 可变的映射
    val mutable = new scala.collection.mutable.HashMap[String, Int]

    val scores1 = Map(("Alice", 10))

    print(scores1)

  }

}
