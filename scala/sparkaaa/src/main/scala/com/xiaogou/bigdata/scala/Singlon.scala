package com.xiaogou.bigdata.scala
class Singlon {
  val id = Singlon.newUniqueNumber()
  private var balance = 0.0
  def deposit(amount : Double): Unit = {
    balance += amount
  }
}
object Singlon {
  private var lastNumber = 0
  def newUniqueNumber() = { lastNumber += 1;
  lastNumber}
  def main(args: Array[String]): Unit = {
    println(Singlon.newUniqueNumber())
    println(Singlon.newUniqueNumber())

    val mySinglon = new Singlon
    mySinglon.deposit(100)

    println(mySinglon.balance)

    mySinglon.balance = 11

    println(mySinglon.balance)
  }
}
