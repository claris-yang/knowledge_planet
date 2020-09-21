package com.xiaogou.bigdata.scala

import javax.security.auth.login.AccountException

import scala.math._


object Accounts {
  private var value = 0
  def increment(): Unit = {
    value += 1
  }
  def current() = value
}

object Demo1 {
  def main(args: Array[String]) : Unit = {
    print(1)
    print(sqrt(2))
    print(pow(2, 4))
    BigInt.probablePrime(100, scala.util.Random)

  }
}
