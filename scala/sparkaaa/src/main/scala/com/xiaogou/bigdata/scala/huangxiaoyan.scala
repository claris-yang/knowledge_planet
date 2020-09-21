package com.xiaogou.bigdata.scala

import scala.collection.mutable.ArrayBuffer

object huangxiaoyan {


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
    return 1
  }
}
