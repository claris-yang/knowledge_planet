package com.xiaogou.bigdata.scala

import scala.math._
object Demo1 {
  def main(args: Array[String]) : Unit = {
    print(1)
    print(sqrt(2))
    print(pow(2, 4))
    BigInt.probablePrime(100, scala.util.Random)
  }
}
