/**
 * JavaScriptCoreCPP
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _JAVASCRIPTCORECPP_DETAIL_JSPERFORMANCECOUNTER_HPP_
#define _JAVASCRIPTCORECPP_DETAIL_JSPERFORMANCECOUNTER_HPP_

#ifdef JAVASCRIPTCORECPP_PERFORMANCE_COUNTER_ENABLE
#include <atomic>

namespace JavaScriptCoreCPP { namespace detail {
  
  // Add -DJAVASCRIPTCORECPP_PERFORMANCE_COUNTER_ENABLE=1 to enable the performance counters.
  
  template <typename T>
  class JSPerformanceCounter {
    
  public:
    
    static long get_objects_alive() {
      return objects_alive_;
    }
    
    static long get_objects_created() {
      return objects_created_;
    }
    
    static long get_objects_destroyed() {
      return objects_destroyed_;
    }
    
    static long get_objects_copy_constructed() {
      return objects_copy_constructed_;
    }
    
    static long get_objects_move_constructed() {
      return objects_move_constructed_;
    }
    
    static long get_objects_copy_assigned() {
      return objects_copy_assigned_;
    }
    
    static long get_objects_move_assigned() {
      return objects_move_assigned_;
    }
    
    JSPerformanceCounter() {
      ++objects_alive_;
      ++objects_created_;
    }
    
    // Copy constructor.
    JSPerformanceCounter(const JSPerformanceCounter& rhs) {
      ++objects_alive_;
      ++objects_created_;
      ++objects_copy_constructed_;
    }
    
    // Move constructor.
    JSPerformanceCounter(JSPerformanceCounter&& rhs) {
      ++objects_alive_;
      ++objects_created_;
      ++objects_move_constructed_;
    }
    
    // copy assignment operator
    JSPerformanceCounter& operator=(const JSPerformanceCounter&& rhs) {
      ++objects_copy_assigned_;
      return *this;
    }
    
    // move assignment operator
    JSPerformanceCounter& operator=(JSPerformanceCounter&& rhs) {
      ++objects_move_assigned_;
      return *this;
    }
    
  protected:
    
    // Objects should never be removed through pointers of this type.
    ~JSPerformanceCounter() {
      --objects_alive_;
      ++objects_destroyed_;
    }
    
    
  private:
    
    static std::atomic<long> objects_alive_;
    static std::atomic<long> objects_created_;
    static std::atomic<long> objects_destroyed_;
    static std::atomic<long> objects_copy_constructed_;
    static std::atomic<long> objects_move_constructed_;
    static std::atomic<long> objects_copy_assigned_;
    static std::atomic<long> objects_move_assigned_;
  };
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_alive_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_created_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_destroyed_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_copy_constructed_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_move_constructed_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_copy_assigned_;
  
  template<typename T>
  std::atomic<long> JSPerformanceCounter<T>::objects_move_assigned_;
  
  
}} // namespace JavaScriptCoreCPP { namespace detail {

#define JAVASCRIPTCORECPP_PERFORMANCE_COUNTER1(class_name) : public detail::JSPerformanceCounter<class_name>
#define JAVASCRIPTCORECPP_PERFORMANCE_COUNTER2(class_name) , public detail::JSPerformanceCounter<class_name>
#else
#define JAVASCRIPTCORECPP_PERFORMANCE_COUNTER1(class_name)
#define JAVASCRIPTCORECPP_PERFORMANCE_COUNTER2(class_name)
#endif // JAVASCRIPTCORECPP_PERFORMANCE_COUNTER_ENABLE

#endif // _JAVASCRIPTCORECPP_DETAIL_JSPERFORMANCECOUNTER_HPP_