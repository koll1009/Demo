#include "kSpinLock.h"

/* Memory Barrier: solve problem introduced by memory reordering
 *
 * Memory reordering:
 *     shall not modify the behavior of a single-threaded program.
 *     therefore, if it is multi-threaded, this optimization can bring problems.
 *     memory barrier has already been used in lock mechanisms, such as
 *     spinlock/mutex. Only lock-free programming requires developers to explicitly
 *     use memory barrier
 *
 * Compiler reordering:
 *     The solution is to explicitly tell the compiler by the designer of the upper
 *     software (through compiler barrier.) When reading a specific variable, the
 *     value of the variable should be read from memory instead of reusing the
 *     previously read value cached in the register.
 *
 *     The volatile keyword described in the previous section can be used to suppress
 *     the compiler reordering optimization for specific variables only. However,
 *     as mentioned earlier, volatile is always bound with a variable. Most of the time,
 *     the compiler reordering optimization for a specific variable is expected to be
 *     eliminated at a specific time.This is why ACCESS_ONCE() was created.
 *     #define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x)).
 *
 *     Due to the defects of ACCESS_ONCE() (a compiler bugs), the kernel code gradually
 *     uses READ_ONCE()/WRITE_ONCE() to replace ACCESS_ONCE()
 *
 * CPU Reordering:
 *     smp_mb() memory barrier is used to implement store-store synchronization
 *     When the smp_mb() memory barrier is called, the CPU first performs a flush operation
 *     on the store buffer. During the flush operation, the modified data cached in the store buffer
 *     will be updated to the cache line after the invalidate acknowledge message is received from
 *     all other CPUs. By doing so, when all the data in the store buffer are updated to the cache line,
 *     the CPU can continue to execute the store operation after the smp_mb() memory barrier.
 *     The load operations after the smp_mb() memory barrier can be performed without completing the store buffer flush operation.
 *
 *     CPU Reordering	CPU Barrier
 *      LoadLoad	        smp_rmb()
 *      StoreStore	    smp_wmb()
 *      full	            smp_mb()
 *
 */

void kSpinLock::lock()
{
    while(flag_.test_and_set(std::memory_order_acquire));
}

void kSpinLock::unlock()
{
    flag_.clear(std::memory_order_release);
}