package com.xiaogou.bigdata.scala

import org.apache.spark.rdd.RDD
import org.apache.spark.{SparkConf, SparkContext}

object WordCount {
  def main(args: Array[String]) : Unit = {

    var config : SparkConf = new SparkConf().setMaster("local[*]").setAppName("WordCount")
    // 开发工具
    var sc = new SparkContext(config)

    println(sc)

    val lines : RDD[String] = sc.textFile("in")
    
    
    val value = sc.makeRDD(1 to 10)
    val words = lines.flatMap(_.split(" "))

    val wordToOne : RDD[(String, Int)] = words.map((_, 1))
    val wordToSum : RDD[(String, Int) ] = wordToOne.reduceByKey(_+_)
    val result : Array[(String, Int)] = wordToSum.collect()
    result.foreach(println)
  }
}
