#include "System.Private.CoreLib.h"

namespace CoreLib { namespace System { namespace Threading { 
    namespace _ = ::CoreLib::System::Threading;
    // Method : System.Threading.Interlocked.Exchange(ref int, int)
    int32_t Interlocked::Exchange_Ref(int32_t& location1, int32_t value)
    {
#ifdef _MSC_VER
		return InterlockedExchange((LONG volatile*)&location1, value);
#else
		__sync_synchronize();
		return __sync_lock_test_and_set((int32_t volatile*)&location1, value);
#endif    
	}
    
    // Method : System.Threading.Interlocked.Exchange(ref long, long)
    int64_t Interlocked::Exchange_Ref(int64_t& location1, int64_t value)
    {
#ifdef _MSC_VER
		return InterlockedExchange64((int64_t volatile*)&location1, value);
#else
		__sync_synchronize();
		return __sync_lock_test_and_set((int64_t volatile*)&location1, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.Exchange(ref float, float)
    float Interlocked::Exchange_Ref(float& location1, float value)
    {
#ifdef _MSC_VER
		return InterlockedExchange((LONG volatile*)&location1, value);
#else
		__sync_synchronize();
		return __sync_lock_test_and_set((int32_t volatile*)&location1, value);
#endif  
	}
    
    // Method : System.Threading.Interlocked.Exchange(ref double, double)
    double Interlocked::Exchange_Ref(double& location1, double value)
    {
#ifdef _MSC_VER
		return InterlockedExchange64((int64_t volatile*)&location1, value);
#else
		__sync_synchronize();
		return __sync_lock_test_and_set((int64_t volatile*)&location1, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.Exchange(ref object, object)
    object* Interlocked::Exchange_Ref(object*& location1, object* value)
    {
#ifdef _MSC_VER
		return (object*)InterlockedExchangePointer((void* volatile*)&location1, value);
#else
		__sync_synchronize();
		return (object*)__sync_lock_test_and_set((void* volatile*)&location1, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.Exchange(ref System.IntPtr, System.IntPtr)
    ::CoreLib::System::IntPtr Interlocked::Exchange_Ref(::CoreLib::System::IntPtr& location1, ::CoreLib::System::IntPtr value)
    {
#ifdef _MSC_VER
		return __init<::CoreLib::System::IntPtr>(InterlockedExchangePointer((void* volatile*)&location1->INTPTR_VALUE_FIELD, value->INTPTR_VALUE_FIELD));
#else
		__sync_synchronize();
		return __init<::CoreLib::System::IntPtr>(__sync_lock_test_and_set((void* volatile*)&location1->INTPTR_VALUE_FIELD, value->INTPTR_VALUE_FIELD));
#endif
	}
    
    // Method : System.Threading.Interlocked._Exchange(System.TypedReference, System.TypedReference)
    void Interlocked::_Exchange(::CoreLib::System::TypedReference location1, ::CoreLib::System::TypedReference value)
    {
#ifdef _MSC_VER
		InterlockedExchangePointer((void* volatile*)&(location1.Value)->INTPTR_VALUE_FIELD, value.Value->INTPTR_VALUE_FIELD);
#else
		__sync_synchronize();
		__sync_lock_test_and_set((void* volatile*)&(location1.Value)->INTPTR_VALUE_FIELD, value.Value->INTPTR_VALUE_FIELD);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref int, int, int)
    int32_t Interlocked::CompareExchange_Ref(int32_t& location1, int32_t value, int32_t comparand)
    {
#ifdef _MSC_VER
		return InterlockedCompareExchange((LONG volatile*)&location1, value, comparand);
#else
		return __sync_val_compare_and_swap((int32_t volatile*)&location1, comparand, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref long, long, long)
    int64_t Interlocked::CompareExchange_Ref(int64_t& location1, int64_t value, int64_t comparand)
    {
#ifdef _MSC_VER
		return InterlockedCompareExchange64((int64_t volatile*)&location1, value, comparand);
#else
		return __sync_val_compare_and_swap((int64_t volatile*)&location1, comparand, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref float, float, float)
    float Interlocked::CompareExchange_Ref(float& location1, float value, float comparand)
    {
#ifdef _MSC_VER
		return InterlockedCompareExchange((LONG volatile*)&location1, value, comparand);
#else
		return __sync_val_compare_and_swap((int32_t volatile*)&location1, comparand, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref double, double, double)
    double Interlocked::CompareExchange_Ref(double& location1, double value, double comparand)
    {
#ifdef _MSC_VER
		return InterlockedCompareExchange64((int64_t volatile*)&location1, value, comparand);
#else
		return __sync_val_compare_and_swap((int64_t volatile*)&location1, comparand, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref object, object, object)
    object* Interlocked::CompareExchange_Ref(object*& location1, object* value, object* comparand)
    {
#ifdef _MSC_VER
		return (object*)InterlockedCompareExchangePointer((void* volatile*)&location1, value, comparand);
#else
		return (object*)__sync_val_compare_and_swap((void* volatile*)&location1, comparand, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref System.IntPtr, System.IntPtr, System.IntPtr)
    ::CoreLib::System::IntPtr Interlocked::CompareExchange_Ref(::CoreLib::System::IntPtr& location1, ::CoreLib::System::IntPtr value, ::CoreLib::System::IntPtr comparand)
    {
#ifdef _MSC_VER
		return __init<::CoreLib::System::IntPtr>(InterlockedCompareExchangePointer((void* volatile*)&location1->INTPTR_VALUE_FIELD, value->INTPTR_VALUE_FIELD, comparand->INTPTR_VALUE_FIELD));
#else
		return __init<::CoreLib::System::IntPtr>(__sync_val_compare_and_swap((void* volatile*)&location1->INTPTR_VALUE_FIELD, comparand->INTPTR_VALUE_FIELD, value->INTPTR_VALUE_FIELD));
#endif
	}
    
    // Method : System.Threading.Interlocked._CompareExchange(System.TypedReference, System.TypedReference, object)
    void Interlocked::_CompareExchange(::CoreLib::System::TypedReference location1, ::CoreLib::System::TypedReference value, object* comparand)
    {
#ifdef _MSC_VER
		InterlockedCompareExchangePointer((void* volatile*)&(location1.Value)->INTPTR_VALUE_FIELD, value.Value->INTPTR_VALUE_FIELD, comparand);
#else
		__sync_val_compare_and_swap((void* volatile*)&(location1.Value)->INTPTR_VALUE_FIELD, comparand, value.Value->INTPTR_VALUE_FIELD);
#endif
	}
    
    // Method : System.Threading.Interlocked.CompareExchange(ref int, int, int, ref bool)
    int32_t Interlocked::CompareExchange_Ref_Ref(int32_t& location1, int32_t value, int32_t comparand, bool& succeeded)
    {
#ifdef _MSC_VER
		int32_t val = *(int32_t*)location1;
		int32_t val_after = InterlockedCompareExchange((LONG volatile*)&location1, value, comparand);
		succeeded = val != val_after;
		return val_after;
#else
		auto val = *(int32_t*)location1;
		succeeded = __sync_bool_compare_and_swap((int32_t volatile*)&location1, comparand, value);
		return val;
#endif
	}
    
    // Method : System.Threading.Interlocked.ExchangeAdd(ref int, int)
    int32_t Interlocked::ExchangeAdd_Ref(int32_t& location1, int32_t value)
    {
#ifdef _MSC_VER
		return InterlockedExchangeAdd((LONG volatile*)&location1, value);
#else
		return __sync_fetch_and_add((int32_t volatile*)&location1, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.ExchangeAdd(ref long, long)
    int64_t Interlocked::ExchangeAdd_Ref(int64_t& location1, int64_t value)
    {
#ifdef _MSC_VER
		return InterlockedExchangeAdd64((int64_t volatile*)&location1, value);
#else
		return __sync_fetch_and_add((int64_t volatile*)&location1, value);
#endif
	}
    
    // Method : System.Threading.Interlocked.MemoryBarrier()
    void Interlocked::MemoryBarrier()
    {
		std::atomic_thread_fence(std::memory_order_relaxed);
    }
    
    // Method : System.Threading.Interlocked._MemoryBarrierProcessWide()
    void Interlocked::_MemoryBarrierProcessWide()
    {
		std::atomic_thread_fence(std::memory_order_relaxed);
    }

}}}

namespace CoreLib { namespace System { namespace Threading { 
    namespace _ = ::CoreLib::System::Threading;
}}}
