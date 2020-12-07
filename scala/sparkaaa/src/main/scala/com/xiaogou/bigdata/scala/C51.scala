package com.xiaogou.bigdata.scala

import java.io.FileReader
import java.util.Properties

import org.apache.avro.ipc.specific.Person

import scala.beans.BeanProperty

class MyProg {
  private val props = new Properties
  props.load(new FileReader("myprog.properties"))
}

class Person(val name : String , val age : Int) {
  println("Just constructed another person")
  def description = name + " is " + age + "years old"
}

// 定义一个类
class Counter{
  private var value = 0
  private var age1 = 0
  @BeanProperty var name : String = _

  def age = age1


  // 方法默认是共有的
  def increment(): Unit = {
    value += 1
  }

  def current() = value

  def isLess(other : Counter) = value < other.value

}
object C51 {

  def main(args: Array[String]): Unit = {
    // 声明一个类
    val myCounter = new Counter
    myCounter.increment()
    println(myCounter.current)

    val person = new Person("xiaolaoshi", 32)

  }

}
